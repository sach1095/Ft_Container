#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

namespace ft
{
	template < typename T, typename Allocator = std::allocator<T> >
	class vector{

	protected:
		T			*my_tab;
		size_t		capacity_size;
		size_t		nb_element;
		Allocator	alloc;

		typedef T value_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef value_type*		pointer;
		typedef value_type*	const_pointer;

	public:

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
			my_tab = original_vector.my_tab;
			capacity_size = original_vector.capacity_size;
			nb_element = original_vector.nb_element;
			alloc = original_vector.alloc;
			return (*this);
		}

		/****************************************************************************************************************************/
		/******************************************  Iterators **********************************************************************/
		/****************************************************************************************************************************/


		/****************************************************************************************************************************/
		/******************************************  Capacity ***********************************************************************/
		/****************************************************************************************************************************/
		size_t	size() { return (nb_element); }
		size_t	max_size(){return (4611686018427387903);}
		size_t	capacity() { return (capacity_size); }

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
		int		at(size_t index)
		{
			if (nb_element < index || nb_element == 0)
				throw OutOfLimitsAlocatedException();
			else
			{
				// assigne tab index a un iterator
				return (this->my_tab[index]);
			}
		}

		int		at(size_t index) const
		{
			if (nb_element < index || nb_element == 0)
				throw OutOfLimitsAlocatedException();
			else
			{
				// assigne tab index a un const iterator
				return (this->my_tab[index]);
			}
		}

		vector &operator[](size_t index)
		{
			if (index > nb_element)
				throw OutOfLimitsAlocatedException();
			else
			{
				// assigne tab index a un iterator
				return (this->my_tab[index]);
			}
		}

		vector &operator[](size_t index) const
		{
			if (index > nb_element)
				throw OutOfLimitsAlocatedException();
			else
			{
				// assigne tab index a un const iterator
				return (this->my_tab[index]);
			}
		}

		int		front()
		{
			if (nb_element == 0)
				throw OutOfLimitsAlocatedException();
			else
				return (my_tab[0]);
		}
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
