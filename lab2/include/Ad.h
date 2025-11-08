#pragma once
#include <string>
using namespace std;

class Ad{
public:
    Ad(const string& title, const string& text, bool isActive);

    string getTitle() const;
    string getText() const;
    bool getIsActive() const;

    void setTitle(const string& title);
    void setText(const string& text);
    void setIsActive();
private:
    string title;
    string text;
    bool isActive;
};
