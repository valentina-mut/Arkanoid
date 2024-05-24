#pragma once
#include "const.hpp"
#include "Rectangle.hpp"


class Platform : public Rectangle {
protected:
public:
    Platform() : Rectangle(-SIZEPLATFORM/2, 1.0f/GRID_SIZE-1, SIZEPLATFORM,  2.0f/GRID_SIZE) { 
        this->hp = 0;
    }
    virtual bool Collision(Ball* ball);
    void MovePlatform(float dx);
};
