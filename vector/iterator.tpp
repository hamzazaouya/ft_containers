#include <iostream>
namespace ft
{
    template<typename value_type> class Iterator
    {
        typedef value_type&     reference;
        typedef value_type*     pointer;
        typedef size_t          size_type;
        public:
            //Default Constructor
            Iterator() { this->_ptr = NULL; }

            //Prarameterized Constructor
            Iterator(pointer _ptr) { this->_ptr = _ptr; }

            //Copy Constructor

            
            Iterator(const Iterator& copy): _ptr(copy._ptr) {}

            // Copy Assignment Operator of iter1 = iter2
            Iterator& operator= (const Iterator& copy)
            {
                if(this != &copy)
                    this->_ptr = copy._ptr;
                return(*this);
            }

            // Copy Assignment Operator iter1 = n
            Iterator& operator= (const value_type copy)
            {
                if(this != &copy)
                    *(this->_ptr = copy);
                return (*this);
            }

            // iter1 == iter2
            bool operator== (const Iterator &rhs) { return (this->_ptr == rhs._ptr); }

            // iter1 != iter2
            bool operator!= (const Iterator &rhs) { return (this->_ptr != rhs._ptr); }

            // *iter
            reference operator*() const { return(*(this->_ptr)); }

            // iter->
            reference operator-> (){ return (&(*_ptr)); }

            // ++iter
            reference operator++()
            {
                this->_ptr++;
                return (*this);
            }

            // --iter
            reference operator--()
            {
                this->_ptr--;
                return (*this);
            }

            // iter++
            value_type operator++(int)
            {
                value_type temp;
                this->_ptr++;
                return (temp);
            }

            // iter--
            value_type operator--(int)
            {
                value_type temp;
                this->_ptr--;
                return (temp);
            }

            // iter + n
            Iterator operator+ (const size_type n) const
            {
                return (Iterator(this->_ptr + n));
            }

            // iter1 - iter2
            Iterator operator- (const Iterator& iter) {return (this->_ptr - iter._ptr); }

            // iter - n
            Iterator operator- (const size_type n)
            {
                return (Iterator(this->_ptr - n));
            }

            // iter1 < iter1
            bool operator< (const Iterator& iter) {return (this->_ptr < iter); }

            // iter1 > iter2
            bool operator> (const Iterator& iter) {return (this->_ptr > iter); }

            // iter1 <= iter2
            bool operator<= (const Iterator& iter) {return (this->_ptr <= iter); }

            // iter1 <= iter2
            bool operator>= (const Iterator& iter) {return (this->_ptr >= iter); }

            // iter += n
            Iterator& operator+= (const size_type n)
            {
                this->_ptr += n;
                return (*this);
            }

            // iter -= n
            Iterator& operator-= (const size_type n)
            {
                this->_ptr -= n;
                return (*this);
            }

            // iter[n]
            reference operator[] (const size_type n) { return (this->_ptr[n]); }
        private:
            pointer _ptr;
    };
}