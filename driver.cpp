#include <stdio.h>
#include <assert.h>

//#include "Array_Base.h"
//#include "Array.h"
//#include "Fixed_Array.h"
#include "Stack.h"
//#include "Queue.h"

//Array Base Tests
void test_array_base_default_constructor(void)
{
	Array_Base <int> array;
	assert(array.size() == 0);
	assert(array.max_size() == 10);

}

void test_array_base_length_constructor(void)
{
	Array_Base <int> b_array{5};
	assert(b_array.size() == 0);
	assert(b_array.max_size() == 5);

	Array_Base <char> other_array{0};
	assert(other_array.size() == 0);
	assert(other_array.max_size() == 10);

}
void test_array_base_fill_constructor(void)
{
	Array_Base <char> array{5, 'a'};
	assert(array.size() == 5);
	assert(array.max_size() == 5);
	
	for (size_t i = 0; i < 5; ++i){	
		assert(array[i] == 'a');
	}	

	Array_Base <int> other_array{0, 8};
	assert(other_array.size() == 10);
	assert(other_array.max_size() == 10);
	
	for (size_t j = 0; j < 10; ++j)
	{	 assert(other_array[j] == 8);}
	

}

void test_array_base_copy_constructor(void) 
{
	Array_Base <int> array{5, 8};
	Array_Base <int> other_array{array};

	assert(other_array.size() == 5);
	assert(other_array.max_size() == 5);
	
	for (size_t i = 0; i < 5; ++i)
	{ 
		assert(8 == other_array[i]);
	  
	 }
}

void test_array_base_assignment_operator(void)
{
	Array_Base <char> other_array{10, 'b'};
	Array_Base <char> array;
	array = other_array;

	assert(array.size() == 10);
	assert(array.max_size() == 10);
	for (size_t i = 0; i < 10; ++i)
	{ assert('b' == array[i]); }
}

void test_array_base_get_operator_const(void)
{
	const Array_Base<int> array{10, 8};
	assert(8 == array[5]);
}

void test_array_base_get(void)
{
	Array_Base <char> array{10, 'b'};
	assert('b' == array.get(5));
}
void test_array_base_set(void)
{
	Array_Base <char> array{10, 'a'};
	array.set(5, 'b');
	assert('b' == array[5]);
}
void test_array_base_find(void)
{
	Array_Base <char> array{5, 'a'};
	array.set(2, 'c');
	
	int index = array.find('c');
	assert(2 == index);
}
void test_array_base_equality(void)
{
	Array_Base <char> array{10, 'a'};
	Array_Base <char> other_array{10, 'a'};

	assert(array == other_array);
	assert(array == array);
}
void test_array_base_inequality(void)
{
	Array_Base <char> array{10, 'a'};
	Array_Base <char> other_array{5, 'b'};

	assert(array != other_array);
}
void test_array_base_slice(void)
{
	Array_Base <char> array{10 , 'a'};
	Array_Base <char> slice;
	slice = array.slice(2);
	assert(8 == slice.size());
	
	for (size_t i = 0; i < slice.size(); ++i){
		assert('a' == slice[i]);
	}
}

void test_array_base_reverse(void)
{
	Array_Base <char> array{10, 'a'};
	array.set(9, 'b');
	assert('b' == array[9]);
	array.reverse();
	assert('b' == array[0]);
}

void array_base_tests(void) {
	test_array_base_default_constructor();
	test_array_base_length_constructor();
	test_array_base_fill_constructor();
	test_array_base_copy_constructor();
	test_array_base_assignment_operator();
	test_array_base_get_operator_const();
	test_array_base_get();
	test_array_base_set();
	test_array_base_find();
	test_array_base_equality();
	test_array_base_inequality();
	test_array_base_slice();
	test_array_base_reverse();	
}

//Array Tests
void test_array_default_constructor(void){
	
	Array<int> array;
	assert(array.max_size() == 10);
	assert(array.size() == 0);	
}

void test_array_length_constructor(void){
	Array<int> array {5};
	assert(array.max_size() == 5);
	assert(0 == array.size());
}

void test_array_fill_constructor(void)
{
	Array<char> array {5, 'a'};
	assert(array.max_size() == 5);
	assert(array.size() == 5);
	
	for (size_t i = 0; i < 5; ++i){	
		assert('a' == array[i]);
	}
}

void test_array_copy_constructor(void)
{
	Array<char> temp {10, 'b'};
	Array<char> array {temp};

	assert(10 == array.max_size());
	assert(10 == array.size());

	for(size_t i = 0; i < 10; ++i){
		assert('b' == array[i]);
	}
}

void test_array_assignment_operator(void)
{
	Array<int> temp {11, 1};
	Array<int> array;
	array = temp;
	
	assert(11 == array.size());
	assert(11 == array.max_size());

	for (size_t i = 0; i < 11; ++i){
		assert (1 == array[i]);
	}
}
	
