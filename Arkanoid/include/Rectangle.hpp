#pragma once
#include "const.hpp"
#include "Ball.hpp"

class Rectangle {
protected:
    float posX, posY; // Координаты верхнего левого угла
    float width, height;   // Ширина и высота
    int hp;
    bool checkCollision(Ball* ball);
public:
    Rectangle(float x, float y, float width, float height) : posX(x), posY(y), width(width), height(height) {}

    void render();

    float getX() const { return posX; }
    float getY() const { return posY; }
    float getWidth() const { return width; }
    float getHeight() const { return height; }
    virtual bool Collision(Ball* ball) = 0;
};

class Square : public Rectangle {
protected:
public:
    Square(float x, float y, int hp) : Rectangle(x, y, 2.0f/GRID_SIZE,  2.0f/GRID_SIZE) { 
        this->hp = hp;
    }
    bool Collision(Ball* ball);
};

class Indestructible : public Rectangle {
protected:
public:
    Indestructible(float x, float y, float width, float height) : Rectangle(x, y, width,  height) { 
        this->hp = 0;
    }
    bool Collision(Ball* ball);
};

