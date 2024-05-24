#include "Game.hpp"
Game::Game() {
    // границы
    SquareV.push_back(new Indestructible(-1, 1, 2.0f, 2.0f/GRID_SIZE));
    SquareV.push_back(new Indestructible(-1, 1, 2.0f/GRID_SIZE, 2.0f));
    SquareV.push_back(new Indestructible(1-2.0f/GRID_SIZE, 1, 2.0f/GRID_SIZE, 2.0f));

    // заполнение разрушающимеся блоками
    for (float i = 1.0f; i < GRID_SIZE/2-1; i++) {
        for (float j = 2.0f; j < GRID_SIZE; j++) {
            int hp = 1 + rand() % 3;
            float posY = 1.0f - 2.0f * i / GRID_SIZE;
            float posX = 1.0f - 2.0f * j / GRID_SIZE;
            SquareV.push_back(new Square(posX, posY, hp));
        }
    }
    balls.push_back(new Ball);
    platform = new Platform;
}

void Game::newIterationGame(){
    renderGrid();
    for (auto& ball : balls)
        ball->render();

    for (auto& bonus : bonuses) 
        bonus->render();

    platform->render();

    checkCollisionBall();
    checkCollisionBonus();

    for (auto& ball : balls)
        ball->move();

    for (auto& bonus : bonuses) 
        bonus->move();

    for (auto ball = balls.begin(); ball != balls.end();) {
        if ((*ball)->GetY()<=-1.0f-SPEEDBALL*1.2) {
            delete *ball;
            ball = balls.erase(ball); 
        } else {
            ++ball;
        }
    }
}

bool Game::ballsSize(){
    if(balls.size()!=0)
        return false;
    return true;
}

void Game::renderGrid(){
    for (auto it = SquareV.begin(); it != SquareV.end(); ++it) {
        (*it)->render();
    }
}
void Game::checkCollisionBall(){
    for (auto& ball : balls) {
        for (auto it = SquareV.begin(); it != SquareV.end();) {
            if ((*it)->Collision(ball)) {
                int randBonus = rand()%10;
                if(randBonus == 0){
                    bonuses.push_back(new AddBall((*it)->getX(),(*it)->getY()));
                }else if(randBonus == 1){
                    bonuses.push_back(new SpeedUp((*it)->getX(),(*it)->getY()));
                }else if(randBonus == 2){
                    bonuses.push_back(new Bottom((*it)->getX(),(*it)->getY()));
                }
                delete *it;
                it = SquareV.erase(it); 
            } else {
                ++it;
            }
        }
        platform->Collision(ball);
    }
    for (int i = 0; i < balls.size(); ++i) {
        for (int j = i + 1; j < balls.size(); ++j) {
            if( std::sqrt(pow(balls[i]->GetX()-balls[j]->GetX(), 2) + 
                pow(balls[i]->GetY()-balls[j]->GetY(), 2)) <= 2.0f*BALLRADIUS){
                balls[i]->SetDirection(-balls[i]->GetDirX(), -balls[i]->GetDirY());
                balls[j]->SetDirection(-balls[j]->GetDirX(), -balls[j]->GetDirY());
                balls[i]->move();
                balls[j]->move();
            }
        }
    }
}
void Game::MovePlatform(float dx){
    platform->MovePlatform(dx);
}
void Game::checkCollisionBonus(){
    for (auto bonus = bonuses.begin(); bonus != bonuses.end();) {

        float overlapLeft = platform->getX() - (*bonus)->GetX();
        float overlapRight = (platform->getX() + SIZEPLATFORM) - (*bonus)->GetX();
        float overlapTop = -1 + 2.0f/GRID_SIZE- (*bonus)->GetY();
        float overlapBottom = -1 - (*bonus)->GetY();
        // Проверка коллизии
        bool collision = overlapLeft <= BONUSRADIUS && overlapRight >= BONUSRADIUS && 
                        overlapBottom <= BONUSRADIUS && overlapTop >= BONUSRADIUS;
        if(collision){
            (*bonus)->useBonus(balls);
            delete *bonus;
            bonus = bonuses.erase(bonus); 
        }else {
            ++bonus;
        }

    }
}

Game::~Game() {
    for (auto& ball : balls) {
        delete ball;
    }
    for (auto& square : SquareV) {
        delete square;
    }
        for (auto& bonus : bonuses) {
        delete bonus;
    }
    delete platform;
}
