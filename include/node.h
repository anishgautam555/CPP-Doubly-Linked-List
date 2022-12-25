#pragma once

#include <memory>
#include <iostream>
#include <fstream>

using namespace std;

/*! Node class using a template*/
template<class G>
class Node
{
public:
	G data; //!< Stores the data as a generic type
	shared_ptr<Node<G>> previous; //!< Pointer to point to previous node
	shared_ptr<Node<G>> next; //!< Pointer to point to next node
	Node(); //!< Default constructor
	void addData(G gData) { data = gData; } //!< Adds data to node
};

/*! Implementation of the default constructor*/
template<class G>
Node<G>::Node()
{
	previous = nullptr; //!< Defaults previous to be a nullptr
	next = nullptr; //!< Defaults next to be a nullptr
}
