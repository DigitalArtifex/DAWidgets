#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(
    QWidget *parent
)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->indicatorWidget_3->setState(QIndicatorWidget::State::Blinking);
}

MainWindow::~MainWindow()
{
    delete ui;
}
