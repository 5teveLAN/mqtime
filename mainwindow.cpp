#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Initialize the object. 'this' sets MainWindow as the parent for memory management.
    m_mqttHandler = new MqttHandler(this);
    connect(m_mqttHandler,
            &MqttHandler::mqttConnectionEstablished,
            this,
            &MainWindow::on_mqttConnected);
    connect(m_mqttHandler,
            &MqttHandler::mqttTopicSubscribed,
            this,
            &MainWindow::on_mqttTopicSubscribed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_mqttConnected()
{
    ui->statusLabel->setText("Connected to Broker");
    ui->statusLabel->setStyleSheet("color: green;");
    m_mqttHandler->subscribeToTopic();

    // Perhaps enable the button to create a session
    //ui->createEventButton->setEnabled(true);
}
void MainWindow::on_mqttTopicSubscribed(const QString &topic)
{
    ui->statusLabel->setText(ui->statusLabel->text() + "\nSubscribed: " + topic);
    ui->statusLabel->setStyleSheet("color: green;");

    // Perhaps enable the button to create a session
    //ui->createEventButton->setEnabled(true);
}
void MainWindow::on_btnMqttConnect_clicked()
{
    m_mqttHandler->connectToBroker();
}
