#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>
#pragma once

extern int score;

const float PI = 3.14159265359f;
const int WIDTH = 600;
const int HEIGHT = 600;
const int GRID_SIZE = 51; 

const float SPEEDBALL = 0.01f;
const float BALLRADIUS = 0.015f;


const float SIZEPLATFORM = 10*2.0f/GRID_SIZE;
const float SPEEDPLATFORM = SIZEPLATFORM / 10;

const float BONUSRADIUS = 0.015f;
const float SPEEDBONUS = 0.01f;

// Цвета квадратов
const float COLORS[4][3]= {
    {1.0f, 1.0f, 1.0f}, // белый
    {1.0f, 0.0f, 0.0f}, // красный
    {0.0f, 1.0f, 0.0f}, // зеленый
    {0.0f, 0.0f, 1.0f}, // синий
};