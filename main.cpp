#include <QApplication>
#include <QDebug>
#include "event.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Event event;

    event.setTitle("專題會議");
    event.setCreator("Amy");

    event.addParticipant("Amy");
    event.addParticipant("Bob");
    event.addParticipant("Claire");

    event.addTimeSlot("2026-06-10 09:00");
    event.addTimeSlot("2026-06-11 09:00");

    event.vote("Amy",   "2026-06-10 09:00");
    event.vote("Bob",   "2026-06-10 09:00");
    event.vote("Claire","2026-06-11 09:00");
    event.vote("Amy",   "2026-06-11 09:00");

    qDebug() << "活動名稱:" << event.getTitle();
    qDebug() << "建立者:" << event.getCreator();
    qDebug() << "最佳時段:" << event.getBestTimes();
    return 0;
}