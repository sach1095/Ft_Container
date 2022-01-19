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

		typedef typename ft::MapIterator<value_type, value_compare>::iterator				iterator;
		typedef typename ft::MapIterator<value_type, value_compare>::const_iterator			const_iterator;
		typedef typename ft::MapIterator<value_type, value_compare>::reverse_iterator		reverse_iterator;
		typedef typename ft::MapIterator<value_type, value_compare>::const_reverse_iterator	const_reverse_iterator;

		typedef size_t										size_type;
		typedef ptrdiff_t									difference_type;

	protected:
		ft::MapIterator<value_type, key_compare>	_map;
		key_compare									_comp;
		allocator_type								_alloc;

	public:

		// explicit map (const key_compare& comp = key_compare(),
		// 	const allocator_type& alloc = allocator_type())
		// {

		// }

		/****************************************************************************************************************************/
		/******************************************  Member functions ***************************************************************/
		/****************************************************************************************************************************/

		/****************************************************************************************************************************/
		/******************************************  Iterators **********************************************************************/
		/****************************************************************************************************************************/


		/****************************************************************************************************************************/
		/******************************************  Capacity ***********************************************************************/
		/****************************************************************************************************************************/


		allocator_type get_allocator() const { return _alloc;}
	};

		/****************************************************************************************************************************/
		/******************************************  Element access *****************************************************************/
		/****************************************************************************************************************************/

	// template <class T, class Alloc>
	// bool operator== (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
	// 	if (lhs.size() != rhs.size())
	// 		return false;	
	// 	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	// }

	// template <class T, class Alloc>
	// bool operator!= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
	// 	return !(lhs == rhs);
	// }

	// template <class T, class Alloc>
	// bool operator<  (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
	// 	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	// }

	// template <class T, class Alloc>
	// bool operator<= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
	// 	if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
	// 		return true;
	// 	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	// }

	// template <class T, class Alloc>
	// bool operator>  (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
	// 	if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
	// 		return false;
	// 	return !ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	// }

	// template <class T, class Alloc>
	// bool operator>= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs){
	// 	if (lhs == rhs)
	// 		return true;
	// 	return !ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	// }

	// template <class T, class Alloc>
	// void swap (map<T,Alloc>& x, map<T,Alloc>& y){
	// 	x.swap(y);
	// }

}

#endif
