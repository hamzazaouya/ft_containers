#include <iostream>
namespace ft
{
    template <class Category, class T, class Distance = ptrdiff_t,class Pointer = T*, class Reference = T&> class Iterator
    {
        typedef T               value_type;
        typedef Distance        difference_type;
        typedef Pointer         pointer;
        typedef Reference       reference;
        public:

        //Constructors
            Iterator(): _ptr(NULL) {}
            Iterator(pointer ptr): _ptr(_ptr) {}
            Iterator(const reference copy): _ptr(copy._ptr) {}

        // Iterator &
            reference operator= (const reference copy)
            {
                if(this != &copy)
                    this->_ptr = copy._ptr;
                return(*this);
            }
            reference operator= (const value_type copy)
            {
                if(this != &copy)
                    *(this->_ptr = copy);
                return (*this);
            }
            reference operator+= (const difference_type n) { this->_ptr += n; return (*this); }
            reference operator-= (const difference_type n) { this->_ptr -= n; return (*this); }

        // Bool
            bool operator== (const reference rhs) { return (this->_ptr == rhs._ptr); }
            bool operator!= (const reference rhs) { return (this->_ptr != rhs._ptr); }
            bool operator< (const reference iter) {return (this->_ptr < iter); }
            bool operator> (const reference iter) {return (this->_ptr > iter); }
            bool operator<= (const reference iter) {return (this->_ptr <= iter); }
            bool operator>= (const reference iter) {return (this->_ptr >= iter); }

        // Reference
            reference operator*() const { return(*(this->_ptr)); }
            reference operator-> () { return (&(*_ptr)); }
            reference operator++() { this->_ptr++; return (*this); }
            reference operator--() { this->_ptr--; return (*this); }
            reference operator[] (const difference_type n) { return (this->_ptr[n]); }
        
        // Iterator
            Iterator operator+ (const difference_type n) const { return (Iterator(this->_ptr + n)); }
            Iterator operator- (const reference iter) {return (Iterator(this->_ptr - iter._ptr)); }
            Iterator operator- (const difference_type n) { return (Iterator(this->_ptr - n)); }

        //Value Type
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