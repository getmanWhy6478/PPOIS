#pragma once

class PlaceRequirement {
public:
    PlaceRequirement();
    PlaceRequirement(int minArea, bool requiresElectricity, bool mustBeAccessible);

    int getMinArea() const;
    void setMinArea(int area);

    bool getRequiresElectricity() const;
    void setRequiresElectricity(bool requiresElectricity);

    bool getMustBeAccessible() const;
    void setMustBeAccessible( bool mustBeAccessible);
    
    bool isSatisfiedBy(int actualArea, bool hasElectricity, bool isAccessible) const;

protected:
    int minArea;
    bool requiresElectricity;
    bool mustBeAccessible;
};
