#include <iostream>
#include <string>
#include "application.h"

//TODO длинный метод. Подумать над тем, как разбить его на более маленькие почти независимые методы.
//Поможет вдобавок устранить дублирование кода
//TODO с исключниями разобраться
void Application::mainMenu()
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
    catch(std::exception &error)
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

//TODO длинный метод. Подумать над тем, как разбить его на более маленькие почти независимые методы.
//Поможет вдобавок устранить дублирование кода
//TODO с исключниями разобраться
void Application::locateShipsMenu()
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
    catch(std::exception &error)
    {
        number=0;
    }
    std::cout<<std::endl;
    switch(number){
    case 1:
        game->getComputerField()->locateAutomatically();
        game->getUserField()->locateAutomatically();
        printField();
        std::cout<<std::endl;
        startGameMenu();
        break;
    case 2:
        game->getComputerField()->locateAutomatically();
        printField();
        if (locateShipsInput())
            startGameMenu();
        else {
            game=new Game();
            locateShipsMenu();
        }
        break;
    case 3:
        game=new Game();
        break;
    default:
        std::cout<<"Invalid number! Try again"<<std::endl;
        std::cin.clear();
        getline(std::cin,str);
        locateShipsMenu();
        break;
    }
}

//TODO длинный метод. Подумать над тем, как разбить его на более маленькие почти независимые методы.
//Поможет вдобавок устранить дублирование кода
//TODO с исключниями разобраться
void Application::startGameMenu()
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
    catch(std::exception &error)
    {
        number=0;
    }
    std::cout<<std::endl;
    switch(number){
    case 1:
        gameProcess();
        game=new Game();
        mainMenu();
        break;
    case 2:
        game=new Game();
        locateShipsMenu();
    case 3:
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
