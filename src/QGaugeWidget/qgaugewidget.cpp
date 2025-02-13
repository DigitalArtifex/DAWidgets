#include "qgaugewidget.h"

QGaugeWidget::QGaugeWidget(QWidget *parent, Mode mode) : QWidget(parent)
{
    m_mode = mode;
    m_private = new QGaugeWidgetPrivate(this);
    connect(m_private, SIGNAL(displayedValueChanged()), this, SLOT(onDisplayedValueChanged()));
    connect(m_private, SIGNAL(progressChanged()), this, SLOT(onProgressChanged()));

    m_progressAnimation = new QPropertyAnimation(m_private, "progress");
    m_progressAnimation->setDuration(500);

    m_displayedValueAnimation = new QPropertyAnimation(m_private, "displayedValue");
    m_displayedValueAnimation->setDuration(500);

    m_animationGroup = new QParallelAnimationGroup(this);
    m_animationGroup->addAnimation(m_progressAnimation);
    m_animationGroup->addAnimation(m_displayedValueAnimation);

    m_progressBarPen.setCapStyle(Qt::FlatCap);
    m_progressBarPen.setColor(m_progressBarColor);
    m_progressBarPen.setWidth(m_pathWidth + 4);

    m_progressBarFillPen.setWidth(m_pathWidth);
    m_progressBarFillPen.setColor(m_progressBarFillColor);
    m_progressBarFillPen.setCapStyle(Qt::FlatCap);

    int id = QFontDatabase::addApplicationFont("://src/QGaugeWidget/fonts/digital-7(mono).ttf");
    m_fontFamily = QFontDatabase::applicationFontFamilies(id).at(0);
}

QGaugeWidget::~QGaugeWidget()
{
    if(m_animationGroup)
        delete m_animationGroup;

    if(m_iconMovie)
        delete m_iconMovie;
}

void QGaugeWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;

    QPixmap pixmap;

    QSize size = m_iconSize;

    qreal x = 10;
    qreal y = 10;

    //Icon Alignment
    if((m_iconAlignment & Qt::AlignHCenter) == Qt::AlignHCenter)
        x = (width() / 2) - (size.width() / 2);

    else if((m_iconAlignment & Qt::AlignLeft) == Qt::AlignLeft)
        x = 10;

    else if((m_iconAlignment & Qt::AlignRight) == Qt::AlignRight)
        x = (width() - size.width()) - 10;

    if((m_iconAlignment & Qt::AlignVCenter) == Qt::AlignVCenter)
        y = (height() / 2) - (size.height() / 2);

    else if((m_iconAlignment & Qt::AlignTop) == Qt::AlignTop)
        y = 10;

    else if((m_iconAlignment & Qt::AlignBottom) == Qt::AlignBottom)
        y = (height() - size.height()) - 10;

    //qss/qproperty overrides - move them out of the painter event somehow

    if(property("icon-right").isValid())
        x -= property("icon-right").toInt();
    if(property("icon-left").isValid())
        x += property("icon-left").toInt();

    if(property("icon-top").isValid())
        y += property("icon-top").toInt();
    if(property("icon-bottom").isValid())
        y -= property("icon-bottom").toInt();

    if(property("icon-size").isValid())
        size = property("icon-size").toSize();

    if(m_animatedIconEnabled)
        pixmap = m_iconMovie->currentPixmap();
    else
    {
        if(isEnabled())
            pixmap = (m_icon.pixmap(size, QIcon::Normal, QIcon::On));
        else
            pixmap = (m_icon.pixmap(size, QIcon::Disabled, QIcon::On));
    }

    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);

    //Draw the background color
    if(property("background-color").isValid())
        painter.fillRect(0,0,width(),height(), QColor(property("background-color").toString()));
    else
        painter.fillRect(0,0,width(),height(), m_backgroundColor);

    painter.drawPixmap(QRect(x, y, size.width(), size.height()), pixmap);

    painter.translate(4, 4);

    //draw background
    painter.setPen(m_progressBarPen);
    painter.drawArc(QRectF(m_paddingX, m_paddingY, m_pathRadius - m_pathWidth, m_pathRadius - m_pathWidth), 225 * 16, (-270*16));

    //draw filler
    painter.setPen(m_progressBarFillPen);
    painter.drawArc(QRectF(m_paddingX, m_paddingY, m_pathRadius - m_pathWidth, m_pathRadius - m_pathWidth), 225 * 16, ((270*16) * m_private->progress()) * -1);

    QFont font;

    if(!m_fontFamily.isEmpty())
        font.setFamily(m_fontFamily);
    else
        font.setFamily(font.defaultFamily());

    font.setPointSize(m_fontSize);
    QFontMetrics fontMetrics(font);

    QString text;

    if(m_mode == Percent)
        text = QString::number(m_private->progress() * 100.00, 'f', 2) + QString("%");
    else if(m_mode == Temperature)
        text = QString::number(m_private->displayedValue(), 'f', 2) + QString("°");
    else
        text = QString::number(m_private->displayedValue(), 'f', 2);

    qreal textWidth = fontMetrics.horizontalAdvance(text);

    //Get true center
    x = width() / 2;
    x -= textWidth / 2;

    if(m_mode != Temperature)
        x -= 3;

    y = (height()/2);

    QPen textPen;
    textPen.setColor(m_textColor);

    painter.setPen(textPen);
    painter.setFont(font);
    painter.drawText(QPoint(x,y),text);
    painter.end();

    QWidget::paintEvent(event);
}

