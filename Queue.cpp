// Queue.cpp

// Honor Pledge:
//
// I pledge that I have neither given nor received any help 
// on this assignment.

//
//Queue
//
template <typename T>
Queue <T>::Queue (void):
	array_()
{

}

//
// Queue
//
template <typename T>
Queue <T>::Queue (const Queue <T> & q):
	array_(q->array_)
{

}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void)
{
	
}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue (T element)
{
  // COMMENT The queue will fail if the array runs out of space. Since this
  // is an unboudned queue, you need to resize the array to make space for
  // new elements. Also, make sure you do not waste any space if you must
  // resize the array to accommodate new elements. This will require updates
  // to your dequeue method.
  //
  // CHANGE resize queue if the array is filled to its max
  
	 if (this->array_.size() == this->array_.max_size()){
		size_t new_size = this->array_.max_size() + 1;
		this->array_.resize(new_size);
	}
	this->array_.set(element, this->array_.size());
}

//
// dequeue
//
template <typename T>
T Queue <T>::dequeue (void)
{
	if (is_empty()){
		throw empty_exception("Dequeue : queue is empty");
	}
	
  // COMMENT This design is OK, but it is not the best design. This will be
  // a very expensive array to use if you are dequeing a lot of elements. This
  // is because you are copying N elements each time you dequeue 1 element.
  // Instead, you only want to copy element when necessary. Come up with a better
  // design that is not as expensive for the client to use.
  //
  // CHANGE instead of copying each element I save the top element, reverse the array
  // resize to remove the last element (which was the top) then reverse again.
  
	else{
		T top = this->array_[0];	
		this->array_.reverse();
		size_t new_size = this->array_.size() - 1;
		this->array_.resize(new_size);
		this->array_.reverse();
		return top;
	}	
}

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue <T> & rhs)
{
  // COMMENT Check for self assignment.
  //
  // CHANGE checked for self assignment.
	if (this == rhs){
		return *this;
	}
	else {
		this->array_ = rhs->array_;
		return *this;
	}
}

//
// clear
// 
template <typename T>
void Queue <T>::clear (void)
{
	if(is_empty()){
		//do nothing
	}

	else{
		this->array_.resize(0);
	}
	
} 
