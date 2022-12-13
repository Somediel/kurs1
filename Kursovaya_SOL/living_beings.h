#pragma once
#include "object.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class living_beings : public object
{
public:

    int left = 0, right = 0, up = 0, down = 0;
    living_beings();
    std::string name; 
    bool gender; 

    void message()
    {
        //"Назовите своего персонажа";
    };

    int relationship;
    void SetRelationshipStatusBar(int scale_rs);
    int GetRelationshipStatusBar();
    
    int fullness;
    void SetFullness(int full);
    int GetFullness();

    int energy;
    void SetEnergy(int energy_sleep);
    int GetEnergy();

    int need;
    void SetNeed(int needness);
    int GetNeed();

    int hygiene;
    void SetHygiene(int hyg);
    int GetHygiene();

    int playful;
    void SetPlayful(int playfullness);
    int GetPlayful();


    void Moving(RenderWindow& window, Sprite flat, Sprite display);
};

