//include header files
#include <iostream>
#include "d_except.h"

using namespace std;

//begin simulated stack using vector
//default constructor
template<class DataType>
miniStackVT<DataType>::miniStackVT()
{
    elementCount = 0;   //sets number of elements to 0
}

//destructor
template<class DataType>
miniStackVT<DataType>::~miniStackVT()
{
}

//returns integer value of how many elements are in the stack
template<class DataType>
int miniStackVT<DataType>::size() const
{
    return content.size();      //return size of vector
}

//returns boolean value determining if stack is empty or not
template<class DataType>
bool miniStackVT<DataType>::IsEmpty() const
{
    return content.empty();     //return true if stack is empty and false if not empty
}

//adds new elements to top of stack
template<class DataType>
void miniStackVT<DataType>::Push(const DataType& value)
{
    content.push_back(value);       //pushs new value to back of vector
    elementCount++;         //increments elementCount
}

//prints all values in the stack from top to bottom
template<class DataType>
void miniStackVT<DataType>::PrintStack()const
{
    for(int i = (elementCount-1); i>=0; i--)
    {
        cout << content[i] << "   " << endl;
    }

    cout << endl;
}

//removes element from top of stack
template<class DataType>
void miniStackVT<DataType>::Pop()
{
    //if the stack is empty throw an exception
    if(content.empty())
    {
        throw underflowError("Attempt to pop from an empty stack");
    }
    else
    {
        content.pop_back();     //remove element from back of vector
        elementCount--;     //decrement elementCount
    }
}

//displays top element in stack
template<class DataType>
DataType& miniStackVT<DataType>::TopStack()
{
    //if the stack is empty throw an exception
    if(content.empty())
    {
        throw underflowError("Attempt to read from an empty stack");
    }

    return content.back();  //return value at the back of the vector
}


//begin simulated stack using list
//default constructor
template<class DataType>
miniStackLT<DataType>::miniStackLT()
{
    elementCount =0;    //sets number of elements to 0
}

//destructor
template<class DataType>
miniStackLT<DataType>::~miniStackLT()
{
}

//returns integer value of how many elements are in the stack
template<class DataType>
int miniStackLT<DataType>::size() const
{
    return content.size();      //return size of vector
}

//returns boolean value determining if stack is empty or not
template<class DataType>
bool miniStackLT<DataType>::IsEmpty() const
{
    return content.empty();     //return true if stack is empty and false if not empty
}

//adds new elements to top of stack
template<class DataType>
void miniStackLT<DataType>::Push(const DataType &value)
{
    content.push_back(value);       //pushs new value to back of vector
    elementCount++;         //increments elementCount
}

//prints all values in the stack from top to bottom
template<class DataType>
void miniStackLT<DataType>::PrintStack()const
{
    for(typename list<DataType>::const_reverse_iterator it = content.crbegin(); it != content.crend(); ++it)
    {
        cout << *it << "   " << endl;
    }

    cout << endl;
}

//removes element from top of stack
template<class DataType>
void miniStackLT<DataType>::Pop()
{
    //if the stack is empty throw an exception
    if(content.empty())
    {
        throw underflowError("Attempt to pop from an empty stack");
    }
    else
    {
        content.pop_back();     //remove element from back of vector
        elementCount--;     //decrement elementCount
    }
}

//displays top element in stack
template<class DataType>
DataType& miniStackLT<DataType>::TopStack()
{
    //if the stack is empty throw an exception
    if(content.empty())
    {
        throw underflowError("Attempt to read from an empty stack");
    }

    return content.back();      //return value at the back of the vector
}


//begin simulated stack using dynamic array
//default constructor
template<class DataType>
miniStackDA<DataType>::miniStackDA()
{
    elementCount = 0;       //set element count to 0
    elementCapacity =0;     //set element capacity to 0
}

//destructor
template<class DataType>
miniStackDA<DataType>::~miniStackDA()
{
    //deallocate memory if any was allocated in the first place
    if(elementCapacity > 0)
    {
        delete[] content;
    }
}

//returns integer value of how many elements are in the stack
template<class DataType>
int miniStackDA<DataType>::size() const
{
    return elementCount;    //return size of vector
}

//returns boolean value determining if stack is empty or not
template<class DataType>
bool miniStackDA<DataType>::IsEmpty() const
{
    //return true if stack is empty and false if not empty
    if(elementCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//adds new elements to top of stack
template<class DataType>
void miniStackDA<DataType>::Push(const DataType &value)
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

    content[elementCount] = value;      //assign new value to last element in the array
    elementCount++;       //increment elementCount by 1
}

//prints all values in the stack from top to bottom
template<class DataType>
void miniStackDA<DataType>::PrintStack()const
{
    for(int i = (elementCount-1); i>=0; i--)
    {
        cout << content[i] << "   " << endl;
    }

    cout << endl;
}

//removes element from top of stack
template<class DataType>
void miniStackDA<DataType>::Pop()
{
    ////if there are elements in the array
    //then decrement the array
    if(elementCount != 0)
    {
        elementCount--;
    }
    else
    {
        throw underflowError("Cannot pop from empty stack");    //throw exception if array is empty
    }
}

//displays top element in stack
template<class DataType>
DataType& miniStackDA<DataType>::TopStack()
{
    //if the stack is empty throw an exception
    if(elementCount == 0)
    {
        throw underflowError("Cannot read from empty stack");
    }
    return content[elementCount-1];     //return value of the last element of the array
}

