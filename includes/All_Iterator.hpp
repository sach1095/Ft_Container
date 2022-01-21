#ifndef _ALL_ITERATOR_HPP_
# define _ALL_ITERATOR_HPP_

#pragma once

namespace ft {

	template <class Iterator> class iterator_traits
	{
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};
	template <class T> class iterator_traits<T*>{
		public:
			typedef ptrdiff_t						difference_type;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef std::random_access_iterator_tag	iterator_category;
	};
	template <class T> class iterator_traits<const T*>{
		public:
			typedef ptrdiff_t						difference_type;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef std::random_access_iterator_tag	iterator_category;
	};
	template < class T >
	class RandomAccessIterator{
		public:

			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef ptrdiff_t						difference_type;
			typedef std::random_access_iterator_tag	iterator_category;

			RandomAccessIterator():_ptr(NULL) {};
			RandomAccessIterator(pointer ptr):_ptr(ptr) {};
			~RandomAccessIterator() {};
			RandomAccessIterator (RandomAccessIterator const& other): _ptr(other._ptr) {};
			RandomAccessIterator &operator=(RandomAccessIterator const& other) {
				if (this != &other)
					_ptr = other._ptr;
				return *this; 
			};

			reference operator*() {return *_ptr;}
			pointer operator->() const {return &(operator*());}

			pointer base() const {return _ptr;}
			

			RandomAccessIterator	&operator++() {
				++_ptr;
				return *this;
			}
			RandomAccessIterator	operator++(int) {
				RandomAccessIterator ret(*this);
				++_ptr;
				return ret;
			}
			RandomAccessIterator	&operator--() {
				--_ptr;
				return *this;
			}
			RandomAccessIterator	operator--(int) {
				RandomAccessIterator ret(*this);
				--_ptr;
				return ret;
			}
			RandomAccessIterator	&operator+=(difference_type n) {
				_ptr += n;
				return *this;
			}
			RandomAccessIterator	&operator-=(difference_type n) {
				_ptr -= n;
				return *this;
			}

			RandomAccessIterator	operator+(difference_type n){return (_ptr + n);}
			RandomAccessIterator	operator-(difference_type n){return (_ptr - n);}
			difference_type			operator-(RandomAccessIterator const& a){return _ptr - a._ptr;}

			reference &operator[] (difference_type n) const {return &_ptr[n];}

			operator RandomAccessIterator<const T> () const
			{ return (RandomAccessIterator<const T>(_ptr)); }

		private:
			pointer	_ptr;
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
	template <class Iterator> 
	class reverse_iterator{
		public:

			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;

			reverse_iterator():_it(NULL){};
			explicit reverse_iterator (iterator_type it):_it(it){};
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it):_it(rev_it.base()){};

			iterator_type base() const{return _it;}
			reference operator*() const {
				iterator_type tmp = _it;
				--tmp;
				return *tmp;
			}
			reverse_iterator operator+ (difference_type n) const {return reverse_iterator(_it - n);}
			reverse_iterator& operator++(){
				--_it;
				return *this;
			};
			reverse_iterator  operator++(int){
				reverse_iterator temp = *this;
				--_it;
				return temp;
			};
			reverse_iterator& operator+= (difference_type n){
				_it -= n;
				return *this;
			};
			reverse_iterator operator- (difference_type n) const {return reverse_iterator(_it + n);}
			reverse_iterator& operator--(){
				++_it;
				return *this;
			};
			reverse_iterator  operator--(int){
				reverse_iterator temp = *this;
				++_it;
				return temp;
			};
			reverse_iterator& operator-= (difference_type n){
				_it += n;
				return *this;
			};
			pointer operator->() const {return &(operator*());}
			reference operator[] (difference_type n) const {return *(_it - n - 1);}

		private:
			iterator_type _it;
	};

	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs){
		return (lhs.base() == rhs.base());
	}

	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs){
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs){
		return (lhs.base() > rhs.base());
	}

	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs){
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
	bool operator> (const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs){
		return (lhs.base() < rhs.base());
	}

	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs){
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+ (
	typename reverse_iterator<Iterator>::difference_type n,
	const reverse_iterator<Iterator>& rev_it){
		return rev_it + n;
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (
	const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs){
		return lhs.base() - rhs.base();
	}

		template < class T >
	struct node
	{
		typedef T	value_type;
		value_type	data;
		node		*left;
		node		*right;
		node		*parent;

		node(value_type const &src) : data(src), left(NULL), right(NULL), parent(NULL) {}
		node(value_type const &src, node *l, node *r, node *p) : data(src), left(l), right(r), parent(p) {}
		node(node *l, node *r, node *p) : left(l), right(r), parent(p) {}
	};

	template < class T >
	class TreeIterator{
		public:

			typedef T								value_type;
			typedef T*								node_ptr;
			typedef typename T::value_type			data;

			typedef data&							reference;
			typedef data*							pointer;

			typedef ptrdiff_t						difference_type;
			typedef std::bidirectional_iterator_tag	iterator_category;

			TreeIterator():_it(NULL) {};
			TreeIterator(node_ptr it, node_ptr first):_it(it), _first(first) {};
			~TreeIterator() {};
			TreeIterator (TreeIterator const& other): _it(other._it), _first(other._first) {};

			TreeIterator &operator=(TreeIterator const& other) {
				if (this != &other)
				{
					_it = other._it;
					_first = other._first;
				}
				return *this; 
			};

			reference operator*() {return _it->data;}
			pointer operator->() const {return &_it->data;}

			TreeIterator &operator++()
			{
				if (_it != NULL)
					_it = _go_to_next();
				return *this;
			}

			TreeIterator operator++(int)
			{
				TreeIterator tmp(*this);
				++(*this);
				return tmp;
			}

			TreeIterator &operator--()
			{
				if (_it != NULL)
					_it = _go_to_befor();
				else
					_it = _go_to_max(_first);
				return *this;
			}

			TreeIterator operator--(int)
			{
				TreeIterator tmp(*this);
				--(*this);
				return tmp;
			}

			bool	operator!=(TreeIterator const& a){return (a._it != _it);};
			bool	operator==(TreeIterator const& a){return (a._it == _it);};

			node_ptr getCurrent () const { return _it; }

		private:
			node_ptr _it;
			node_ptr _first;

			node_ptr _go_to_min(node_ptr n)
			{
				while (n->left)
					n = n->left;
				return n;
			}

			node_ptr _go_to_max(node_ptr n)
			{
				while (n->right)
					n = n->right;
				return n;
			}

			node_ptr _go_to_next()
			{
				node_ptr n = _it;
				node_ptr next = NULL;

				if (n->right != NULL)
					return _go_to_min(n->right);

				next = n->parent;
				while (next != NULL && n == next->right)
				{
					n = next;
					next = next->parent;
				}
				return next;
			}

			node_ptr _go_to_befor()
			{
				node_ptr n = _it;
				node_ptr prev = NULL;

				if (n->left != NULL)
					return _go_to_max(n->left);
				
				prev = n->parent;
				while (prev != NULL && n == prev->left)
				{
					n = prev;
					prev = prev->parent;
				}
				return prev;
			}

	};
}

#endif