void QGaugeWidget::resizeEvent(QResizeEvent *event)
{
    if(this->width() > this->height())
    {
        m_paddingX = this->width() - this->height();
        m_paddingX /= 2;
        m_paddingY = m_pathWidth / 2;
        m_pathRadius = this->height() - m_pathWidth;
    }
    else
    {
        m_paddingY = this->height() - this->width();
        m_paddingY /= 2;
        m_paddingY += m_pathWidth / 2;
        m_paddingX = m_pathWidth / 2;
        m_pathRadius = this->width() - m_pathWidth;
    }

    QWidget::resizeEvent(event);
}

void QGaugeWidget::showEvent(QShowEvent *event)
{
    if(m_animatedIconEnabled)
        m_iconMovie->start();

    QWidget::showEvent(event);
}

void QGaugeWidget::hideEvent(QHideEvent *event)
{
    if(m_animatedIconEnabled)
        m_iconMovie->stop();

    QWidget::hideEvent(event);
}

void QGaugeWidget::setMode(Mode mode)
{
    if (m_mode == mode)
        return;

    m_mode = mode;
    emit modeChanged();

    update();
}

void QGaugeWidget::setTextColor(const QColor &textColor)
{
    if (m_textColor == textColor)
        return;
    m_textColor = textColor;
    emit textColorChanged();

    update();
}

void QGaugeWidget::setProgressBarFillPen(const QPen &progressBarFillPen)
{
    if (m_progressBarFillPen == progressBarFillPen)
        return;

    m_progressBarFillPen = progressBarFillPen;
    emit progressBarFillPenChanged();

    update();
}

void QGaugeWidget::setProgressBarPen(const QPen &progressBarPen)
{
    if (m_progressBarPen == progressBarPen)
        return;
    m_progressBarPen = progressBarPen;
    emit progressBarPenChanged();

    update();
}

void QGaugeWidget::setProgressBarFillColor(const QColor &progressBarFillColor)
{
    if (m_progressBarFillColor == progressBarFillColor)
        return;

    m_progressBarFillColor = progressBarFillColor;
    m_progressBarFillPen.setColor(m_progressBarColor);

    emit progressBarFillColorChanged();

    update();
}

void QGaugeWidget::setProgressBarColor(const QColor &progressBarColor)
{
    if (m_progressBarColor == progressBarColor)
        return;

    m_progressBarColor = progressBarColor;
    m_progressBarPen.setColor(m_progressBarColor);

    emit progressBarColorChanged();

    update();
}

void QGaugeWidget::setAnimationsEnabled(bool animationsEnabled)
{
    if (m_animationsEnabled == animationsEnabled)
        return;

    m_animationsEnabled = animationsEnabled;
    emit animationsEnabledChanged();

    if(!m_animationsEnabled)
        setAnimatedIconEnabled(false);
}

