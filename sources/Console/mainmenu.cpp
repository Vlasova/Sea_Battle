#include <iostream>
#include <string>
#include "application.h"

using namespace std;

void Application::mainMenu(){
         cout<<"1. New game"<<endl
             <<"2. Exit"<<endl
             <<"Select item: ";
    int number;
    string str;
    cin>>number;
    switch(number){
    case 1:
        startGame();
        break;
    case 2:
        break;
    default:
        cout<<"Invalid number! Try again"<<endl;
        cin.clear();
        getline(cin,str);
        mainMenu();
        break;
    }
}
