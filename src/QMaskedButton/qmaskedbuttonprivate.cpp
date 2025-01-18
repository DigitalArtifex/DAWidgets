#include "qmaskedbuttonprivate.h"

QMaskedButtonPrivate::QMaskedButtonPrivate(QObject *parent)
    : QObject{parent}
{

}

void QMaskedButtonPrivate::setHoverOpacity(
    qreal hoverOpacity)
{
    if (qFuzzyCompare(m_hoverOpacity, hoverOpacity))
        return;
    m_hoverOpacity = hoverOpacity;
    emit hoverOpacityChanged();
}

void QMaskedButtonPrivate::setClickOpacity(
    qreal clickOpacity)
{
    if (qFuzzyCompare(m_clickOpacity, clickOpacity))
        return;
    m_clickOpacity = clickOpacity;
    emit clickOpacityChanged();
}

void QMaskedButtonPrivate::setOpacity(
    qreal opacity)
{
    if (qFuzzyCompare(m_opacity, opacity))
        return;
    m_opacity = opacity;
    emit opacityChanged();
}
