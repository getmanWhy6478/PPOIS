#include "../include/Recommendation.h"

Recommendation::Recommendation(std::string text, Visitor* visitor)
    : text(text), author(visitor) {}

std::string Recommendation::getText() const {
    return text;
}

void Recommendation::setText(std::string text) {
    this->text = text;
}

Visitor* Recommendation::getAuthor() const {
    return author;
}

void Recommendation::setAuthor(Visitor* author) {
    this->author = author;
}
