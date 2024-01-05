#include "Rectangle.h"

MyRectangle::MyRectangle(Graphics& gfx) : gf(gfx)
{
   
}

void MyRectangle::DrawRectangle(int xp, int yp, int w, int h, int r, int g, int b)
{
    for(int x = xp; x <xp + w; ++x )
    {
        for(int y = yp; y <yp + h; ++y)
        {
            gf.PutPixel(x, y, r, g, b);
        }
    }
    
}

void MyRectangle::Test(int x, int y)
{
    //look. In the video variables for loops are created each time the program goes into its scope. In my case I just
    // constantly change the very same variable.
    // Figure out how you made it work and came up with the solution for drawing rectangle properly.
    int tempx = x;
    int tempy = y;
    for(int y = tempy; y < 400; ++y)
    {
        for(x; x < 350; ++x)
        {
            gf.PutPixel(x, y, 255, 255, 255);
        }
        
        
    }// the issue is that x doesn't reset the value (kinda solved)
}

// & is being used when creating objects to avoid error about deleted constructor holy fuck I think I get it
