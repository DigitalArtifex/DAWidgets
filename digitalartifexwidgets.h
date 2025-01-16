#ifndef DIGITALARTIFEXWIDGETS_H
#define DIGITALARTIFEXWIDGETS_H

//#include <QtDesigner>
#include <QtUiPlugin>
#include <qplugin.h>

class Q_DECL_EXPORT DigitalArtifexWidgets : public QObject, public QDesignerCustomWidgetCollectionInterface
{
        Q_OBJECT
        Q_INTERFACES(QDesignerCustomWidgetCollectionInterface)
        Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetCollectionInterface")

    public:
        explicit DigitalArtifexWidgets(QObject *parent = nullptr);

        QList<QDesignerCustomWidgetInterface*> customWidgets() const override;

    private:
        QList<QDesignerCustomWidgetInterface*> m_widgets;
};

#endif // DIGITALARTIFEXWIDGETS_H
