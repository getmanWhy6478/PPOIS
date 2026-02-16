#pragma once

#include <string>
#include <vector>
#include "Review.h"

class Exhibition;
class Review;

class Critic {
private:
    std::string firstName;
    std::string lastName;
    std::string publication;
    std::string specialization;
    std::vector<Review*> reviews;
    std::string credentials;

public:
    Critic() = default;
    Critic(const std::string& firstName, const std::string& lastName,
           const std::string& publication);
    ~Critic() = default;
    
    std::string getFirstName() const;
    void setFirstName(const std::string& firstName);

    std::string getLastName() const;
    void setLastName(const std::string& lastName);

    std::string getFullName() const;

    std::string getPublication() const;
    void setPublication(const std::string& publication);

    std::string getSpecialization() const;
    void setSpecialization(const std::string& specialization);

    void addReview(Review* review);
    std::vector<Review*> getReviews() const;
    
    std::string getCredentials() const;
    void setCredentials(const std::string& credentials);

    Review* writeReview(const std::string& reviewId, Exhibition* exhibition,
                        const std::string& title, const std::string& content,
                        int rating);
};

