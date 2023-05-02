#include "doublyLinkListCollection.h"
#include "DynamicArray.h"
#include "readfile.h"
#include "homepage.h"
#include "guessUser.h"
#include "admin.h"
#include "customerMenu.h"
using namespace std;



int main()
{
    DoublyLinkedList<UniversityNode> universitiesList = readFromFileDoubly("2023_QS_World_University_Rankings.csv");
    DynamicArrayCollection<UniversityNode2> universitiesList2 = readFromFileArray("2023_QS_World_University_Rankings.csv");
    DoublyLinkedList<Customer> customerlist;
    //mergeSort(universitiesList2,sortByInstitutionAsc);
    universitiesList2.display();
    //generateDummyData(customerlist);
    // customerlist.displayForward();
    //homepage(customerlist);
    int selection;
    do{
    
    drawLine(20, "Homempage");
    cout << "1. Guess User" << endl;
    cout << "2. Login" << endl;
    cout << "3. Register" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter selection :";
    cin >> selection;
    if (cin.fail()){
        cout << "Please enter valid input!" << endl;
        cin.clear();
        //cin.ignore();
        continue;
    }
    switch (selection)
    {
    case 1:
        guess_User_Menu();
        break;
    case 2:
    {
        Customer *loggedInUser = login(customerlist);
        if (loggedInUser != NULL)
        {
            // user successfully logged in
            cout << "Welcome " << loggedInUser->name << "!" << endl;
            customerMenu();
        }
        else
        {
            // login failed
            cout << "Login failed. Please check your username and password." << endl;
        }
        break;
    }
    case 3:
        register_Cus(customerlist);
        break;
    case 4:
        exit(0);
        break;
    default:
        cout << "Invalid input , try again!" << endl;
        break;
    }
    }while(selection !=4);

    cout << "Thanks for using my system";
}

    
