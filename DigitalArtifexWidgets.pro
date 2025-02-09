PERIOD = '.'
EXTENSION = '.so'
PRLEXTENSION = '.prl'
NAME        = DAWidgets
VERSION     = $$QT_VERSION
TEMPLATE    = lib

DEFINES     += DIGITALARTIFEX_LIBRARY
QT += core widgets quick

contains(CONFIG, plugin) {
    QT += designer

    DISTFILES   += \
        src/DAWidgets \
        README.md

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

    TARGET      = $$qtLibraryTarget($$NAME)
    creator.files = $$OUT_PWD/lib$$TARGET$$EXTENSION
    creator.path = $$clean_path($$[QT_HOST_LIBS]/../../../Tools/QtCreator/lib/Qt/plugins/designer/)
    creator.CONFIG += no_check_exist
    INSTALLS += creator

    designer.files = $$OUT_PWD/lib$$TARGET$$EXTENSION
    designer.path = $$[QT_INSTALL_PLUGINS]/designer/
    designer.CONFIG += no_check_exist
    INSTALLS += designer
}
else {

    CONFIG      += shared metatypes
    TARGET      = $$qtLibraryTarget(Qt$$QT_MAJOR_VERSION$$NAME)

    TARGET.path = $$[QT_HOST_LIBS]/

    PRIVATE_HEADERS.path = $$[QT_INSTALL_HEADERS]/QtDAWidgets/$$QT_VERSION/QtDAWidgets/private
    INSTALLS += PRIVATE_HEADERS

    GCC_VERSION = $$QMAKE_CXX.QMAKE_GCC_MAJOR_VERSION$$PERIOD$$QMAKE_CXX.QMAKE_GCC_MINOR_VERSION$$PERIOD$$QMAKE_CXX.QMAKE_GCC_PATCH_VERSION

#create the module file information
modulefile = '{ $$escape_expand(\\n\\t)\
"name": "DAWidgets", $$escape_expand(\\n\\t)\
"repository": "qtbase", $$escape_expand(\\n\\t)\
"version": "$$QT_VERSION", $$escape_expand(\\n\\t)\
"plugin_types": ["generic"], $$escape_expand(\\n\\t)\
"built_with": { $$escape_expand(\\n\\t\\t)\
"compiler_id": "GNU", $$escape_expand(\\n\\t\\t)\
"compiler_target": "", $$escape_expand(\\n\\t\\t)\
"compiler_version": "$$GCC_VERSION", $$escape_expand(\\n\\t\\t)\
"cross_compiled": false, $$escape_expand(\\n\\t\\t)\
"target_system": "$$QMAKE_TARGET.platform", $$escape_expand(\\n\\t\\t)\
"architecture": "$$QMAKE_TARGET.arch" $$escape_expand(\\n\\t)\
}$$escape_expand(\\n)}'

    write_file($$OUT_PWD/DAWidgets.json, modulefile)

    headerfiles.files = $$HEADERS
    headerfiles.files += $$_PRO_FILE_PWD_/src/DAWidgets
    headerfiles.path = $$[QT_INSTALL_HEADERS]/QtDAWidgets/
    INSTALLS    += headerfiles

    module.files = $$OUT_PWD/DAWidgets.json
    module.path = $$[QT_HOST_PREFIX]/modules
    INSTALLS += module


    prlfile = 'QMAKE_PRL_TARGET = lib$$TARGET$$EXTENSION$$escape_expand(\\n)QMAKE_PRL_CONFIG = shared$$escape_expand(\\n)QMAKE_PRL_VERSION = $$QT_VERSION$$escape_expand(\\n)QMAKE_PRL_LIBS = \$\$[QT_INSTALL_LIBS]/libQt6Gui.so -lGL \$\$[QT_INSTALL_LIBS]/libQt6Core.so \$\$[QT_INSTALL_LIBS]/libQt6Quick.so -pthread$$escape_expand(\\n)QMAKE_PRL_LIBS_FOR_CMAKE = \$\$[QT_INSTALL_LIBS]/libQt6Gui.so;-lGL;\$\$[QT_INSTALL_LIBS]/libQt6Core.so;\$\$[QT_INSTALL_LIBS]/libQt6Quick.so;-pthread'

    write_file($$OUT_PWD/lib$$TARGET$$PRLEXTENSION, prlfile)

    prl.files = $$OUT_PWD/lib$$TARGET$$PRLEXTENSION
    prl.path = $$[QT_HOST_LIBS]/
    INSTALLS += prl

    #QMAKE_POST_LINK
}

include(qthrobberwidget.pri)
include(qgaugewidget.pri)
include(qmaskedbutton.pri)
include(qindicatorwidget.pri)
