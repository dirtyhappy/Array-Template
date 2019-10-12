   // -*- C++ -*-
// $Id: Stack.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_STACK_H_
#define _CS507_STACK_H_

#include "Array.h"
#include <exception>
// COMMENT You should use aggregation instead of inheritance since logically a
// stack is not an array.
//
//CHANGE Instead of inheriting from the Array_Base <T> class I added a memeber variable array_ which 
//is an instance of the Array <T> class.
/**
 * @class Stack
 *
 * Basic stack for abitrary elements.
 */
template <typename T>
class Stack 
{
public:
  /// Type definition of the type.
  typedef T type;

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the stack is empty.
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
     * @param[in]      msg         Error message.
     */
    empty_exception (const char * msg)
      : msg_(msg) { }
	virtual const char* what() const throw (){
		return this->msg_;
	}

  protected:
	const char * msg_;
  };
	

  /// Default constructor.
  Stack (void);

  /// Copy constructor.
  Stack (const Stack <T> & s);

  /// Destructor.
  ~Stack (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Stack & operator = (const Stack <T> & rhs);

  /**
   * Push a new \a element onto the stack. The element is inserted
   * before all the other elements in the list.
   *
   * @param[in]      element       Element to add to the list
   */
  void push (T element);

  /**
   * Remove the top-most element from the stack.
   *
   * @exception      empty_exception    The stack is empty.
   */
  void pop (void);

  /**
   * Get the top-most element on the stack. If there are no element 
   * on the stack, then the stack_is_empty exception is thrown.
   *
   * @return         Element on top of the stack.
   * @exception      empty_exception    The stack is empty
   */
  T top (void) const;

  /**
   * Test if the stack is empty
   *
   * @retval         true          The stack is empty
   * @retval         false         The stack is not empty
   */
  bool is_empty (void) const;

  /// Remove all elements from the stack.
  void clear (void);

  //Return the size of the stack.
  size_t size(void) const;

private:
  // add member variable here
  //
  Array <T> array_; 

};

// include the inline files
#include "Stack.inl"

// include the source file since template class
#include "Stack.cpp"

#endif  // !defined _CS507_STACK_H_
