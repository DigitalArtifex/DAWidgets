#ifndef QINDICATORWIDGETPLUGIN_H
#define QINDICATORWIDGETPLUGIN_H

#include <QObject>
#include <QtUiPlugin>

class Q_DECL_EXPORT QIndicatorWidgetPlugin : public QObject, public QDesignerCustomWidgetInterface
{
        Q_OBJECT
        // Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetInterface")
        Q_INTERFACES(QDesignerCustomWidgetInterface)
    public:
        explicit QIndicatorWidgetPlugin(QObject *parent = nullptr);

        bool isContainer() const override;
        bool isInitialized() const override;
        QIcon icon() const override;
        QString domXml() const override;
        QString group() const override;
        QString includeFile() const override;
        QString name() const override;
        QString toolTip() const override;
        QString whatsThis() const override;
        QWidget *createWidget(QWidget *parent) override;
        void initialize(QDesignerFormEditorInterface *core) override;

    private:
        bool m_initialized = false;
};

#endif // QINDICATORWIDGETPLUGIN_H
