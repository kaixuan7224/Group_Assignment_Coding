#ifndef DOUBLY_LINKED_LIST_COLLECTION_H
#define DOUBLY_LINKED_LIST_COLLECTION_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

template <class T> // abstract type 
class DoublyNode
{
public:
    T data;
    DoublyNode<T> *prev;
    DoublyNode<T> *next;
    DoublyNode(T data)
    {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

template <class T>
class DoublyLinkedList
{
private:
    DoublyNode<T> *head;
    DoublyNode<T> *tail;
    int size;

public:
    DoublyLinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    ~DoublyLinkedList() {
        while (head != nullptr) {
            DoublyNode<T>* temp = head;
            head = head->next;
            delete temp;
        }
        cout <<"Linklist has been deconstructed" << endl;
        tail = nullptr;
        size = 0;
    }

    void insertAtBegining(T data) {
         DoublyNode<T> *newNode = new DoublyNode<T>(data); 
         if (head == NULL) {
            head = tail = newNode;
        } else {
            head->prev =  newNode;
            newNode->next = head;
            head =  newNode;
        }
    }

    void insertAtEnd(T data){
        DoublyNode<T> *newNode = new DoublyNode<T>(data);
         if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next =  newNode;
            newNode->prev = tail;
            tail =  newNode;
        }
        size++;
    }

    void displayForward() {
        DoublyNode<T>* current = head;
        while (current != NULL) {
            cout << current->data.toString() << endl;
            current = current->next;
        }
    }

    int getSize() {
        return size;
    }


    DoublyNode<T>* getHead() {
        return head;
    }

    DoublyNode<T>* getTail() {
        return tail;
    }
    void DeleteLastNode(){
    if (tail == NULL) {
        cout<<"Empty list, no node to be deleted";
    }else {
        DoublyNode<T> * current = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(current);
    }

    
}
};

class UniversityNode
{
public:
    int rank;
    string institution, locationCode, location, arRank, 
           erRank, fsrRank,cpfRank, ifrRank, isrRank,
           irnRank, gerRank, scoreScaled;
    float arScore, erScore, fsrScore, cpfScore, ifrScore, 
          isrScore, irnScore, gerScore;

    UniversityNode(){}

    UniversityNode (int rank, string institution, string locationCode, string location,
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

    string toString() {
        stringstream ss;
        ss << "Rank: " << this->rank << "\tUniversity Name: " << this->institution << "\tLocation: " << this->location;
        return ss.str();


}
};

// Customer class
class Customer {
public:
string name,contactNumber,password,gender;

Customer() {}

Customer(string name,string password,string contactNo, string gender) {
    this->name = name;
    this->password = password;
    this->contactNumber = contactNo;
    this->gender = gender;
}

 string toString() {
        stringstream ss;
        ss << "Name: " << this->name << "\tContact Number: " << this->contactNumber << "\tGender: " << this->gender;
        return ss.str();
}
};


#endif // DOUBLY_LINKED_LIST_COLLECTION_H