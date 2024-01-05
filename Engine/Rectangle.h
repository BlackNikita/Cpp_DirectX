#pragma once
#include "Graphics.h"


class MyRectangle
{
    Graphics& gf;
public:
// Lil' update. I've done it. Now I just need to understand how everything works.    
    MyRectangle( Graphics& gfx);
    void DrawRectangle(int x, int y, int w, int h, int r, int g, int b);
    void Test(int x, int y);
};