void test_array_get(void)
{
	Array<int> array {11, 2};
	assert(2 == array.get(5));
}
void test_array_set(void)
{
	Array<int> array{11, 2};
	array.set(5, 6);
	assert(6 == array.get(5));
}
void test_array_find(void)
{
	Array<int> array{11,2};
	array.set(5, 7);
	size_t index = array.find(7);
	assert(5 == index);
}
void test_array_equality(void)
{
	Array<int> array{11,2};
	Array <int> temp {11,2};
	assert(temp == array);
}
void test_array_inequality(void)
{
	Array<int> array{11,2};
	Array<int> temp {11,3};
	assert(temp != array);
}
void test_array_fill(void)
{
	Array<char> array{11};
	array.fill('c');
	assert(11 == array.max_size());
	assert(11 == array.size());
	for (size_t i = 0; i < 11; ++i){
		assert('c' == array[i]);
	}
}
void test_array_slice(void)
{
	
	Array <char> array{10 , 'a'};
	Array_Base <char> slice;
	slice = array.slice(2);
	assert(8 == slice.size());
	
	for (size_t i = 0; i < slice.size(); ++i){
		assert('a' == slice[i]);
	}
}
void test_array_reverse(void) 
{
	Array <char> array{10, 'a'};
	array.set(9, 'b');
	assert('b' == array[9]);
	array.reverse();
	assert('b' == array[0]);
}
void test_array_resize(void)
{
	Array <char> array{10};
	array.set(0, 'a');
	assert(1 == array.size());

	array.resize(5);
	assert(1 == array.size());
	array.resize(12);
	assert(12 == array.max_size());
	assert('a' == array[0]);

	array.set(1, 'b');
	assert(2 == array.size());
	array.resize(1);
	assert(1 == array.size());
	assert('a' == array[0]);
}
void test_array_shrink(void)
{
	Array<char> array{10};
	array.set(0, 'a');
	array.shrink();
	assert(1 == array.max_size());
	assert('a' == array[0]);

	array.resize(12);
	array.set(4, 'b');
	assert(5 == array.size());
	array.shrink();
	assert(5 == array.size());
	assert(5 == array.max_size());
	assert('b' == array[4]);
	assert('a' == array[0]);
}

void array_tests(void)
{
	test_array_default_constructor();
	test_array_length_constructor();
	test_array_fill_constructor();
	test_array_copy_constructor();
	test_array_assignment_operator();
	test_array_get();
	test_array_set();
	test_array_find();
	test_array_equality();
	test_array_inequality();
	test_array_fill();
	test_array_slice();
	test_array_reverse();
	test_array_resize();
	test_array_shrink();
}
//Fixed_Array Tests
void test_fixed_array_default_constructor(void){
}

void test_fixed_array_length_constructor(void){
}

void test_fixed_array_fill_constructor(void){ }

void test_fixed_array_copy_constructor(void) { }
void test_fixed_array_copy_constructor_size(void) { }

void test_fixed_array_assignment_operator(void) { }
void test_fixed_array_assignment_operator_size(void) { }
void test_fixed_array_get_size(void){ }
void test_fixed_array_get_max(void) { }
void test_fixed_array_get_operator(void) { }
void test_fixed_array_get_operator_const(void) { }
void test_fixed_array_get(void) { }
void test_fixed_array_set(void) { }
void test_fixed_array_find(void) { }
void test_fixed_array_find_overload(void) { }
void test_fixed_array_equality(void) { }
void test_fixed_array_inequality(void) { }
void test_fixed_array_fill(void) { }
void test_fixed_array_slice(void) { }
void test_fixed_array_slice_overload(void) { }
void test_fixed_array_reverse(void) { }


//Stack Tests
void test_stack_default_constructor(void){
	Stack <int> stack;
	Stack <int> s {};	

	assert(true == stack.is_empty());
	assert(true == s.is_empty());
}
void test_stack_copy_constructor(void)
{
	Stack <int> stack;
	stack.push(5);
	assert(5 == stack.top());
	Stack<int> s {stack};
	assert(false == s.is_empty());
	assert(5 == s.top());
}

void test_stack_assignment_operator(void)
{
	Stack<int> stack;
	stack.push(5);
	stack.push(10);
	stack.push(40);
	assert(3 == stack.size());
	assert(40 == stack.top());
	Stack<int> s = stack;
	assert(3 == s.size());
	assert(40 == stack.top());
}
void test_stack_push(void)
{
	Stack<int> stack;
	stack.push(5);
	assert(5 == stack.top());
	stack.push(10);
	stack.push(60);
	stack.push(70);
	assert(70 == stack.top());
}
void test_stack_pop(void)
{
	Stack<int> stack;
	stack.push(5);
	stack.pop();
	assert(0 == stack.size());
	stack.push(5);
	stack.push(10);
	assert(10 == stack.top());
	stack.pop();
	assert(5 == stack.top());
	
}


void stack_tests(void){
	test_stack_default_constructor();
	test_stack_copy_constructor();
	test_stack_assignment_operator();
	test_stack_push();
	test_stack_pop();
}

//Queue Tests
void test_queue_default_constructor(void){
}
void test_queue_copy_constructor(void) { }

void test_queue_assignment_operator(void) { }
void test_queue_is_empty(void) { }
void test_queue_enqueue(void) { }
void test_queue_dequeue(void) { }
void test_queue_clear(void) { }

int main(void){
	try{ 
		array_base_tests();
		array_tests();
		stack_tests();
		printf("All Tests passed\n");
	}
	catch(std::exception& e){ 
		printf("%s\n", e.what());
	}
	return 0;
}
