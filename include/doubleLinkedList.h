#pragma once

/*! \class Double Linked List
    \brief A double linked list data structure
*/

#include "node.h"
using namespace std;

/*! Double Linked List class, inheriting from node.h and uses template*/
template<class G>
class DoubleLinkedList
{
private:
    int size; //!< Size of the list
public:
    shared_ptr<Node<G>> head; //!< Points to the list head
    shared_ptr<Node<G>> tail; //!< Points to the list tail
    DoubleLinkedList(); //!< Default constructor
    void printForwards(); //!< Traverses forwards
    void printBackwards(); //!< Traverses backwards
    void returnSize(); //!< Gets the size of the list and tells the user
    bool isEmpty(); //!< Checks if list is empty or contains elements
    G getData(Node<G>& gNode); //!< Tells user what the node's data is
    void pushToFront(Node<G>& gData); //!< Pushes new node to front
    void pushToBack(Node<G>& gData); //!< Pushes new node to back
    void pushBetweenNodes(Node<G>& gPrev, Node<G>& gData, Node<G>& gNext); //!< Pushes node between two nodes
    void popHead(); //!< Pops head off list
    void popTail(); //!< Pops tail off list
};

/*! Default constructor for the double linked list class*/
template<class G>
DoubleLinkedList<G>::DoubleLinkedList()
{
    size = 0; //!< Initialises list size to 0
    head = nullptr; //!< Head by default is a nullptr
    tail = nullptr; //!< Tail by default is a nullptr
    return;
}

/*! Implementation of forward traverse*/
template<class G>
void DoubleLinkedList<G>::printForwards()
{
    /*! Says if list is empty*/
    if (size == 0) {
        cout << "List is empty!" << endl;
        return;
    }

    shared_ptr<Node<G>> listTraverse = head; //!< New pointer that points to the head

    cout << "Here is your list forwards: " << endl; //!< Tells user the direction, for formatting

    /*! Outputs the data, moves to the next point, and continues until the tail, which would be pointing to null*/
    while (listTraverse != nullptr) {
        cout << listTraverse->data << endl; //!< Outputs data
        listTraverse = listTraverse->next; //!< Pointer now points to the next node
    }
}

/*! Implementation of backwards traverse*/
template<class G>
void DoubleLinkedList<G>::printBackwards()
{
    /*! Says if list is empty */
    if (size == 0) {
        cout << "List is empty" << endl;
        return;
    }

    shared_ptr<Node<G>> listTraverse = tail; //!< New pointer that points to the tail

    cout << "Here is your list backwards: " << endl; //!< Tells the direction for formatting

    /*! Outputs the data, moves to the previous point, and continues to the head which points to null*/
    while (listTraverse != nullptr) {
        cout << listTraverse->data << endl; //!< Outputs data
        listTraverse = listTraverse->previous; //!< Pointer now points to the previous node
    }
}

/*! Returns the size of the list*/
template<class G>
void DoubleLinkedList<G>::returnSize()
{
    cout << "The size of the list is: " << size << endl; //!< Outputs the list size
}

/*! Checks if the list is empty*/
template<class G>
bool DoubleLinkedList<G>::isEmpty()
{
    /*! If size = 0, the list is empty, therefore it returns as true*/
    if (size == 0) {
        cout << "List is empty!" << endl; //!< Outputs result
        return true; //!< Returns result
    }
    /*! If size != 0, there are nodes in the list, therefore it returns as false*/
    else {
        cout << "List is not empty!" << endl; //!< Outputs result
        return false; //!< Returns result
    }
}

/*! Gets the data and shows the user*/
template<class G>
G DoubleLinkedList<G>::getData(Node<G>& gData)
{
    cout << "The data for the selected node is: " << gData.data << endl; //!< Finds data of node and outputs it
    return gData.data; //!< Returns result
}

