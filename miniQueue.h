#ifndef MINIQUEUE_H
#define MINIQUEUE_H

#include <vector>
#include<list>

using namespace std;

template<class DataType>
class miniQueueVT
{
private:
    vector<DataType> content;
    int elementCount; // element count in a Queue
public:
    miniQueueVT(); //class constructor – queue size set to zero
    ~miniQueueVT();	//class destructor - return memory used by queue elements
    void enqueue(const DataType &); //add an item to the back of the queue
    void dequeue(); //remove the first item from the queue and return its value
    // Issue exception if the queue is empty
    DataType& front(); //return the value of the front	item in the queue
    // Issue exception if the queue is empty
    void PrintQueue()const;	// print all queue content (front to back)
    bool IsEmpty()const; //returns true if there are no elements in the queue
    int size()const; //return the number of elements in the queue

};

template<class DataType>
class miniQueueLT
{
private:
    list<DataType> content;
    int elementCount; // element count in a Queue
public:
    miniQueueLT(); //class constructor – queue size set to zero
    ~miniQueueLT();	//class destructor - return memory used by queue elements
    void enqueue(const DataType &); //add an item to the back of the queue
    void dequeue(); //remove the first item from the queue and return its value
    // Issue exception if the queue is empty
    DataType& front(); //return the value of the front	item in the queue
    // Issue exception if the queue is empty
    void PrintQueue()const;	// print all queue content (front to back)
    bool IsEmpty()const; //returns true if there are no elements in the queue
    int size()const; //return the number of elements in the queue

};

template<class DataType>
class miniQueueDA
{
private:
    DataType *content;
    int elementCount; // element count in a Queue
    int elementCapacity;
public:
    miniQueueDA(); //class constructor – queue size set to zero
    ~miniQueueDA();	//class destructor - return memory used by queue elements
    void enqueue(const DataType &); //add an item to the back of the queue
    void dequeue(); //remove the first item from the queue and return its value
    // Issue exception if the queue is empty
    DataType& front(); //return the value of the front	item in the queue
    // Issue exception if the queue is empty
    void PrintQueue()const;	// print all queue content (front to back)
    bool IsEmpty()const; //returns true if there are no elements in the queue
    int size()const; //return the number of elements in the queue

};
#include "miniQueue.cpp"
#endif
