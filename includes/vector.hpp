#ifndef _VECTOR_HPP_
# define _VECTOR_HPP_

#pragma once

namespace ft
{
	template < typename T, typename Allocator = std::allocator<T> >
	class vector{

	protected:
		T			*my_tab;
		size_t		capacity_size;
		size_t		nb_element;
		Allocator	alloc;

	public:
		typedef T value_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef value_type*		pointer;
		typedef value_type*	const_pointer;

		typedef ft::RandomAccessIterator<value_type> 		iterator;
		typedef ft::RandomAccessIterator<const value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

		class OutOfLimitsAlocatedException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return ("Occurence not allocated");
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

		iterator begin() {return my_tab;}
		const_iterator begin() const {return my_tab;}

		iterator end() {return &my_tab[nb_element];}
		const_iterator end() const {return &my_tab[nb_element];}

		reverse_iterator rbegin(){return reverse_iterator(end());}
		const_reverse_iterator rbegin() const {return const_reverse_iterator(end());}

		reverse_iterator rend(){return reverse_iterator(begin());}
		const_reverse_iterator rend() const {return const_reverse_iterator(begin());}

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

		void	reserve() {}
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


		/****************************************************************************************************************************/
		/******************************************  Allocator **********************************************************************/
		/****************************************************************************************************************************/



		/****************************************************************************************************************************/
		/******************************************  Allocator **********************************************************************/
		/****************************************************************************************************************************/




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
			T *temp = NULL;
			if (capacity_size == 0)
			{
				temp = alloc.allocate(1);
				capacity_size = 1;
			}
			else
			{
				temp = alloc.allocate((capacity_size * 2));
				capacity_size = capacity_size * 2;
			}

			for (size_t i = 0; i < size(); i++)
			{
				alloc.construct(&temp[i], my_tab[i]);
			}
			destroy_tab();
			my_tab = temp;
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
	};
}

#endif
