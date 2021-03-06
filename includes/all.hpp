#ifndef _ALL_HPP_
#define _ALL_HPP_

#pragma once

# define SUCCESS 0
# define FAIL 1

# include <iostream>
# include <memory>
# include <sys/time.h>
# include <string.h>
# include <limits.h>
# include <ctime>
# include <chrono>
# include <algorithm>
# include <array>
# include <iterator>
# include <ios>
# include <istream>
# include <iomanip>
# include <cstring>
# include <cmath>
# include <sstream>
# include <string>
# include <cctype>
# include <cstdlib>
# include <vector>
# include <stack>
# include <map>

typedef unsigned long long uint64;

# include "../includes/enable_if.hpp"
# include "../includes/lecxico_equal.hpp"
# include "../includes/is_integral.hpp"
# include "../includes/pair.hpp"
# include "../includes/All_Iterator.hpp"
# include "../includes/vector.hpp"
# include "../includes/stack.hpp"
# include "../includes/map_tree.hpp"
# include "../includes/map.hpp"

uint64	get_time(void);

bool	ft_vector_test();
bool	ft_stack_test();
bool	ft_map_test();
bool	ft_map_speed_test();

#endif
