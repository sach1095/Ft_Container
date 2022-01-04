#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

# include <iostream>
# include <vector>
# include <memory>

namespace ft
{
	template < typename T, typename Allocator = std::allocator<T> >
	class vector{

	private:
		T			*my_tab;
		size_t		size_max_allocated;
		size_t		size_max_construct;
		Allocator	alloc;
	public:

		class OutOfLimitsAlocatedException: public std::exception
		{
			virtual const char* what() const throw()
			{
				return ("Occurence not allocated");
			}
		};
		vector(Allocator alloc = Allocator()) : size_max_allocated(0), size_max_construct(0), alloc(alloc)
		{
			my_tab = NULL;
		};

		vector(size_t N, Allocator alloc = Allocator()) : size_max_allocated(N), size_max_construct(N), alloc(alloc)
		{
			my_tab = alloc.allocate(N);
			for (size_t i = 0; i < N; i++)
			{
				alloc.construct(&my_tab[i], T());
			}
		};

		vector(size_t N, T element, Allocator alloc = Allocator()) : size_max_allocated(N), size_max_construct(N), alloc(alloc)
		{
			my_tab = alloc.allocate(N);
			for (size_t i = 0; i < N; i++)
			{
				alloc.construct(&my_tab[i], element);
			}
		};

		size_t	capacity() { return (size_max_allocated); }
		size_t	size() { return (size_max_construct); }

		size_t at (size_t index)
		{
			if (size() < index)
				throw OutOfLimitsAlocatedException();
			else
				return (this->my_tab[index]);
		}

		void destroy_tab()
		{
			for (size_t i = 0; i < size(); i++)
			{
				alloc.destroy(&my_tab[i]);
			}
			alloc.deallocate(my_tab, capacity());
			my_tab = NULL;
		}

		void	my_realloc_size()
		{
			T *temp = NULL;
			if (capacity() == 0)
			{
				temp = alloc.allocate(1);
				size_max_allocated = 1;
			}
			else
			{
				temp = alloc.allocate((capacity() * 2));
				size_max_allocated = capacity() * 2;
			}

			for (size_t i = 0; i < size(); i++)
			{
				alloc.construct(&temp[i], my_tab[i]);
			}
			destroy_tab();
			my_tab = temp;
		}

		void push_back(T new_insert)
		{
			if (capacity() > size())
			{
				alloc.construct(&my_tab[size()], new_insert);
				size_max_construct++;
			}
			else
			{
				my_realloc_size();
				alloc.construct(&my_tab[size()], new_insert);
				size_max_construct++;
			}
		}
		~vector()
		{
			destroy_tab();
		}
	};
}



#endif
