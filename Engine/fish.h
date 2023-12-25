#pragma once

class Fish
{
public:
    void Update();
    void ProcessConsumption(int dudex, int dudey, int dudewidth, int dudeheight);
    int x;
    int y;
    int yv;
    int xv;
    bool IsEaten = false;
    static constexpr int width = 24;
    static constexpr int height = 24;
};
