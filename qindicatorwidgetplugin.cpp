#include "qindicatorwidgetplugin.h"

#include "src/QIndicatorWidget/qindicatorwidget.h"

#include <QtPlugin>
#include <QString>
#include <QStringLiteral>

using namespace Qt::Literals::StringLiterals;

QIndicatorWidgetPlugin::QIndicatorWidgetPlugin(QObject *parent)
{
    Q_UNUSED(parent)
}

bool QIndicatorWidgetPlugin::isContainer() const
{
    return false;
}

bool QIndicatorWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QIcon QIndicatorWidgetPlugin::icon() const
{
    return {};
}

QString QIndicatorWidgetPlugin::domXml() const
{
    return uR"(
<ui language="c++">
  <widget class="QIndicatorWidget" name="indicatorWidget">
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
      <string>Status Indicator Widget</string>
    </property>
  </widget>
</ui>
)"_s;
}

QString QIndicatorWidgetPlugin::name() const
{
    return u"QIndicatorWidget"_s;
}

QString QIndicatorWidgetPlugin::toolTip() const
{
    return {};
}

QString QIndicatorWidgetPlugin::whatsThis() const
{
    return {};
}

QString QIndicatorWidgetPlugin::group() const
{
    return u"DigialArtifex Widgets [Indicators]"_s;
}

QString QIndicatorWidgetPlugin::includeFile() const
{
    return u"QtDAWidgets/qindicatorwidget.h"_s;
}

QWidget *QIndicatorWidgetPlugin::createWidget(QWidget *parent)
{
    return new QIndicatorWidget(parent);
}

void QIndicatorWidgetPlugin::initialize(QDesignerFormEditorInterface *core)
{
    Q_UNUSED(core)

    if (m_initialized)
        return;

    m_initialized = true;
}
