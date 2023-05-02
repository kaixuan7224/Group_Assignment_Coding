void generateDummyData(DoublyLinkedList<Customer> &customerlist)
{
    string names[] = {"Alice", "Bob", "Charlie", "David", "Emily"};
    string genders[] = {"Female", "Male", "Female", "Male", "Female"};
    string passwords[] = {"password1", "password2", "password3", "password4", "password5"};
    string phoneNos[] = {"012-345-6789", "015-678-9842", "018-453-5642", "019-456-3457", "011-245-5674"};

    for (int i = 0; i < 5; i++)
    {
        Customer cus(names[i], passwords[i], phoneNos[i], genders[i]);
        customerlist.insertAtEnd(cus);
        
    }
}


