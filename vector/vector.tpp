#ifndef VECTOR_TPP
#define VECTOR_TPP
#include <iostream>
#include <memory>
#include <stdexcept>
#include <type_traits>
#include <math.h>
#include "iterator.tpp"
#include "../utils/type_traits.tpp"
namespace ft
{
	template <class T, class Alloc = std::allocator<T> > class vector
	{
		public:
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef size_t											size_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef Iterator<std::input_iterator_tag,value_type>	iterator;
		explicit vector (const allocator_type& alloc = allocator_type())
		{
			this->_size = 0;
			this->_capacity = 0;
			this->_data = NULL;
			this->_allocator = alloc;
		}
		explicit vector(size_type n, const value_type& val, const allocator_type& alloc = allocator_type())
		{
			std::cout << "hello forom Constructer 1" << std::endl;
			this->_size = n;
			this->_capacity = n;
			this->_data = this->_allocator.allocate(n);
			this->_allocator = alloc;
			for(int i = 0; i < n; i++)
				this->_allocator.construct(this->_data + i, val);
		}
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0 )
		{
			std::cout << "Hello from Iterator constructer" << std::endl;
			this->_allocator = alloc;
			// while(first < last)
			// {
			// 	this->push_back(*first);
			// 	first++;
			// }
		}
		vector (const vector& copy)
		{
			this->_size = copy._size;
			this->_capacity = copy._capacity;
			this->_data = this->_allocator.allocate(this->_capacity);
			for(int i = 0; i < this->_size; i++)
				this->_data[i] = copy._data[i];
		}
		~vector()
		{
			for(int i = 0; i < this->_capacity; i++)
				this->_allocator.destroy(this->_data + i);
			this->_allocator.deallocate(this->_data, this->_capacity);
		}
		/*============================ Opeator Overloading =============================*/

		vector& operator= (const vector& copy)
		{
			if(this != &copy)
			{
				this->_size = copy._size;
				if(this->_capacity < copy._capacity)
					this->_capacity = copy._capacity;
				if(this->_data)
					this->_allocator.destroy(this->_data);
				this->_data = this->_allocator.allocate(this->_capacity);
				for(int i = 0; i < this->_size; i++)
					this->_data[i] = copy._data[i];
			}
			return (*this);
		}

		/*========================= Iterator Functions ======================*/

		iterator begin(void) { return (iterator(this->_data)); }
		//const_iterator begin() const {return (iterator(this->_data));}
		iterator end(void) { return (iterator(this->_data + this->_size)); }
		//const_iterator end() const {return (iterator(this->_data + this->_size))}
		/*================== Capacity Functions =======================*/

		bool empty() const { return (!this->_size); }
		size_type size(void) const { return (_size); }
		size_type capacity(void) const { return (_capacity); }
		size_type max_size(void) const { return (_allocator.max_size()); }
		void resize (size_type n, value_type val = value_type())
		{
			if(n < this->_size)
				for(int i = n; i < this->_size; i++)
					this->_allocator.destroy(this->_data + i);
			else if(n > this->_size)
			{
				if(this->_capacity < n)
					reserve(this->_capacity * 2 < n ? n : this->_capacity * 2);
				for(int i = this->_size; i < n; i++)
					this->_allocator.construct(this->_data + i, val);
			}
			this->_size = n;
		}
		void reserve(size_type n)
		{
			if (n < this->_capacity)
				return ;
			pointer new_data = this->_allocator.allocate(n);
			for(size_type i = 0; i < this->_size; i++)
				_allocator.construct(new_data + i , *(this->_data + i));
			for(size_type i = 0; i < this->_capacity; i++)
				this->_allocator.destroy(this->_data + i);
			if(this->_capacity)
				this->_allocator.deallocate(this->_data, this->_capacity);
			this->_data = new_data;
			this->_capacity = n;
		}

		// ======================= Element Access Functions =====================

		reference operator[] (size_type n) { return (this->_data[n]); }
		reference front() { return (this->_data[0]); }
		const_reference front() const {return (this->_data[0]); }
		reference back(){ return (this->_data[this->_size - 1]); }
		const_reference back() const { return (this->_data[this->_size - 1]); }
		reference at (size_type n)
		{
			if(n < this->_size)
				return (this->_data[n]);
			throw std::out_of_range("vector");
		}
		const_reference at (size_type n) const
		{
			if(n < this->_size)
				return (this->_data[n]);
			throw std::out_of_range("vector");
		}

		// ======================== Modifiers Functions =========================

		template <class InputIterator>
  		void assign (InputIterator first, InputIterator last)
		{
			while(first < last)
			{
				push_back(*first);
				first++;
			}
		}
		void push_back (const value_type& val)
		{
			if(this->_capacity == this->_size)
				reserve(this->_capacity == 0 ? 1 : this->_capacity * 2);
			this->_allocator.construct(this->_data + this->_size, val);
			this->_size++;
		}
		void pop_back()
		{
			this->_allocator.destroy(this->_data + this->_size - 1);
			this->_size--;
		}
	private:
		pointer			_data;
		size_type		_size;
		size_type		_capacity;
		allocator_type	_allocator;
	};
}

#endif