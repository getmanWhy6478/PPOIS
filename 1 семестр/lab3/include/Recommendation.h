#pragma once

#include <string>
#include <vector>
#include "Visitor.h"
class Visitor;
class Recommendation {
private:
    std::string text;
    Visitor* author;

public:
    Recommendation() = default;
    Recommendation(std::string text, Visitor* visitor);
    ~Recommendation() = default;
    
    std::string getText() const;
    void setText(std::string text);
    Visitor* getAuthor() const;
    void setAuthor(Visitor* author);
    
};
