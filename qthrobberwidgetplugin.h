#ifndef QTHROBBERWIDGETPLUGIN_H
#define QTHROBBERWIDGETPLUGIN_H

#include <QObject>
#include <QtUiPlugin>

class Q_DECL_EXPORT QThrobberWidgetPlugin : public QObject, public QDesignerCustomWidgetInterface
{
        Q_OBJECT
        Q_INTERFACES(QDesignerCustomWidgetInterface)
    public:
        explicit QThrobberWidgetPlugin(QObject *parent = nullptr);

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


#endif // QTHROBBERWIDGETPLUGIN_H
