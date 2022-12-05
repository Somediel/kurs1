#pragma once
#include "object.h"

class living_beings : public object
{
public:

    living_beings();
    std::string name; 
    bool gender; 

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


    /*
    Image boy_proba;
    boy_proba.loadFromFile("images\\Boy_Proba.png");

    Texture boy_texture;
    boy_texture.loadFromImage(boy_proba);

    Sprite boy_sprite;
    boy_sprite.setTexture(boy_texture);
    boy_sprite.setPosition(50,25);
    */
};

