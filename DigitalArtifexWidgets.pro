CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(digitalartifexwidgets)
TEMPLATE    = lib

DISTFILES   += src/QGaugeWidget/qgaugewidget.json src/QThrobberWidget/qthrobberwidget.json \
    install.sh \
    src/QMaskedButton/qmaskedbutton.json src/QIndicatorWidget/qindicatorwidget.json

DEFINES     += DIGITALARTIFEX_LIBRARY

HEADERS     = qgaugewidgetplugin.h qthrobberwidgetplugin.h digitalartifexwidgets.h \
    dalib_global.h \
    qindicatorwidgetplugin.h \
    qmaskedbuttonplugin.h
SOURCES     = qgaugewidgetplugin.cpp qthrobberwidgetplugin.cpp digitalartifexwidgets.cpp \
    qindicatorwidgetplugin.cpp \
    qmaskedbuttonplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L.

QT += designer core widgets quick

include(qthrobberwidget.pri)
include(qgaugewidget.pri)
include(qmaskedbutton.pri)
include(qindicatorwidget.pri)

target.path = $$[QT_INSTALL_PLUGINS]/designer/
INSTALLS    += target

header_files.files = $$HEADERS
header_files.files -= dalib_global.h
header_files.files -= digitalartifexwidgets.h
header_files.path = $$[QT_INSTALL_HEADERS]/DigitalArtifexWidgets/
INSTALLS += header_files

lib_files.files = $$OUT_PWD/libdigitalartifexwidgets.so $$OUT_PWD/libdigitalartifexwidgets.so.debug
lib_files.path = $$[QT_HOST_LIBS]/
INSTALLS += lib_files

unix{
    QMAKE_POST_LINK += $$quote(cp $$PWD/digitalartifexwidgets.h $$OUT_PWD$$escape_expand(\n\t))
    QMAKE_POST_LINK += $$quote(cp $$PWD/src/QGaugeWidget/qgaugewidget.json $$OUT_PWD$$escape_expand(\n\t))
    QMAKE_POST_LINK += $$quote(cp $$PWD/src/QGaugeWidget/qgaugewidget.h $$OUT_PWD$$escape_expand(\n\t))
    QMAKE_POST_LINK += $$quote(cp $$PWD/src/QThrobberWidget/qthrobberwidget.json $$OUT_PWD$$escape_expand(\n\t))
    QMAKE_POST_LINK += $$quote(cp $$PWD/src/QThrobberWidget/qthrobberwidget.h $$OUT_PWD$$escape_expand(\n\t))
    QMAKE_POST_LINK += $$quote(cp $$PWD/src/QMaskedButton/qmaskedbutton.json $$OUT_PWD$$escape_expand(\n\t))
    QMAKE_POST_LINK += $$quote(cp $$PWD/src/QMaskedButton/qmaskedbutton.h $$OUT_PWD$$escape_expand(\n\t))
    QMAKE_POST_LINK += $$quote(cp $$PWD/src/QIndicatorWidget/qindicatorwidget.json $$OUT_PWD$$escape_expand(\n\t))
    QMAKE_POST_LINK += $$quote(cp $$PWD/src/QIndicatorWidget/qindicatorwidget.h $$OUT_PWD$$escape_expand(\n\t))
    QMAKE_POST_LINK += $$quote(cp $$PWD/install.sh $$OUT_PWD$$escape_expand(\n\t))
}
 win32 {
    QMAKE_POST_LINK += $$quote(cmd /c copy /y $$PWD/digitalartifexwidgets.h $$OUT_PWD$$escape_expand(\n\t))
    QMAKE_POST_LINK += $$quote(cmd /c copy /y $$PWD/src/QGaugeWidget/qgaugewidget.json $$OUT_PWD$$escape_expand(\n\t))
    QMAKE_POST_LINK += $$quote(cmd /c copy /y $$PWD/src/QGaugeWidget/qgaugewidget.h $$OUT_PWD$$escape_expand(\n\t))
    QMAKE_POST_LINK += $$quote(cmd /c copy /y $$PWD/src/QThrobberWidget/qthrobberwidget.json $$OUT_PWD$$escape_expand(\n\t))
    QMAKE_POST_LINK += $$quote(cmd /c copy /y $$PWD/src/QThrobberWidget/qthrobberwidget.h $$OUT_PWD$$escape_expand(\n\t))
    QMAKE_POST_LINK += $$quote(cmd /c copy /y $$PWD/src/QMaskedButton/qmaskedbutton.json $$OUT_PWD$$escape_expand(\n\t))
    QMAKE_POST_LINK += $$quote(cmd /c copy /y $$PWD/src/QMaskedButton/qmaskedbutton.h $$OUT_PWD$$escape_expand(\n\t))
    QMAKE_POST_LINK += $$quote(cmd /c copy /y $$PWD/src/QIndicatorWidget/qindicatorwidget.json $$OUT_PWD$$escape_expand(\n\t))
    QMAKE_POST_LINK += $$quote(cmd /c copy /y $$PWD/src/QIndicatorWidget/qindicatorwidget.h $$OUT_PWD$$escape_expand(\n\t))
}
