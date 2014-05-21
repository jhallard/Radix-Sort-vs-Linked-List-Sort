#ifndef LINKEDLISTSORT_H
#define LINKEDLISTSORT_H

/*
    @Author  - John Allard
    @Date    - March 19th, 2014
    @Purpose - This file contains a function that sorts a list of strings by building a linked list of those strings in sorted order.
      It basically goes linearly through the given list of unsorted strings and puts them into a linked list in sorted order. It then
      converts this linked list is to a vector of strings.
*/

#include <iostream>
#include <vector>
#include <string>


#include "Node.h"

/*
    --LinkedListSort--
    @Param container  - The container of strings to be sorted, an array of strings.
    @Param listlength - the length of the array of strings
    @Param count      - a reference variable that counts the number of operations performed by the function
    @Return           - returns a vector of strings in sorted order
*/
std::vector<std::string> LinkedListSort(std::string * container, int listLength, int & count)
{

    std::vector<std::string> sortedList;       // our final sorted list to be returned
    Node<std::string> * headPtr = nullptr;     // pointer to the head of the linked list
    Node<std::string> *temp, *previous, *current; // nodes that are used for inserting strings into the list

    // main loop that goes through and places the strings into the linked list in sorted order
    for(int i = 0; i < listLength; i++)
    {
        previous = nullptr;
        current = headPtr;

        // this while loop goes through the entire linked link to place the current word in the correct spot
        while(current != nullptr && (current->getItem().compare(container[i]) < 0))
        {
            previous = current;
            current = current->getNext();
            count++;
        }

        // if we exited the loop it means that we found the proper place to put the current word
        temp = new Node<std::string>;
        temp->setItem(container[i]);

        if(previous == nullptr)
        {
            temp->setNext(headPtr);
            headPtr = temp;
        }
        else
        {
            temp->setNext(current);
            previous->setNext(temp);
        }

        temp = nullptr;
    }

    //copy the sorted strings over from the linked list to our vector of strings to be returned to the user
    Node<std::string> * hold = headPtr;
    for(int i = 0; i < listLength; i++)
    {
        sortedList.push_back(hold->getItem());
        hold = hold->getNext();
    }

    return sortedList;
}


#endif