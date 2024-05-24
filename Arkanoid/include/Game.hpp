#pragma once
#include "const.hpp"
#include "Rectangle.hpp"
#include "Ball.hpp"
#include "Platform.hpp"
#include "Bonus.hpp"

class Game {
public:
    Game();
    void newIterationGame();
    bool ballsSize();
    void MovePlatform(float dx);
    ~Game();
private:
    void renderGrid();
    void checkCollisionBall();
    void checkCollisionBonus();
    std::vector<Rectangle*> SquareV;
    std::vector<Ball*> balls;
    std::vector<Bonus*> bonuses;
    Platform *platform;
};
