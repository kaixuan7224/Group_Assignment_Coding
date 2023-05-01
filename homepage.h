#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <iostream>
#include "doublyLinkListCollection.h"
#include "DynamicArray.h"
#include "guessUser.h"
#include "customerMenu.h"
#include <regex>
using namespace std;

bool checkData(DoublyLinkedList<Customer> &customerlist, string field, string fieldname)
{
    DoublyNode<Customer> *current = customerlist.getHead();
    while (current != NULL)
    {

        if (fieldname == "name" && current->data.name == field)
        {
            return true; // if have existing name in the list retunr true
        }
        else if (fieldname == "phoneNo" && current->data.contactNumber == field)
        {
            return true;
        }

        current = current->next;
    }
    return false;
}

bool validatePhone(string phoneNo)
{
    // Create a regular expression pattern for a phone number format
    regex pattern("\\d{3}-\\d{3}-\\d{4}");
    if (regex_match(phoneNo, pattern))
        if (phoneNo.substr(0, 2) == "01")
        {
            return true;
        }
    return false;
}

void register_Cus(DoublyLinkedList<Customer> &customerlist)
{

    string name, password, confpass, phoneNo, gender;
    drawLine(10, "Register");
    cin.ignore(); // ignore the first character which is the new line chracter
    do
    {
        cout << "Register Name :";
        getline(cin, name); // getline
        if (checkData(customerlist, name, "name"))
        {
            cout << "The register name is existed, please enter a new one!" << endl;
        }

    } while (checkData(customerlist, name, "name"));
    do
    {
        cout << "Password:";
        cin >> password;
        cout << "Confirm Password:";
        cin >> confpass;
    } while (password != confpass);
    do
    {
        cout << "Phone Number(format: xxx-xxx-xxxx)::";
        cin >> phoneNo;
        if (!validatePhone(phoneNo))
            cout << "The phone number fomrat is wrong!,enter it agian" << endl;
        else if (checkData(customerlist, phoneNo, "phoneNo"))
        {
            cout << "The phone number is existed, please enter a new one!" << endl;
        }
    } while (checkData(customerlist, phoneNo, "phoneNo") || (!validatePhone(phoneNo)));
    bool validInput = false;
    while (!validInput)
    {
        cout << "Please enter your gender (F/M): ";
        cin >> gender;
        // Convert gender input to lowercase
        for (int i = 0; i < gender.length(); i++)
        {
            gender[i] = tolower(gender[i]);
        }

        if (gender == "f" || gender == "female")
        {
            gender = "Female";
            validInput = true;
        }
        else if (gender == "m" || gender == "male")
        {
            gender = "Male";
            validInput = true;
        }
        else
        {
            cout << "Invalid input. Please enter 'F', 'Female', 'M', or 'Male'." << endl;
        }
    }
    Customer cus(name, password, phoneNo, gender);
    customerlist.insertAtEnd(cus);
    customerlist.displayForward();
}

void exit()
{
}

Customer *login(DoublyLinkedList<Customer> &customerlist)
{
    string name, password;
    cout << "User:";
    cin.ignore();
    getline(cin, name);
    cout << "Password:";
    cin >> password;
    DoublyNode<Customer> *current = customerlist.getHead();
    while (current != NULL)
    {
        if (current->data.name == name)
        {
            if (current->data.password == password)
            {
                return &current->data;
            }
            break;
        }
        else
            current = current->next;
    }
    return NULL; // doesn't find the user or incorrect login credencial
}

void homepage(DoublyLinkedList<Customer> &customerlist)
{

    int selection;
    Customer *loggedInUser = NULL;
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
        cin.ignore();
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
        exit();
        break;
    default:
        cout << "Invalid input , try again!" << endl;
        break;
    }
    }while(selection !=1 || selection !=2 || selection !=3 ||selection !=4  );
}

#endif // HOMEPAGE_H