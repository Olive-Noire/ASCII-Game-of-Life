#include "../Headers/Rectangle.hpp"

Rectangle::Rectangle(const Twain<uint8>& pos, const Twain<uint8>& s) : position{pos}, size{s} {}

bool operator==(const Rectangle& left, const Rectangle& right) {

    return left.position == right.position && left.size == right.size;

}

bool operator!=(const Rectangle& left, const Rectangle& right) { return !(left == right); }