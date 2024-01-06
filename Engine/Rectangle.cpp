#include "Rectangle.h"

MyRectangle::MyRectangle(Graphics& gfx, MainWindow& wnd) : gf(gfx), wnd(wnd)
{
    
}

void MyRectangle::DrawRectangle(int xp, int yp, int w, int h, int r, int g, int b)
{
    // Here I can change values of the rectangle like position and size.
    if(!IsInitialized)
    {
        xPos = xp;
        yPos = yp;
        width = w;
        height = h;
        IsInitialized = true;
    }
        if(wnd.kbd.KeyIsPressed('W'))
        {
            height--;
        }
        if(wnd.kbd.KeyIsPressed('A'))
        {
            width--;
        }
        if(wnd.kbd.KeyIsPressed('S'))
        {
            height++;
        }
        if(wnd.kbd.KeyIsPressed('D'))
        {
            width++;
        }
    
        if(wnd.kbd.KeyIsPressed(VK_UP))
        {
            yPos--;
        }
        if(wnd.kbd.KeyIsPressed(VK_DOWN))
        {
            yPos++;
        }
        if(wnd.kbd.KeyIsPressed(VK_LEFT))
        {
            xPos--;
        }
        if(wnd.kbd.KeyIsPressed(VK_RIGHT))
        {
            xPos++;
        }
    // Add collision check.

    ClampPosition(xPos, yPos, width, height);
    
    for(int x = xPos; x <xPos + width; ++x )
    {
        for(int y = yPos; y <yPos + height; ++y)
        {
            gf.PutPixel(x, y, r, g, b);
        }
    }
    
    // finish writing the function for drawing and then go to the next video
    
}

void MyRectangle::ClampPosition(int x, int y, int r_width, int r_height)
{
    if(x < 0)
    {
        xPos = 0;
    }
    if(x + r_width >= gf.ScreenWidth)
    {
        width = r_width - 1;
    }
    
    if(y <= 0)
    {
        yPos = 0;
    }
    if(y + r_height >= gf.ScreenHeight)
    {
        height = r_height - 1;
    }
}


// & is being used when creating objects to avoid error about deleted constructor holy fuck I think I get it
//To be more clear, & makes a reference which is used later on void by passed object into constructor.