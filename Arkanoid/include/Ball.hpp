#pragma once
#include "const.hpp"

class Ball {
public:
    Ball();
    void render();
    void move();
    void SpeedUp();
    float GetX();
    float GetY();
    float GetDirX() const;
    float GetDirY() const;
    void SetDirection(float newDirX, float newDirY);
    void SetBonusBottom();
private:
    static int bonusBottom;
    int numSpeedUp;
    float posX;
    float posY;
    float dirX; 
    float dirY;
};