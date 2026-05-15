#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MqttHandler.h"
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
private slots:
    // This is the function that will run when the signal is caught
    void onMqttConnected();
    void on_btnMqttConnect_clicked();
};
#endif // MAINWINDOW_H
