#include "session.h"
#include <QRandomGenerator>
#include "mainwindow.h"

Session::Session(MainWindow *window)
    : m_username("ggd"),
    m_mainWindow(window)
{
    m_eventHandler = new EventHandler(this);
    //m_mqttHandler = new MqttHandler();
    this->initConnections();
}

QString Session::getCurrentUser()
{
    return m_username;
}

void Session::initConnections()
{
    // ==========================================
    // Page 1: Identity Setup
    // ==========================================
    connect(
        m_mainWindow, &MainWindow::roleSelected,
        this, &Session::onRoleSelected
        );

    connect(
        this, &Session::roleSetupSuccessed,
        m_mainWindow, &MainWindow::onRoleSetupSuccessed
        );


    // ==========================================
    // Page 2 (Host): Create Event
    // ==========================================
    connect(
        m_mainWindow, &MainWindow::createEventSubmitted,
        m_eventHandler, &EventHandler::onCreateEventSubmitted
        );

    connect(
        m_eventHandler, &EventHandler::eventCreationSuccessed,
        m_mainWindow, &MainWindow::onEventCreationSuccessed
        );


    // ==========================================
    // Page 2 (Guest): Join Event
    // ==========================================
    connect(
        m_mainWindow, &MainWindow::joinEventSubmitted,
        m_eventHandler, &EventHandler::onJoinEventSubmitted
        );

    connect(
        m_eventHandler, &EventHandler::eventJoinSuccessed,
        m_mainWindow, &MainWindow::onEventJoinSuccessed
        );


    // ==========================================
    // Page 3: Time Matrix Grid
    // ==========================================
    connect(
        m_mainWindow, &MainWindow::timeSelectionChanged,
        m_eventHandler, &EventHandler::onTimeSelectionChanged
        );

    connect(
        m_eventHandler, &EventHandler::eventMatrixUpdated,
        m_mainWindow, &MainWindow::onEventMatrixUpdated
        );
}


void Session::onRoleSelected(QString username, bool isHost)
{
    m_username = username;
    m_isHost = isHost;
    emit roleSetupSuccessed(isHost);
}


void Session::setRole(bool isHost)
{
    m_isHost = isHost;
}