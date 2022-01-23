#ifndef _STACK_HPP_
# define _STACK_HPP_

#pragma once

#include "vector.hpp"

namespace ft
{
	template <class T,class Container = ft::vector<T> >
	class stack
	{
		template <class F, class K>
		friend bool operator==(const stack<F,K> &lhs, const stack<F,K> &rhs);
		template <class F, class K>
		friend bool operator!=(const stack<F,K> &lhs, const stack<F,K> &rhs);
		template <class F, class K>
		friend bool operator<(const stack<F,K> &lhs, const stack<F,K> &rhs);
		template <class F, class K>
		friend bool operator<=(const stack<F,K> &lhs, const stack<F,K> &rhs);
		template <class F, class K>
		friend bool operator>(const stack<F,K> &lhs, const stack<F,K> &rhs);
		template <class F, class K>
		friend bool operator>=(const stack<F,K> &lhs, const stack<F,K> &rhs);

	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;
		typedef typename ft::vector<T>::iterator iterator;
	
		explicit stack (const container_type& ctnr = container_type()) : _my_stack_tab(ctnr) {};

		bool empty() const {return _my_stack_tab.empty() ;}
		size_type size() const {return _my_stack_tab.size();}

		value_type& top() {return _my_stack_tab.back();}
		const value_type& top() const {return _my_stack_tab.back();}

		void push (const value_type& val) {_my_stack_tab.push_back(val);}
		void pop() { _my_stack_tab.pop_back();}

		protected:
			container_type _my_stack_tab;
	};

	template <class T, class Container>
	bool operator== (const stack<T, Container>& lhs, const stack<T, Container>& rhs) { return lhs._my_stack_tab == rhs._my_stack_tab; }
	template <class T, class Container>
	bool operator!= (const stack<T, Container>& lhs, const stack<T, Container>& rhs) { return lhs._my_stack_tab != rhs._my_stack_tab; }
	template <class T, class Container>
	bool operator<  (const stack<T, Container>& lhs, const stack<T, Container>& rhs) { return lhs._my_stack_tab <  rhs._my_stack_tab; }
	template <class T, class Container>
	bool operator<= (const stack<T, Container>& lhs, const stack<T, Container>& rhs) { return lhs._my_stack_tab <= rhs._my_stack_tab; }
	template <class T, class Container>
	bool operator>  (const stack<T, Container>& lhs, const stack<T, Container>& rhs) { return lhs._my_stack_tab >  rhs._my_stack_tab; }
	template <class T, class Container>
	bool operator>= (const stack<T, Container>& lhs, const stack<T, Container>& rhs) { return lhs._my_stack_tab >= rhs._my_stack_tab; }
}

#endif
