// -*- C++ -*-
// Queue.inl

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment

//
// is_empty
//
template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
	if (0 == this->array_.size()){
		return true;
	}

	else{
		return false;
	}
}

//
// size
//
template <typename t>
inline
size_t Stack <T>::size (void) const
{
	return this->array_.size();
}
