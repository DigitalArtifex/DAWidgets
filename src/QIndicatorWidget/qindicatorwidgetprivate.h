#ifndef QINDICATORWIDGETPRIVATE_H
#define QINDICATORWIDGETPRIVATE_H

#include <QObject>
#include <QPropertyAnimation>
#include "dalib_global.h"

class QIndicatorWidget;

class DA_EXPORT QIndicatorWidgetPrivate : public QObject
{
        Q_OBJECT

        friend QIndicatorWidget;

    public:
        qreal indicatorOpacity() const { return m_indicatorOpacity; }

        bool isBlinking() const { return m_isBlinking; }

    public slots:
        void setIndicatorOpacity(qreal indicatorOpacity);

        void setIsBlinking(
            bool isBlinking)
        {
            m_isBlinking = isBlinking;
        }

    signals:
        void indicatorOpacityChanged();

    private slots:
        void onIndicatorOpacityAnimationFinished();

    private:
        explicit QIndicatorWidgetPrivate(QObject *parent = nullptr);

        void on();
        void off();

        qreal m_indicatorOpacity = 0.0;
        QPropertyAnimation *m_indicatorAnimation = nullptr;

        bool m_isBlinking = false;

        Q_PROPERTY(
            qreal indicatorOpacity READ indicatorOpacity WRITE setIndicatorOpacity NOTIFY
                indicatorOpacityChanged FINAL)
};

#endif // QINDICATORWIDGETPRIVATE_H
