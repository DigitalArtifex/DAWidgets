#include "qindicatorwidget.h"

QIndicatorWidget::QIndicatorWidget(
    QWidget *parent
)
    : QWidget{parent}
{
    m_indicatorAnimation = new QPropertyAnimation(this, "indicatorOpacity");
    m_indicatorAnimation->setDuration(150);

    connect(m_indicatorAnimation, SIGNAL(finished()), this, SLOT(onIndicatorOpacityAnimationFinished()));
}

void QIndicatorWidget::setIndicatorOpacity(qreal indicatorOpacity)
{
    if (qFuzzyCompare(m_indicatorOpacity, indicatorOpacity))
        return;

    m_indicatorOpacity = indicatorOpacity;
    emit indicatorOpacityChanged();

    update();
}

void QIndicatorWidget::setState(State state)
{
    if (m_state == state)
        return;
    m_state = state;
    emit stateChanged();

    switch(m_state)
    {
        case State::Off:
            m_indicatorAnimation->setDuration(150);
            off();
            break;

        case State::Blinking:
            m_indicatorAnimation->setDuration(1000);
            on();
            break;

        case State::On:
            on();
            break;
    }
}

void QIndicatorWidget::onIndicatorOpacityAnimationFinished()
{
    if(m_state == State::Blinking && m_indicatorOpacity == 0)
        on();
    else if(m_state == State::Blinking && m_indicatorOpacity != 0)
        off();
}

void QIndicatorWidget::on()
{
    if(m_indicatorAnimation->state() == QPropertyAnimation::Running)
        m_indicatorAnimation->stop();

    m_indicatorAnimation->setStartValue(0.0);
    m_indicatorAnimation->setEndValue(1.0);
    m_indicatorAnimation->start();
}

void QIndicatorWidget::off()
{
    if(m_indicatorAnimation->state() == QPropertyAnimation::Running)
        m_indicatorAnimation->stop();

    m_indicatorAnimation->setStartValue(1.0);
    m_indicatorAnimation->setEndValue(0.0);
    m_indicatorAnimation->start();
}

void QIndicatorWidget::paintEvent(QPaintEvent *event)
{

    QPainter painter;

    painter.begin(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::LosslessImageRendering);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);

    QBrush backgroundBrush(m_backgroundColor);
    backgroundBrush.setStyle(Qt::BrushStyle::NoBrush);

    QPen backgroundPen(m_borderColor);
    backgroundPen.setWidth(m_broderWidth);

    painter.setPen(backgroundPen);
    painter.setBrush(backgroundBrush);
    painter.drawRect(0,0,width(),height());

    qint16 size;

    if(width() > height())
        size = height() - 9;
    else
        size = width() - 9;

    QPen indicatorPen(m_indicatorBorderColor);
    indicatorPen.setWidth(m_indicatorBorderWidth);

    painter.setPen(indicatorPen);
    QBrush indicatorBackgroundBrush(m_indicatorBackgroundColor);
    painter.setBrush(indicatorBackgroundBrush);
    painter.drawEllipse(QPoint(width()/2,height()/2), size / 2, size / 2);

    painter.setPen(Qt::transparent);
    QRadialGradient indicatorGradient(width() / 2, height() / 2, size);
    indicatorGradient.setColorAt(0, m_indicatorColor);
    indicatorGradient.setColorAt(.8, m_indicatorBackgroundColor);
    indicatorGradient.setColorAt(1, m_indicatorBackgroundColor);

    QBrush indicatorBrush(indicatorGradient);

    painter.setBrush(indicatorBrush);
    painter.setOpacity(m_indicatorOpacity);
    painter.drawEllipse(QPoint(width()/2,height()/2), size / 2, size / 2);

    painter.end();

    QWidget::paintEvent(event);
}

void QIndicatorWidget::setIndicatorBorderColor(const QColor &indicatorBorderColor)
{
    if (m_indicatorBorderColor == indicatorBorderColor)
        return;

    m_indicatorBorderColor = indicatorBorderColor;
    emit indicatorBorderColorChanged();
}

void QIndicatorWidget::setIndicatorBorderWidth(qint8 indicatorBorderWidth)
{
    if (m_indicatorBorderWidth == indicatorBorderWidth)
        return;
    m_indicatorBorderWidth = indicatorBorderWidth;
    emit indicatorBorderWidthChanged();
}

void QIndicatorWidget::setBorderColor(const QColor &borderColor)
{
    if (m_borderColor == borderColor)
        return;

    m_borderColor = borderColor;
    emit borderColorChanged();
}

void QIndicatorWidget::setBroderWidth(qint8 broderWidth)
{
    if (m_broderWidth == broderWidth)
        return;
    m_broderWidth = broderWidth;
    emit broderWidthChanged();
}

void QIndicatorWidget::setIndicatorBackgroundColor(const QColor &indicatorBackgroundColor)
{
    if (m_indicatorBackgroundColor == indicatorBackgroundColor)
        return;
    m_indicatorBackgroundColor = indicatorBackgroundColor;
    emit indicatorBackgroundColorChanged();

    update();
}

void QIndicatorWidget::setIndicatorColor(const QColor &indicatorColor)
{
    if (m_indicatorColor == indicatorColor)
        return;

    m_indicatorColor = indicatorColor;
    emit indicatorColorChanged();

    update();
}

void QIndicatorWidget::setBackgroundColor(const QColor &backgroundColor)
{
    if (m_backgroundColor == backgroundColor)
        return;
    m_backgroundColor = backgroundColor;
    emit backgroundColorChanged();

    update();
}
