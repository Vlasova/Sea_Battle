#include <iostream>
#include <string>
#include "application.h"


Application::Application()
{
    game = new GameInterface();
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
    else std::cout<<lineNumber<<"  ";
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

//TODO длинный метод. Подумать над тем, как разбить его на более маленькие почти независимые методы.
//Поможет вдобавок устранить дублирование кода
//Сложно читать такой длинный метод.
//TODO 
//Странная реализация и обработка исключений.
//Более хорошее решение - создать классы исключений, наследованные от std::exception.
//Перегрузить в них функцию what().
//Исключения (генерацию) лучше поместить в ядро.
//В приложении их только ловить
//Вместо того, чтобы бросать и ловить исключения в приложении, можно обрабатывать ошибки и без исключений.
//В данной ситуации исключения ради исключений
bool Application::locateShipsInput()
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
        std::cout<<"Lenght of the ship: "<<std::endl;
        std::cin>>str;
        commands(str);
        lenght=inputLenght(str);
        std::cout<<"Ship location(vertical-1,horizontal-2): "<<std::endl;
        std::cin>>str;
        commands(str);
        number=inputLocation(str);
        if (number==1)
            location=shipLocation::vertical;
        if (number==2)
            location=shipLocation::horizontal;
        std::cin.clear();
        getline(std::cin,str);

        if (isInputCorrect(x, y, lenght, number, location)){
            game->getUserField()->placeShip(x, y, lenght, location);
            printFields();
        }
    }
    std::cout<<"All ships are placed!"<<std::endl<<std::endl;
    return true;
}

int Application::inputX(std::string str)
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

int Application::inputY(std::string str)
{
    int y;
    if(str.length()==2)
        y=str[1]-'0';
    else y=(str[1]-'0')*10+(str[2]-'0');
    return y-1;
}

int Application::inputLenght(std::string str)
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

int Application::inputLocation(std::string str)
{
    int number;
    try
    {
        number=std::stoi(str);
    }
    catch(std::exception &e)
    {
        number=0;
    }
    return number;
}

//TODO длинный метод. Подумать над тем, как разбить его на более маленькие почти независимые методы.
//Поможет вдобавок устранить дублирование кода
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

        if (game->makeUserMove(x-1,y-1)){
            for (int i=0; i<Field::NUMBER_OF_SHIPS;i++)
                for (int j=0; j<game->getComputerField()->getFieldShips()[i].getLenght(); j++)
                {
                    //TODO слишком длинные условия
                    if (game->getComputerField()->getFieldShips()[i].getShipCells()[j].getX()==x-1 && game->getComputerField()->getFieldShips()[i].getShipCells()[j].getY()==y-1)
                    {
                        if (game->getComputerField()->getFieldShips()[i].getShipStatus()==shipStatus::destroyed){
                            game->getComputerField()->drawAroundShip(game->getComputerField()->getFieldShips()[i]);
                            printFields();
                            std::cout<<"You hit!"<<std::endl;
                            std::cout<<"Ship destroyed!"<<std::endl;
                        }
                        else{
                            printFields();
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
            printFields();
            std::cout<<"You miss!"<<std::endl<<std::endl;
        }
        while (game->makeComputerMove() && !game->getUserField()->allShipsDestroyed())
        {
            printFields();
            std::cout<<"Computer hit!"<<std::endl<<std::endl;
        }
        if (game->getUserField()->allShipsDestroyed()){
            decideWinner();
        }
        else{
            printFields();
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
    if (game->getUserField()->allShipsDestroyed())
        std::cout<<"You lost!"<<std::endl<<std::endl;
    //Не видел до этого нигде delete game.
    //Может и есть, но нереально найти в таких длинных методах.
    //если объект в с++ создается с new, то обязательно должно быть delete.
    //В данной ситуации вроде так:
    //new в конструкторе
    //new здесь
    //delete только в деструкторе.
    //после одного new и перед следующим обязательно дожен быть delete.
    //иначе - непредсказуемое поведение
    //TODO добавить delete, если нужно(!)
    game=new GameInterface();
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

//TODO длинный метод. Подумать над тем, как разбить его на более маленькие почти независимые методы.
//Поможет вдобавок устранить дублирование кода
bool Application::isInputCorrect(int x, int y, int lenght, int number, shipLocation location)
{
    static int count1Deck=0;
    static int count2Deck=0;
    static int count3Deck=0;
    static int count4Deck=0;

    if (x>Field::FIELD_SIZE-1 || x<0|| y>Field::FIELD_SIZE-1 || y<0)
    {
        std::cout<<"Error! Wrong coordinates! Use letter a..j and number 1..10"<<std::endl;
        return false;
    }
    if (lenght<1 || lenght>4)
    {
        std::cout<<"Error! Wrong lenght!"<<std::endl;
        return false;
    }
    if (number<1 || number>2)
    {
        std::cout<<"Error! Wrong input! Use 1 or 2"<<std::endl;
        return false;
    }
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

    if (lenght==1){
        count1Deck++;
        if (count1Deck>4){
            count1Deck--;
            std::cout<<"Error! You can place only four 1-deck ship"<<std::endl;
            return false;
        }
    }
    if (lenght==2){
        count2Deck++;
        if (count2Deck>3){
            count2Deck--;
            std::cout<<"Error! You can place only three 2-deck ship"<<std::endl;
            return false;
        }
    }
    if (lenght==3){
        count3Deck++;
        if (count3Deck>2){
            count3Deck--;
            std::cout<<"Error! You can place only two 3-deck ship"<<std::endl;
            return false;
        }
    }
    if (lenght==4){
        count4Deck++;
        if (count4Deck>1){
            count4Deck--;
            std::cout<<"Error! You can place only one 4-deck ship"<<std::endl;
            return false;
        }
    }
    return true;
}

void Application::isCoordinatesCorrect(int x, int y)
{
    if(x>Field::FIELD_SIZE || x<0 || y>Field::FIELD_SIZE || y<0)
        throw 5;

}
//TODO удобнее читать, когда деструктор идет вслед за конструктором
Application::~Application()
{
    delete game;
}



