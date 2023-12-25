#include "fish.h"
#include "Graphics.h"
void Fish::Update()
{
    x += xv;
    y += yv;
    const int right = x + width;
    if(x < 0)
    {
        x = 0;
        xv = -xv;
    } else if(right >= Graphics::ScreenWidth)
    {
        x = Graphics::ScreenWidth - 1 - width;
        xv = -xv;
    }
    const int bottom = y + height;
    if(y < 0)
    {
        y = 0;
        yv = -yv;
    } else if(bottom >= Graphics::ScreenHeight)
    {
        y = Graphics::ScreenHeight - 1 - height;
        yv = -yv;
    }
}

void Fish::ProcessConsumption(int dudex, int dudey, int dudewidth, int dudeheight)
{
    const int duderight = dudex + dudewidth;
    const int dudebottom = dudey + dudeheight;
    const int fishright = x + width;
    const int fishbottom = y + height;
    if(duderight >= x &&
        dudebottom >= y &&
        fishright >= dudex &&
        dudebottom >= dudey)
    {
        IsEaten = true;
    }
}

