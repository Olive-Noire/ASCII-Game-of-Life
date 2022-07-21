#ifndef DEF_CASE_HPP
#define DEF_CASE_HPP

#include "./Memory.hpp"
#include "./Twain.hpp"

class Case {

    public:

    Case(const Twain<uint8>& = Twain<uint8>{});

    ~Case() = default;

    Case& operator=(const Case&) = default;
    Case& operator=(Case&&) = default;

    friend bool operator==(const Case&, const Case&);
    friend bool operator!=(const Case&, const Case&);

    Twain<uint8> position;

};

#endif // DEF_CASE_HPP