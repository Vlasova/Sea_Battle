#include <iostream>
#include <string>
#include "application.h"


Application::Application()
{
    game = new Game();
}


//TODO длинный метод. Подумать над тем, как разбить его на более маленькие почти независимые методы.
//Поможет вдобавок устранить дублирование кода
//TODO добавить noexcept, т.к функция не генерирует исключений
void Application::printField()
{
    int number=1;
    std::cout<<"   "<<"A "<<"B "<<"C "<<"D "<<"E "<<"F "<<"G "<<"H "<<"I "<<"J"
            <<"         "<<"A "<<"B "<<"C "<<"D "<<"E "<<"F "<<"G "<<"H "<<"I "<<"J"<<std::endl;
    for (int i=0;i<Field::FIELD_SIZE;i++)
    {
        if (number==10)
            std::cout<<number<<" ";
        else std::cout<<number<<"  ";
        for (int j=0;j<Field::FIELD_SIZE;j++)
        {
            if (game->getUserField()->getFieldCells()[i][j].getStatus()==cellStatus::whole)
                std::cout<<"O"<<" ";
            if (game->getUserField()->getFieldCells()[i][j].getStatus()==cellStatus::stricken)
                std::cout<<"X"<<" ";
            if (game->getUserField()->getFieldCells()[i][j].getStatus()==cellStatus::blank)
                std::cout<<"."<<" ";
            if (game->getUserField()->getFieldCells()[i][j].getStatus()==cellStatus::tried)
                std::cout<<"_"<<" ";
        }
        std::cout<<"     ";
        if (number==10)
            std::cout<<number<<" ";
        else std::cout<<number<<"  ";
        for (int j=0;j<Field::FIELD_SIZE;j++)
        {
            if (game->getComputerField()->getFieldCells()[i][j].getStatus()==cellStatus::whole)
                std::cout<<"*"<<" ";
            if (game->getComputerField()->getFieldCells()[i][j].getStatus()==cellStatus::stricken)
                std::cout<<"X"<<" ";
            if (game->getComputerField()->getFieldCells()[i][j].getStatus()==cellStatus::blank)
                std::cout<<"*"<<" ";
            if (game->getComputerField()->getFieldCells()[i][j].getStatus()==cellStatus::tried)
                std::cout<<"."<<" ";
        }
        std::cout<<std::endl;
        number++;
    }

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
    int x, y, lenght, line;
    shipLocation location;
    char charX;

    while (!game->getUserField()->allShipsLocate())
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
                if (line==0)
                    location=shipLocation::vertical;
                if (line==1)
                    location=shipLocation::horizontal;
            }
            catch(std::exception &error)
            {
                throw 7;
            }

            std::cin.clear();
            getline(std::cin,str);
            isInputCorrect(x-1,y-1,lenght,line, location);
            game->getUserField()->placeShip(x-1,y-1,lenght,location);
            printField();
        }
        //TODO исключения ловят по ссылке на const. В данной ситуации не критично, т.к тип int. Но в последствии ты же его заменишь на свой класс.
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
        while (game->makeComputerMove() && !game->getUserField()->allShipsDestroyed())
        {
            printField();
            std::cout<<"Computer hit!"<<std::endl<<std::endl;
        }
        if (game->getUserField()->allShipsDestroyed()){
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

//TODO длинный метод. Подумать над тем, как разбить его на более маленькие почти независимые методы.
//Поможет вдобавок устранить дублирование кода
void Application::isInputCorrect(int x, int y, int lenght, int line, shipLocation location)
{
    static int count1Deck=0;
    static int count2Deck=0;
    static int count3Deck=0;
    static int count4Deck=0;

    if(x>Field::FIELD_SIZE-1 || x<0 || y>Field::FIELD_SIZE-1 || y<0)
        throw 5;
    if(lenght<1 || lenght>4)
        throw 6;
    if(line<0 || line>1)
        throw 7;
    if((location==shipLocation::horizontal && x+lenght>Field::FIELD_SIZE) || (location==shipLocation::vertical && y+lenght>Field::FIELD_SIZE))
        throw 8;
    if(!game->getUserField()->canPlaceShip(x,y,lenght,location))
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
    if(x>Field::FIELD_SIZE || x<0 || y>Field::FIELD_SIZE || y<0)
        throw 5;

}
//TODO удобнее читать, когда деструктор идет вслед за конструктором
Application::~Application()
{
    delete game;
}



