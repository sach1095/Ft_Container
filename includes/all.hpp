#ifndef _ALL_HPP_
#define _ALL_HPP_

#pragma once

# define SUCCESS 0
# define FAIL 1

# include <iostream>
# include <vector>
# include <memory>
# include <string.h>
# include <array>
# include <iterator>
# include <ios>
# include <limits.h>
# include <istream>
# include <iomanip>

struct input_iterator_tag {};

# include "../includes/iterator_traits.hpp"
# include "../includes/Reverse_Iterator.hpp"
# include "../includes/Random_Access_Iterator.hpp"
# include "../includes/enable_if.hpp"
# include "../includes/is_integral.hpp"
# include "../includes/lecxico_equal.hpp"
# include "../includes/vector.hpp"

bool	ft_vector_test();

#endif
