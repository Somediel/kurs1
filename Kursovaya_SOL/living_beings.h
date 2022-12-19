#pragma once
#include "object.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class living_beings : public object
{
public:

    int left = 0, right = 0, up = 0, down = 0;
    living_beings();
    /*std::string name; 
    bool gender; */

    void message()
    {
        //"Назовите своего персонажа";
    };

    
    float fullness;
    void SetFullness(float full);
    float GetFullness();

    float energy;
    void SetEnergy(float energy_sleep);
    float GetEnergy();

    float need;
    void SetNeed(float needness);
    float GetNeed();

    float hygiene;
    void SetHygiene(float hyg);
    float GetHygiene();

    float playful;
    void SetPlayful(float playfullness);
    float GetPlayful();


    void Moving(RenderWindow& window, Sprite flat, Sprite display);
};

