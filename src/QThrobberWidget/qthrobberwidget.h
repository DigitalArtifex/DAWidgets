#ifndef QTHROBBERWIDGET_H
#define QTHROBBERWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QGuiApplication>

#include "dalib_global.h"

#include "qthrobberwidgetprivate.h"

class DA_EXPORT QThrobberWidget : public QWidget {
        Q_OBJECT
    public:
        enum Speed
        {
            Fastest,
            Fast,
            Normal,
            Slow,
            Slowest
        };

        QThrobberWidget(QWidget * parent = 0);

        ~QThrobberWidget();

        qreal fontSize() const;

        QSize iconSize() const;

        QIcon icon() const;

        Q_INVOKABLE void start();

        Q_INVOKABLE void stop();

        bool isPlaying() const;

        QColor throbberColor() const;

        QPen throbberPen() const;

        int throbberWidth() const;

        bool iconOpacityAnimationEnabled() const;

        bool iconScaleAnimationEnabled() const;

        Qt::Alignment textAlignment() const;

        QString text() const;

        QColor textColor() const;

        Qt::Alignment iconAlignment() const;

        Speed speed() const;

    public slots:

        void setFontSize(qreal fontSize);

        void setIconSize(const QSize &iconSize);

        void setIcon(const QIcon &icon);

        void setThrobberColor(const QColor &throbberColor);

        void setThrobberPen(const QPen &throbberPen);

        void setThrobberWidth(int throbberWidth);

        void setIconOpacityAnimationEnabled(bool iconOpacityAnimationEnabled);

        void setIconScaleAnimationEnabled(bool iconScaleAnimationEnabled);

        void setTextAlignment(const Qt::Alignment &textAlignment);

        void setText(const QString &text);

        void setTextColor(const QColor &textColor);

        void setIconAlignment(const Qt::Alignment &iconAlignment);

        void setSpeed(Speed speed);

        void setIsPlaying(bool isPlaying);

    protected slots:
        void onAnimationGroupFinished();
        void onSecondaryAnimationGroupFinished();

        void onThrobberRotationChanged();
        void onInnerThrobberRotationChanged();
        void onThrobberLengthChanged();

        void onIconScaleChanged();
        void onIconOpacityChanged();

    signals:

        void fontSizeChanged();

        void iconSizeChanged();

        void iconChanged();

        void isPlayingChanged();

        void throbberColorChanged();

        void throbberPenChanged();

        void throbberWidthChanged();

        void iconOpacityAnimationEnabledChanged();

        void iconScaleAnimationEnabledChanged();

        void textAlignmentChanged();

        void textChanged();

        void textColorChanged();

        void iconAlignmentChanged();

        void speedChanged();

    protected:
        void calculateRect();

        virtual void paintEvent(QPaintEvent *event) override;
        virtual void resizeEvent(QResizeEvent *event) override;

    private:
        QThrobberWidgetPrivate *m_private;

        QPropertyAnimation *m_throbberRotationAnimation = nullptr;
        QPropertyAnimation *m_throbberLengthAnimation = nullptr;
        QPropertyAnimation *m_iconOpacityAnimation = nullptr;
        QPropertyAnimation *m_iconScaleAnimation = nullptr;

        QParallelAnimationGroup *m_animationGroup = nullptr;
        QParallelAnimationGroup *m_secondaryAnimationGroup = nullptr;

        QString m_fontFamily;
        qreal m_fontSize = 12;

        int m_throbberWidth = 8;

        int m_pathRadius = 0;
        int m_paddingX = 0;
        int m_paddingY = 0;

        bool m_animationsEnabled = true;
        bool m_isPlaying = false;
        bool m_throbberLengthGrowing = false;
        bool m_throbberPenSet = false;
        bool m_iconOpacityAnimationEnabled = true;
        bool m_iconScaleAnimationEnabled = false;

        QString m_text;
        QColor m_textColor = QColor("#30b7e0");

        QColor m_throbberColor = QColor("#30b7e0");
        QPen m_throbberPen;

        QSize m_iconSize = QSize(24,24);
        QIcon m_icon;
        Qt::Alignment m_iconAlignment = Qt::AlignCenter;
        Qt::Alignment m_textAlignment = Qt::AlignCenter;

        Speed m_speed = Normal;

        Q_PROPERTY(qreal fontSize READ fontSize WRITE setFontSize NOTIFY fontSizeChanged FINAL)
        Q_PROPERTY(QSize iconSize READ iconSize WRITE setIconSize NOTIFY iconSizeChanged FINAL)
        Q_PROPERTY(QIcon icon READ icon WRITE setIcon NOTIFY iconChanged FINAL)
        Q_PROPERTY(bool isPlaying READ isPlaying WRITE setIsPlaying NOTIFY isPlayingChanged FINAL)
        Q_PROPERTY(QColor throbberColor READ throbberColor WRITE setThrobberColor NOTIFY throbberColorChanged FINAL)
        Q_PROPERTY(QPen throbberPen READ throbberPen WRITE setThrobberPen NOTIFY throbberPenChanged FINAL)
        Q_PROPERTY(int throbberWidth READ throbberWidth WRITE setThrobberWidth NOTIFY throbberWidthChanged FINAL)
        Q_PROPERTY(bool iconOpacityAnimationEnabled READ iconOpacityAnimationEnabled WRITE setIconOpacityAnimationEnabled NOTIFY iconOpacityAnimationEnabledChanged FINAL)
        Q_PROPERTY(bool iconScaleAnimationEnabled READ iconScaleAnimationEnabled WRITE setIconScaleAnimationEnabled NOTIFY iconScaleAnimationEnabledChanged FINAL)
        Q_PROPERTY(Qt::Alignment textAlignment READ textAlignment WRITE setTextAlignment NOTIFY textAlignmentChanged FINAL)
        Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged FINAL)
        Q_PROPERTY(QColor textColor READ textColor WRITE setTextColor NOTIFY textColorChanged FINAL)
        Q_PROPERTY(Qt::Alignment iconAlignment READ iconAlignment WRITE setIconAlignment NOTIFY iconAlignmentChanged FINAL)
        Q_PROPERTY(Speed speed READ speed WRITE setSpeed NOTIFY speedChanged FINAL)
};

Q_DECLARE_METATYPE(QThrobberWidget)
#endif // QTHROBBERWIDGET_H
