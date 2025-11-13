#include "../include/Complaint.h"
Complaint::Complaint()
    : badWords("") {}
Complaint::Complaint(string badWords)
    : badWords(badWords) {}
string Complaint::getBadWords() const{
    return badWords;
}

void Complaint::setBadWords(string words) {
    this->badWords = words;
}