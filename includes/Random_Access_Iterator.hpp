#ifndef _RANDOM_ACCESS_ITERATOR_HPP_
# define _RANDOM_ACCESS_ITERATOR_HPP_

#pragma once

namespace ft{
	template < class T >
	class RandomAccessIterator{
		private:
			T	*ptr;
		public:
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef ptrdiff_t						difference_type;
			typedef std::random_access_iterator_tag	iterator_category;

			RandomAccessIterator():ptr(NULL) {};
			RandomAccessIterator(pointer ptr):ptr(ptr) {};
			~RandomAccessIterator() {};
			RandomAccessIterator (RandomAccessIterator const& other): ptr(other.ptr) {};
			RandomAccessIterator &operator=(RandomAccessIterator const& other) {
				if (this != &other)
					ptr = other.ptr;
				return *this; 
			};

		//Dereference
			reference operator*() {return *ptr;}
			pointer operator->() const {return &(operator*());}

			pointer base() const {return ptr;}
			

		//Incrementation
			RandomAccessIterator	&operator++() {
				++ptr;
				return *this;
			}
			RandomAccessIterator	operator++(int) {
				RandomAccessIterator ret(*this);
				++ptr;
				return ret;
			}
			RandomAccessIterator	&operator--() {
				--ptr;
				return *this;
			}
			RandomAccessIterator	operator--(int) {
				RandomAccessIterator ret(*this);
				--ptr;
				return ret;
			}
			RandomAccessIterator	&operator+=(difference_type n) {
				ptr += n;
				return *this;
			}
			RandomAccessIterator	&operator-=(difference_type n) {
				ptr -= n;
				return *this;
			}

			RandomAccessIterator	operator+(difference_type n){return (ptr + n);}
			RandomAccessIterator	operator-(difference_type n){return (ptr - n);}
			difference_type			operator-(RandomAccessIterator const& a){return ptr - a.ptr;}

			reference &operator[] (difference_type n) const {return &ptr[n];}

			operator RandomAccessIterator<const T> () const
			{ return (RandomAccessIterator<const T>(ptr)); }


	};

	template <typename T>
	typename ft::RandomAccessIterator<T>::difference_type
	operator!=(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<T> rhs){
		return (lhs.base() != rhs.base());
	}

	template <typename T>
	typename ft::RandomAccessIterator<T>::difference_type
	operator==(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<T> rhs){
		return (lhs.base() == rhs.base());
	}
	template <typename T>
	typename ft::RandomAccessIterator<T>::difference_type
	operator<(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<T> rhs){
		return (lhs.base() < rhs.base());
	}
	template <typename T>
	typename ft::RandomAccessIterator<T>::difference_type
	operator<=(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<T> rhs){
		return (lhs.base() <= rhs.base());
	}
	template <typename T>
	typename ft::RandomAccessIterator<T>::difference_type
	operator>(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<T> rhs){
		return (lhs.base() > rhs.base());
	}
	template <typename T>
	typename ft::RandomAccessIterator<T>::difference_type
	operator>=(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<T> rhs){
		return (lhs.base() >= rhs.base());
	}

	template<typename T, typename Tconst>
	typename ft::RandomAccessIterator<T>::difference_type
	operator==(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<Tconst> rhs){
		return (lhs.base() == rhs.base());
	}

	template<typename T, typename Tconst>
	typename ft::RandomAccessIterator<T>::difference_type
	operator!=(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<Tconst> rhs){
		return (lhs.base() != rhs.base());
	}

	template<typename T, typename Tconst>
	typename ft::RandomAccessIterator<T>::difference_type
	operator<=(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<Tconst> rhs){
		return (lhs.base() <= rhs.base());
	}

	template<typename T, typename Tconst>
	typename ft::RandomAccessIterator<T>::difference_type
	operator<(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<Tconst> rhs){
		return (lhs.base() < rhs.base());
	}

	template<typename T, typename Tconst>
	typename ft::RandomAccessIterator<T>::difference_type
	operator>=(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<Tconst> rhs){
		return (lhs.base() >= rhs.base());
	}

	template<typename T, typename Tconst>
	typename ft::RandomAccessIterator<T>::difference_type
	operator>(const ft::RandomAccessIterator<T> lhs, const ft::RandomAccessIterator<Tconst> rhs){
		return (lhs.base() > rhs.base());
	}
}

#endif
