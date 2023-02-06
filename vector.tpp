#ifndef VECTOR_TPP
#define VECTOR_TPP
#include <memory>
namespace ft
{
    template <class T, class Alloc = std::allocator<T> > class vector
    {
        typedef T											value_type;
        typedef Alloc										allocator_type;
        typedef size_t										size_type;
        typedef typename allocator_type::reference			reference;
        typedef typename allocator_type::const_reference	const_reference;
        typedef typename allocator_type::pointer			pointer;
        typedef typename allocator_type::const_pointer		const_pointer;

        private:
            value_type  *_arr;
            size_type   _size;
            size_type   _capacity;

        public:
        vector()
        {
			std::cout << "constructor called" << std::endl;
            _size = 0;
            _capacity = 0;
        }
		vector(size_type n, const value_type& val)
		{
			_size = n;
			_capacity = n;
			this->_arr = allocator_type.allocate(n);
			allocator_type.construct(_arr, val);
		}
		vector (const vector& copy)
		{
			this->_size = copy._size;
			this->_capacity = copy._capacity;
			this->_arr = _arr;
		}
		vector& operator = (const vector& copy)
		{
			if(this != &copy)
			{
				this->_size = copy._size;
				this->_capacity = copy._capacity;
				this->_arr = _arr;
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
			std::cout << "distructor called" << std::endl;
        }
    };
}

#endif