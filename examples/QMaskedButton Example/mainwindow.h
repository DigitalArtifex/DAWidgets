#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "DigitalArtifexWidgets/qmaskedbutton.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    protected:
        void setupUi();

    private:
        Ui::MainWindow *ui;

        QMaskedButton *m_xUpWidget = nullptr;
        QMaskedButton *m_xDownWidget = nullptr;
        QMaskedButton *m_yUpWidget = nullptr;
        QMaskedButton *m_yDownWidget = nullptr;
        QMaskedButton *m_zUpWidget = nullptr;
        QMaskedButton *m_zDownWidget = nullptr;
        QMaskedButton *m_homeWidget = nullptr;
};
#endif // MAINWINDOW_H
