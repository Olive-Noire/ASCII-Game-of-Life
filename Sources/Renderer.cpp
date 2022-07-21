#include "../Headers/Renderer.hpp"

//Twain<uint8> Renderer::size = Twain<uint8>{64, 64};

void Renderer::Clear() {

    for (uint16 i{0}; i < WIDTH*HEIGHT; i++) m_render[i] = ' ';

}

std::ostream& operator<<(std::ostream& flux, const Renderer& renderer) {

    for (uint8 i{0}; i < HEIGHT; i++) {

        for (uint8 j{0}; j < WIDTH; j++) {

            flux << renderer.m_render[j+WIDTH*i];

        }

        flux << std::endl;

    }

    return flux;

}

Renderer& operator<<(Renderer& renderer, const Case& c) {

    renderer.m_render[c.position[0]+c.position[1]*WIDTH] = renderer.pen;

    return renderer;

}

Renderer& operator<<(Renderer& renderer, const Rectangle& r) {

    for (uint8 i{0}; i < r.size[0]; i++) {

        for (uint8 j{0}; j < r.size[1]; j++) {

            if (static_cast<uint8>(r.position[0]+i <= r.size[0]) && static_cast<uint8>(r.position[1]+j) <= r.size[1]) {

                renderer << Case{Twain<uint8>{static_cast<uint8>(r.position[0]+i), static_cast<uint8>(r.position[1]+j)}};

            }

        }

    }

    return renderer;

}