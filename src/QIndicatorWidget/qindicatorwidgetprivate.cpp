#include "qindicatorwidgetprivate.h"

QIndicatorWidgetPrivate::QIndicatorWidgetPrivate(
    QObject *parent
)
    : QObject{parent}
{
    m_indicatorAnimation = new QPropertyAnimation(this, "indicatorOpacity");
    m_indicatorAnimation->setDuration(150);

    connect(m_indicatorAnimation, SIGNAL(finished()), this, SLOT(onIndicatorOpacityAnimationFinished()));
}

void QIndicatorWidgetPrivate::setIndicatorOpacity(
    qreal indicatorOpacity)
{
    if (qFuzzyCompare(m_indicatorOpacity, indicatorOpacity))
        return;

    m_indicatorOpacity = indicatorOpacity;
    emit indicatorOpacityChanged();
}

void QIndicatorWidgetPrivate::onIndicatorOpacityAnimationFinished()
{
    if(m_isBlinking && m_indicatorOpacity == 0)
        on();
    else if(m_isBlinking && m_indicatorOpacity != 0)
        off();
}

void QIndicatorWidgetPrivate::on()
{
    if(m_indicatorAnimation->state() == QPropertyAnimation::Running)
        m_indicatorAnimation->stop();

    m_indicatorAnimation->setStartValue(0.0);
    m_indicatorAnimation->setEndValue(1.0);
    m_indicatorAnimation->start();
}

void QIndicatorWidgetPrivate::off()
{
    if(m_indicatorAnimation->state() == QPropertyAnimation::Running)
        m_indicatorAnimation->stop();

    m_indicatorAnimation->setStartValue(1.0);
    m_indicatorAnimation->setEndValue(0.0);
    m_indicatorAnimation->start();
}
