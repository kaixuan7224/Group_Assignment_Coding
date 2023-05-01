#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include "doublyLinkListCollection.h"
#include "DynamicArray.h"
#include "readfile.h"
#include "customerMenu.h"
using namespace std;


void display_register(){};
void modify_User(){};
void update_User(){};
void view_ReplyFeedback(){};
void summarize_report(){};

void admin_Menu()
{
    int selection;
    drawLine(20, "Admin Menu");
    cout << "1. Display register user details" << endl;
    cout << "2. Modify a user details" << endl;
    cout << "3. Update user account based on inactivity status" << endl;
    cout << "4. View & reply customer feedback" << endl;
    cout << "5. Summarize & Report" << endl;
    cout << "6. Log out" << endl;

    cout << "Enter selection :";
    cin >> selection;
    switch (selection)
    {
    case 1:
        display_register();
        break;
    case 2:
        modify_User();
        break;
    case 3:
        update_User();
        break;
    case 4:
        view_ReplyFeedback();
        break;
    case 5:
        summarize_report();
    case 6:
        log_out();
    default:
        cout << "Invalid input, try it again!";
    }
}


#endif //ADMIN_H