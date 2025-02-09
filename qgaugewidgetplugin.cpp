#include "qgaugewidgetplugin.h"

#include "src/QGaugeWidget/qgaugewidget.h"

#include <QtPlugin>
#include <QString>
#include <QStringLiteral>

using namespace Qt::Literals::StringLiterals;

QGaugeWidgetPlugin::QGaugeWidgetPlugin(QObject *parent)
{
    Q_UNUSED(parent)
}

bool QGaugeWidgetPlugin::isContainer() const
{
    return false;
}

bool QGaugeWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QIcon QGaugeWidgetPlugin::icon() const
{
    return {};
}

QString QGaugeWidgetPlugin::domXml() const
{
    return uR"(
<ui language="c++">
  <widget class="QGaugeWidget" name="gaugeWidget">
)"
           R"(
    <property name="geometry">
      <rect>
        <x>0</x>
        <y>0</y>
        <width>100</width>
        <height>100</height>
      </rect>
    </property>
")
R"(
    <property name="toolTip">
      <string>Gauge Cluster Widget</string>
    </property>
    <property name="whatsThis">
      <string>The gauge cluster widget provides a stylish way to display a percentage, temperature or raw value.</string>
    </property>
  </widget>
</ui>
)"_s;
}

QString QGaugeWidgetPlugin::name() const
{
    return u"QGaugeWidget"_s;
}

QString QGaugeWidgetPlugin::toolTip() const
{
    return {};
}

QString QGaugeWidgetPlugin::whatsThis() const
{
    return {};
}

QString QGaugeWidgetPlugin::group() const
{
    return u"DigialArtifex Widgets [Display]"_s;
}

QString QGaugeWidgetPlugin::includeFile() const
{
    return u"QtDAWidgets/qgaugewidget.h"_s;
}

QWidget *QGaugeWidgetPlugin::createWidget(QWidget *parent)
{
    return new QGaugeWidget(parent);
}

void QGaugeWidgetPlugin::initialize(QDesignerFormEditorInterface *core)
{
    Q_UNUSED(core)

    if (m_initialized)
        return;

    m_initialized = true;
}
