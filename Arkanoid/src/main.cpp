#include "main.hpp"


Game* game;
GLFWwindow* window;
int score;
static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // Проверка, была ли нажата клавиша A или D или Q.
    if (key == GLFW_KEY_A)
    {
        if (action == GLFW_PRESS || action == GLFW_REPEAT)
        {
            game->MovePlatform(-SPEEDPLATFORM);
        }
    }
    else if (key == GLFW_KEY_D)
    {
        if (action == GLFW_PRESS || action == GLFW_REPEAT)
        {
            game->MovePlatform(SPEEDPLATFORM);
        }
    }else if (key == GLFW_KEY_Q)
    {
        if (action == GLFW_PRESS || action == GLFW_REPEAT)
        {
            // рестарт
            score = 0;
            delete game;
            game = new Game ();
        }
    }
}

int main() {
    game = new Game ();

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(WIDTH, HEIGHT, "game", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keyCallback);

    while (!glfwWindowShouldClose(window)) {

        glClear(GL_COLOR_BUFFER_BIT);

        game->newIterationGame();
        RenderScore(score);
        if(game->ballsSize()){
            // рестарт(закончились мячи)
            score = 0;
            delete game;
            game = new Game ();
        }

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    delete game;
    glfwTerminate();
    return 0;
}
