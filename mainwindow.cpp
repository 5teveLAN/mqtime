#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateConnectionStatusUi()
{
    ui->statusLabel->setText("Connected to Broker");
    ui->statusLabel->setStyleSheet("color: green;");

    // Perhaps enable the button to create a session
    //ui->createEventButton->setEnabled(true);
}
void MainWindow::updateSubscriptionStatusUi(const QString &topic)
{
    ui->statusLabel->setText(ui->statusLabel->text() + "\nSubscribed: " + topic);
    ui->statusLabel->setStyleSheet("color: green;");

    // Perhaps enable the button to create a session
    //ui->createEventButton->setEnabled(true);
}
void MainWindow::on_btnMqttConnect_clicked()
{
    emit connectionRequested();
}

void MainWindow::on_btnHost_clicked()
{
    bool isHost = 1;
    roleSelected(isHost);
}

void MainWindow::on_btnGuest_clicked()
{
    bool isHost = 0;
    roleSelected(isHost);
}

void MainWindow::on_btnMqttSubscribe_clicked() {}
