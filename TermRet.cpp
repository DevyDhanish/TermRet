#include <iostream>
#include "bin/art.h"
#include "bin/color.h"

std::string games[] = {"snake.exe"};

#define length_of_games sizeof(games) / sizeof(games[0])

int main()
{
    // std::string gameName;
    // std::string filePath;

    std::cout << Green << gini_art << reset_color;
    std::cout << Red << "======================================" << reset_color << std::endl;
    std::cout << "LIST OF GAME AVAILABLE RN." << std::endl;
    std::cout << "\n";

    for (int i = 0; i < length_of_games; i++)
    {
        std::cout << i + 1 << " - " << Yellow << games[i] << reset_color << std::endl;
    }

    std::cout << Red << "Use run <game name.exe>" << reset_color << "\n";
    // while (P_ISRunning)
    // {
    //     std::cout << "Which game do you want to play : ";
    //     std::cin >> gameName;
    //     filePath = "build/" + gameName;

    //     int result = system(filePath.c_str());

    //     if (result != 0)
    //     {
    //         std::cout << Red << "Failed to run : " << gameName << reset_color << "\n";
    //     }
    //     else
    //     {
    //         P_ISRunning = 0;
    //     }
    // }
    return 0;
}