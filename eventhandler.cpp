#include "eventhandler.h"
#include <QRandomGenerator>

EventHandler::EventHandler(Session *session, QObject *parent)
    : QObject{parent}
    , m_event(new Event())
    , m_session(session)
{
    if (!m_session)
    {
        qWarning() << "[EventHandler] Warning: Initialized with a null Session pointer!";
    }
}

void EventHandler::onCreateEventSubmitted(QString eventName, QStringList dates, QTime startTime, QTime endTime)
{
    // 1. Convert QStringList of dates to QList<QDate>
    QList<QDate> convertedDates;
    QString currentUser = m_session->getCurrentUser();

    // Applied std::as_const here as well to optimize the input list loop
    for (const QString &dateStr : std::as_const(dates)) {
        QDate date = QDate::fromString(dateStr, "yyyy-MM-dd");
        if (date.isValid()) {
            convertedDates.append(date);
        }
    }

    // 2. Populate your m_event object using its setters
    if (!m_event) {
        m_event = new Event();
    }
    m_event->setTitle(eventName);
    m_event->setSelectedDates(convertedDates);
    m_event->setTimeRange(startTime, endTime);
    m_event->setCreator(currentUser);
    m_event->addParticipant(currentUser);
    // 3. Generate hourly TimeSlots for each selected date within the time range
    // FIX: Added std::as_const to prevent list detachment
    for (const QDate &date : std::as_const(convertedDates))
    {
        QTime currentSlotTime = startTime;

        while (currentSlotTime < endTime)
        {
            // FIX: Used multi-arg .arg() override syntax to prevent redundant string allocations
            QString slotString = QString("%1 %2")
                                     .arg(date.toString("yyyy-MM-dd"), currentSlotTime.toString("HH:mm"));

            m_event->addTimeSlot(slotString);
            currentSlotTime = currentSlotTime.addSecs(3600);
        }
    }

    // 4. Generate the invite code and notify the MainWindow
    m_inviteCode = this->generateInviteCode();
    emit eventCreationSuccessed(m_inviteCode, m_event);
}

void EventHandler::onJoinEventSubmitted(QString inviteCode)
{
    m_inviteCode = inviteCode;
    m_event =  this->joinEvent(m_inviteCode);
    if (m_event)
        emit eventJoinSuccessed(m_event);
    else
        emit eventJoinFailed();
}

void EventHandler::onTimeSelectionChanged(QStringList timeSlots)
{
    // 1. Ensure we have a valid event instance to modify
    if (!m_event)
    {
        qWarning() << "[EventHandler] Cannot update time selection: m_event is null.";
        return;
    }

    QString currentUser = m_session->getCurrentUser();

    for (const QString &slotTime : timeSlots)
    {
        m_event->vote(currentUser, slotTime);
    }

    emit eventMatrixUpdated();
}


QString EventHandler::generateInviteCode()
{
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
    const int codeLength = 5;
    QString inviteCode;

    // Optimization: Pre-allocate memory for 5 characters
    inviteCode.reserve(codeLength);

    for (int i = 0; i < codeLength; ++i) {
        // Generate a secure random index
        quint32 index = QRandomGenerator::global()->bounded(static_cast<quint32>(possibleCharacters.length()));
        inviteCode.append(possibleCharacters.at(index));
    }

    return inviteCode;
}

Event *EventHandler::joinEvent(QString inviteCode)
{
    return m_event;
}