/*! Implementation of the push to front function*/
template<class G>
void DoubleLinkedList<G>::pushToFront(Node<G>& gData)
{
    shared_ptr<Node<G>> temp = shared_ptr<Node<G>>(new Node<G>()); //!< Creates a pointer to point to the old head

    /*! If the list is empty, the node will be both the head and tail*/
    if (size == 0) {

        head = shared_ptr<Node<G>>(new Node<G>(gData)); //!< New node to insert into the list, equal to head
        head->next = nullptr; //!< Points to null in the forwards direction
        head->previous = nullptr; //!< Points to null in the backwards direction
        tail = head; //!< Declares head to be equal to the tail
        size++; //!< Increases the list size by 1
    }
    /*! If the list is not empty, the new head will be placed on top of the old head*/
   else {
        temp = head; //!< Declared the pointer made to point to the new head to be equal to the old head
        head = shared_ptr<Node<G>>(new Node<G>(gData)); //!< New node to insert into the list, equal to new head
        temp->previous = head; //!< The old head points to the new head in the backwards direction
        head->next = temp; //!< Makes the new head point to the old head in the forwards direction
        head->previous = nullptr; //!< Ensures the backwards direction is null
        size++; //!< Increases the list size by 1
   }

}

/*! Implementation of the push to back function*/
template<class G>
void DoubleLinkedList<G>::pushToBack(Node<G>& gData)
{
    shared_ptr<Node<G>> temp = shared_ptr<Node<G>>(new Node<G>()); //!< Creates a pointer to point to the old tail

    /*! If the list is empty, the new node is both the head and tail*/
    if (size == 0) {
        tail = shared_ptr<Node<G>>(new Node<G>(gData)); //!< Makes the tail equal to the new node
        tail->next = nullptr; //!< Points to null in the forwards direction
        tail->previous = nullptr; //!< Points to null in the backwards direction
        head = tail; //!< Declares head to be equal to the new node
        size++; //!< Increases the size of the list by 1
    }
    /*! If the list contains nodes, the new node will be the new tail*/
    else {
        temp = tail; //!< temp is the old tail
        tail = shared_ptr<Node<G>>(new Node<G>(gData)); //!< The tail is now equal to the new tail
        temp->next = tail; //!< Makes the old tail point to the new tail
        tail->next = nullptr; //!< Tells the new tail to point to null in the forwards direction
        tail->previous = temp; //!< Makes sure the new tail points to the old tail in the backwards direction
        size++; //!< Increases the list size by 1
    }
}

/*! Implementation of the push between nodes function*/
template<class G>
void DoubleLinkedList<G>::pushBetweenNodes(Node<G>& gPrev, Node<G>& gData, Node<G>& gNext)
{
    shared_ptr<Node<G>> newNode = shared_ptr<Node<G>>(new Node<G>(gData)); //!< Pointer to point at the new node
    shared_ptr<Node<G>> prevNode = shared_ptr<Node<G>>(new Node<G>(gPrev)); //!< Pointer to point to the previous node
    shared_ptr<Node<G>> nextNode = shared_ptr<Node<G>>(new Node<G>(gNext)); //!< Pointer to point to the next node
    
    if (prevNode = head) head = prevNode; //!< Initialising previous node
    if (nextNode = tail) tail = nextNode; //!< Initialising next node

    prevNode->next = newNode; //!< Ensures the previous node points to the new node in the forwards direction
    newNode->previous = prevNode; //!< Ensures the new node points to the previous node in the backwards direction
    newNode->next = nextNode; //!< Ensures the new node points to the next node in the forwards direction
    nextNode->previous = newNode; //!< Ensures the next node points to the new node in the backwards direction
    
    size++;  //!< Increases the size by 1
}

/*! Implementation of the pop head function*/
template<class G>
void DoubleLinkedList<G>::popHead()
{
    shared_ptr<Node<G>> temp = head; //!< Pointer that is the head
    head = head->next; //!< Current head is now equal to the next node
    temp->next = nullptr; //!< Stops the old head pointing to anything in the forwards direction
    temp->previous = nullptr; //!< Causes the pointer to go out of scope as it now doesn't point to anything
    head->previous = nullptr; //!< Ensures the backwards direction points to null
    size--; //!< Reduce the list size by 1
}

/*! Implementation of the pop tail function*/
template<class G>
void DoubleLinkedList<G>::popTail()
{
    shared_ptr<Node<G>> temp = tail;
    tail = tail->previous; //!< Current tail is now equal to the previous node
    temp->next = nullptr; //!< Stops the old tail pointing to anything in the forwards direction
    temp->previous = nullptr; //!< Causes the pointer to go out of scope as it now doesn't point to anything
    tail->next = nullptr;
    size--; //!< Reduces the list size by 1
}
