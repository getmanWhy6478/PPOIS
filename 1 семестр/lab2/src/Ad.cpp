#include "../include/Ad.h"
Ad::Ad() 
    : title(""), text(""), isActive(true) {}
Ad::Ad(const string& title, const string& text, bool isActive)
    : title(title), text(text), isActive(isActive) {}

string Ad::getTitle() const {
    return title;
}

string Ad::getText() const {
    return text;
}

bool Ad::getIsActive() const {
    return isActive;
}

void Ad::setTitle(const string& newTitle) {
    title = newTitle;
}

void Ad::setText(const string& newText) {
    text = newText;
}

void Ad::setIsActive() {
    isActive = true;
}
