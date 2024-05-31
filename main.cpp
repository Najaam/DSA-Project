#include <iostream>
#include "my_library.h"
using namespace MyLibrary;

int main(){
LinkedList<int> intList;
    intList.insertAtBeginning(10);
    intList.insertAtEnd(20);
    intList.insertAtPosition(15, 1);
    intList.insertAtPosition(5, 0);
    intList.insertAtPosition(25, 4); 
    intList.writeToFile("linked_list.txt");

LinkedList<string> stringList;
    stringList.insertAtBeginning("hello");
    stringList.insertAtEnd("world");
    stringList.insertAtPosition("middle", 1);

    cout << "String List:" << endl;
    stringList.writeToFile("linked_list.txt");
    stringList.readFromFile("linked_list.txt");

   

}

