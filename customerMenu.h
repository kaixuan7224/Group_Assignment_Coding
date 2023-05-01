#ifndef CUSTONER_MENU_H
#define CUSTONER_MENU_H

#include <iostream>
#include "doublyLinkListCollection.h"
#include "DynamicArray.h"
#include "readfile.h"
#include "homepage.h"
using namespace std;


void display_Uni_Des()
{
    cout << "Display University" << endl;
}
void search_University()
{
    cout << "Search University" << endl;
}
void save_favourite()
{
    cout << "Save University" << endl;
}
void send_Feedback()
{
    cout << "Send Feedback" << endl;
}
void review_Feedback()
{
    cout << "Review Feedback" << endl;
}
void log_out()
{
    cout << "Log out" << endl;
}

void customerMenu()
{
    int selection;
    // while (true){
    drawLine(20, "Customer Menu");
    cout << "1. Display University in descending order" << endl;
    cout << "2. Search university" << endl;
    cout << "3. Save favourite University" << endl;
    cout << "4. Send Feedback to MoHE" << endl;
    cout << "5. Review Feedback" << endl;
    cout << "6. Log out" << endl;
    cout << "Enter selection :";
    cin >> selection;
    switch (selection)
    {
    case 1:
        display_Uni_Des();
        break;
    case 2:
        search_University();
        break;
    case 3:
        save_favourite();
        break;
    case 4:
        send_Feedback();
        break;
    case 5:
        review_Feedback();
        break;
    case 6:
        log_out();
        break;

    default:
        cout << "Invalid input , try again!" << endl;
    }
}


#endif //CUSTONER_MENU_H