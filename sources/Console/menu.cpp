#include <iostream>
#include <string>
#include "application.h"

void Application::mainMenu() noexcept
{
    std::cout<<"1. New game"<<std::endl
            <<"2. Exit"<<std::endl
           <<"Select item: ";
    int number;
    std::string str;
    std::cin>>str;
    try
    {
        number=std::stoi(str);
    }
    catch(std::exception &e)
    {
        number=0;
    }
    std::cout<<std::endl;
    switch(number){
    case 1:
        locateShipsMenu();
        break;
    case 2:
        std::exit(0);
    default:
        std::cout<<"Invalid number! Try again"<<std::endl;
        std::cin.clear();
        getline(std::cin,str);
        mainMenu();
        break;
    }
}

void Application::locateShipsMenu() noexcept
{
    std::cout<<"1. Locate ships automatically"<<std::endl
            <<"2. Locate ships on one's own"<<std::endl
           <<"3. Exit"<<std::endl
          <<"Select item: ";
    int number;
    std::string str;
    std::cin>>str;
    try
    {
        number=std::stoi(str);
    }
    catch(std::exception &e)
    {
        number=0;
    }
    std::cout<<std::endl;
    switch(number){
    case 1:
        locateShipsAutomatically();
        break;
    case 2:
        locateShipsOnOnesOwn();
        break;
    case 3:
        exit();
        break;
    default:
        std::cout<<"Invalid number! Try again"<<std::endl;
        std::cin.clear();
        getline(std::cin,str);
        locateShipsMenu();
        break;
    }
}

void Application::startGameMenu() noexcept
{
    std::cout<<"1. Start game"<<std::endl
            <<"2. Locate ships again"<<std::endl
            <<"3. Exit"<<std::endl
           <<"Select item: ";
    int number;
    std::string str;
    std::cin>>str;
    try
    {
        number=std::stoi(str);
    }
    catch(std::exception &e)
    {
        number=0;
    }
    std::cout<<std::endl;
    switch(number){
    case 1:
        startGame();
        break;
    case 2:
        locateShipsAgain();
        break;
    case 3:
        exit();
        break;
    default:
        std::cout<<"Invalid number! Try again"<<std::endl;
        std::cin.clear();
        getline(std::cin,str);
        startGameMenu();
        break;
    }

}

void Application::locateShipsAutomatically() noexcept
{
    game->placeShipsAutomatically(game->getComputerField());
    game->placeShipsAutomatically(game->getUserField());
    printFields();
    std::cout<<std::endl;
    startGameMenu();
}

void Application::locateShipsOnOnesOwn() noexcept
{
    game->placeShipsAutomatically(game->getComputerField());
    printFields();
    if (locateShipsInput())
        startGameMenu();
    else {
        delete game;
        game=new GameAPI();
        locateShipsMenu();
    }
}

void Application::exit() noexcept
{
    delete game;
    game=new GameAPI();
    mainMenu();
}

void Application::startGame() noexcept
{
    gameProcess();
    delete game;
    game=new GameAPI();
    mainMenu();
}

void Application::locateShipsAgain() noexcept
{
    delete game;
    game=new GameAPI();
    locateShipsMenu();
}
