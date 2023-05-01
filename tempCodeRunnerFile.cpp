#include "doublyLinkListCollection.h"
#include "DynamicArray.h"
#include "readfile.h"
#include "homepage.h"
#include "guessUser.h"
#include "admin.h"
#include "customerMenu.h"

void generateDummyData(DoublyLinkedList<Customer> &customerlist)
{
    string names[] = {"Alice", "Bob", "Charlie", "David", "Emily"};
    string genders[] = {"Female", "Male", "Female", "Male", "Female"};
    string passwords[] = {"password1", "password2", "password3", "password4", "password5"};
    string phoneNos[] = {"1234567890", "2345678901", "3456789012", "4567890123", "5678901234"};

    for (int i = 0; i < 5; i++)
    {
        Customer cus(names[i], passwords[i], phoneNos[i], genders[i]);
        customerlist.insertAtEnd(cus);
    }
}

int main()
{
    DoublyLinkedList<UniversityNode> universitiesList = readFromFileDoubly("2023_QS_World_University_Rankings.csv");
    DynamicArrayCollection<UniversityNode2> universitiesList2 = readFromFileArray("2023_QS_World_University_Rankings.csv");
    DoublyLinkedList<Customer> customerlist;
    //mergeSort(universitiesList2,sortByInstitutionAsc);
    //universitiesList2.display();
    
    generateDummyData(customerlist);
    customerlist.displayForward();
    homepage(customerlist);
}