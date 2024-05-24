#include "Rectangle.hpp"

void Rectangle::render() {

    glColor3f(COLORS[hp][0], COLORS[hp][1], COLORS[hp][2]);
    glBegin(GL_QUADS);
    glVertex2f(posX, posY);
    glVertex2f(posX+width, posY);
    glVertex2f(posX+width, posY-height);
    glVertex2f(posX, posY-height);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); 
    glLineWidth(0.1f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(posX, posY);
    glVertex2f(posX+width, posY);
    glVertex2f(posX+width, posY-height);
    glVertex2f(posX, posY-height);
    glEnd();

}

bool Square::Collision(Ball* ball){
    if (checkCollision(ball)){
        hp --;
        ++score;
        if (hp == 0)
            return true;
    }
    return false;
}

bool Indestructible::Collision(Ball* ball){
    checkCollision(ball);
    return false;
}

bool Rectangle::checkCollision(Ball* ball) {
    // Нахождение перекрытия
    float overlapLeft = posX - ball->GetX();
    float overlapRight = (posX + width) - ball->GetX();
    float overlapTop = posY - ball->GetY();
    float overlapBottom = (posY - height) - ball->GetY();

    // Проверка коллизии
    bool collision = overlapLeft <= BALLRADIUS && overlapRight >= BALLRADIUS && 
    overlapBottom <= BALLRADIUS && overlapTop >= BALLRADIUS;

    if (collision) {
        // Определение стороны столкновения
        bool ballFromLeft = overlapLeft < overlapRight;
        bool ballFromTop = overlapTop < overlapBottom;

        float minOverlapX = std::min(overlapLeft, overlapRight);
        float minOverlapY = std::min(overlapTop, overlapBottom);

        // Изменение направления в зависимости от стороны столкновения
        if (minOverlapX > minOverlapY) {
            ball->SetDirection(-ball->GetDirX(), ball->GetDirY());
        } else {
            ball->SetDirection(ball->GetDirX(), -ball->GetDirY());
        }
    }

    return collision;
}

