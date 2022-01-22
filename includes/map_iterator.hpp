#ifndef _MAP_ITERATOR_HPP_
# define _MAP_ITERATOR_HPP_

#pragma once

namespace ft {

	template <class T, class Compare, class Alloc = std::allocator<node<T> > >
	class MyTree
	{
		public:
			typedef T		value_type;
			typedef Compare	key_compare;
			typedef Alloc	allocator_type;

			typedef size_t	size_type;

			typedef node<value_type>	node;
			typedef node				*node_ptr;

			typedef ft::TreeIterator<node>							iterator;
			typedef ft::TreeIterator<node>							const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		/*************************************************************************************************************************/
		/***************************************  Member functions ***************************************************************/
		/*************************************************************************************************************************/

		MyTree(const key_compare& comp = key_compare(), 
		const allocator_type& alloc = allocator_type()): _comp(comp), _alloc(alloc) {
			_size = 0;
			_first = NULL;
		};

		MyTree operator=(MyTree const& copy)
			{
				if (this != &copy)
				{
					_alloc = copy._alloc;
					_comp = copy._comp;
					_size = copy._size;
					_CopyAll(*this, copy._first);
				}
				return *this;
			}

		MyTree(MyTree const& copy)
			{
				_alloc = copy._alloc;
				_comp = copy._comp;
				_size = copy._size;
				_CopyAll(*this, copy._first);
			}

		~MyTree()
			{
				if (_size > 0)
					_clear(_first);
			}

		/****************************************************************************************************************************/
		/******************************************  Iterators **********************************************************************/
		/****************************************************************************************************************************/

		iterator begin() {
			if (!_first)
				return end();
			return iterator(_min(_first), _first);
		}

		iterator begin() const {
			if (!_first)
				return end();
			return iterator(_min(_first), _first);
		}

		iterator end() { return iterator(NULL, _first); }
		iterator end() const { return iterator(NULL, _first); }
		
		/****************************************************************************************************************************/
		/******************************************  Capacity ***********************************************************************/
		/****************************************************************************************************************************/

		bool empty() const {return (_size == 0);}
		size_type size() const {return _size;}
		size_type	max_size() const {return (461168601842738790);}

		/****************************************************************************************************************************/
		/******************************************  Modifiers **********************************************************************/
		/****************************************************************************************************************************/

		ft::pair<iterator, bool> insert(value_type val, node_ptr start)
		{
			node_ptr cursor = start;
			node_ptr prev = NULL;

			while (cursor != NULL)
			{
				prev = cursor;

				if (_comp(val.first, cursor->data.first))
					cursor = cursor->left;
				else if (_comp(cursor->data.first, val.first))
					cursor = cursor->right;
				else
					return ft::make_pair<iterator, bool>(iterator(cursor, _first), false);
			}

			node_ptr new_node = _new_node(val);
			new_node->parent = prev;
			if (prev == NULL)
			{
				_first = new_node;
				_first->parent = NULL;
			}
			else if (_comp(new_node->data.first, prev->data.first))
				prev->left = new_node;
			else
				prev->right = new_node;
			_size++;

			return (ft::make_pair<iterator, bool>(iterator(new_node, _first), true));
		}

		iterator insert (iterator position, const value_type& val)
		{
			node_ptr next = _findNext(position.getCurrent());
			if (_comp(position.getCurrent()->data.first, val.first) && _comp(val.first, next->data.first))
			{
				ft::pair<iterator, bool> result = insert(val, position.getCurrent());
				return result.first;
			}
			else
				return insert(val, _first).first;
		}

		void	erase(iterator position)
		{
			node_ptr tmp = find(*position);
			if (!tmp)
				return ;
			_remove(tmp);
		}

		size_type erase(value_type const &k)
		{
			node_ptr tmp = find(k);
			if (tmp)
				_remove(tmp);
			else
				return 0;
			return 1;
		}

		void swap (MyTree& x){
			node_ptr		tmp_first = _first;
			size_type		tmp_size = _size;
			allocator_type	tmp_alloc = _alloc;
			key_compare		tmp_comp = _comp;

			_first = x._first;
			_size = x._size;
			_alloc = x._alloc;
			_comp = x._comp;

			x._first = tmp_first;
			x._size = tmp_size;
			x._alloc = tmp_alloc;
			x._comp = tmp_comp;
		}

		void	clear()
		{
			_clear(_first);
			_size = 0;
			_first = NULL;
		}

