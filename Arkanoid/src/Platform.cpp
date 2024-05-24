#include "Platform.hpp"

bool Platform::Collision(Ball* ball){
    if(checkCollision(ball))
        // небольшая добавка чтобы можно было управлять шариком
        ball->SetDirection(ball->GetDirX() - 0.01*(posX + SIZEPLATFORM/2 - ball->GetX()), ball->GetDirY());
    return false;
}

void Platform::MovePlatform(float dx){
    posX += dx;
    if (posX < -1)
        posX = -1;
    else if(posX + SIZEPLATFORM > 1)
        posX = 1-SIZEPLATFORM;
}