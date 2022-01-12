#ifndef _ENABLE_IF_HPP_
# define _ENABLE_IF_HPP_

#pragma once

namespace ft{

	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };
}

#endif
