#ifndef _VECTOR_HPP_
# define _VECTOR_HPP_

#pragma once

namespace ft
{
	template < typename T, typename Allocator = std::allocator<T> >
	class vector{

	public:
		typedef T value_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef value_type*		pointer;
		typedef value_type*	const_pointer;

		typedef size_t										size_type;
		typedef ft::RandomAccessIterator<value_type> 		iterator;
		typedef ft::RandomAccessIterator<const value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	protected:
		pointer		my_tab;
		size_t		capacity_size;
		size_t		nb_element;
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
		vector(Allocator alloc = Allocator()) : capacity_size(0), nb_element(0), alloc(alloc)
		{
			my_tab = NULL;
		};

		vector(size_t N, Allocator alloc = Allocator()) : capacity_size(N), nb_element(N), alloc(alloc)
		{
			my_tab = alloc.allocate(N);
			for (size_t i = 0; i < N; i++)
			{
				alloc.construct(&my_tab[i], T());
			}
		};

		vector(size_t N, T element, Allocator alloc = Allocator()) : capacity_size(N), nb_element(N), alloc(alloc)
		{
			my_tab = alloc.allocate(N);
			for (size_t i = 0; i < N; i++)
			{
				alloc.construct(&my_tab[i], element);
			}
		};

		~vector()
		{
			destroy_tab();
		}

		vector &operator=(const vector &original_vector)
		{
			if (this == &original_vector)
				return (*this);
			capacity_size = original_vector.capacity_size;
			nb_element = original_vector.nb_element;
			alloc = original_vector.alloc;
			my_tab = alloc.allocate(capacity_size);
			for (size_t i = 0; i < nb_element; i++)
				alloc.construct(&my_tab[i], original_vector.my_tab[i]);
			return (*this);
		}

		/****************************************************************************************************************************/
		/******************************************  Iterators **********************************************************************/
		/****************************************************************************************************************************/
		iterator begin(void) {return (iterator(this->my_tab));}
		const_iterator begin(void) const { return (const_iterator(this->my_tab)); }

		reverse_iterator rbegin(void) { return (reverse_iterator(this->end())); }
		const_reverse_iterator rbegin(void) const { return (const_reverse_iterator(this->end())); }

		iterator end(void) { return (iterator(&(this->my_tab[this->nb_element]))); }
		const_iterator end(void) const { return (const_iterator(&(this->my_tab[this->nb_element]))); }

		reverse_iterator rend(void) { return (reverse_iterator(this->begin())); }
		const_reverse_iterator rend(void) const { return (const_reverse_iterator(this->begin())); }

		/****************************************************************************************************************************/
		/******************************************  Capacity ***********************************************************************/
		/****************************************************************************************************************************/
		size_t	size() const { return (nb_element); }
		size_t	max_size() const {return (4611686018427387903);}
		size_t	capacity() const { return (capacity_size); }

		bool	empty()
		{
			if (nb_element == 0)
				return (true);
			return (false);
		}

		void	reserve(size_t N)
		{
			if (N > max_size())
				throw bad_alloc();
			else if (N > capacity_size)
			{
				my_realloc_size(N);
			}
		}

		void	resize(size_t N, T value = T())
		{
			if (N < nb_element)
			{
				for (size_t i = N; i < nb_element; i++)
				{
					alloc.destroy(my_tab + i);
				}
				nb_element = N;
			}
			else if (N > nb_element)
			{
				for (size_t i = nb_element; i < N; i++)
				{
					push_back(value);
				}
			}
		}

		/****************************************************************************************************************************/
		/******************************************  Element access *****************************************************************/
		/****************************************************************************************************************************/
		reference	at(size_t index)
		{
			if (nb_element <= index)
				throw OutOfLimitsAlocatedException();
			else
				return (my_tab[index]);
		}
		const_reference	at(size_t index) const
		{
			if (nb_element <= index)
				throw OutOfLimitsAlocatedException();
			else
				return (my_tab[index]);
		}

		reference operator[](size_t index){ return (this->my_tab[index]); }
		const_reference operator[](size_t index) const { return (this->my_tab[index]); }

		reference front() { return (my_tab[0]);}
		const_reference front() const { return (my_tab[0]);}

		reference back() {return my_tab[nb_element - 1];}
		const_reference back() const {return my_tab[nb_element - 1];}

