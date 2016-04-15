#include <iostream>
#include "application.h"


Application::Application()
{
    game = new Game();
}

void Application::startGame()
{
    printField();
}

void Application::printField()
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
         if (game->getPlayerField()->getFieldCells()[i][j].getStatus()==0)
             std::cout<<"x"<<" ";
         if (game->getPlayerField()->getFieldCells()[i][j].getStatus()==1)
             std::cout<<"X"<<" ";
         if (game->getPlayerField()->getFieldCells()[i][j].getStatus()==2)
             std::cout<<"*"<<" ";
     }
     std::cout<<"     ";
     if (number==10)
         std::cout<<number<<" ";
     else std::cout<<number<<"  ";
     for (int j=0;j<Field::FIELD_SIZE;j++)
     {
         if (game->getComputerField()->getFieldCells()[i][j].getStatus()==0)
             std::cout<<"x"<<" ";
         if (game->getComputerField()->getFieldCells()[i][j].getStatus()==1)
             std::cout<<"X"<<" ";
         if (game->getComputerField()->getFieldCells()[i][j].getStatus()==2)
             std::cout<<"*"<<" ";
     }
     std::cout<<std::endl;
     number++;
    }

}


void Application::loadGame()
{

}
