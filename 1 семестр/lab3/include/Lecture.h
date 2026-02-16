#pragma once

#include "Event.h"
#include <string>

class Lecture : public Event {
private:
    std::string speakerName;
    std::string topic;
    bool requiresRegistration;

public:
    Lecture() = default;
    Lecture(const std::string& eventId, const std::string& title,
            Gallery* gallery, const std::string& speakerName);
    ~Lecture() = default;
    
    std::string getSpeakerName() const;
    void setSpeakerName(const std::string& name);
    std::string getTopic() const;
    void setTopic(const std::string& topic);
    bool getRequiresRegistration() const;
    void setRequiresRegistration(bool requires);
};

