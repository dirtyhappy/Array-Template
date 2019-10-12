	// -*- C++ -*-
	//
// Honor Pledge:
//
// I pledge that I neither given nor received any help
// on this assignment.

#ifndef QUEUE_H_
#define QUEUE_H_

#include "Array.h"
#include <exception>

// COMMENT You should use aggregation instead of inheritance since logically
// a queue is not an array. You are also violating LSP with this design.
//
// CHANGE Instead of inheriting from Array_Base <T> class I added an instance
// of the Array <T> class as member variable array_


/**
 * @class Queue
 *
 * Basic queue for arbitrary elements
 */
template <typename T>
class Queue  
{
public:
	/// type definition of the type.
	typedef T type;

	/**
	 * @class empty_exception
	 *
	 * Exception thrown to indicate the queue is empty.
	 */
	class empty_exception : public std::exception
	{
	public:
	/// Default constructor.
	empty_exception (void)
		: std::exception () { }

	/**
	 * Initializing constructor.
	 * 
	 * @param	msg		Error message.
	 */
	empty_exception (const char * msg)
		: std::exception (msg) { }
	};

	/// Default constructor.
	Queue (void);

	/// Copy constructor.
	Queue (const Queue <T> & q);

	/// Destructor.
	~Queue (void);
	
	/**
	 * Assignment operator
	 *
	 * @param[in]		rhs			Right-hand side of operator
	 * @return			Reference to self
	 */
	const Queue & operator = (const Queue <T> & rhs);

	/**
	 * Add element to end of the queue.
	 *
	 * @param[in]		element		Element to add to the queue.
	 */
	void enqueue (T element);

	/**
	 * Remove element at front of the list and returns the element.
	 * If there are no elements on the queue, then empty_exception is thrown.
	 *
	 * @return			Element at beginning of the queue.
	 * @exception		empty_exception		The queue is empty.
	 */
	T  dequeue (void);

	/**
	 * Test if queue is empty.
	 *
	 * @retval		true		The queue is empty
	 * @retval		false		The queue is not empty
	 */
	bool is_empty (void) const;

	
	///Remove all elements fron the queue.
	void clear (void);

	//Return Size of the Queue.
	void size (void) const;

private:
	// add member variables here
	//
	Array <T> array_;

};

// include the inline files
#include "Queue.inl"

// include the source files since template class
#include "Queue.cpp"

#endif	// !defined QUEUE_H_