		/****************************************************************************************************************************/
		/******************************************  Modifiers **********************************************************************/
		/****************************************************************************************************************************/

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL)
		{
			size_type size = last - first;
			if (size > capacity_size)
			{
				T *tmp = alloc.allocate(size);
				for (size_type i = 0; i < size; i++)
				{
					alloc.construct(&tmp[i], *first);
					alloc.destroy(&my_tab[i]);
					first++;
				}
				destroy_tab();
				my_tab = tmp;
				capacity_size = size;
				nb_element = size;
			}
			else
			{
				for (size_type i = 0; i < size; i++)
				{
					alloc.destroy(&my_tab[i]);
					alloc.construct(&my_tab[i], *first);
					first++;
				}
				nb_element = size;
			}
		}

		void assign(size_type n, const value_type& val)
		{
			if (n < nb_element)
			{
				for (size_t i = 0; i < n; i++)
				{
					my_tab[i] = val;
				}
				for (size_t y = nb_element; y > n; y--)
				{
					pop_back();
				}
			}
			else
			{
				if (n > capacity_size)
					my_realloc_size();
				if (n > capacity_size)
					my_realloc_size(n);
				for (size_t i = 0; i < nb_element; i++)
				{
					alloc.destroy(my_tab + i);
				}
				nb_element = 0;
				for (size_t i = 0; i < n; i++)
				{
					push_back(val);
				}
			}
		}

		void	push_back(T new_insert)
		{
			if (capacity_size > size())
			{
				alloc.construct(&my_tab[size()], new_insert);
				nb_element++;
			}
			else
			{
				my_realloc_size();
				alloc.construct(&my_tab[size()], new_insert);
				nb_element++;
			}
		}

		void	pop_back()
		{
			alloc.destroy(&my_tab[size()]);
			nb_element--;
		}

		iterator insert(iterator position, const value_type& val)
		{
			std::cout << "at stat insert size = " << nb_element << " capa = " << capacity_size << std::endl;
			if (nb_element + 1 >= capacity_size)
				my_realloc_size();
			std::cout << "insert afther realloc size = " << nb_element << " capa = " << capacity_size << std::endl;
			size_type dist = 0;
			if (nb_element > 0)
				dist = position - begin();
			std::cout << "insert dist = " << dist << std::endl;
			alloc.construct(&my_tab[nb_element], my_tab[nb_element - 1]);
			for (size_type i = nb_element - 1; i > dist; i--)
				my_tab[i] = my_tab[i - 1];
			my_tab[dist] = val;
			nb_element++;
			return position;
		}

		void insert(iterator position, size_type n, const value_type& val)
		{
			if (n <= 0)
				return ;
			if (nb_element + n > capacity_size)
				my_realloc_size();
			if (nb_element + n > capacity_size)
				my_realloc_size(n);
			size_type dist = 0;
			nb_element += n;
			if (nb_element > 0)
				dist = position - begin();
			for (size_type i = nb_element; i > (dist + n); i--)
				alloc.construct(&my_tab[i], my_tab[i - n]);
			for (size_t i = (dist + n); i > dist; i--)
			{
				alloc.construct(&my_tab[i], val);
			}
			for (size_t i = dist; i > 0; i--)
			{
				alloc.construct(&my_tab[i], my_tab[i - n]);
			}
			std::cout << "end" << std::endl;
		}

		// template <class InputIterator>
		// void insert (iterator position, InputIterator first, InputIterator last)
		// {
		// }
		/****************************************************************************************************************************/
		/******************************************  Allocator **********************************************************************/
		/****************************************************************************************************************************/

		Allocator get_allocator() const{ return (alloc); }

		/****************************************************************************************************************************/
		/******************************************  Non-member function overloads **************************************************/
		/****************************************************************************************************************************/

		void	destroy_tab()
		{
			for (size_t i = nb_element; i > 0; i--)
			{
				alloc.destroy(my_tab + i);
			}
			alloc.deallocate(my_tab, capacity_size);
			my_tab = NULL;
		}

		void	my_realloc_size()
		{
			if (capacity_size == 0)
			{
				my_tab = alloc.allocate(1);
				capacity_size = 1;
			}
			else
			{
				pointer tmp = alloc.allocate(capacity_size * 2);
				for (size_type i = 0; i < nb_element; i++)
				{
					alloc.construct(&tmp[i], my_tab[i]);
					alloc.destroy(&my_tab[i]);
				}
				alloc.deallocate(my_tab, capacity_size);
				my_tab = tmp;
				capacity_size *= 2;
			}
		}

		void	my_realloc_size(size_t N)
		{
			if (capacity_size < N)
			{
				pointer tmp = alloc.allocate(N);
				for (size_type i = 0; i < nb_element; i++)
				{
					alloc.construct(&tmp[i], my_tab[i]);
					alloc.destroy(&my_tab[i]);
				}
				alloc.deallocate(my_tab, capacity_size);
				my_tab = tmp;
				capacity_size = N;
			}
		}
	};
}

#endif
