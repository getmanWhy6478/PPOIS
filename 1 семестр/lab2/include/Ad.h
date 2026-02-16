#pragma once
#include <string>
using namespace std;

class Ad{
public:
    Ad();
    Ad(const string& title, const string& text, bool isActive);

    string getTitle() const;
    void setTitle(const string& title);

    string getText() const;
    void setText(const string& text);

    bool getIsActive() const;
    void setIsActive();
    
private:
    string title;
    string text;
    bool isActive;
};
