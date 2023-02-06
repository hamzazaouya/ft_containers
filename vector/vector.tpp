#ifndef VECTOR_TPP
#define VECTOR_TPP
#include <memory>
namespace ft
{
	template <class T, class Alloc = std::allocator<T> > class vector
	{
		private:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef size_t										size_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

			value_type		*_arr;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_allocator;

		public:
		vector()
		{
			//std::cout << "Default constructor" << std::endl;
			this->_size = 0;
			this->_capacity = 0;
			this->_arr = NULL;
		}
		vector(size_type n, const value_type& val)
		{
			//std::cout << "Fill Constructor" << std::endl;
			allocator_type alloc;
			this->_size = n;
			this->_capacity = n;
			this->_arr = this->_allocator.allocate(n);
			for(int i = 0; i < n; i++)
				_arr[i] = val;
		}
		vector (const vector& copy)
		{
			//std::cout << "Copy Constructor" << std::endl;
			this->_size = copy._size;
			this->_capacity = copy._capacity;
			this->_arr = this->_allocator.allocate(this->_capacity);
			for(int i = 0; i < this->_size; i++)
				this->_arr[i] = copy._arr[i];
		}
		vector& operator= (const vector& copy)
		{
			//std::cout << "Copy Assignment" << std::endl;
			if(this != &copy)
			{
				this->_size = copy._size;
				if(this->_capacity < copy._capacity)
					this->_capacity = copy._capacity;
				if(this->_arr)
					this->_allocator.destroy(this->_arr);
				this->_arr = this->_allocator.allocate(this->_capacity);
				for(int i = 0; i < this->_size; i++)
					this->_arr[i] = copy._arr[i];
			}
			return (*this);
		}
		size_type size(void) const
		{
			return (_size);
		}
		size_type capacity(void) const
		{
			return (_capacity);
		}
		reference operator[] (size_type n)
		{
			return (this->_arr[n]);
		}
		const_reference operator[] (size_type n) const
		{
			return (this->_arr[n]);
		}
		~vector()
		{
			//std::cout << "distructor called" << std::endl;
			this->_allocator.deallocate(this->_arr, this->_capacity);
			this->_allocator.destroy(this->_arr);
		}
	};
}

#endif