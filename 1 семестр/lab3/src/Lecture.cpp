#include "../include/Lecture.h"
#include "../include/Gallery.h"

Lecture::Lecture(const std::string& eventId, const std::string& title,
                 Gallery* gallery, const std::string& speakerName)
    : Event(eventId, title, gallery), speakerName(speakerName),
      requiresRegistration(false) {
}

std::string Lecture::getSpeakerName() const {
    return speakerName;
}

void Lecture::setSpeakerName(const std::string& name) {
    this->speakerName = name;
}

std::string Lecture::getTopic() const {
    return topic;
}

void Lecture::setTopic(const std::string& topic) {
    this->topic = topic;
}

bool Lecture::getRequiresRegistration() const {
    return requiresRegistration;
}

void Lecture::setRequiresRegistration(bool requires) {
    this->requiresRegistration = requires;
}


