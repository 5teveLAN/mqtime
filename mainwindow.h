#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mqtthandler.h"
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

private:
    Ui::MainWindow *ui;
    MqttHandler *m_mqttHandler;
signals:
    void connectionRequested();
    void roleSelected(bool isHost);
public slots:
    // This is the function that will run when the signal is caught
    void updateConnectionStatusUi();
    void updateSubscriptionStatusUi(const QString &topic);
private slots:
    void on_btnMqttConnect_clicked();
    void on_btnHost_clicked();
    void on_btnMqttSubscribe_clicked();
    void on_btnGuest_clicked();
};
#endif // MAINWINDOW_H
