#include "../include/Review.h"
#include "../include/Critic.h"
#include "../include/Exhibition.h"

Review::Review(const std::string& reviewId, Critic* critic,
               Exhibition* exhibition)
    : reviewId(reviewId), critic(critic), exhibition(exhibition),
      rating(0), viewCount(0) {
}

std::string Review::getReviewId() const {
    return reviewId;
}

void Review::setReviewId(const std::string& id) {
    this->reviewId = id;
}

Critic* Review::getCritic() const {
    return critic;
}

void Review::setCritic(Critic* critic) {
    this->critic = critic;
}

Exhibition* Review::getExhibition() const {
    return exhibition;
}

void Review::setExhibition(Exhibition* exhibition) {
    this->exhibition = exhibition;
}

std::string Review::getTitle() const {
    return title;
}

void Review::setTitle(const std::string& title) {
    this->title = title;
}

std::string Review::getContent() const {
    return content;
}

void Review::setContent(const std::string& content) {
    this->content = content;
}

int Review::getRating() const {
    return rating;
}

void Review::setRating(int rating) {
    this->rating = rating;
}
std::string Review::getPublication() const {
    return publication;
}

void Review::setPublication(const std::string& publication) {
    this->publication = publication;
}

int Review::getViewCount() const {
    return viewCount;
}

void Review::incrementViewCount() {
    viewCount++;
}


