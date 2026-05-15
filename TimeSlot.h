#ifndef TIMESLOT_H
#define TIMESLOT_H
#include <string>
#include <vector>

class TimeSlot
{
private:
    std::string time;
    int score;
    std::vector<std::string> voters;

public:
    void addVote(std::string user);
    int getScore();
};

#endif // TIMESLOT_H
