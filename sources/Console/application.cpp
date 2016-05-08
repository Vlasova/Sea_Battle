#include <iostream>
#include <string>
#include "application.h"


Application::Application()
{
    game = new Game();
}


void Application::printField()
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
            if (game->getPlayerField()->getFieldCells()[i][j].getStatus()==0)
                std::cout<<"O"<<" ";
            if (game->getPlayerField()->getFieldCells()[i][j].getStatus()==1)
                std::cout<<"X"<<" ";
            if (game->getPlayerField()->getFieldCells()[i][j].getStatus()==2)
                std::cout<<"."<<" ";
            if (game->getPlayerField()->getFieldCells()[i][j].getStatus()==3)
                std::cout<<"_"<<" ";
        }
        std::cout<<"     ";
        if (number==10)
            std::cout<<number<<" ";
        else std::cout<<number<<"  ";
        for (int j=0;j<FIELD_SIZE;j++)
        {
            if (game->getComputerField()->getFieldCells()[i][j].getStatus()==0)
                std::cout<<"*"<<" ";
            if (game->getComputerField()->getFieldCells()[i][j].getStatus()==1)
                std::cout<<"X"<<" ";
            if (game->getComputerField()->getFieldCells()[i][j].getStatus()==2)
                std::cout<<"*"<<" ";
            if (game->getComputerField()->getFieldCells()[i][j].getStatus()==3)
                std::cout<<"."<<" ";
        }
        std::cout<<std::endl;
        number++;
    }

}

bool Application::locateShipsInput()
{
    std::cout<<"Locate ships"<<std::endl;
    int x, y, lenght, line;
    char charX;

    while (!game->getPlayerField()->allShipsLocate())
    {
        try
        {
            std::string str;
            std::cout<<"Coordinates of the first deck: "<<std::endl;
            std::cin>>str;
            commands(str);
            charX=str[0];
            if(str.length()==2)
                y=str[1]-'0';
            else y=(str[1]-'0')*10+(str[2]-'0');
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
            isInputCorrect(x-1,y-1,lenght,shipLine(line));
            game->getPlayerField()->placeShip(x-1,y-1,lenght,shipLine(line));
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
                break;
            }
        }
    }
    std::cout<<"All ships are placed!"<<std::endl<<std::endl;
    return true;
}

void Application::gameProcess()
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
        if(str.length()==2)
            y=str[1]-'0';
        else y=(str[1]-'0')*10+(str[2]-'0');
        if (charX<96)
            x=charX-64;
        else
            x=charX-96;
        std::cin.clear();
        getline(std::cin,str);
        isCoordinatesCorrect(x-1,y-1);

        if (game->makeMove(x-1,y-1)){
            for (int i=0; i<NUMBER_OF_SHIPS;i++)
                for (int j=0; j<game->getComputerField()->getFieldShips()[i].getLenght(); j++)
                {
                    if (game->getComputerField()->getFieldShips()[i].getShipCells()[j].getX()==x-1 && game->getComputerField()->getFieldShips()[i].getShipCells()[j].getY()==y-1)
                    {
                        if (game->getComputerField()->getFieldShips()[i].getShipStatus()==2){
                            game->getComputerField()->drawAroundShip(game->getComputerField()->getFieldShips()[i]);
                            printField();
                            std::cout<<"You hit!"<<std::endl;
                            std::cout<<"Ship destroyed!"<<std::endl;
                        }
                        else{
                            printField();
                            std::cout<<"You hit!"<<std::endl;
                        }
                    }

                }
            if (game->getComputerField()->allShipsDestroyed())
                decideWinner();
            else{
                gameProcess();
            }
        }

        else
        {
            printField();
            std::cout<<"You miss!"<<std::endl<<std::endl;
        }
        while (game->makeComputerMove() && !game->getPlayerField()->allShipsDestroyed())
        {
            printField();
            std::cout<<"Computer hit!"<<std::endl<<std::endl;
        }
        if (game->getPlayerField()->allShipsDestroyed()){
            decideWinner();
        }
        else{
            printField();
            std::cout<<"Computer miss!"<<std::endl<<std::endl;
            gameProcess();
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




void Application::decideWinner()
{
    if (game->getComputerField()->allShipsDestroyed())
        std::cout<<"You won!"<<std::endl<<std::endl;
    if (game->getPlayerField()->allShipsDestroyed())
        std::cout<<"You lost!"<<std::endl<<std::endl;
    game=new Game();
    mainMenu();
}

void Application::commands(std::string str)
{
    if (str=="exit")
    {
        std::cout<<std::endl;
        throw 9;
    }
}

void Application::isInputCorrect(int x, int y, int lenght, shipLine line)
{
    static int count1Deck=0;
    static int count2Deck=0;
    static int count3Deck=0;
    static int count4Deck=0;

    if(x>FIELD_SIZE-1 || x<0 || y>FIELD_SIZE-1 || y<0)
        throw 5;
    if(lenght<1 || lenght>4)
        throw 6;
    if(line<0 || line>1)
        throw 7;
    if((line==horizontal && x+lenght>FIELD_SIZE) || (line==vertical && y+lenght>FIELD_SIZE))
        throw 8;
    if(!game->getPlayerField()->canPlaceShip(x,y,lenght,line))
        throw 0;
    if (lenght==1){
        count1Deck++;
        if (count1Deck>4){
            count1Deck--;
            throw 1;
        }
    }
    if (lenght==2){
        count2Deck++;
        if (count2Deck>3){
            count2Deck--;
            throw 2;
        }
    }
    if (lenght==3){
        count3Deck++;
        if (count3Deck>2){
            count3Deck--;
            throw 3;
        }
    }
    if (lenght==4){
        count4Deck++;
        if (count4Deck>1){
            count4Deck--;
            throw 4;
        }
    }
}

void Application::isCoordinatesCorrect(int x, int y)
{
    if(x>FIELD_SIZE || x<0 || y>FIELD_SIZE || y<0)
        throw 5;

}

Application::~Application()
{
    delete game;
}



