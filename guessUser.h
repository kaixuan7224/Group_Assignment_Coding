#ifndef GUESS_USER_H
#define GUESS_USER_H

#include <iostream>
#include "doublyLinkListCollection.h"
#include "DynamicArray.h"
#include "readfile.h"
#include "homepage.h"
using namespace std;


void drawLine(int line, string title)
{
    for (int i = 0; i < line; i++)
        cout << "=";
    cout << title;
    for (int i = 0; i < line; i++)
        cout << "=";
    cout << endl;
}

void display_University() {
    
}
void display_Uni_Asc_name() {}
void search_Individual_Uni() {}
void goBack() {}

void guess_User_Menu()
{
    int selection;
    drawLine(20, "Guess User Menu");
    cout << "1. Display all University details" << endl;
    cout << "2. Display university ascending by university name" << endl;
    cout << "3. Search individual university details" << endl;
    cout << "4. GoBack" << endl;
    cout << "Enter selection :";
    cin >> selection;
    switch (selection)
    {
    case 1:
        display_University();
        break;
    case 2:
        display_Uni_Asc_name();
        break;
    case 3:
        search_Individual_Uni();
        break;
    case 4:
        goBack();
        break;
    default:
        cout << "Invalid input, try it again!\n";
    }
}


#endif //GUESS_USER_H