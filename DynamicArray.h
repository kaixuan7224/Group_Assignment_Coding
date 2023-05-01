#ifndef DYANAMIC_ARRAY_H
#define DYANAMIC_ARRAY_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <locale>  // for std::wstring_convert
#include <codecvt> // for std::codecvt_utf8
using namespace std;

template <typename T>
class DynamicArrayCollection
{
private:
    T *data;
    int size;
    int capacity;

public:
    DynamicArrayCollection()
    { // constructor
        size = 0;
        capacity = 10;
        data = new T[capacity];
    }
    ~DynamicArrayCollection()
    {
        cout << "DynamicArray Deleted" << endl;
        delete[] data;
    }
    void insertAtEnd(T item)
    {
        if (size == capacity) // create newArray, and pass the oldArray data to newArray
        {
            T *newData = new T[capacity * 2];
            for (int i = 0; i < size; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity *= 2;
        }
        data[size++] = item;
    }

    void insertAtBegining(T item)
    {
        if (size == capacity) // create newArray, and pass the oldArray data to newArray
        {
            T *newData = new T[capacity * 2];
            for (int i = 0; i < size; i++)
            {
                newData[i + 1] = data[i];
            }
            delete[] data;
            data = newData;
            capacity *= 2;
            // shifts all the existing elements to the right by one index and
            // then inserts the new element at the first index.
        }
        else
        {
            for (int i = size; i > 0; i--)
            {
                data[i] = data[i - 1];
            }
        }
        data[0] = item;
        size++;
    }

    T get(int index) // search something in index
    {
        if (index < 0 || index >= size)
        {
            throw "Index out of bounds.";
        }
        return data[index];
    }
    void set(int index, const T &item)
    {
        if (index >= 0 && index < size)
        {
            data[index] = item;
        }
    }

    int getSize()
    {
        return size;
    }

    void display()
    {
        cout << "Rank\t" << setw(100) << left << "Institution" << setw(15) << left << "Location" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << data[i].toString() << endl;
        }
    }
};

class UniversityNode2
{
public:
    int rank;
    string institution, locationCode, location, arRank,
        erRank, fsrRank, cpfRank, ifrRank, isrRank,
        irnRank, gerRank, scoreScaled;
    float arScore, erScore, fsrScore, cpfScore, ifrScore,
        isrScore, irnScore, gerScore;

    UniversityNode2() {}

    UniversityNode2(int rank, string institution, string locationCode, string location,
                    float arScore, string arRank, float erScore, string erRank,
                    float fsrScore, string fsrRank, float cpfScore, string cpfRank,
                    float ifrScore, string ifrRank, float isrScore, string isrRank,
                    float irnScore, string irnRank, float gerScore, string gerRank,
                    string scoreScaled)
    {
        this->rank = rank;
        this->institution = institution;
        this->locationCode = locationCode;
        this->location = location;
        this->arScore = arScore;
        this->arRank = arRank;
        this->erScore = erScore;
        this->erRank = erRank;
        this->fsrScore = fsrScore;
        this->fsrRank = fsrRank;
        this->cpfScore = cpfScore;
        this->cpfRank = cpfRank;
        this->ifrScore = ifrScore;
        this->ifrRank = ifrRank;
        this->isrScore = isrScore;
        this->isrRank = isrRank;
        this->irnScore = irnScore;
        this->irnRank = irnRank;
        this->gerScore = gerScore;
        this->gerRank = gerRank;
        this->scoreScaled = scoreScaled;
    }

    string toString()
    {
        int count = 0;
        int institutionWidth = 100;
        stringstream ss;
        for (char c : this->institution)
        {
            if (static_cast<unsigned char>(c) > 127)
            { 
                char first = c;           // check if character is non-ASCII
                count++; // add 1 to width for special character
            }
            // if(static_cast<unsigned char>(c) == 150 ) //  - is 3 byte
            // {
            //     count++;
            // }
        }
        institutionWidth = institutionWidth + count / 2;
        ss << this->rank << "\t" << left << setw(institutionWidth) << this->institution << left << setw(15) << this->location;
        return ss.str();
    }

};
// }

//     else if (displayType == "university")
//     {
//         ss << left << setw(institutuionWidth) << this->institution << this->rank << "\t" << this->location;
//         return ss.str();
//     }

//     else
//         cout << "Invalid displayType" << endl;
//     return NULL;
// }
//     }
// };
#endif // DYANAMIC_ARRAY_H