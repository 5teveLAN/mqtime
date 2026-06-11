#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTime>

// Standalone test function to simulate user operations by emitting signals
void MainWindow::test(MainWindow *window)
{
    qDebug() << "=== Starting User Simulation Test ===";

    // Simulate Page 1: User selects role as Host
    qDebug() << "[Sim] Emitting roleSelected (Host)...";
    emit window->roleSelected("Alice", true);

    // Simulate Page 2 (Host): Creating an event
    qDebug() << "[Sim] Emitting createEventSubmitted...";
    QStringList eventDates = {"2026-06-15", "2026-06-16"};
    emit window->createEventSubmitted("Project Sync", eventDates, QTime(9, 0), QTime(18, 0));

    // Simulate Page 2 (Guest): Joining an event
    qDebug() << "[Sim] Emitting joinEventSubmitted...";
    emit window->joinEventSubmitted("XYZ789");

    // Simulate Page 3: Time slot selection updates
    qDebug() << "[Sim] Emitting timeSelectionChanged...";
    QStringList selectedSlots = {"09:00", "14:00"};
    emit window->timeSelectionChanged(selectedSlots);

    qDebug() << "=== User Simulation Test Completed ===";
}

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

void MainWindow::onRoleSetupSuccessed(bool isHost)
{
    qDebug() << "[Slot] onRoleSetupSuccessed -> isHost:" << isHost;
}

void MainWindow::onEventCreationSuccessed(QString inviteCode, Event *event)
{
    m_event = event;
    qDebug() << "[Slot] onEventCreationSuccessed -> Invite Code:" << inviteCode;
}

void MainWindow::onEventJoinSuccessed(Event *event)
{
    m_event = event;
    qDebug() << "[Slot] onEventJoinSuccessed -> Event Pointer:" << m_event;
}

void MainWindow::onEventJoinFailed()
{
    qDebug() << "[Slot] onEventJoinFailed invoked.";
}

void MainWindow::onEventMatrixUpdated()
{
    qDebug() << "[Slot] onEventMatrixUpdated -> Event Pointer:" << m_event;
}