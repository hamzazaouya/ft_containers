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

        // Constructors
            Iterator(): _ptr(NULL) {}
            Iterator(const Iterator& iter): _ptr(iter._ptr) {}
            Iterator(const pointer ptr): _ptr(ptr) {}
            Iterator operator= (const Iterator& iter)
            {
                if(this != &iter)
                    this->_ptr = iter._ptr;
                return(*this);
            }
            Iterator& operator+= (const difference_type& n) { this->_ptr += n; return (*this); }
            Iterator& operator-= (const difference_type& n) { this->_ptr -= n; return (*this); }

        // Bool
            bool operator== (const Iterator& rhs) { return (this->_ptr == rhs._ptr); }
            bool operator!= (const Iterator& rhs) { return (this->_ptr != rhs._ptr); }
            bool operator< (const Iterator& iter) {return (this->_ptr < iter); }
            bool operator> (const Iterator& iter) {return (this->_ptr > iter); }
            bool operator<= (const Iterator& iter) {return (this->_ptr <= iter); }
            bool operator>= (const Iterator& iter) {return (this->_ptr >= iter); }

        // Reference
            reference operator*() const { return(*(this->_ptr)); }
            pointer operator-> () const { return (_ptr); }
            reference operator[] (const difference_type n) { return (this->_ptr[n]); }
        
        // Iterator
            Iterator& operator++() { this->_ptr++; return (*this); }
            Iterator& operator--() { this->_ptr--; return (*this); }
            Iterator operator+ (const difference_type& n) const { return (Iterator(this->_ptr + n)); }
            Iterator operator- (const difference_type& n) { return (Iterator(this->_ptr - n)); }
            Iterator operator- (const reference& iter) {return (Iterator(this->_ptr - iter._ptr)); }

        //Value Type
            Iterator operator++(int)
            {
                value_type temp;
                this->_ptr++;
                return (temp);
            }
            Iterator operator--(int)
            {
                value_type temp;
                this->_ptr--;
                return (temp);
            }
            reference operator[] (difference_type n) const {return (*(this->_ptr + n))}
        private:
            pointer _ptr;
    };
}