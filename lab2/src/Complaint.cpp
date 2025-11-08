#include "../include/Complaint.h"

string Complaint::getBadWords() const{
    return badWords;
}

void Complaint::setBadWords(string words) {
    this->badWords = words;
}