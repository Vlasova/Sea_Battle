#include <iostream>
#include "application.h"

void Application::mainMenu(){
    std::cout<<"1. New game"<<std::endl
             <<"2. Exit"<<std::endl
             <<"Select item: ";
    int number;
    std::cin>>number;
    switch(number){
    case 1:
        startGame();
        break;
    case 2:
        loadGame();
        break;

    }


}
