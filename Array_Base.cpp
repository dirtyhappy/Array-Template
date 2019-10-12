// Array_Base.cpp
//
// Honot Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array_Base.h"
#include <stdexcept>  //for std::out_of_range

#define DEFAULT_SIZE 10

//-----------------------------------------------------------------------------
//
// Array_Base
//
template <typename T>
Array_Base <T>::Array_Base (void):
	data_(new T[DEFAULT_SIZE]),
	cur_size_(0),
	max_size_(DEFAULT_SIZE)

{

}

//-----------------------------------------------------------------------------
//
// Array_Base(size_t)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length):
	data_(nullptr),
	cur_size_(0),
	max_size_(0)
{
	size_t size = (length > 0) ? length : DEFAULT_SIZE;

	this->data_ = new T[size]; 
	this->max_size_ = size;
}

//-----------------------------------------------------------------------------
//
// Array_Base (size_t length, T fill)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill):
	data_(nullptr),
	cur_size_(0),
	max_size_(0)
{
	size_t size = (length > 0) ?  length : DEFAULT_SIZE;

	this->data_ = new T[size];
//	this->cur_size_= size;
	this->max_size_ = size;
	
	this->fill(fill);
}

//-----------------------------------------------------------------------------
//
// Array_Base (const Array & arr)
//
template <typename T>
Array_Base <T>::Array_Base (const Array_Base <T> & arr):
	data_(nullptr),
	cur_size_(0),
	max_size_(0)
{
	this->cur_size_ = arr.cur_size_;
	this->max_size_ = arr.max_size_;

	//allocate memory for data_
	this->data_ = new T[arr.max_size_];
	memcpy (this->data_, arr.data_, (sizeof(arr.data_[0]) * this->cur_size_));
	
}


//-----------------------------------------------------------------------------
//
// ~Array_Base
//
template <typename T>
Array_Base <T>::~Array_Base(void)
{
	if (nullptr != this->data_)
	{
		delete [] this->data_;
	}
}

//-----------------------------------------------------------------------------
//
// operator = 
//
template <typename T>
const Array_Base <T> & Array_Base <T>::operator = (const Array_Base <T>  & rhs)
{
	if (this == &rhs){
		return *this;
	}

	else if (rhs.cur_size_ > max_size_){
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
// operator [] 
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
	if (index >= this->cur_size_){
		throw std::out_of_range("[] operator: Out of Range");
	}

	else {
		return this->data_[index];
	}
} 

//-----------------------------------------------------------------------------
//
// operator []
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
	if (index >= this->cur_size_){
		throw std::out_of_range("[] operator: Out of Range");
	}

	else {
		return this->data_[index];
	}
	
}

//-----------------------------------------------------------------------------
//
// get
//
template <typename T>
T Array_Base <T>::get (size_t index) const
{
	if (index >= this->cur_size_){
		throw std::out_of_range("[] operator: Out of Range");
	}

	else {
		return this->data_[index];
	}
	
}

//-----------------------------------------------------------------------------
//
// set
//
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
	if (index >= this->max_size_){
		throw std::out_of_range("Set : Out of Range");
	}

	else if (index >= this->cur_size_) {
		this->cur_size_ = index + 1;
	}
	this->data_[index] = value;
}

//-----------------------------------------------------------------------------
//
// find
//
template <typename T>
int Array_Base <T>::find (T element) const
{
	return this->find(element, 0);	
}


//-----------------------------------------------------------------------------
//
// find (char, size_t)
//
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
	if (start >= this->cur_size_){
		throw std::out_of_range("Find : Out of Range");
	}	

	else{
		for(size_t i = 0; i < this->cur_size_; ++i){
			if(this->data_[i] == val){
				return i;
			}
		}

		return -1;
	}

}


//-----------------------------------------------------------------------------
//
// operator ==
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base <T> & rhs) const
{
	if (&rhs == this){
		return true;
	}
	else if(this->max_size_ == rhs.max_size_){
		if (this->cur_size_ == rhs.cur_size_){
			for (size_t i = 0; i < cur_size_; ++i){
				if (this->data_[i] != rhs.data_[i]){
					return false;
				}
			}
			return true;
		}
		
		else{
			return false;
		}
	}		
	
	else{
		return false;
	}
	
}

//-----------------------------------------------------------------------------
//
// operator !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base <T> & rhs) const
{
	if (this->operator== (rhs)){
		return false;
	}

	else{
		return true;
	}
}

//-----------------------------------------------------------------------------
//
// fill
//
template <typename T>
void Array_Base <T>::fill (T element)
{
	for(size_t i = 0; i < max_size_; ++i){
		this->data_[i] = element;
	}
	this->cur_size_ = this->max_size_;
	
}

//-----------------------------------------------------------------------------
//
// slice
//
template <typename T>
Array_Base <T> Array_Base <T>::slice (size_t begin) const
{
	if (begin > cur_size_){
		throw std::out_of_range("Slice : Out of Range");
	}

	else{
		Array_Base <T> slice_array {(cur_size_ - begin)};
		for (size_t i = begin; i < cur_size_; ++i){
			size_t index  = i - begin;
			slice_array.set(index,data_[i]); 
		}
		return slice_array;
	}
}

//-----------------------------------------------------------------------------
//
// slice overload
//
template <typename T>
Array_Base <T> Array_Base <T>::slice (size_t begin, size_t end) const
{
	if (end < begin) {
		throw std::out_of_range ("Slice : End larger than begin");

	}	
	
	else if (begin >= cur_size_ || end >= cur_size_){
		throw std::out_of_range ("Slice : Out of Range");
	}

	else {
		Array_Base slice_array (((end - begin) + 1));
		for (size_t i = begin; i <= end; ++i){
			size_t index = i - begin;
			slice_array[index] = data_[i];
		}
		return slice_array;
	}
}

//-----------------------------------------------------------------------------
//
// reverse
//
template <typename T>
void Array_Base <T>::reverse (void)
{
		size_t end = cur_size_ - 1;
		size_t start = 0;
		while (start <= end){
			T tmp = data_[start];
			data_[start++] = data_[end];
			data_[end--] = tmp;
			
		}
}

//-----------------------------------------------------------------------------
