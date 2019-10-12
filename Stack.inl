// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
	if (this->is_empty()){
		empty_exception e("Top: Stack is empty");
		throw e; 
	}

	else {
		size_t top = this->size() - 1;
		return this->array_[top];
	}
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	if(0 == this->size()){
		return true;
	}
	
	else{
		return false;
	}
}

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return this->array_.size();
}

