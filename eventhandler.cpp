#include "eventhandler.h"

EventHandler::EventHandler(QObject *parent)
    : QObject{parent}
{
    m_event = new Event();
}


