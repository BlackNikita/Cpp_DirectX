#pragma once

class Dude
{
public:
    int x = 100;
    int y = 100;
    static constexpr int height = 20;
    static constexpr int width = 20;
    void ClampToScreen();
};