		/****************************************************************************************************************************/
		/******************************************  Operations *********************************************************************/
		/****************************************************************************************************************************/

		node_ptr find(value_type const& val) const
		{
			node_ptr tmp = _first;

			while (tmp)
			{
				if (val.first == tmp->data.first)
					return tmp;
				else if (_comp(val.first, tmp->data.first))
					tmp = tmp->left;
				else 
					tmp = tmp->right;
			}
			return NULL;
		}

		size_type count (const value_type& val) const
		{
			if (find(val))
				return 1;
			return 0;
		}

		node_ptr	getFirts() const {return _first;}

		private:
			node_ptr		_first;
			size_type		_size;
			key_compare		_comp;
			allocator_type	_alloc;

			node_ptr _new_node(const value_type &val)
			{
				node_ptr ret = _alloc.allocate(1);
				_alloc.construct(ret, val);
				ret->left = NULL;
				ret->right = NULL;
				ret->parent = NULL;

				return ret;
			}

			void	_remove(node_ptr to_remove)
			{
				node_ptr save;

				if (to_remove->right && to_remove->left) // two children
				{
					if (_comp(to_remove->data.first, _first->data.first)) // left side
					{
						save = _min(to_remove->right);
						node_ptr buf = save->parent;
						save->parent = to_remove->parent;
						save->left = to_remove->left;
						to_remove->parent->left = save;
						to_remove->left->parent = save;

						if (to_remove->right != save)
						{
							save->right = to_remove->right;
							to_remove->right->parent = save;
							if (buf != to_remove)
								buf->left = NULL;
						}
					}
					else // right side
					{
						save = _max(to_remove->left);

						node_ptr buf = save->parent;
						save->parent = to_remove->parent;
						save->right = to_remove->right;
							
						to_remove->right->parent = save;
						if (to_remove->parent)
							to_remove->parent->left = save;
						if (to_remove->left != save)
						{
							save->left = to_remove->left;
							to_remove->left->parent = save;

							if (buf != to_remove)
								buf->right = NULL;
						}
						if (save->parent == NULL)
							_first = save;
						
					}
				}
				else if (to_remove->left) // if he have one child
				{
					save = to_remove->left;

					if (to_remove->parent)
					{
						save->parent = to_remove->parent;
						if (to_remove == to_remove->parent->right)
							to_remove->parent->right = save;
						else if (to_remove == to_remove->parent->left)
							to_remove->parent->left = save;
					}
					else
					{
						save->parent = NULL;
						_first = save;
					}
				}
				else if (to_remove->right)
				{
					save = to_remove->right;

					if (to_remove->parent)
					{
						save->parent = to_remove->parent;
						if (to_remove == to_remove->parent->right)
							to_remove->parent->right = save;
						else if (to_remove == to_remove->parent->left)
							to_remove->parent->left = save;
					}
					else
					{
						save->parent = NULL;
						_first = save;
					}
				}
				else // if no children
				{
					if (to_remove != _first)
					{
						if (to_remove == to_remove->parent->right)
							to_remove->parent->right = NULL;
						else if (to_remove == to_remove->parent->left)
							to_remove->parent->left = NULL;
					}
				}
				_alloc.destroy(to_remove);
				_alloc.deallocate(to_remove, 1);
				_size--;
			}

			void	_CopyAll(MyTree &dest, node_ptr copy)
			{
				if (copy != NULL)
				{
					_CopyAll(dest, copy->left);
					dest.insert(copy->data, _first);
					_CopyAll(dest, copy->right);
				}
			}

			void	_clear(node_ptr ptr)
			{
				if (!ptr)
					return ;
				_clear(ptr->left);
				_clear(ptr->right);
				_alloc.destroy(ptr);
				_alloc.deallocate(ptr, 1);
			}

			node_ptr _findNext(node_ptr ptr)
			{
				node_ptr next = NULL;

				if (ptr->right != NULL)
					return _min(ptr->right);

				next = ptr->parent;
				while (next != NULL && ptr == next->right)
				{
					ptr = next;
					next = next->parent;
				}
				return next;
			}

			node_ptr	_min(node_ptr cursor)
			{
				while (cursor->left != NULL)
					cursor = cursor->left;
				return cursor;
			}

			node_ptr	_min(node_ptr cursor) const
			{
				while (cursor->left != NULL)
					cursor = cursor->left;
				return cursor;
			}

			node_ptr	_max(node_ptr cursor)
			{
				while (cursor->right != NULL)
					cursor = cursor->right;
				return cursor;
			}
	};
}

#endif
