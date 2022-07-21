#include <iostream>
#include <cstdlib>
#include <time.h>

#include "../Headers/Renderer.hpp"

void Sleep(int milliseconds) {

    clock_t time_end;
    time_end = clock()+milliseconds*CLOCKS_PER_SEC/1000;
    while (clock() < time_end) {}

}

int main() {

    std::srand(time(0));

    Renderer r;

    Rectangle line{Twain<uint8>{0, 0}, Twain<uint8>{26, HEIGHT}};
    // Rectangle background{Twain<uint8>{0, 0}, Twain<uint8>{WIDTH, HEIGHT}};

    bool grid[WIDTH][HEIGHT], next[WIDTH][HEIGHT];
    for (uint8 i{0}; i < WIDTH; i++) {

        for (uint8 j{0}; j < HEIGHT; j++) grid[i][j] = std::rand()%2;

    }

    while (true) {

        // Render
        
        for (uint8 i{0}; i < HEIGHT; i++) std::cout << std::endl;

        r.Clear();

        // r.pen = '.';
        // r << background;

        r.pen = '#';
        for (uint8 i{0}; i < WIDTH; i++) {

            for (uint8 j{0}; j < HEIGHT; j++) {

                if (grid[i][j]) r << Case{Twain<uint8>{i, j}};

                uint8 count{0};

                if (i > 0) count += grid[i-1][j];
                if (i < WIDTH-1) count += grid[i+1][j];
                if (i > 0 && j < HEIGHT-1) count += grid[i-1][j+1];
                if (i > 0 && j > 0) count += grid[i-1][j-1];
                if (j < HEIGHT-1) count += grid[i][j+1];
                if (j > 0) count += grid[i][j-1];
                if (i < WIDTH-1 && j < HEIGHT-1) count += grid[i+1][j+1];
                if (i < WIDTH-1 && j > 0) count += grid[i+1][j-1];

                if (count < 2 || count > 3) {
                    
                    next[i][j] = false;

                } else if (count == 2) {

                    next[i][j] = grid[i][j];

                } else if (count == 3) {

                    next[i][j] = true;

                }

            }

        }

        for (uint8 i{0}; i < WIDTH; i++) {

            for (uint8 j{0}; j < HEIGHT; j++) grid[i][j] = next[i][j];

        }

        std::cout << r;

        Sleep(500);

    }

    return 0;

}

// g++ -m32 "./Code/Sources/*.cpp" -o "./bin/Terminal" -std=c++17 -s -Wall -Wextra -pedantic-errors