void QGaugeWidget::setAnimatedIcon(const QString &animatedIcon)
{
    if (m_animatedIcon == animatedIcon)
        return;

    if(!animatedIcon.endsWith(".gif", Qt::CaseInsensitive))
    {
        qWarning() << "(QGaugeWidget) Animated Icon must be the path of a valid gif file/resource";
        return;
    }

    m_animatedIcon = animatedIcon;
    emit animatedIconChanged();

    setAnimatedIconEnabled(true);

    if(!m_iconMovie)
    {
        m_iconMovie = new QMovie(this);
        connect(m_iconMovie, SIGNAL(frameChanged(int)), this, SLOT(iconMovieFrameChanged(int)));
    }

    m_iconMovie->setFileName(animatedIcon);
    m_iconMovie->start();

    update();
}

void QGaugeWidget::setAnimatedIconEnabled(bool animatedIconEnabled)
{
    if (m_animatedIconEnabled == animatedIconEnabled)
        return;

    m_animatedIconEnabled = animatedIconEnabled;
    emit animatedIconEnabledChanged();
}

void QGaugeWidget::setPathWidth(int pathWidth)
{
    if (m_pathWidth == pathWidth)
        return;

    m_pathWidth = pathWidth;

    m_progressBarPen.setWidth(pathWidth);
    m_progressBarFillPen.setWidth(pathWidth - 4);

    emit pathWidthChanged();

    update();
}

void QGaugeWidget::iconMovieFrameChanged(int frame)
{
    Q_UNUSED(frame)
    update();
}

void QGaugeWidget::onDisplayedValueChanged()
{
    update();
}

void QGaugeWidget::onProgressChanged()
{
    update();
}

void QGaugeWidget::setValue(qreal value)
{
    if (qFuzzyCompare(m_value, value))
        return;

    if(value < m_minimum)
        value = m_minimum;
    else if(value > m_maximum)
        value = m_maximum;

    m_value = value;

    if(m_animationsEnabled)
    {
        if(m_animationGroup->state() == QParallelAnimationGroup::Running)
            m_animationGroup->stop();

        m_progressAnimation->setStartValue(m_private->progress());
        m_progressAnimation->setEndValue(m_value / m_maximum);

        m_displayedValueAnimation->setStartValue(m_private->displayedValue());
        m_displayedValueAnimation->setEndValue(m_value);

        m_animationGroup->start();
    }
    else
    {
        m_private->setProgress(m_value / m_maximum);
        m_private->setDisplayedValue(m_value);
    }

    emit valueChanged();
}

void QGaugeWidget::setMaximum(qreal maximum)
{
    if (qFuzzyCompare(m_maximum, maximum))
        return;

    m_maximum = maximum;

    if(m_minimum == m_maximum)
        m_maximum += 1.0;

    if(m_animationsEnabled)
    {
        if(m_animationGroup->state() == QParallelAnimationGroup::Running)
            m_animationGroup->stop();

        m_progressAnimation->setStartValue(m_private->progress());
        m_progressAnimation->setEndValue(m_value / m_maximum);

        m_displayedValueAnimation->setStartValue(m_private->displayedValue());
        m_displayedValueAnimation->setEndValue(m_value);

        m_animationGroup->start();
    }
    else
    {
        m_private->setProgress(m_value / m_maximum);
        m_private->setDisplayedValue(m_value);
    }

    emit maximumChanged();

    update();
}

void QGaugeWidget::setMinimum(qreal minimum)
{
    if (qFuzzyCompare(m_minimum, minimum))
        return;
    m_minimum = minimum;
    emit minimumChanged();

    update();
}


void QGaugeWidget::setIcon(const QIcon &icon)
{
    m_icon = icon;
    update();
    emit iconChanged();

    update();
}

void QGaugeWidget::setIconSize(const QSize &iconSize)
{
    if (m_iconSize == iconSize)
        return;
    m_iconSize = iconSize;
    emit iconSizeChanged();

    update();
}

void QGaugeWidget::setFontSize(qreal fontSize)
{
    if (qFuzzyCompare(m_fontSize, fontSize))
        return;
    m_fontSize = fontSize;
    emit fontSizeChanged();

    update();
}

void QGaugeWidget::setBackgroundColor(const QColor &backgroundColor)
{
    if (m_backgroundColor == backgroundColor)
        return;

    m_backgroundColor = backgroundColor;
    emit backgroundColorChanged();

    update();
}

