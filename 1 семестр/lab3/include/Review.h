#pragma once

#include <string>
#include "Critic.h"
#include "Exhibition.h"

class Critic;

class Review {
private:
    std::string reviewId;
    Critic* critic;
    Exhibition* exhibition;
    std::string title;
    std::string content;
    int rating; 
    std::string publication;
    int viewCount;

public:
    Review() = default;
    Review(const std::string& reviewId, Critic* critic,
           Exhibition* exhibition);
    ~Review() = default;
    
    std::string getReviewId() const;
    void setReviewId(const std::string& id);
    Critic* getCritic() const;
    void setCritic(Critic* critic);
    Exhibition* getExhibition() const;
    void setExhibition(Exhibition* exhibition);
    std::string getTitle() const;
    void setTitle(const std::string& title);
    std::string getContent() const;
    void setContent(const std::string& content);
    int getRating() const;
    void setRating(int rating);
    std::string getPublication() const;
    void setPublication(const std::string& publication);
    int getViewCount() const;
    void incrementViewCount();
};

