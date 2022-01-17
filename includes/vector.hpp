#ifndef _VECTOR_HPP_
# define _VECTOR_HPP_

#pragma once

namespace ft
{
	template < typename T, typename Allocator = std::allocator<T> >
	class vector{

	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename ft::My_Iterator<pointer> iterator;
		typedef typename ft::My_Iterator<const_pointer> const_iterator;
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef std::size_t size_type;

	protected:
		pointer		_my_tab;
		size_t		_size_capacity;
		size_t		_size_element;
		Allocator	alloc;

	public:

		class OutOfLimitsAlocatedException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return ("Occurence not allocated");
			}
		};

		class bad_alloc : public std::exception
		{
			virtual const char* what() const throw()
			{
				return ("bad_alloc");
			}
		};

		/****************************************************************************************************************************/
		/******************************************  Member functions ***************************************************************/
		/****************************************************************************************************************************/
		vector(Allocator alloc = Allocator()) : _my_tab(NULL), _size_capacity(0), _size_element(0), alloc(alloc)
		{
			_my_tab = NULL;
		};

		vector(size_t N, Allocator alloc = Allocator()) :_my_tab(NULL), _size_capacity(N), _size_element(N), alloc(alloc)
		{
			_my_tab = alloc.allocate(N);
			for (size_t i = 0; i < N; i++)
			{
				alloc.construct(&_my_tab[i], T());
			}
		};

		vector(size_t N, T element, Allocator alloc = Allocator()) :_my_tab(NULL), _size_capacity(N), _size_element(N), alloc(alloc)
		{
			_my_tab = alloc.allocate(N);
			for (size_t i = 0; i < N; i++)
			{
				alloc.construct(&_my_tab[i], element);
			}
		};

		template <class InputIterator>
		vector (InputIterator first, InputIterator last,Allocator alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL) : _my_tab(NULL), _size_capacity(0), _size_element(0), alloc(alloc)
		{
			size_t nb_insert = last - first;

			_my_tab = alloc.allocate(nb_insert);
			_size_capacity = nb_insert;
			for (size_type i = 0; i < nb_insert; i++)
				push_back(*(first + i));
		}

		~vector()
		{
			destroy_tab();
		}

		vector &operator=(const vector &original_vector)
		{
			if (this == &original_vector)
				return (*this);
			_size_capacity = original_vector._size_capacity;
			_size_element = original_vector._size_element;
			alloc = original_vector.alloc;
			_my_tab = alloc.allocate(_size_capacity);
			for (size_t i = 0; i < _size_element; i++)
				alloc.construct(&_my_tab[i], original_vector._my_tab[i]);
			return (*this);
		}

		/****************************************************************************************************************************/
		/******************************************  Iterators **********************************************************************/
		/****************************************************************************************************************************/
		iterator begin() {return _my_tab;}
		const_iterator begin() const {return _my_tab;}
		iterator end() {return &_my_tab[size()];}
		const_iterator end() const {return &_my_tab[size()];}
		reverse_iterator rbegin(){return reverse_iterator(end());}
		const_reverse_iterator rbegin() const {return const_reverse_iterator(end());}
		reverse_iterator rend(){return reverse_iterator(begin());}
		const_reverse_iterator rend() const {return const_reverse_iterator(begin());}

		/****************************************************************************************************************************/
		/******************************************  Capacity ***********************************************************************/
		/****************************************************************************************************************************/
		size_t	size() const { return (_size_element); }

		size_t	max_size() const {return (4611686018427387903);}

		void	resize(size_t N, T value = T())
		{
			if (N < _size_element)
			{
				for (size_t i = N; i < _size_element; i++)
				{
					alloc.destroy(_my_tab + i);
				}
				_size_element = N;
			}
			else if (N > _size_element)
			{
				for (size_t i = _size_element; i < N; i++)
				{
					push_back(value);
				}
			}
		}

		size_t	capacity() const { return (_size_capacity); }

		bool	empty()
		{
			if (_size_element == 0)
				return (true);
			return (false);
		}

		void	reserve(size_t N)
		{
			if (N > max_size())
				throw bad_alloc();
			else if (N > _size_capacity)
			{
				my_realloc_size(N);
			}
		}

		/****************************************************************************************************************************/
		/******************************************  Element access *****************************************************************/
		/****************************************************************************************************************************/

		reference operator[](size_t index){ return (this->_my_tab[index]); }
		const_reference operator[](size_t index) const { return (this->_my_tab[index]); }

		reference	at(size_t index)
		{
			if (_size_element <= index)
				throw OutOfLimitsAlocatedException();
			else
				return (_my_tab[index]);
		}
		const_reference	at(size_t index) const
		{
			if (_size_element <= index)
				throw OutOfLimitsAlocatedException();
			else
				return (_my_tab[index]);
		}

		reference front() { return (_my_tab[0]);}
		const_reference front() const { return (_my_tab[0]);}

		reference back() {return _my_tab[_size_element - 1];}
		const_reference back() const {return _my_tab[_size_element - 1];}

		/****************************************************************************************************************************/
		/******************************************  Modifiers **********************************************************************/
		/****************************************************************************************************************************/

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL)
		{
			size_type size = last - first;
			if (size > _size_capacity)
			{
				T *tmp = alloc.allocate(size);
				for (size_type i = 0; i < size; i++)
				{
					alloc.construct(&tmp[i], *(first + i));
					alloc.destroy(&_my_tab[i]);
				}
				destroy_tab();
				_my_tab = tmp;
				_size_capacity = size;
				_size_element = size;
			}
			else
			{
				for (size_type i = 0; i < size; i++)
				{
					alloc.destroy(&_my_tab[i]);
					alloc.construct(&_my_tab[i], *first);
					first++;
				}
				_size_element = size;
			}
		}

		void assign(size_type n, const value_type& val)
		{
			if (n < _size_element)
			{
				for (size_t i = 0; i < n; i++)
				{
					_my_tab[i] = val;
				}
				for (size_t y = _size_element; y > n; y--)
				{
					pop_back();
				}
			}
			else
			{
				if (n > _size_capacity)
					my_realloc_size();
				if (n > _size_capacity)
					my_realloc_size(n);
				for (size_t i = 0; i < _size_element; i++)
				{
					alloc.destroy(_my_tab + i);
				}
				_size_element = 0;
				for (size_t i = 0; i < n; i++)
				{
					push_back(val);
				}
			}
		}

		void	push_back(T new_insert)
		{
			if (_size_capacity > size())
			{
				alloc.construct(&_my_tab[size()], new_insert);
				_size_element++;
			}
			else
			{
				my_realloc_size();
				alloc.construct(&_my_tab[size()], new_insert);
				_size_element++;
			}
		}

		void	pop_back()
		{
			alloc.destroy(&_my_tab[size()]);
			_size_element--;
		}

		iterator insert(iterator position, const value_type& val)
		{
			size_t pos = 0;
			if (_size_element > 0)
				pos = position - begin();
			if (_size_element + 1 > _size_capacity)
				my_realloc_size();
			for (size_t i = _size_element; i > pos; i--)
			{
				alloc.construct(&_my_tab[i], _my_tab[i -1]);
			}
			alloc.construct(&_my_tab[pos], val);
			_size_element += 1;
			return (iterator(&_my_tab[pos]));
		}

		void insert(iterator position, size_type n, const value_type& val)
		{
			size_t pos = position - begin();
			if (_size_element + n > _size_capacity * 2)
				my_realloc_size(_size_element + n);
			else if (_size_element + n > _size_capacity)
				my_realloc_size();

			position = iterator(&_my_tab[pos]);
			for (size_t i = 0; i < n; i++)
			{
				position = insert(position, val);
			}
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			size_t nb_insert = last - first;
			size_t pos = position - begin();
			if (_size_element + nb_insert > _size_capacity)
				my_realloc_size();
			else if (_size_element + nb_insert > _size_capacity * 2)
				my_realloc_size(_size_element + nb_insert);

			position = iterator(&_my_tab[pos]);
			for (size_t i = nb_insert - 1; i > 0; i--)
			{
				position = insert(position, *(first + i));
			}
			position = insert(position, *first);
		}

		iterator erase (iterator position)
		{
			size_t pos = position - begin();
			alloc.destroy(_my_tab + pos);
			for (size_t i = pos; i < _size_element - 1; i++)
			{
				alloc.construct(&_my_tab[i], _my_tab[i + 1]);
			}
			_size_element--;
			return (iterator(&_my_tab[pos]));
		}

		iterator erase (iterator first, iterator last)
		{
			size_t pos = first - begin();
			size_t nb_element = last - first;

			if (nb_element != 0)
			{
				for (size_t i = pos; i < nb_element; i++)
				{
					alloc.destroy(_my_tab + pos);
				}
				for (size_t i = pos; i < _size_element - nb_element; i++)
				{
					alloc.construct(&_my_tab[i], _my_tab[i + nb_element]);
				}
				_size_element -= nb_element;
			}
			return (iterator(first));
		}

		void swap (vector& x)
		{
			pointer		tmp_my_tab = _my_tab;
			size_t		tmp_size_capacity = _size_capacity;
			size_t		tmp_size_element = _size_element;
			Allocator	tmp_alloc = alloc;

			_my_tab = x._my_tab;
			_size_capacity = x._size_capacity;
			_size_element = x._size_element;
			alloc = x.alloc;

			x._my_tab = tmp_my_tab;
			x._size_capacity = tmp_size_capacity;
			x._size_element = tmp_size_element;
			x.alloc = tmp_alloc;
		}

		void	clear()
		{
			for (size_t i = _size_element; i > 0; i--)
			{
				alloc.destroy(_my_tab + i);
			}
			_size_element = 0;
		}
		/****************************************************************************************************************************/
		/******************************************  Allocator **********************************************************************/
		/****************************************************************************************************************************/

		Allocator get_allocator() const{ return (alloc); }

		/****************************************************************************************************************************/
		/******************************************  My function utils **************************************************************/
		/****************************************************************************************************************************/

		void	destroy_tab()
		{
			clear();
			alloc.deallocate(_my_tab, _size_capacity);
			_my_tab = NULL;
		}

		void	my_realloc_size()
		{
			if (_size_capacity == 0)
			{
				_my_tab = alloc.allocate(1);
				_size_capacity = 1;
				return ;
			}
			pointer tmp;
			tmp = alloc.allocate(_size_capacity * 2);
			size_t save = _size_element;
			for (size_type i = 0; i < _size_element; i++)
			{
				alloc.construct(&tmp[i], _my_tab[i]);
			}
			destroy_tab();
			_size_capacity *= 2;
			_size_element = save;
			_my_tab = tmp;
		}

		void	my_realloc_size(size_t N)
		{
			if (_size_capacity < N)
			{
				pointer tmp = alloc.allocate(N);
				size_t save = _size_element;
				for (size_type i = 0; i < _size_element; i++)
				{
					alloc.construct(&tmp[i], _my_tab[i]);
				}
				destroy_tab();
				_my_tab = tmp;
				_size_element = save;
				_size_capacity = N;
			}
		}

	};

		/****************************************************************************************************************************/
		/******************************************  Non-member function overloads **************************************************/
		/****************************************************************************************************************************/

		template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
		{
			x.swap(y);
		}

		template <class T, class Alloc>
		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			for (size_t i = 0; i < lhs.size(); i++)
			{
				if (lhs[i] != rhs[i])
					return (false);
			}
			if (lhs.size() != rhs.size())
				return (false);
			return (true);
		}

		template <class T, class Alloc>
		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			if (!(lhs == rhs))
				return true;
			return false;
		}

		template <class T, class Alloc>
		bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

		template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
			if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
				return true;
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

		template <class T, class Alloc>
		bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
			if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
				return false;
			return !ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

		template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
			if (lhs == rhs)
				return true;
			return !ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}
}


#endif
