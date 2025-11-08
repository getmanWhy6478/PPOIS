#pragma once

class PlaceRequirement {
public:
    PlaceRequirement();
    PlaceRequirement(int minArea, bool requiresElectricity, bool mustBeAccessible);

    int getMinArea() const;
    bool getRequiresElectricity() const;
    bool getMustBeAccessible() const;

    void setMinArea(int area);
    void setRequiresElectricity(bool requiresElectricity);
    void setMustBeAccessible( bool mustBeAccessible);

    bool isSatisfiedBy(int actualArea, bool hasElectricity, bool isAccessible) const;

protected:
    int minArea;
    bool requiresElectricity;
    bool mustBeAccessible;
};
