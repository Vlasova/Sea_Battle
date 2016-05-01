#include <iostream>
#include <string>
#include "application.h"
#include "unistd.h"

#include "../Core/game.h"

Application::Application()
{
    game = new Game();
}


void Game::printField()
{
    int number=1;
    std::cout<<"   "<<"A "<<"B "<<"C "<<"D "<<"E "<<"F "<<"G "<<"H "<<"I "<<"J"
            <<"         "<<"A "<<"B "<<"C "<<"D "<<"E "<<"F "<<"G "<<"H "<<"I "<<"J"<<std::endl;
    for (int i=0;i<FIELD_SIZE;i++)
    {
        if (number==10)
            std::cout<<number<<" ";
        else std::cout<<number<<"  ";
        for (int j=0;j<FIELD_SIZE;j++)
        {
            if (getPlayerField()->getFieldCells()[i][j].getStatus()==0)
                std::cout<<"O"<<" ";
            if (getPlayerField()->getFieldCells()[i][j].getStatus()==1)
                std::cout<<"X"<<" ";
            if (getPlayerField()->getFieldCells()[i][j].getStatus()==2)
                std::cout<<"."<<" ";
            if (getPlayerField()->getFieldCells()[i][j].getStatus()==3)
                std::cout<<"_"<<" ";
        }
        std::cout<<"     ";
        if (number==10)
            std::cout<<number<<" ";
        else std::cout<<number<<"  ";
        for (int j=0;j<FIELD_SIZE;j++)
        {
            if (getComputerField()->getFieldCells()[i][j].getStatus()==0)
                std::cout<<"*"<<" ";
            if (getComputerField()->getFieldCells()[i][j].getStatus()==1)
                std::cout<<"X"<<" ";
            if (getComputerField()->getFieldCells()[i][j].getStatus()==2)
                std::cout<<"*"<<" ";
            if (getComputerField()->getFieldCells()[i][j].getStatus()==3)
                std::cout<<"."<<" ";
        }
        std::cout<<std::endl;
        number++;
    }

}

bool Game::locateShips()
{
    std::cout<<"Locate ships"<<std::endl;
    int x, y, lenght, line;
    char charX;

    while (!playerField->allShipsLocate())
    {
        try
        {
            std::string str;
            std::cout<<"Coordinates of the first deck: "<<std::endl;
            std::cin>>str;
            commands(str);
            charX=str[0];
            y=str[1]-'0';
            if (charX<96)
                x=charX-64;
            else
                x=charX-96;
            std::cout<<"Lenght of the ship: "<<std::endl;
            std::cin>>str;
            commands(str);
            try
            {
                lenght=std::stoi(str);
            }
            catch(std::exception &error)
            {
                throw 6;
            }
            std::cout<<"Ship location(vertical-0,horizontal-1): "<<std::endl;
            std::cin>>str;
            commands(str);
            try
            {
                line=std::stoi(str);
            }
            catch(std::exception &error)
            {
                throw 7;
            }

            std::cin.clear();
            getline(std::cin,str);
            playerField->isInputCorrect(x-1,y-1,lenght,shipLine(line));
            playerField->placeShip(x-1,y-1,lenght,shipLine(line));
            printField();
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
                std::cout<<"Error! Wrong coordinates! Use letter a..j and number 1..10"<<std::endl;
                break;
            case 6:
                std::cout<<"Error! Wrong lenght!"<<std::endl;
                break;
            case 7:
                std::cout<<"Error! Wrong input! Use 0 or 1"<<std::endl;
                break;
            case 8:
                std::cout<<"Error! It is impossible to place the ship"<<std::endl;
                break;
            case 9:
                return false;

            }
        }
    }
    std::cout<<"All ships are placed!"<<std::endl;
    return true;
}




void Game::gameProcess()
{
    try
    {
        std::cout<<"Make move: ";
        int x,y;
        char charX;
        std::string str;
        std::cin>>str;
        commands(str);
        charX=str[0];
        y=str[1]-'0';
        if (charX<96)
            x=charX-64;
        else
            x=charX-96;
        std::cin.clear();
        getline(std::cin,str);
        computerField->isCoordinatesCorrect(x-1,y-1);
        {
            if (computerField->shot(x-1,y-1)){
                for (int i=0; i<NUMBER_OF_SHIPS;i++)
                    for (int j=0; j<computerField->getFieldShips()[i].getLenght(); j++)
                    {
                        if (computerField->getFieldShips()[i].getShipCells()[j].getX()==x-1 && computerField->getFieldShips()[i].getShipCells()[j].getY()==y-1)
                        {
                            if (computerField->getFieldShips()[i].getShipStatus()==2){
                                computerField->drawAroundShip(computerField->getFieldShips()[i]);
                                printField();
                                std::cout<<"You hit!"<<std::endl;
                                std::cout<<"Ship destroyed!"<<std::endl;
                            }
                            else
                            {
                                printField();
                                std::cout<<"You hit!"<<std::endl;
                            }
                        }
                    }
                if(!computerField->allShipsDestroyed() && !playerField->allShipsDestroyed())
                    gameProcess();
                else
                    decideWinner();
            }

            else{
                printField();
                std::cout<<"You miss!"<<std::endl;
                makeComputerMove();
            }
        }

    }
    catch(int Deck)
    {switch(Deck)
        {
        case 5:
            std::cout<<"Error! Wrong coordinates! Use letter a..j and number 1..10"<<std::endl;
            gameProcess();
            break;
        case 8:
            break;
        }
    }
}


void Game::makeComputerMove()
{
    int x,y;
    sleep(2);
    x=std::rand()%(FIELD_SIZE-1);
    y=std::rand()%(FIELD_SIZE-1);
    if (playerField->shot(x,y)){
        printField();
        std::cout<<"Computer hit!"<<std::endl;
        if (playerField->allShipsDestroyed())
            decideWinner();
        else
            makeComputerMove();
    }
    else{
        printField();
        std::cout<<"Computer miss!"<<std::endl;
        gameProcess();
    }
}

void Game::decideWinner()
{
    if (computerField->allShipsDestroyed())
        std::cout<<"You won!"<<std::endl<<std::endl;
    if (playerField->allShipsDestroyed())
        std::cout<<"You lost!"<<std::endl<<std::endl;
}

void Game::commands(std::string str)
{
    if (str=="exit")
    {
        std::cout<<std::endl;
        throw 9;
    }
}

Application::~Application()
{
    delete game;
}



