#ifndef _IS_INTERGRAL_HPP_
# define _IS_INTERGRAL_HPP_

#pragma once

namespace ft{

template< class T > struct remove_cv                   { typedef T type; };
	template< class T > struct remove_cv<const T>          { typedef T type; };
	template< class T > struct remove_cv<volatile T>       { typedef T type; };
	template< class T > struct remove_cv<const volatile T> { typedef T type; };

	template<class T, T v>
	struct integral_constant {
		const static T value = v;
		typedef T value_type;
		typedef integral_constant<T, v> type;
		operator value_type() const { return value; }
		value_type operator()() const { return value; }
	};

	typedef integral_constant<bool,true> true_type;
	typedef integral_constant<bool,false> false_type;

	template <class T>	struct _is_integral_impl                     		: public false_type {};
	template <>			struct _is_integral_impl<bool>						: public true_type {};
	template <>			struct _is_integral_impl<char>						: public true_type {};
	template <>			struct _is_integral_impl<char16_t>					: public true_type {};
	template <>			struct _is_integral_impl<char32_t>					: public true_type {};
	template <>			struct _is_integral_impl<wchar_t>					: public true_type {};
	template <>			struct _is_integral_impl<signed char>				: public true_type {};
	template <>			struct _is_integral_impl<short int>					: public true_type {};
	template <>			struct _is_integral_impl<int>						: public true_type {};
	template <>			struct _is_integral_impl<long int>					: public true_type {};
	template <>			struct _is_integral_impl<long long int>				: public true_type {};
	template <>			struct _is_integral_impl<unsigned char>				: public true_type {};
	template <>			struct _is_integral_impl<unsigned short int>		: public true_type {};
	template <>			struct _is_integral_impl<unsigned int>				: public true_type {};
	template <>			struct _is_integral_impl<unsigned long int>			: public true_type {};
	template <>			struct _is_integral_impl<unsigned long long int>	: public true_type {};

	template <class T>	struct is_integral : public _is_integral_impl<typename remove_cv<T>::type> {};

}

#endif
