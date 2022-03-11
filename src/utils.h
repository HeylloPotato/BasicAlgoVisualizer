#pragma once

/* 
This file is just for having Vector2 and color data structures
instead of needing multiple variables per

Vector2 = (x, y)
Color = (R, G, B, O)
        Red
            Green
                Blue
                    Opacity
*/

struct Vector2
{
    Vector2()
    :x(0.0f), y(0.0f)
    {}

    Vector2(float x, float y)
    :x(x), y(y)
    {}

    float x, y;
};

struct Color
{   
    Color()
    :r(0.0f), g(0.0f), b(0.0f), o(0.0f)
    {}

    Color(float r, float g, float b, float o)
    :r(r), g(g), b(b), o(o)
    {}

    // Set the color to white
    Color white()
    {
        return Color(255, 255, 255, 255);
    }

    Color red()
    {
        return Color(255, 0, 0, 255);
    }

    float r, g, b, o;
};
