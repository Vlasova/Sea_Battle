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
    for (int i=0;i<FIELD_SIZE;i++)
    {
        if (number==10)
            std::cout<<number<<" ";
        else std::cout<<number<<"  ";
        for (int j=0;j<FIELD_SIZE;j++)
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
        for (int j=0;j<FIELD_SIZE;j++)
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
    for (int i=0;i<NUMBER_OF_SHIPS;i++)
    {
        std::cout<<"Coordinates of the first deck(separated by a space): "<<std::endl;
        std::cin>>charX>>y;
        std::cout<<"Lenght of the ship: "<<std::endl;
        std::cin>>lenght;
        std::cout<<"Ship location(vertical-0,horizontal-1): "<<std::endl;
        std::cin>>line;
        x=charX-64;
        try
        {
            if (playerField->canPlaceShip(x-1,y-1,lenght,shipLine(line)))
            {
                playerField->placeShip(x-1,y-1,lenght,shipLine(line));
                printField();
            }
            else throw 0;

        }

        catch(int Deck)
        {
            switch(Deck){
            case 0:
                std::cout<<"Error! Ships must not touch"<<std::endl;
                break;
            case 1:
                std::cout<<"Error! You can place only four 1-deck ship"<<std::endl;
                break;
            case 2:
                std::cout<<"Error! You can place only three 2-deck ship"<<std::endl;
                break;
            case 3:
                std::cout<<"Error! You can place only two 3-deck ship"<<std::endl;
                break;
            case 4:
                std::cout<<"Error! You can place only one 4-deck ship"<<std::endl;
                break;
            case 5:
                std::cout<<"Error! It is impossible to place the ship"<<std::endl;
                break;
            }

        }

    }
}

void Application::loadGame()
{

}



