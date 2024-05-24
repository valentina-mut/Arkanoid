#include "Ball.hpp"

int Ball::bonusBottom = 0;

Ball::Ball() {
    posX = 0.0f;
    posY = -0.5f;
    dirX = 0;
    dirY = -SPEEDBALL;
    numSpeedUp = 0;
}

void Ball::render(){
    const int num_segments = 8;
    glColor3f(1.0f, 1.0f, 1.0f); 
    glLineWidth(1.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * PI * float(i) / float(num_segments);
        glVertex2f(posX + BALLRADIUS * cos(theta), posY + BALLRADIUS * sin(theta));
    }
    glEnd();
}

void Ball::move(){
    if (numSpeedUp>0){
        posX += dirX*1.25f;
        posY += dirY*1.25f;
        --numSpeedUp;
    }else{
        posX += dirX;
        posY += dirY;
    }
    if (posY <=-1.0f-SPEEDBALL*1.2 && bonusBottom >0){
        --bonusBottom;
        dirY = -dirY;
        move();
    }
}

void Ball::SpeedUp(){
    numSpeedUp = 1000;
}

float Ball::GetX(){
    return posX;
}
float Ball::GetY(){
    return posY;
}

float Ball::GetDirX() const { return dirX; }
float Ball::GetDirY() const { return dirY; }

void Ball::SetDirection(float newDirX, float newDirY) { 
    float normDir = SPEEDBALL/std::sqrt(newDirX*newDirX + newDirY*newDirY);
    dirX = newDirX * normDir; 
    dirY = newDirY * normDir; 
}
void Ball::SetBonusBottom(){
    ++bonusBottom;
}