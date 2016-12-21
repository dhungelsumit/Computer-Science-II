#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <stdexcept>//set of standard exceptions that both the library and programs can use to report common errors.

using namespace std;

struct Information {//structure to store information from file
    string FirstName;
    string LastName;
    double GPA;
    };


template <typename T>//definition of template
struct Node {
    T info;
    Node<T>* next;
    Node<T>* previous;
};

template <typename T>//definition of template
class DoublyLL{//doubly linked list
    public:
        DoublyLL();
        void insertelement(T element);
        void printelements();
        void reverseprint();
    private:
        Node<T>* head;
    };

template <typename T>//definition of template
DoublyLL<T>::DoublyLL(){
    head = NULL;
    }

template <typename T>//definition of template
void DoublyLL<T>::insertelement (T element){
    if (head==NULL)
    {
        Node<T> *newNode = new Node<T>;
        newNode->info = element;
        head = newNode;
        newNode->next = NULL;
        newNode->previous = NULL;

    }
    else
    {

        Node<T> *current;
        Node<T> *newNode = new Node<T>;
        newNode->info = element;
        current = head;
        while (current->next!=NULL)//looping until the last element of the list
        {
            current = current->next;
        }
        current->next = newNode;//inserting element after last list element
        newNode->next = NULL;
        newNode->previous = current;//pointing to the previous element
    }
}

template <typename T>
void DoublyLL<T>::printelements(){
    Node<T> *current;
    current = head;
    while (current!=NULL)//looping until the last element of the list
        {
            cout << setw(10) << current->info.LastName << "\t" <<current->info.FirstName << "\t\t" << current->info.GPA << endl;
            current = current->next;
        }
}

template <typename T>
void DoublyLL<T>::reverseprint(){
    Node<T> *current;
    current = head;
    while (current->next!=NULL)//looping until the last element of the list
        {
           current = current->next;
        }

    while (current!=NULL)
        {
            cout << setw(10) << current->info.LastName <<"\t"<<current->info.FirstName << "\t\t"<< current->info.GPA << endl;
            current = current->previous;
        }
}

int main(){
    DoublyLL<Information> LinkedList;
    Information element;
    ifstream myfile;
    myfile.open("infile.txt");
    for (int i=0; i<11; i++)
    {
        myfile >> element.LastName;
        myfile >> element.FirstName;
        myfile >> element.GPA;
        LinkedList.insertelement(element);
    }
    cout << "Ascending Order:\n" <<endl;
    cout << setw(10) << "Last Name" << "\t" <<"First Name"<<"\t"<<"GPA\n"<<endl;
    LinkedList.printelements();
    cout<<"\n"<<"..................................... \n"<<endl;
    cout << "Descending Order:\n" << endl;
    cout << setw(10) << "Last Name" << "\t" <<"First Name"<<"\t"<<"GPA\n"<<endl;
    LinkedList.reverseprint();
    return 0;
}
/*
Ascending Order:

 Last Name      First Name      GPA

   Herold,      Jill            0.3
  Jackson,      Stan            1
    Jerry,      Francis         1.67
     Joan,      Wilson          2
    Smith,      Stanley         2.17
   Claire,      Claude          2.4
Rodriguez,      San             2.89
 Robinson,      Mary            3.2
   Elliot,      Amelia          3.34
  Remeaux,      Sol             3.7
    Bacon,      Francis         4

.....................................

Descending Order:

 Last Name      First Name      GPA

    Bacon,      Francis         4
  Remeaux,      Sol             3.7
   Elliot,      Amelia          3.34
 Robinson,      Mary            3.2
Rodriguez,      San             2.89
   Claire,      Claude          2.4
    Smith,      Stanley         2.17
     Joan,      Wilson          2
    Jerry,      Francis         1.67
  Jackson,      Stan            1
   Herold,      Jill            0.3

Process returned 0 (0x0)   execution time : 0.047 s
Press any key to continue.
*/
