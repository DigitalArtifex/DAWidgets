#include "qgaugewidgetprivate.h"

QGaugeWidgetPrivate::QGaugeWidgetPrivate(QObject *parent)
    : QObject{parent}
{
}

QGaugeWidgetPrivate::~QGaugeWidgetPrivate()
{

}

void QGaugeWidgetPrivate::setDisplayedValue(qreal displayedValue)
{
    m_displayedValue = displayedValue;
    emit displayedValueChanged();
}

void QGaugeWidgetPrivate::setProgress(qreal progress)
{
    m_progress = progress;
    emit progressChanged();
}
