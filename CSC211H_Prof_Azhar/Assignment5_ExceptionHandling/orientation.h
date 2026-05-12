#ifndef ORIENTATION_H
#define ORIENTATION_H

enum class Orientation
{
    NORTH,
    EAST,
    SOUTH,
    WEST
};

/// PREFIX ++  ( ++d )
inline Orientation &operator++(Orientation &d)
{
    d = static_cast<Orientation>(
        (static_cast<int>(d) + 1) % 4);
    return d;
}

/// POSTFIX ++ ( d++ )
inline Orientation operator++(Orientation &d, int)
{
    Orientation old = d;
    d = static_cast<Orientation>(
        (static_cast<int>(d) + 1) % 4);
    return old;
}

/// PREFIX --  ( --d )
inline Orientation &operator--(Orientation &d)
{
    d = static_cast<Orientation>(
        (static_cast<int>(d) + 3) % 4);
    return d;
}

/// POSTFIX -- ( d-- )
inline Orientation operator--(Orientation &d, int)
{
    Orientation old = d;
    d = static_cast<Orientation>(
        (static_cast<int>(d) + 3) % 4);
    return old;
}

#endif