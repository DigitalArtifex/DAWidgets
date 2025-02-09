#include "qthrobberwidgetplugin.h"

#include "src/QThrobberWidget/qthrobberwidget.h"

#include <QtPlugin>
#include <QString>
#include <QStringLiteral>

using namespace Qt::Literals::StringLiterals;

QThrobberWidgetPlugin::QThrobberWidgetPlugin(QObject *parent)
{
    Q_UNUSED(parent)
}

bool QThrobberWidgetPlugin::isContainer() const
{
    return false;
}

bool QThrobberWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QIcon QThrobberWidgetPlugin::icon() const
{
    return {};
}

QString QThrobberWidgetPlugin::domXml() const
{
    return uR"(
<ui language="c++">
  <widget class="QThrobberWidget" name="throbberWidget">
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
      <string>Loading Throbber Widget</string>
    </property>
    <property name="whatsThis">
      <string>The throbber widget provides a stylish way to display a busy indicator or loading status.</string>
    </property>
  </widget>
</ui>
)"_s;
}

QString QThrobberWidgetPlugin::name() const
{
    return u"QThrobberWidget"_s;
}

QString QThrobberWidgetPlugin::toolTip() const
{
    return {};
}

QString QThrobberWidgetPlugin::whatsThis() const
{
    return {};
}

QString QThrobberWidgetPlugin::group() const
{
    return u"DigialArtifex Widgets [Indicators]"_s;
}

QString QThrobberWidgetPlugin::includeFile() const
{
    return u"QtDAWidgets/qthrobberwidget.h"_s;
}

QWidget *QThrobberWidgetPlugin::createWidget(QWidget *parent)
{
    return new QThrobberWidget(parent);
}

void QThrobberWidgetPlugin::initialize(QDesignerFormEditorInterface *core)
{
    Q_UNUSED(core)

    if (m_initialized)
        return;

    m_initialized = true;
}
