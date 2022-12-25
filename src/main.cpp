/**
@file main.cpp
*/


/*! \mainpage Lab Book 3
 *
 * Implementation of a Double Linked List
 */

// Define and includes to show memory leak report
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

#include <iostream>
#include "doubleLinkedList.h"

using namespace std;

/*! Entry point for the application. I have added a series of tests to prove this is working. */
int main() 
{
	/*! Initialisation*/
	DoubleLinkedList<string> myList; //!< Create list
	myList.isEmpty();//!< Check if list is empty

	/*! Creation of the nodes and adding data*/
	Node<string> myNode1; //!< Node 1
	Node<string> myNode2; //!< Node 2
	Node<string> myNode3; //!< Node 3
	myNode1.addData("head node"); //!< Add data to node 1
	myNode2.addData("tail node"); //!< Add data to node 2
	myNode3.addData("middle node"); //!< Add data to node 3
	cout << endl; // Formatting

	/*! Pushes node 1 to the front and outputs it's data*/
	myList.pushToFront(myNode1); //!< Pushes node 1 to front
	myList.isEmpty(); //!< Check if the list is empty anymore
	myList.getData(myNode1); //!< Outputs the data of node 1
	cout << endl; // Formatting

	/*! Pushes node 2 to the back and outputs it's data*/
	myList.pushToBack(myNode2); //!< Pushes node 2 to the back
	myList.returnSize(); //!< Outputs the size of the list
	myList.getData(myNode2); //!< Outputs the data of node 2
	cout << endl; // Formatting

	/*! Traverses the list*/
	myList.printForwards(); //!< Traverses backwards
	cout << endl; // Formatting
	myList.printBackwards(); //!< Traverses forwards
	cout << endl; // Formatting

	/*! Pushes between the two nodes then traverses backwards */
	myList.pushBetweenNodes(myNode1, myNode3, myNode2); //!< Pushes node 3 into the middle
	myList.getData(myNode3); //!< Outputs the data
	myList.printBackwards(); //!< Traverses backwards
	cout << endl; //!< Formatting

	/*! Removes the head, traverses again and returns the size to prove it's working*/
	myList.popHead(); //!< Removes the head
	myList.printForwards(); //!< Traverses forwards
	myList.returnSize(); //!< Outputs the new list size
	cout << endl; // Formatting

	/*! Reattaches the head, removes the tail then returns the size before traversing forwards*/
	myList.pushToFront(myNode1); //!< Pushes node 1 back to the front
	myList.popTail(); //!< Removes tail
	myList.returnSize(); //!< Returns the new size of the list to show it has changed
	myList.printForwards(); //!< Traverses forwards
	
	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
}