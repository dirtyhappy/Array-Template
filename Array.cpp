// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"

//-----------------------------------------------------------------------------
//
// Array
//
template <typename T>
Array <T>::Array (void):
	Array_Base<T>()
{	
}

//-----------------------------------------------------------------------------
//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length):
	Array_Base<T>(length)
{
	
}

//-----------------------------------------------------------------------------
//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill):
	Array_Base<T>(length, fill)
{
	
}

//-----------------------------------------------------------------------------
//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array <T> & array):
	Array_Base<T>(array)
{

}

//-----------------------------------------------------------------------------
//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
}

//-----------------------------------------------------------------------------
//
// operator=
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array <T> & rhs)
{
	if (this == &rhs){
		return *this;
	}

	else if (rhs.cur_size_ > this->max_size_){
		delete [] this->data_;
		this->data_ = nullptr;

		this->data_ = new T[rhs.max_size_];
	}
	memcpy(this->data_, rhs.data_,(sizeof(rhs.data_[0]) * rhs.cur_size_));

	this->max_size_ = rhs.max_size_;
	this->cur_size_ = rhs.cur_size_;
	
	return *this;
}
//-----------------------------------------------------------------------------
//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
/*	if (new_size > this->max_size_){
	this->max_size_ = new_size;
		
		T * new_data = new T [new_size];
		
		for(size_t i = 0; i < this->cur_size_; ++i){
			new_data[i] = this->data_[i];
		}
		
		delete [] this->data_;
		this->data_ = new T[(*new_data)];
	}
*/		
	
	if (new_size > this->max_size_){
		Array <T> temp{new_size};
		memcpy(temp.data_, this->data_, (sizeof(this->data_[0]) * this->cur_size_));
		temp.cur_size_ = this->cur_size_;
		this->operator =(temp);	
	}

	else if (new_size < this->cur_size_){
		this->cur_size_ = new_size;
	}

	

}

//-----------------------------------------------------------------------------
//
// shrink
//
template <typename T>
void Array <T>::shrink (void)
{
	if (this->cur_size_ < this->max_size_){
		Array <T> temp {this->cur_size_};
		memcpy(temp.data_, this->data_, (sizeof(this->data_[0]) * this->cur_size_));
		temp.cur_size_ = this->cur_size_;
		this->operator =(temp);	
	}
}

//-----------------------------------------------------------------------------
