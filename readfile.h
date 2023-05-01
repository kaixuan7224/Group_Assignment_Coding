#ifndef READ_FILE_H
#define READ_FILE_H

#include "doublyLinkListCollection.h"
#include "DynamicArray.h"
#include <fstream> //file

// return type                //function name  //arguments
DoublyLinkedList<UniversityNode> readFromFileDoubly(const string &filename)
{

    DoublyLinkedList<UniversityNode> universitiesList2;
    string array[21];
    int array_sizes = sizeof(array) / sizeof(array[0]);
    string tempdata;
    ifstream file1(filename);

    while (file1.good())
    {
        for (int i = 0; i < array_sizes; i++)
        {
            if (i != 20)
                getline(file1, array[i], ',');
            else
                getline(file1, array[i], '\n'); // last data in column

            while (array[i].front() == '"' && array[i].back() != '"') // read whole "   " and combine to one data
            {
                getline(file1, tempdata, ',');
                array[i] = array[i] + "," + tempdata;
                tempdata.clear();
            }
            if (array[i] == "") // if empty data, assign to 0
            {
                array[i] = '0';
            }
        }

        int found = array[0].find("Rank");
        if (found != string::npos) // find substring
        {
            continue;
        }

        if (array[0] == "0")
        { // check if the rank until the last
            break;
        }

        UniversityNode node(stoi(array[0]), array[1], array[2], array[3], stof(array[4]), array[5], stof(array[6]), array[7],
                            stof(array[8]), array[9], stof(array[10]), array[11], stof(array[12]), array[13], stof(array[14]), array[15],
                            stof(array[16]), array[17], stof(array[18]), array[19], array[20]);

        universitiesList2.insertAtEnd(node);
    }

    return universitiesList2;
}

DynamicArrayCollection<UniversityNode2> readFromFileArray(const string &filename)
{

    DynamicArrayCollection<UniversityNode2> universitiesList;
    string array[21];
    int array_sizes = sizeof(array) / sizeof(array[0]);
    string tempdata;
    ifstream file1(filename);

    while (file1.good())
    {
        for (int i = 0; i < array_sizes; i++)
        {
            if (i != 20)
                getline(file1, array[i], ',');
            else
                getline(file1, array[i], '\n'); // last data in column

            while (array[i].front() == '"' && array[i].back() != '"') // read whole "   " and combine to one data
            {
                getline(file1, tempdata, ',');
                array[i] = array[i] + "," + tempdata;
                tempdata.clear();
            }
            if (array[i] == "") // if empty data, assign to 0
            {
                array[i] = '0';
            }
        }

        int found = array[0].find("Rank");
        if (found != string::npos) // find substring
        {
            continue;
        }

        if (array[0] == "0")
        { // check if the rank until the last
            break;
        }

        UniversityNode2 node(stoi(array[0]), array[1], array[2], array[3], stof(array[4]), array[5], stof(array[6]), array[7],
                             stof(array[8]), array[9], stof(array[10]), array[11], stof(array[12]), array[13], stof(array[14]), array[15],
                             stof(array[16]), array[17], stof(array[18]), array[19], array[20]);

        universitiesList.insertAtEnd(node);
    }

    return universitiesList;
}



template <typename T>
void mergeSort(DynamicArrayCollection<T> &arr, bool (*compareFunc)(const T &, const T &))
{
    if (arr.getSize() <= 1)
    {
        return;
    }

    int mid = arr.getSize() / 2;

    DynamicArrayCollection<T> left;
    for (int i = 0; i < mid; i++)
    {
        left.insertAtEnd(arr.get(i));
    }

    DynamicArrayCollection<T> right;
    for (int i = mid; i < arr.getSize(); i++)
    {
        right.insertAtEnd(arr.get(i));
    }

    mergeSort(left, compareFunc);
    mergeSort(right, compareFunc);

    int i = 0, j = 0, k = 0;

    while (i < left.getSize() && j < right.getSize())
    {
        if (compareFunc(left.get(i), right.get(j)))
        {
            arr.set(k++, left.get(i++));
        }
        else
        {
            arr.set(k++, right.get(j++));
        }
    }

    while (i < left.getSize())
    {
        arr.set(k++, left.get(i++));
    }

    while (j < right.getSize())
    {
        arr.set(k++, right.get(j++));
    }
}

// Sorting Type
bool sortByRankAsc(const UniversityNode2 &a, const UniversityNode2 &b) //if Rank of a < b ,return true
{
    return a.rank < b.rank;
}

bool sortByRankDsc(const UniversityNode2 &a, const UniversityNode2 &b) //if Rank of b < a ,return true
{
    return b.rank < a.rank;
}

bool sortByInstitutionAsc(const UniversityNode2 &a, const UniversityNode2 &b) 
{
    return a.institution < b.institution;
}

bool sortByInstitutionDsc(const UniversityNode2 &a, const UniversityNode2 &b) 
{
    return b.institution < a.institution;
}

bool sortByLocationAsc(const UniversityNode2 &a, const UniversityNode2 &b) 
{
    return a.location < b.location;
}

bool sortByLocationDsc(const UniversityNode2 &a, const UniversityNode2 &b) 
{
    return b.location < a.location;
}

#endif //READ_FILE_H