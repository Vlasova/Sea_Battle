#include <iostream>
#include <string>
#include "application.h"


Application::Application()
{
    game = new Game();
}

void Application::startGame()
{
    game->printField();
    game->locateShips();
}

void Game::printField()
{
    int number=1;
    std::cout<<"   "<<"A"<<" "<<"B"<<" "<<"C"<<" "<<"D"<<" "<<"E"<<" "<<"F"<<" "<<"G"<<" "<<"H"<<" "<<"I"<<" "<<"J"
      <<"         "<<"A"<<" "<<"B"<<" "<<"C"<<" "<<"D"<<" "<<"E"<<" "<<"F"<<" "<<"G"<<" "<<"H"<<" "<<"I"<<" "<<"J"<<std::endl;
    for (int i=0;i<Field::FIELD_SIZE;i++)
{
     if (number==10)
         std::cout<<number<<" ";
     else std::cout<<number<<"  ";
     for (int j=0;j<Field::FIELD_SIZE;j++)
     {
         if (getPlayerField()->getFieldCells()[i][j].getStatus()==0)
             std::cout<<"x"<<" ";
         if (getPlayerField()->getFieldCells()[i][j].getStatus()==1)
             std::cout<<"X"<<" ";
         if (getPlayerField()->getFieldCells()[i][j].getStatus()==2)
             std::cout<<"*"<<" ";
     }
     std::cout<<"     ";
     if (number==10)
         std::cout<<number<<" ";
     else std::cout<<number<<"  ";
     for (int j=0;j<Field::FIELD_SIZE;j++)
     {
         if (getComputerField()->getFieldCells()[i][j].getStatus()==0)
             std::cout<<"x"<<" ";
         if (getComputerField()->getFieldCells()[i][j].getStatus()==1)
             std::cout<<"X"<<" ";
         if (getComputerField()->getFieldCells()[i][j].getStatus()==2)
             std::cout<<"*"<<" ";
     }
     std::cout<<std::endl;
     number++;
    }

}

void Game::locateShips()
{
    std::cout<<"Locate ships"<<std::endl;
    int x, y, lenght, line;
    char charX;
    for (int i=0;i<Field::NUMBER_OF_SHIPS;i++)
    {
        std::cout<<"Coordinates of the first deck(separated by a space): "<<std::endl;
        std::cin>>charX>>y;
        std::cout<<"Lenght of the ship: "<<std::endl;
        std::cin>>lenght;
        std::cout<<"Ship location(vertical-0,horizontal-1): "<<std::endl;
        std::cin>>line;
        x=charX-64;
        playerField->placeShip(x,y,lenght,shipLine(line));
        printField();
    }
}


void Application::loadGame()
{

}
