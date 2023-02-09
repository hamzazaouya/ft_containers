#include <iostream>
namespace ft
{
    template<typename value_type> class Iterator
    {
        typedef value_type&     reference;
        typedef value_type*     pointer;
        public:
            Iterator()
            {
                this->_ptr = nullptr;
            }
            Iterator(pointer _ptr)
            {
                this->_ptr = _ptr;
            }
            Iterator(const Iterator& copy)
            {
                this->_ptr = copy._ptr;
            }
            Iterator& operator= (const Iterator& copy)
            {
                std::cout << "hello" << std::endl;
                // if(this != &copy)
                // {
                //     this->_ptr = copy._ptr;
                // }
                return(*this);
            }
            Iterator& operator= (const value_type copy)
            {
                std::cout << "Hello world" << std::endl;
                // if(this != &copy)
                // {
                //     *(this->_ptr = copy);
                // }
                return (*this);
            }
            bool operator== (Iterator &rhs)
            {
                std::cout << this->_ptr << std::endl;
                std::cout << rhs._ptr << std::endl;
                return (this->_ptr == rhs._ptr);
            }
            bool operator!= (Iterator &rhs)
            {
                return (this->_ptr != rhs._ptr);
            }
            reference operator*()
            {
                return(*(this->_ptr));
            }
            reference operator-> ()
            {
                
            }
            reference operator++()
            {
                this->_ptr++;
                return (*this);
            }
            reference operator--()
            {
                this->_ptr--;
                return (*this);
            }
            value_type operator++(int)
            {
                value_type temp;
                this->_ptr++;
                return (temp);
            }
            value_type operator--(int)
            {
                value_type temp;
                this->_ptr--;
                return (temp);
            }
        private:
            pointer _ptr;
    };
}