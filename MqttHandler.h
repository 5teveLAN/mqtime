#ifndef MQTTHANDLER_H
#define MQTTHANDLER_H

#include <QObject>
#include <QString>
#include <QtMqtt/QMqttClient>

class MqttHandler : public QObject
{
    Q_OBJECT

private:
    QString m_brokerAddress;
    quint16 m_brokerPort;
    QString m_clientId;
    QString m_username;
    QString m_password;
    QMqttClient *m_client;

public:
    explicit MqttHandler(QObject *parent = nullptr);

    // Setters for UI and Configuration updates
    void setBrokerAddress(const QString &address);
    void setBrokerPort(quint16 port);
    void setClientCredentials(const QString &user, const QString &pass);
    void setClientId(const QString &id);

    // Getter for UI
    QString getBrokerAddress() const;
    quint16 getBrokerPort() const;

    void connectToBroker();
    void subscribeToTopic(const QString &topic);
    void publishMessage(const QString &topic, const QString &message);

signals:
    void mqttMessageReceived(const QString &topic, const QString &message);
    void mqttConnectionEstablished();
    void mqttErrorOccurred(const QString &error);
    void mqttSettingsChanged(); // Notify UI that values were updated

private slots:
    //void handleMessage(const QByteArray &message, const QMqttTopicName &topic);
};

#endif // MQTTHANDLER_H