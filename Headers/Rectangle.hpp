#ifndef DEF_RECTANGLE_HPP
#define DEF_RECTANGLE_HPP

#include "./Memory.hpp"
#include "./Twain.hpp"

class Rectangle {

    public:

    Rectangle(const Twain<uint8>& = Twain<uint8>{}, const Twain<uint8>& = Twain<uint8>{});

    Rectangle(const Rectangle&) = default;
    Rectangle(Rectangle&&) = default;

    ~Rectangle() = default;

    Rectangle& operator=(const Rectangle&) = default;
    Rectangle& operator=(Rectangle&&) = default;

    friend bool operator==(const Rectangle&, const Rectangle&);
    friend bool operator!=(const Rectangle&, const Rectangle&);

    Twain<uint8> position, size;

};

#endif // DEF_RECTANGLE_HPP