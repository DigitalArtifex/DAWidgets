#include "digitalartifexwidgets.h"
#include "qgaugewidgetplugin.h"
#include "qthrobberwidgetplugin.h"
#include "qmaskedbuttonplugin.h"
#include "qindicatorwidgetplugin.h"

DigitalArtifexWidgets::DigitalArtifexWidgets(QObject *parent)
    : QObject(parent)
{
    m_widgets.append(new QGaugeWidgetPlugin(this));
    m_widgets.append(new QThrobberWidgetPlugin(this));
    m_widgets.append(new QIndicatorWidgetPlugin(this));
    m_widgets.append(new QMaskedButtonPlugin(this));
}

QList<QDesignerCustomWidgetInterface *> DigitalArtifexWidgets::customWidgets() const
{
    return m_widgets;
}
