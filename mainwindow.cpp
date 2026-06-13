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
    QStringList selectedSlots = {"2026-06-15 09:00", "2026-06-15 14:00"};
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

    // 1. Safety check to make sure the event object exists
    if (!m_event)
    {
        qWarning() << "[MainWindow] m_event is null. Cannot update UI matrix.";
        return;
    }

    // 2. Extensively call Event member functions to extract current state
    QString title = m_event->getTitle();
    QString creator = m_event->getCreator();
    QList<QDate> dates = m_event->getSelectedDates();
    QList<TimeSlot> timeslots = m_event->getTimeSlots();
    QList<Participant> participants = m_event->getParticipants();
    QStringList bestTimes = m_event->getBestTimes();

    // 3. Print complete data matrix structure to console for debugging
    qDebug() << "================== UI MATRIX UPDATE ==================";
    qDebug() << "Event Title      :" << title;
    qDebug() << "Event Creator    :" << creator;
    qDebug() << "Total Dates      :" << dates.size();
    qDebug() << "Total Time Slots :" << timeslots.size();
    qDebug() << "Total Attendees  :" << participants.size();

    // 4. Iterate through all optimal time choices using a for loop
    qDebug() << "--- Listing All Best Times Found ---";
    for (int i = 0; i < bestTimes.size(); ++i)
    {
        qDebug() << QString("  Option #%1: %2").arg(i + 1).arg(bestTimes.at(i));
    }
    qDebug() << "======================================================";

    // 5. Example UI layout manipulation blocks
    /*
  ui->titleLabel->setText(title);

  // Clear any existing list items in your UI text container
  ui->bestTimesListWidget->clear();

  // Dynamically feed the best times directly into a UI view list widget
  for (const QString &timeOption : bestTimes)
  {
    ui->bestTimesListWidget->addItem(timeOption);
  }
  */
}