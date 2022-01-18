#ifndef _MAP_ITERATOR_HPP_
# define _MAP_ITERATOR_HPP_

#pragma once

namespace ft {

	template <class T, class Compare, class Alloc = std::allocator<node<T> > >
	class MapIterator
	{
		public:
			typedef T		value_type;
			typedef Compare	key_compare;
			typedef Alloc	allocator_type;

			typedef size_t	size_type;

			typedef node<value_type>	node;
			typedef node				*node_ptr;

			typedef ft::NodeIterator<node>							iterator;
			typedef ft::NodeIterator<node>							const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;


			MapIterator(const key_compare& comp = key_compare(), 
			const allocator_type& alloc = allocator_type()): _alloc(alloc), _comp(comp){
				_size = 0;
				_first = NULL;
			};

			bool empty() const {return (_size == 0);}
			size_type size() const {return _size;}
			size_type	max_size() const {return _alloc.max_size();}


		private:
			node_ptr		_first;
			size_type		_size;
			allocator_type	_alloc;
			key_compare		_comp;

			

			node_ptr _new_node(const value_type &val)
			{
				node_ptr ret = _alloc.allocate(1);
				_alloc.construct(ret, val);
				ret->left = NULL;
				ret->right = NULL;
				ret->parent = NULL;

				return ret;
			}
	};



}

#endif
