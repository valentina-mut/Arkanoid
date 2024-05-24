#include "Bonus.hpp"

Bonus::Bonus(float x, float y) {
    this->x = x + 1.0f / GRID_SIZE;
    this->y = y + 1.0f / GRID_SIZE;
}

void Bonus::move() {
    this->y -= SPEEDBONUS;
}

void Bonus::render(){
    const int num_segments = 8;
    glColor3f(0.75f, 0.75f, 0.75f);
    glLineWidth(1.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.14f * float(i) / num_segments;
        glVertex2f(x + BONUSRADIUS * cos(theta), y + BONUSRADIUS * sin(theta));
    }
    glEnd();
}

float Bonus::GetX(){
    return x;
}
float Bonus::GetY(){
    return y;
}


AddBall::AddBall(float x, float y) : Bonus(x, y) {}

void AddBall::useBonus(std::vector<Ball*>& Balls) {
    Balls.push_back(new Ball());
}


SpeedUp::SpeedUp(float x, float y) : Bonus(x, y) {}

void SpeedUp::useBonus(std::vector<Ball*>& balls) {
    for (auto& ball : balls) {
        ball->SpeedUp();
    }
}

Bottom::Bottom(float x, float y) : Bonus(x, y) {}

void Bottom::useBonus(std::vector<Ball*>& balls) {
    balls[0]->SetBonusBottom();
}