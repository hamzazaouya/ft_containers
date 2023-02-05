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
		reference operator = (const_reference v)
		{
			std::cout << "Copy Assignment operator" << std::endl;
			if(this != &v)
			{
				std::cout << "Copy Assignment operator" << std::endl;
				this->_size = v._size;
				this->_capacity = v._capacity;
			}
		}
        size_type size(void) const
        {
            return (_size);
        }
        size_type capacity(void) const
        {
            return (_capacity);
        }
        ~vector()
        {
			std::cout << "distructor called" << std::endl;
        }
    };
}

#endif