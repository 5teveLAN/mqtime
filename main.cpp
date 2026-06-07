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

    event.addTimeSlot("6/10 09:00");
    event.addTimeSlot("6/10 14:00");
    event.addTimeSlot("6/11 09:00");

    event.vote("Amy", "6/10 09:00");
    event.vote("Bob", "6/10 09:00");
    event.vote("Claire", "6/11 09:00");

    qDebug() << "活動名稱:" << event.getTitle();
    qDebug() << "建立者:" << event.getCreator();
    qDebug() << "最佳時段:" << event.getBestTime();

    return 0;
}