#include "../include/Critic.h"
#include "../include/Review.h"
#include <ctime>

Critic::Critic(const std::string& firstName, const std::string& lastName,
               const std::string& publication)
    : firstName(firstName), lastName(lastName), publication(publication) {
}

std::string Critic::getFirstName() const {
    return firstName;
}

void Critic::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

std::string Critic::getLastName() const {
    return lastName;
}

void Critic::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

std::string Critic::getFullName() const {
    return firstName + " " + lastName;
}

std::string Critic::getPublication() const {
    return publication;
}

void Critic::setPublication(const std::string& publication) {
    this->publication = publication;
}

std::string Critic::getSpecialization() const {
    return specialization;
}

void Critic::setSpecialization(const std::string& specialization) {
    this->specialization = specialization;
}

void Critic::addReview(Review* review) {
    reviews.push_back(review);
}

std::vector<Review*> Critic::getReviews() const {
    return reviews;
}
std::string Critic::getCredentials() const {
    return credentials;
}

void Critic::setCredentials(const std::string& credentials) {
    this->credentials = credentials;
}

Review* Critic::writeReview(const std::string& reviewId, Exhibition* exhibition,
                            const std::string& title, const std::string& content,
                            int rating) {
    if (!exhibition || reviewId.empty() || content.empty() ||
        rating < 1 || rating > 10) {
        return nullptr;
    }

    Review* review = new Review(reviewId, this, exhibition);
    review->setTitle(title);
    review->setContent(content);
    review->setRating(rating);
    review->setPublication(publication);

    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    reviews.push_back(review);
    return review;
}

