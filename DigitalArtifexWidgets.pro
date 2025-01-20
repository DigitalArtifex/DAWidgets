CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(digitalartifexwidgets)
TEMPLATE    = lib

DISTFILES   += \
    src/QGaugeWidget/qgaugewidget.json \
    src/QThrobberWidget/qthrobberwidget.json \
    src/QMaskedButton/qmaskedbutton.json \
    src/QIndicatorWidget/qindicatorwidget.json

DEFINES     += DIGITALARTIFEX_LIBRARY

HEADERS     = \
    qgaugewidgetplugin.h \
    qthrobberwidgetplugin.h \
    digitalartifexwidgets.h \
    dalib_global.h \
    qindicatorwidgetplugin.h \
    qmaskedbuttonplugin.h

SOURCES     = \
    qgaugewidgetplugin.cpp \
    qthrobberwidgetplugin.cpp \
    digitalartifexwidgets.cpp \
    qindicatorwidgetplugin.cpp \
    qmaskedbuttonplugin.cpp

RESOURCES   = icons.qrc
LIBS        += -L.

QT += designer core widgets quick

include(qthrobberwidget.pri)
include(qgaugewidget.pri)
include(qmaskedbutton.pri)
include(qindicatorwidget.pri)

headerfiles.files = $$HEADERS
headerfiles.path = $$[QT_INSTALL_HEADERS]/DigitalArtifexWidgets/
INSTALLS    += headerfiles

target.path = $$[QT_HOST_LIBS]/
INSTALLS    += target

creator.files = $$OUT_PWD/libdigitalartifexwidgets.so $$OUT_PWD/libdigitalartifexwidgets.so.debug
creator.path = $$clean_path($$[QT_HOST_LIBS]/../../../Tools/QtCreator/lib/Qt/plugins/designer/)
INSTALLS += creator

designer.files = $$OUT_PWD/libdigitalartifexwidgets.so $$OUT_PWD/libdigitalartifexwidgets.so.debug
designer.path = $$[QT_INSTALL_PLUGINS]/designer/
INSTALLS += designer
