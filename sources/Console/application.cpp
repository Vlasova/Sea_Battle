#include <iostream>
#include <string>
#include "application.h"


Application::Application() noexcept
{
    game = new GameAPI();
}

Application::~Application() noexcept
{
    delete game;
}

void Application::printFields() noexcept
{
    std::cout<<"   "<<"A "<<"B "<<"C "<<"D "<<"E "<<"F "<<"G "<<"H "<<"I "<<"J"
            <<"         "<<"A "<<"B "<<"C "<<"D "<<"E "<<"F "<<"G "<<"H "<<"I "<<"J"<<std::endl;
    for (int i=0;i<Field::FIELD_SIZE;i++)
    {
        printUserFieldLine(i);
        printComputerFieldLine(i);

    }

}

void Application::printUserFieldLine(int lineNumber) noexcept
{
    if (lineNumber+1==10)
        std::cout<<lineNumber+1<<" ";
    else std::cout<<lineNumber+1<<"  ";
    for (int j=0;j<Field::FIELD_SIZE;j++)
    {
        if (game->getUserField()->getFieldCells()[lineNumber][j].getStatus()==cellStatus::whole)
            std::cout<<"O"<<" ";
        if (game->getUserField()->getFieldCells()[lineNumber][j].getStatus()==cellStatus::stricken)
            std::cout<<"X"<<" ";
        if (game->getUserField()->getFieldCells()[lineNumber][j].getStatus()==cellStatus::blank)
            std::cout<<"."<<" ";
        if (game->getUserField()->getFieldCells()[lineNumber][j].getStatus()==cellStatus::tried)
            std::cout<<"_"<<" ";
    }
    std::cout<<"     ";
}

void Application::printComputerFieldLine(int lineNumber) noexcept
{
    if (lineNumber+1==10)
        std::cout<<lineNumber+1<<" ";
    else std::cout<<lineNumber+1<<"  ";
    for (int j=0;j<Field::FIELD_SIZE;j++)
    {
        if (game->getComputerField()->getFieldCells()[lineNumber][j].getStatus()==cellStatus::whole)
            std::cout<<"*"<<" ";
        if (game->getComputerField()->getFieldCells()[lineNumber][j].getStatus()==cellStatus::stricken)
            std::cout<<"X"<<" ";
        if (game->getComputerField()->getFieldCells()[lineNumber][j].getStatus()==cellStatus::blank)
            std::cout<<"*"<<" ";
        if (game->getComputerField()->getFieldCells()[lineNumber][j].getStatus()==cellStatus::tried)
            std::cout<<"."<<" ";
    }
    std::cout<<std::endl;
}

bool Application::locateShipsInput() noexcept
{
    std::cout<<"Locate ships"<<std::endl;
    int x, y, lenght, number;
    shipLocation location;
    std::string str;

    while (!game->getUserField()->allShipsLocate())
    {
        std::cout<<"Coordinates of the first deck: "<<std::endl;
        std::cin>>str;
        commands(str);
        x=inputX(str);
        y=inputY(str);
        if (!isCoordinatesCorrect(x,y))
            continue;

        std::cout<<"Lenght of the ship: "<<std::endl;
        std::cin>>str;
        commands(str);
        lenght=inputLenght(str);
        if (!isLenghtCorrect(lenght))
            continue;

        std::cout<<"Ship location(vertical-1,horizontal-2): "<<std::endl;
        std::cin>>str;
        commands(str);
        number=inputLocation(str);
        if (number==1)
            location=shipLocation::vertical;
        if (number==2)
            location=shipLocation::horizontal;
        if (!isLocationCorrect(number))
            continue;

        std::cin.clear();
        getline(std::cin,str);

        if (!canPlaceShip(x, y, lenght, number, location))
            continue;
        game->placeUserShip(x, y, lenght, location);
        printFields();

    }
    std::cout<<"All ships are placed!"<<std::endl<<std::endl;
    return true;
}

int Application::inputX(std::string str) noexcept
{
    char charX;
    int x;
    charX=str[0];
    if (charX<96)
        x=charX-64;
    else
        x=charX-96;
    return x-1;
}

int Application::inputY(std::string str) noexcept
{
    int y;
    if(str.length()==2)
        y=str[1]-'0';
    else y=(str[1]-'0')*10+(str[2]-'0');
    return y-1;
}

int Application::inputLenght(std::string str) noexcept
{
    int lenght;
    try
    {
        lenght=std::stoi(str);
    }
    catch(std::exception &e)
    {
        lenght=0;
    }
    return lenght;
}

int Application::inputLocation(std::string str) noexcept
{
    int location;
    try
    {
        location=std::stoi(str);
    }
    catch(std::exception &e)
    {
        location=0;
    }
    return location;
}

