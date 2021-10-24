#pragma once

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

    Color black()
    {
        return Color(0, 0, 0, 255);
    }

    float r, g, b, o;
};