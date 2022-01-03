#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

# include <iostream>
# include <vector>
# include <memory>

namespace ft
{
	template < typename T, typename Allocator = std::allocator<T> >
	class vector{

	public:
		T *my_tab;
		Allocator alloc;

		vector(size_t N, Allocator alloc = Allocator()) : alloc(alloc)
		{
			my_tab = alloc.allocate(N);
			for (size_t i = 0; i < N; i++)
			{
				alloc.construct(&my_tab[i], T());
			}

		};

		int at (size_t index)
		{
			return this->my_tab[index];
		}
		~vector()
		{
			for (size_t i = 0; i < count; i++) // taille de tout ceux qui est construct.
			{
				alloc.destroy(&my_tab[i]);
			}
			alloc.deallocate(my_tab, size_max) // taille de tout ceux qui est allocate.
		}
	};
}



#endif
