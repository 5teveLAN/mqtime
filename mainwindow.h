#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
signals:
    // Setting Page
    void mqttConfigSubmitted(const QString &host, int port);

    // Page 1
    void roleSelected(const QString &username, bool isHost);

    // Page 2 (Host)
    void createEventSubmitted(const QString &eventName, const QStringList &dates, const QTime &startTime, const QTime &endTime);

    // Page 2 (Guest)
    void joinEventSubmitted(const QString &inviteCode);

    // Page 3
    void timeSelectionChanged(const QStringList &timeSlots);

private:
    Ui::MainWindow *ui;
signals:
    void connectionRequested();
    void roleSelected(bool isHost);

};
#endif // MAINWINDOW_H
