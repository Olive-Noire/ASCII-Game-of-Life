#include "../Headers/Case.hpp"

Case::Case(const Twain<uint8>& pos) : position{pos} {}

bool operator==(const Case& left, const Case& right) { return left.position == right.position; }
bool operator!=(const Case& left, const Case& right) { return !(left == right); }