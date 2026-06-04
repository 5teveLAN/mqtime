#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_btnHost_clicked()
{
    QString username = ui->txtUsername->text().trimmed();
    if (username.isEmpty()) return;
    emit roleSelected(username, true);
}

void MainWindow::on_btnGuest_clicked()
{
    QString username = ui->txtUsername->text().trimmed();
    if (username.isEmpty()) return;
    emit roleSelected(username, false);
}

void MainWindow::on_btnCreateEvent_clicked()
{
    QString eventName = ui->txtEventName->text().trimmed();
    QStringList dates;
    dates << ui->calendarWidget->selectedDate().toString("yyyy-MM-dd");
    auto parseTime = [](const QString &text) -> QTime {
        QTime t = QTime::fromString(text, "h:mm AP");
        if (!t.isValid())
            t = QTime::fromString(text, "hh:mm AP");
        return t;
    };
    QTime startTime = parseTime(ui->comboStartHour->currentText());
    QTime endTime   = parseTime(ui->comboEndHour->currentText());
    emit createEventSubmitted(eventName, dates, startTime, endTime);
}

void MainWindow::on_btnJoinEvent_clicked()
{
    QString inviteCode = ui->txtInviteCode->text().trimmed();
    if (inviteCode.isEmpty()) return;
    emit joinEventSubmitted(inviteCode);
}

void MainWindow::on_pushButton_clicked()
{
    QStringList timeSlots;
    QTableWidget *table = ui->tableTimeMatrix;
    for (QTableWidgetItem *item : table->selectedItems()) {
        QString col = table->horizontalHeaderItem(item->column())
        ? table->horizontalHeaderItem(item->column())->text()
        : QString::number(item->column());
        QString row = table->verticalHeaderItem(item->row())
                          ? table->verticalHeaderItem(item->row())->text()
                          : QString::number(item->row());
        timeSlots << col + "_" + row;
    }
    emit timeSelectionChanged(timeSlots);
}