#pragma once
#include "MainWindow.h"

class MyRectangle
{
    Graphics& gf;
    MainWindow& wnd;
    int xPos;
    int yPos;
    int width;
    int height;
    bool IsInitialized = false;
public:
// Lil' update. I've done it. Now I just need to understand how everything works (P.S. I think I get it)    
    MyRectangle(Graphics& gfx, MainWindow& wnd);
    void DrawRectangle(int x, int y, int w, int h, int r, int g, int b);
    void ClampPosition(int x, int y, int r_width, int r_height);
};
