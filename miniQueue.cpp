//include header files
#include <iostream>
#include "d_except.h"

using namespace std;

//begin simulated queue using vector
//default constructor
template<class DataType>
miniQueueVT<DataType>::miniQueueVT()
{
    elementCount = 0;   //sets number of elements to 0
}

//destructor
template<class DataType>
miniQueueVT<DataType>::~miniQueueVT()
{
}

//adds new elements to back of queue
template<class DataType>
void miniQueueVT<DataType>::enqueue(const DataType &value)
{
    content.push_back(value);   //pushes a value to end of vector
    elementCount++;     //increments number of elements by 1
}

//removes element from front of queue
template<class DataType>
void miniQueueVT<DataType>::dequeue()
{
    //if the queue is empty throw an exception
    if(content.empty())
    {
        throw underflowError("Attempt to pop from an empty stack");
    }
    else
    {
        cout << "The value being erased from the queue is " << content[0]<< endl;  //display value being popped
        content.erase(content.begin());     //erase element from beginning of vector
        elementCount--;     //decrement number of elements by 1
    }
}

//displays front element in queue
template<class DataType>
DataType& miniQueueVT<DataType>::front()
{
    //if the queue is empty throw an exception
    if(content.empty())
    {
        throw underflowError("Attempt to read from an empty stack");
    }

    return content.front();     //return front value
}

//prints all values in the queue from front to back
template<class DataType>
void miniQueueVT<DataType>::PrintQueue()const
{
    //write all values in queue
    for(int i =0; i<elementCount; i++)
    {
        cout << content[i] << "   " << endl;
    }

    cout << endl;
}

//returns boolean value determining if queue is empty or not
template<class DataType>
bool miniQueueVT<DataType>::IsEmpty()const
{
    return content.empty();     //return true if queue is empty and false if not empty
}

//returns integer value of how many elements are in the queue
template<class DataType>
int miniQueueVT<DataType>::size()const
{
    return content.size();  //return size of vector
}


//begin simulated queue using list
//default constructor
template<class DataType>
miniQueueLT<DataType>::miniQueueLT()
{
    elementCount=0;     //sets number of elements to 0
}

//destructor
template<class DataType>
miniQueueLT<DataType>::~miniQueueLT()
{
}

//adds new elements to back of queue
template<class DataType>
void miniQueueLT<DataType>::enqueue(const DataType &value)
{
    content.push_back(value);   //pushes a value to end of list
    elementCount++;     //increments number of elements by 1
}

//removes element from front of queue
template<class DataType>
void miniQueueLT<DataType>::dequeue()
{
    //if the queue is empty throw an exception
    if(content.empty())
    {
        throw underflowError("Attempt to pop from an empty queue");
    }
    else
    {
        typename list<DataType>::iterator it = content.begin();     //declare begin iterator
        cout << "The value being erased from the queue is " << *it<< endl;     //display value being popped
        content.erase(content.begin());     //erase element from beginning of list
        elementCount--;         //decrement number of elements by 1
    }
}

//displays front element in queue
template<class DataType>
DataType& miniQueueLT<DataType>::front()
{
    //if the queue is empty throw an exception
    if(content.empty())
    {
        throw underflowError("Attempt to read from an empty stack");
    }

    return content.front();     //return front value
}

//prints all values in the queue from front to back
template<class DataType>
void miniQueueLT<DataType>::PrintQueue()const
{
    //write all values in queue
    for(typename list<DataType>::const_iterator it = content.cbegin(); it != content.cend(); it++)
    {
        cout << *it << "   " << endl;
    }

    cout << endl;
}

//returns boolean value determining if queue is empty or not
template<class DataType>
bool miniQueueLT<DataType>::IsEmpty()const
{
    return content.empty();     //return true if queue is empty and false if not empty
}

//returns integer value of how many elements are in the queue
template<class DataType>
int miniQueueLT<DataType>::size()const
{
    return content.size();      //return size of list
}


//begin simulated queue using dynamic array
//default constructor
template<class DataType>
miniQueueDA<DataType>::miniQueueDA()
{
    elementCount =0;    //sets number of elements to 0
    elementCapacity = 0;    //sets capacity of elements to 0
}

//destructor
template<class DataType>
miniQueueDA<DataType>::~miniQueueDA()
{
    //deallocate memory if any was allocated in the first place
    if(elementCapacity > 0)
    {
        delete[] content;
    }
}

//adds new elements to back of queue
template<class DataType>
void miniQueueDA<DataType>::enqueue(const DataType &value)
{
    //if the elementCount and elementCapacity are both 0 then create a new, one element array
    if(elementCount == 0 && elementCapacity == 0)
    {
        content = new DataType[1];
        elementCapacity++;
    }
    //if the elementCount and elementCapacity are equal to each other
    //then create a new array double the size of the previous array
    else if(elementCount==elementCapacity)
    {
        elementCapacity=2*elementCapacity;
        DataType *temp = new DataType[elementCapacity];

        for(int i = 0; i<elementCount; i++)
        {
            temp[i]=content[i];
        }

        delete[] content;
        content = temp;
    }

    content[elementCount] = value;     //assign new value to last element in the array
    elementCount++;     //increment elementCount by 1
}

//removes element from front of queue
template<class DataType>
void miniQueueDA<DataType>::dequeue()
{
    //if there are elements in the array
    //then create new array starting with the previous array's second element
    if(elementCount != 0)
    {
        DataType *temp = new DataType[elementCapacity];

        for(int i=0; i<elementCount-1; i++)
        {
            temp[i]=content[i+1];
        }

        cout << "The value being erased from the queue is " << content[0]<< endl;
        delete[] content;
        content = temp;
        elementCount--;

    }
    else
    {
        throw underflowError("Cannot pop from empty queue");    //throw exception if array is empty
    }
}

//displays front element in queue
template<class DataType>
DataType& miniQueueDA<DataType>::front()
{
    //if the queue is empty throw an exception
    if(elementCount == 0)
    {
        throw underflowError("Cannot read from empty queue");
    }
    return content[0];  //return front value
}

//prints all values in the queue from front to back
template<class DataType>
void miniQueueDA<DataType>::PrintQueue()const
{
    //write all values in queue
    for(int i = 0; i<elementCount; i++)
    {
        cout << content[i] << "   " << endl;
    }

    cout << endl;
}

//returns boolean value determining if queue is empty or not
template<class DataType>
bool miniQueueDA<DataType>::IsEmpty()const
{
    //return true if queue is empty and false if not empty
    if(elementCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//returns integer value of how many elements are in the queue
template<class DataType>
int miniQueueDA<DataType>::size()const
{
    return elementCount;    //return number of elements
}

