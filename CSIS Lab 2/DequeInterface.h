#ifndef DEQUE_H
#define DEQUE_H

#include "Node.h"

/**
@Class    - DequeInterface
@Author   - John Allard
@Purpose  - This is an interface for a double ended queue, where the user can both put items into and take items out of both ends of a queue. 
@Template - ItemType – The type of value that the user wants to be stored and operated 	   	      upon in this deque.
**/

template <class ItemType>
class DequeInterface
{
public:

	
/**
	@Function - EnqueueFront
	@Purpose  - Put an item into the front of the queue
	@Param     - newNode  : The value that the user wants inserted into the front
	@Return    - boolean which indicates if the value was successfully enqueued
	@PreCond   - none, deque can be empty or filled.
	@PostCond  - The deque will be greater by size one, with the new member now in the 
			front of the queue
**/
	virtual bool enqueFront(const ItemType & newNode) = 0;

	/**
	@Function - EnqueueBack
	@Purpose  - Put an item into the back of the queue
	@Param     - newNode  : The value that the user wants inserted into the back
	@Return    - boolean which indicates if the value was successfully enqueued
	@PreCond   - none, deque can be empty or filled.
	@PostCond  - The deque will be greater by size one, with the new member now in the 
			back of the queue
**/
	virtual bool enqueBack(const ItemType & newNode)  = 0;


	
/**
	@Function - DequeueFront
	@Purpose  - Pull an item from the front of the queue
	@Return   - boolean which indicates if the value was successfully dequeued
	@PreCond  - Can only dequeue if deque is not empty, no errors are thrown
	@PostCond – If queue is non-empty before call, it will have 1 less node in its 
	            chain, taken from the front of the deque. If it is empty, this function 			will not change the deque.	
**/
	virtual bool dequeueFront()           = 0;

	/**
	@Function - DequeueBack
	@Purpose  - Pull an item from the back of the queue
	@Return    - boolean which indicates if the value was successfully dequeued
	@PreCond  - Can only dequeue if deque is not empty, no errors are thrown
	@PostCond – If queue is non-empty before call, it will have 1 less node in its 
	            chain, taken from the back of the deque. If it is empty, this function 			      will not change the deque.
**/
	virtual bool dequeueBack()            = 0;

/**
	@Function - PeakFront
	@Purpose  - See the item at the front of the queue without removing it
	@Return   - The value of the item at the front of the dequeue
	@Throws   - Precondition violation if the deque is empty.
	@Notice   - Function is constant, makes no changes to the deque.
**/
	virtual ItemType peekFront() const       = 0;

	/**
	@Function - PeakFront
	@Purpose  - See the item at the back of the queue without removing it
	@Return   - The value of the item at the back of the dequeue
	@Throws   - Precondition violation if the deque is empty.
	@Notice   - Function is constant, makes no changes to the deque.
**/
	virtual ItemType peekBack()  const       = 0;


	/**
	@Function - PeakFront
	@Purpose  - See the item at the back of the queue without removing it
	@Return   - Boolean corresponding to if the deque is empty.
	@Notice   - Function is constant, makes no changes to the deque.
**/
	virtual bool isEmpty() const          = 0;


};

#endif