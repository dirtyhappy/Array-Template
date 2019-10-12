// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//
template <typename T>
Stack <T>::Stack (void):
	array_()
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack <T> & stack):
	array_(stack.array_)
{

}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{	
	//resize the internal array if max elements has been reached
	if(this->array_.size() == this->array_.max_size()){
		this->array_.resize(this->array_.max_size() + 1);
	}
	//set the new element to end of the internal array
	this->array_.set(this->array_.size(),element);	
	
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
	if (this->is_empty()){
		throw empty_exception("Pop: Stack is empty");
	}
	else {
    // COMMENT You current design of the stack is copying each element
    // over on location each time your pop a new element from the stack.
    // Unfortunately, this is an expensive operation—--especially if you
    // have a large number of elements on the stack. Improve your design
    // so that you are not copying each element every time you pop a new
    // element from the stack.
    //
    //CHANGE instead of looking at the front of the internal array object in Stack
    //I look at the end of the array as the top 
    //(last element in array is first in stack)
    //which gets rid of need to shift elements down the array.

		//resize the array to one less element
		//which changes the cur_size_ of the internal array
		size_t new_size = this->array_.size() - 1;
		this->array_.resize(new_size); 
	}	
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack <T> & rhs)
{
  // COMMENT Check for self assignment.
  //
  //CHANGE Checked for self assignment.
  
	if (rhs == this){
		return *this;
	}
	else{
		this->array_ = rhs->array_;
		return *this;
	}
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
	this->array_.resize(0);
}
