#include "qmaskedbuttonplugin.h"

#include "src/QMaskedButton/qmaskedbutton.h"

#include <QtPlugin>
#include <QString>
#include <QStringLiteral>

using namespace Qt::Literals::StringLiterals;

QMaskedButtonPlugin::QMaskedButtonPlugin(QObject *parent)
{
    Q_UNUSED(parent)
}

bool QMaskedButtonPlugin::isContainer() const
{
    return false;
}

bool QMaskedButtonPlugin::isInitialized() const
{
    return m_initialized;
}

QIcon QMaskedButtonPlugin::icon() const
{
    return {};
}

QString QMaskedButtonPlugin::domXml() const
{
    return uR"(
<ui language="c++">
  <widget class="QMaskedButton" name="maskedButton">
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

QString QMaskedButtonPlugin::name() const
{
    return u"QMaskedButton"_s;
}

QString QMaskedButtonPlugin::toolTip() const
{
    return {};
}

QString QMaskedButtonPlugin::whatsThis() const
{
    return {};
}

QString QMaskedButtonPlugin::group() const
{
    return u"DigialArtifex Widgets [Buttons]"_s;
}

QString QMaskedButtonPlugin::includeFile() const
{
    return u"QtDAWidgets/qmaskedbutton.h"_s;
}

QWidget *QMaskedButtonPlugin::createWidget(QWidget *parent)
{
    return new QMaskedButton(parent);
}

void QMaskedButtonPlugin::initialize(QDesignerFormEditorInterface *core)
{
    Q_UNUSED(core)

    if (m_initialized)
        return;

    m_initialized = true;
}
