#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(
    QWidget *parent
)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUi()
{
    QPixmap xDownImage(":/images/ui/toolhead/x_down_control_image.png");
    QPixmap xDownClickedImage(":/images/ui/toolhead/x_down_control_image_clicked.png");
    QPixmap xDownHoverImage(":/images/ui/toolhead/x_down_control_image_hover.png");

    m_xDownWidget = new QMaskedButton(ui->frame);
    m_xDownWidget->setPixmap(xDownImage);
    m_xDownWidget->setClickPixmap(xDownClickedImage);
    m_xDownWidget->setHoverPixmap(xDownHoverImage);
    m_xDownWidget->setFixedSize(317, 218);
    connect(m_xDownWidget, SIGNAL(clicked(QMaskedButton*)), this, SLOT(xDownClickEvent()));

    QPixmap xUpImage(":/images/ui/toolhead/x_up_control_image.png");
    QPixmap xUpClickedImage(":/images/ui/toolhead/x_up_control_image_clicked.png");
    QPixmap xUpHoverImage(":/images/ui/toolhead/x_up_control_image_hover.png");

    m_xUpWidget = new QMaskedButton(ui->frame);
    m_xUpWidget->setPixmap(xUpImage);
    m_xUpWidget->setClickPixmap(xUpClickedImage);
    m_xUpWidget->setHoverPixmap(xUpHoverImage);
    m_xUpWidget->setFixedSize(317, 218);
    connect(m_xUpWidget, SIGNAL(clicked(QMaskedButton*)), this, SLOT(xUpClickEvent()));

    QPixmap yDownImage(":/images/ui/toolhead/y_down_control_image.png");
    QPixmap yDownClickedImage(":/images/ui/toolhead/y_down_control_image_clicked.png");
    QPixmap yDownHoverImage(":/images/ui/toolhead/y_down_control_image_hover.png");

    m_yDownWidget = new QMaskedButton(ui->frame);
    m_yDownWidget->setPixmap(yDownImage);
    m_yDownWidget->setClickPixmap(yDownClickedImage);
    m_yDownWidget->setHoverPixmap(yDownHoverImage);
    m_yDownWidget->setFixedSize(317, 218);
    connect(m_yDownWidget, SIGNAL(clicked(QMaskedButton*)), this, SLOT(yDownClickEvent()));

    QPixmap yUpImage(":/images/ui/toolhead/y_up_control_image.png");
    QPixmap yUpClickedImage(":/images/ui/toolhead/y_up_control_image_clicked.png");
    QPixmap yUpHoverImage(":/images/ui/toolhead/y_up_control_image_hover.png");

    m_yUpWidget = new QMaskedButton(ui->frame);
    m_yUpWidget->setPixmap(yUpImage);
    m_yUpWidget->setClickPixmap(yUpClickedImage);
    m_yUpWidget->setHoverPixmap(yUpHoverImage);
    m_yUpWidget->setFixedSize(317, 218);
    connect(m_yUpWidget, SIGNAL(clicked(QMaskedButton*)), this, SLOT(yUpClickEvent()));

    QPixmap zDownImage(":/images/ui/toolhead/z_down_control_image.png");
    QPixmap zDownClickedImage(":/images/ui/toolhead/z_down_control_image_clicked.png");
    QPixmap zDownHoverImage(":/images/ui/toolhead/z_down_control_image_hover.png");

    m_zDownWidget = new QMaskedButton(ui->frame);
    m_zDownWidget->setPixmap(zDownImage);
    m_zDownWidget->setClickPixmap(zDownClickedImage);
    m_zDownWidget->setHoverPixmap(zDownHoverImage);
    m_zDownWidget->setFixedSize(317, 218);
    connect(m_zDownWidget, SIGNAL(clicked(QMaskedButton*)), this, SLOT(zDownClickEvent()));

    QPixmap zUpImage(":/images/ui/toolhead/z_up_control_image.png");
    QPixmap zUpClickedImage(":/images/ui/toolhead/z_up_control_image_clicked.png");
    QPixmap zUpHoverImage(":/images/ui/toolhead/z_up_control_image_hover.png");

    m_zUpWidget = new QMaskedButton(ui->frame);
    m_zUpWidget->setPixmap(zUpImage);
    m_zUpWidget->setClickPixmap(zUpClickedImage);
    m_zUpWidget->setHoverPixmap(zUpHoverImage);
    m_zUpWidget->setFixedSize(317, 218);
    connect(m_zUpWidget, SIGNAL(clicked(QMaskedButton*)), this, SLOT(zUpClickEvent()));

    QPixmap homeImage(":/images/ui/toolhead/home_default.png");
    QPixmap homeClickedImage(":/images/ui/toolhead/home_clicked.png");
    QPixmap homeHoverImage(":/images/ui/toolhead/home_hover.png");

    m_homeWidget = new QMaskedButton(ui->frame);
    m_homeWidget->setPixmap(homeImage);
    m_homeWidget->setClickPixmap(homeClickedImage);
    m_homeWidget->setHoverPixmap(homeHoverImage);
    m_homeWidget->setFixedSize(317, 218);
    connect(m_homeWidget, SIGNAL(clicked(QMaskedButton*)), this, SLOT(homeClickEvent()));

    m_homeWidget->setEnabled(true);
}
