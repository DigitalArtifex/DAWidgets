#include "qthrobberwidgetprivate.h"

QThrobberWidgetPrivate::QThrobberWidgetPrivate(QObject *parent)
    : QObject{parent}
{

}

void QThrobberWidgetPrivate::setIconOpacity(qreal iconOpacity)
{
    if (qFuzzyCompare(m_iconOpacity, iconOpacity))
        return;

    m_iconOpacity = iconOpacity;
    emit iconOpacityChanged();
}

void QThrobberWidgetPrivate::setIconScale(qreal iconScale)
{
    if (qFuzzyCompare(m_iconScale, iconScale))
        return;

    m_iconScale = iconScale;
    emit iconScaleChanged();
}

void QThrobberWidgetPrivate::setInnerThrobberRotation(qreal innerThrobberRotation)
{
    if (qFuzzyCompare(m_innerThrobberRotation, innerThrobberRotation))
        return;

    m_innerThrobberRotation = innerThrobberRotation;
    emit innerThrobberRotationChanged();
}

void QThrobberWidgetPrivate::setThrobberLength(qreal throbberLength)
{
    if (qFuzzyCompare(m_throbberLength, throbberLength))
        return;

    m_throbberLength = throbberLength;
    emit throbberLengthChanged();
}

void QThrobberWidgetPrivate::setThrobberRotation(qreal throbberRotation)
{
    if (qFuzzyCompare(m_throbberRotation, throbberRotation))
        return;

    m_throbberRotation = throbberRotation;
    emit throbberRotationChanged();
}
