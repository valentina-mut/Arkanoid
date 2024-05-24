#pragma once
#include "const.hpp"
#include "stb_easy_font.h"

void print_string(float dx, float x, float y, char *text, float r, float g, float b)
{
    glScalef(dx, -dx, 1);
    static char buffer[99999]; // ~500 chars
    int num_quads;

    num_quads = stb_easy_font_print(x, y, text, NULL, buffer, sizeof(buffer));

    glColor3f(r,g,b);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 16, buffer);
    glDrawArrays(GL_QUADS, 0, num_quads*4);
    glDisableClientState(GL_VERTEX_ARRAY);
    glScalef(1 / dx, 1 / -dx, 1);
}

void RenderScore(int score){
    char text[10];
    snprintf(text, sizeof(text), "%d", score);
    print_string(0.01f, -85.0f, 85.0f, text, 0.95f, 0.95f, 0.95f);
}

