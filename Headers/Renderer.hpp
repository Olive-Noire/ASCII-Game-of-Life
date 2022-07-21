#ifndef DEF_RENDERER_HPP
#define DEF_RENDERER_HPP

#include "./Rectangle.hpp"
#include "./Memory.hpp"
#include "./Twain.hpp"
#include "./Case.hpp"

#define WIDTH 32
#define HEIGHT 32

class Renderer {

    public:

    Renderer() = default;

    ~Renderer() = default;

    void Clear();

    Renderer& operator=(const Renderer&) = default;
    Renderer& operator=(Renderer&&) = default;

    friend std::ostream& operator<<(std::ostream&, const Renderer&);
    friend Renderer& operator<<(Renderer&, const Case&);
    friend Renderer& operator<<(Renderer&, const Rectangle&);

    char pen{' '};

    private:

    char m_render[WIDTH*HEIGHT];

};

#endif // DEF_RENDERER_HPP