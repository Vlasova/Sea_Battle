#include <iostream>
#include <string>
#include "application.h"

void Application::mainMenu()
{
    std::cout<<"1. New game"<<std::endl
            <<"2. Exit"<<std::endl
           <<"Select item: ";
    int number;
    std::string str;
    std::cin>>number;
    std::cout<<std::endl;
    switch(number){
    case 1:
        locateShipsMenu();
        break;
    case 2:
        break;
    default:
        std::cout<<"Invalid number! Try again"<<std::endl;
        std::cin.clear();
        getline(std::cin,str);
        mainMenu();
        break;
    }

}

void Application::locateShipsMenu()
{
    std::cout<<"1. Locate ships automatically"<<std::endl
            <<"2. Locate ships on one's own"<<std::endl
           <<"3. Exit"<<std::endl
          <<"Select item: ";
    int number;
    std::string str;
    std::cin>>number;
    std::cout<<std::endl;
    switch(number){
    case 1:
        game->getComputerField()->locateAutomatically();
        game->getPlayerField()->locateAutomatically();
        game->printField();
        startGameMenu();
        break;
    case 2:
        game->getComputerField()->locateAutomatically();
        game->printField();
        game->locateShips();
        startGameMenu();
        break;
    case 3:
        game=new Game();
        mainMenu();
        break;
    default:
        std::cout<<"Invalid number! Try again"<<std::endl;
        std::cin.clear();
        getline(std::cin,str);
        locateShipsMenu();
        break;
    }


}

void Application::startGameMenu()
{
    std::cout<<"1. Start game"<<std::endl
            <<"2. Exit"<<std::endl
           <<"Select item: ";
    int number;
    std::string str;
    std::cin>>number;
    std::cout<<std::endl;
    switch(number){
    case 1:
        startGame();
        break;
    case 2:
        game=new Game();
        mainMenu();
        break;
    default:
        std::cout<<"Invalid number! Try again"<<std::endl;
        std::cin.clear();
        getline(std::cin,str);
        startGameMenu();
        break;
    }

}
