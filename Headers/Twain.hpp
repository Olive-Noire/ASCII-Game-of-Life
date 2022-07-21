#ifndef DEF_TWAIN_HPP
#define DEF_TWAIN_HPP

#include <iostream>

template<typename Type> class Twain {

    public:

    constexpr Twain(const Type &a = Type{}, const Type &b = Type{}) : first{a}, second{b} {}

    Twain(const Twain&) = default;
    Twain(Twain&&) = default;

    ~Twain() = default;

    void Clear() { *this = Twain<Type>{}; }

    friend bool operator==(const Twain &l, const Twain &r) { return l[0] == r[0] && l[1] == r[1]; }
    friend bool operator!=(const Twain &l, const Twain &r) { return !(l == r); }

    Type& operator[](bool index) {

        if (index == 0) {

            return first;

        } else {

            return second;

        }

    }

    constexpr Type operator[](bool index) const {
        
        if (index == 0) {

            return first;

        } else {

            return second;

        }

    }

    Twain& operator=(const Twain&) = default;
    Twain& operator=(Twain&&) = default;

    friend std::ostream& operator<<(std::ostream &flux, const Twain &t) {
        
        return flux << "(" << t[0] << ", " << t[1] << ")";
        
    }

    Type first, second;

};

#endif // DEF_TWAIN_HPP