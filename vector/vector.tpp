#ifndef VECTOR_TPP
#define VECTOR_TPP
#include <memory>
#include "iterator.tpp"
namespace ft
{
	template <class T, class Alloc = std::allocator<T> > class vector
	{
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef size_t										size_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef Iterator<value_type>							iterator;
			typedef Iterator<const value_type>						const_iterator;
		vector()
		{
			//std::cout << "Default constructor" << std::endl;
			this->_size = 0;
			this->_capacity = 0;
			this->_m_data = NULL;
		}
		vector(size_type n, const value_type& val, const allocator_type& alloc = allocator_type())
		{
			//std::cout << "Fill Constructor" << std::endl;
			this->_size = n;
			this->_capacity = n;
			this->_m_data = this->alloc.allocate(n);
			for(int i = 0; i < n; i++)
				_m_data[i] = val;
		}
		template <class InputIterator> vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		{
			
		}
		vector (const vector& copy)
		{
			//std::cout << "Copy Constructor" << std::endl;
			this->_size = copy._size;
			this->_capacity = copy._capacity;
			this->_m_data = this->_allocator.allocate(this->_capacity);
			for(int i = 0; i < this->_size; i++)
				this->_m_data[i] = copy._m_data[i];
		}

		/*============================ Opeator Overloading =============================*/

		vector& operator= (const vector& copy)
		{
			//std::cout << "Copy Assignment" << std::endl;
			if(this != &copy)
			{
				this->_size = copy._size;
				if(this->_capacity < copy._capacity)
					this->_capacity = copy._capacity;
				if(this->_m_data)
					this->_allocator.destroy(this->_m_data);
				this->_m_data = this->_allocator.allocate(this->_capacity);
				for(int i = 0; i < this->_size; i++)
					this->_m_data[i] = copy._m_data[i];
			}
			return (*this);
		}
		reference operator[] (size_type n)
		{
			return (this->_m_data[n]);
		}
		const_reference operator[] (size_type n) const
		{
			return (this->_m_data[n]);
		}

		/*================== Capacity Functions =======================*/

		size_type size(void) const
		{
			return (_size);
		}
		size_type capacity(void) const
		{
			return (_capacity);
		}

		/*========================= Iterator Functions ======================*/

		iterator begin(void)
		{
			return (iterator(this->_m_data));
		}
		// const_iterator begin(void) const
		// {
		// 	return (iterator(this->_m_data));
		// }
		iterator end(void)
		{
			return (iterator(this->_m_data + this->_size));
		}
		// const_iterator end(void) const 
		// {
		// 	return (iterator(this->_m_data + this->_size));
		// }
		~vector()
		{
			//std::cout << "distructor called" << std::endl;
			this->_allocator.deallocate(this->_m_data, this->_capacity);
			this->_allocator.destroy(this->_m_data);
		}

		private:
			value_type		*_m_data;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_allocator;
	};
}

#endif