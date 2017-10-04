#ifndef MINISTACK_H
#define MINISTACK_H

#include <vector>
#include<list>

using namespace std;

template<class DataType>
class miniStackVT
{
private:
    vector<DataType> content;
    int elementCount;  // number of elements in the stack
public:
    miniStackVT();	// constructor create a stack with size	zero
    ~miniStackVT(); // destructor
    int size() const; //return the number of elements in the stack
    bool IsEmpty() const; // check empty stack
    void Push(const	DataType & ); // push a node in the stack
    void PrintStack()const;	//print	all stack content (TOP to BOTTOM)
    void Pop(); // Pop an element from the top of stack.
    // Issue exception if the stack is empty
    DataType& TopStack(); // Return Data from the top of the stack.
    // Issue exception if the stack is empty

};

template<class DataType>
class miniStackLT
{
private:
    list<DataType> content;
    int elementCount;  // number of elements in the stack
public:
    miniStackLT();	// constructor create a stack with size	zero
    ~miniStackLT(); // destructor
    int size() const; //return the number of elements in the stack
    bool IsEmpty() const; // check empty stack
    void Push(const	DataType & ); // push a node in the stack
    void PrintStack()const;	//print	all stack content (TOP to BOTTOM)
    void Pop(); // Pop an element from the top of stack.
    // Issue exception if the stack is empty
    DataType& TopStack(); // Return Data from the top of the stack.
    // Issue exception if the stack is empty

};

template<class DataType>
class miniStackDA
{
private:
    DataType *content;
    int elementCount;  // number of elements in the stack
    int elementCapacity;
public:
    miniStackDA();	// constructor create a stack with size	zero
    ~miniStackDA(); // destructor
    int size() const; //return the number of elements in the stack
    bool IsEmpty() const; // check empty stack
    void Push(const	DataType & ); // push a node in the stack
    void PrintStack()const;	//print	all stack content (TOP to BOTTOM)
    void Pop(); // Pop an element from the top of stack.
    // Issue exception if the stack is empty
    DataType& TopStack(); // Return Data from the top of the stack.
    // Issue exception if the stack is empty

};
#include "miniStack.cpp"
#endif
