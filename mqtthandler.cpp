#include "mqtthandler.h"
#include <QDebug>
#include <QUuid>

MqttHandler::MqttHandler(QObject *parent)
    : QObject(parent)                      //Must add: QObject constructor
    , m_brokerAddress("broker.hivemq.com") // Default initial value
    , m_brokerPort(1883)                   // Standard MQTT port
    , m_clientId("")
    , m_username("")
    , m_password("")
    , m_topic("test_topic")
{
    m_client = new QMqttClient(this);

    // Sync initial values to the QMqttClient instance
    m_client->setHostname(m_brokerAddress);
    m_client->setPort(m_brokerPort);
    m_clientId = QUuid::createUuid().toString().remove('{').remove('}');
    m_client->setClientId(m_clientId);
    m_client->setUsername(m_username);
    m_client->setPassword(m_password);

    // Connections
    connect(m_client,
            &QMqttClient::connected,
            this,
            &MqttHandler::mqttConnectionEstablished,
            Qt::UniqueConnection);
    connect(m_client, &QMqttClient::messageReceived, this, &MqttHandler::handleMessage);
    connect(m_client, &QMqttClient::errorChanged, this, [this](QMqttClient::ClientError error) {
        emit mqttErrorOccurred(QString("MQTT Error Code: %1").arg(error));
    });
}

void MqttHandler::setBrokerAddress(const QString &address)
{
    if (m_brokerAddress != address) {
        m_brokerAddress = address;
        m_client->setHostname(m_brokerAddress);
        emit mqttSettingsChanged();
    }
}
void MqttHandler::setBrokerPort(quint16 port)
{
    if (m_brokerPort != port) {
        m_brokerPort = port;
        m_client->setPort(m_brokerPort);
        emit mqttSettingsChanged();
    }
}
void MqttHandler::setClientCredentials(const QString &user, const QString &pass)
{
    m_username = user;
    m_password = pass;
    m_client->setUsername(m_username);
    m_client->setPassword(m_password);
    emit mqttSettingsChanged();
}
void MqttHandler::setClientId(const QString &id)
{
    if (m_clientId != id) {
        m_clientId = id;
        m_client->setClientId(m_clientId);
        emit mqttSettingsChanged();
    }
}

void MqttHandler::connectToBroker()
{
    // Check if we are already connected or connecting to avoid redundant calls
    if (m_client->state() != QMqttClient::Disconnected) {
        return;
    }
    m_client->connectToHost();
}

void MqttHandler::subscribeToTopic()
{
    if (m_client->state() != QMqttClient::Connected) {
        // Optional: Log a warning or queue the topic for later
        return;
    }
    // Actual MQTT subscription
    auto subscription = m_client->subscribe(m_topic);
    // if success
    if (subscription) {
        emit mqttTopicSubscribed(m_topic);
    }
}

void MqttHandler::handleMessage(const QByteArray &message, const QMqttTopicName &topic) {}