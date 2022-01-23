#ifndef _MAP_HPP_
# define _MAP_HPP_

#pragma once

namespace ft
{
	template < class Key, 
	class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
	class map{

	public :

		typedef Key											key_type;
		typedef T											mapped_type;
		typedef ft::pair<const key_type, mapped_type>		value_type;
		typedef Compare										key_compare;
		typedef Alloc 										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

		class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				public:
					value_compare (Compare c) : comp(c) {}

				protected:
					Compare comp;

				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

		typedef typename ft::MyTree<value_type, value_compare>::iterator				iterator;
		typedef typename ft::MyTree<value_type, value_compare>::const_iterator			const_iterator;
		typedef typename ft::MyTree<value_type, value_compare>::reverse_iterator		reverse_iterator;
		typedef typename ft::MyTree<value_type, value_compare>::const_reverse_iterator	const_reverse_iterator;

		typedef ptrdiff_t									difference_type;
		typedef size_t										size_type;

	protected:
		key_compare							_comp;
		allocator_type						_alloc;
		ft::MyTree<value_type, key_compare>	_map;

	public:

		/*************************************************************************************************************************/
		/***************************************  Member functions ***************************************************************/
		/*************************************************************************************************************************/

		explicit map (const key_compare& comp = key_compare(), 
		const allocator_type& alloc = allocator_type()): _comp(comp), _alloc(alloc) {};
		
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc)
		{
			while (first != last)
				insert(*first++);
		}

		map (const map &new_map)
		{
			_alloc = new_map._alloc;
			_comp = new_map._comp;
			_map = new_map._map;
		}

		~map(){};

		/****************************************************************************************************************************/
		/******************************************  Iterators **********************************************************************/
		/****************************************************************************************************************************/

		iterator begin() {return _map.begin();}
		const_iterator begin() const {return _map.begin();}
		iterator end() {return _map.end();}
		const_iterator end() const {return _map.end();}
		reverse_iterator rbegin(){return reverse_iterator(end());}
		const_reverse_iterator rbegin() const {return const_reverse_iterator(end());}
		reverse_iterator rend(){return reverse_iterator(begin());}
		const_reverse_iterator rend() const {return const_reverse_iterator(begin());}

		/****************************************************************************************************************************/
		/******************************************  Capacity ***********************************************************************/
		/****************************************************************************************************************************/

		bool empty() const {return _map.empty();}
		size_type size() const {return _map.size();}
		size_type	max_size() const {return _map.max_size();}

		/****************************************************************************************************************************/
		/******************************************  Element access *****************************************************************/
		/****************************************************************************************************************************/

		mapped_type& operator[] (const key_type& k)
		{
			return (*((this->insert(ft::make_pair(k,mapped_type()))).first)).second;
		}

		/****************************************************************************************************************************/
		/******************************************  Modifiers **********************************************************************/
		/****************************************************************************************************************************/

		ft::pair<iterator,bool> insert (const value_type& val)
		{ 
			return _map.insert(val, _map.getFirts());
		}

		iterator insert (iterator position, const value_type& val){
			return _map.insert(position, val);
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last){
			while (first != last)
				_map.insert(*first++, _map.getFirts());
		}

		void erase (iterator position){ _map.erase(position); }

		size_type erase (const key_type& k){ return _map.erase(ft::make_pair(k, mapped_type())); }

		void erase (iterator first, iterator last){
			while (first != last)
				_map.erase(first++);
		}

		void swap (map& x)
		{
			allocator_type tmpAlloc = _alloc;
			key_compare tmpComp = _comp;

			_alloc = x._alloc;
			_comp = x._comp;

			x._alloc = tmpAlloc;
			x._comp = tmpComp;

			_map.swap(x._map);
		}

		void clear() { _map.clear(); }

		/****************************************************************************************************************************/
		/******************************************  Observers **********************************************************************/
		/****************************************************************************************************************************/
		
		key_compare key_comp() const {return key_compare();}
		value_compare value_comp() const {return value_compare(key_compare());}

		/****************************************************************************************************************************/
		/******************************************  Operations *********************************************************************/
		/****************************************************************************************************************************/

		iterator find (const key_type& k)
		{
			iterator ret(_map.find(ft::make_pair(k, mapped_type())), _map.getFirts());
			return ret;
		}

		const_iterator find (const key_type& k) const
		{
			iterator ret(_map.find(ft::make_pair(k, mapped_type())), _map.getFirts());
			return ret;
		}

		size_type count (const key_type& k) const { return _map.count(ft::make_pair(k, mapped_type())); }

		iterator lower_bound (const key_type& k) { return _map.lower_bound(ft::make_pair(k, mapped_type())); }
		const_iterator lower_bound (const key_type& k) const { return _map.lower_bound(ft::make_pair(k, mapped_type())); }

		iterator upper_bound (const key_type& k) { return _map.upper_bound(ft::make_pair(k, mapped_type())); }
		const_iterator upper_bound (const key_type& k) const { return _map.upper_bound(ft::make_pair(k, mapped_type())); }
		
		ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
			const_iterator low = lower_bound(k);
			const_iterator up = upper_bound(k);
			return ft::make_pair(low, up);
		}
		ft::pair<iterator,iterator> equal_range (const key_type& k) {
			iterator low = lower_bound(k);
			iterator up = upper_bound(k);
			return ft::make_pair(low, up);
		}

		/****************************************************************************************************************************/
		/******************************************  Allocator **********************************************************************/
		/****************************************************************************************************************************/

		allocator_type get_allocator() const { return _alloc;}

	};

	template <class T, class Alloc>
	bool operator== (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
			if (lhs.size() != rhs.size())
				return false;	
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}

	template <class T, class Alloc>
	bool operator!= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
			return !(lhs == rhs);
		}

	template <class T, class Alloc>
	bool operator<  (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

	template <class T, class Alloc>
	bool operator<= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
			if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
				return true;
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

	template <class T, class Alloc>
	bool operator>  (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
			if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
				return false;
			return !ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

	template <class T, class Alloc>
	bool operator>= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
			if (lhs == rhs)
				return true;
			return !ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

	template <class T, class Alloc>
	void swap (map<T,Alloc>& x, map<T,Alloc>& y){
		x.swap(y);
	}

}

#endif
