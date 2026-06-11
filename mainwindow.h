#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QTime>
#include <event.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Ui::MainWindow *ui;
    Event *m_event;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void test(MainWindow *window);
signals:
    // Page 1
    void roleSelected(QString username, bool isHost);

    // Page 2 (Host)
    void createEventSubmitted(QString eventName, QStringList dates, QTime startTime, QTime endTime);

    // Page 2 (Guest)
    void joinEventSubmitted(QString inviteCode);

    // Page 3
    void timeSelectionChanged(QStringList timeSlots);

public slots:
    // Page 1
    void onRoleSetupSuccessed(bool isHost);

    // Page 2 (Host)
    void onEventCreationSuccessed(QString inviteCode, Event *event);

    // Page 2 (Guest)
    void onEventJoinSuccessed(Event *event);
    void onEventJoinFailed();

    // Page 3
    void onEventMatrixUpdated();

};
#endif // MAINWINDOW_H