void Application::gameProcess() noexcept
{
    while (!game->allShipsDestroyed(game->getComputerField()) &&
           !game->allShipsDestroyed(game->getUserField()))
    {
        std::cout<<"Make move: ";
        int x,y;
        std::string str;
        std::cin>>str;
        commands(str);
        x=inputX(str);
        y=inputY(str);
        if (!isCoordinatesCorrect(x, y))
            continue;
        std::cin.clear();
        getline(std::cin,str);

        if (game->makeUserMove(x ,y))
        {
            ifUserHit(x, y);
            continue;

        }
        else
        {
            printFields();
            std::cout<<"You miss!"<<std::endl<<std::endl;
        }

        while (game->makeComputerMove() && !game->allShipsDestroyed(game->getUserField()))
        {
            ifComputerHit();
        }

        printFields();
        std::cout<<"Computer miss!"<<std::endl<<std::endl;

    }
}

void Application::decideWinner() noexcept
{
    if (game->allShipsDestroyed(game->getComputerField()))
        std::cout<<"You won!"<<std::endl<<std::endl;
    if (game->allShipsDestroyed(game->getUserField()))
        std::cout<<"You lost!"<<std::endl<<std::endl;
    delete game;
    game=new GameAPI();
    mainMenu();
}

void Application::commands(std::string str) noexcept
{
    if (str=="exit")
    {
        std::cout<<std::endl;
        delete game;
        game=new GameAPI();
        mainMenu();
    }
}

bool Application::canPlaceShip(int x, int y, int lenght, int number, shipLocation location) noexcept
{

    if ((number==2 && x+lenght>Field::FIELD_SIZE) || (number==1 && y+lenght>Field::FIELD_SIZE))
    {
        std::cout<<"Error! It is impossible to place the ship"<<std::endl;
        return false;
    }
    if (!game->getUserField()->canPlaceShip(x,y,lenght,location))
    {
        std::cout<<"Error! Ships must not touch"<<std::endl;
        return false;
    }

    static int count1Deck=0;
    static int count2Deck=0;
    static int count3Deck=0;
    static int count4Deck=0;

    if (lenght==1)
    {
        count1Deck++;
        if (count1Deck>4){
            std::cout<<"Error! You can place only four 1-deck ships"<<std::endl;
            return false;
        }
    }

    if (lenght==2)
    {
        count2Deck++;
        if (count2Deck>3){
            std::cout<<"Error! You can place only three 2-deck ships"<<std::endl;
            return false;
        }
    }

    if (lenght==3)
    {
        count3Deck++;
        if(count3Deck>2){
            std::cout<<"Error! You can place only two 3-deck ships"<<std::endl;
            return false;
        }
    }

    if (lenght==4)
    {
        count4Deck++;
        if (count4Deck>1){
            std::cout<<"Error! You can place only one 4-deck ship"<<std::endl;
            return false;
        }
    }

    return true;
}

bool Application::isCoordinatesCorrect(int x, int y) noexcept
{
    if(x>Field::FIELD_SIZE || x<0 || y>Field::FIELD_SIZE || y<0)
    {
        std::cout<<"Error! Wrong coordinates! Use letter a..j and number 1..10"<<std::endl;
        return false;
    }
    return true;

}

bool Application::isLenghtCorrect(int lenght) noexcept
{
    if (lenght<1 || lenght>4)
    {
        std::cout<<"Error! Wrong lenght!"<<std::endl;
        return false;
    }
    return true;
}

bool Application::isLocationCorrect(int location) noexcept
{
    if (location<1 || location>2)
    {
        std::cout<<"Error! Wrong input! Use 1 or 2"<<std::endl;
        return false;
    }
    return true;
}

void Application::ifUserHit(int x, int y) noexcept
{
    int shipNumber;
    shipNumber=game->getComputerField()->whoseDeck(x, y);
    if (game->getComputerField()->isShipDestroyed(shipNumber))
    {
        game->getComputerField()->changeCellsAroundShip(game->getComputerField()->getFieldShips()[shipNumber]);
        printFields();
        std::cout<<"You hit!"<<std::endl;
        std::cout<<"Ship destroyed!"<<std::endl;

    }
    else
    {
        printFields();
        std::cout<<"You hit!"<<std::endl;
    }
    if (game->allShipsDestroyed(game->getComputerField()))
        decideWinner();

}

void Application::ifComputerHit() noexcept
{
    printFields();
    std::cout<<"Computer hit!"<<std::endl<<std::endl;
    if (game->allShipsDestroyed(game->getUserField()))
        decideWinner();
}






