// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void):
	Array_Base<T>(N)
{

}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr):
	Array_Base<T>(arr)
{

}

//
// Fixed_Array
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr):
	Array_Base<T>(arr)
{
	this->cur_size_ = M;
	this->max_size_ = M;
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill):
	Array_Base <T>(N, fill)
{
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	if (this == rhs){
		return *this;
	}
	else{
		this = rhs;
		return *this;
	}	
}

//
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
	this = rhs;
	this->cur_size_ = rhs->cur_size_;
	this->max_size_ = rhs->max_size_;
	
	return *this;
}
