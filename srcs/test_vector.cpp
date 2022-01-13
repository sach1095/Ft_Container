# include "../includes/all.hpp"

static bool check_equal(ft::vector<int, std::allocator<int> > &my_vector, std::vector<int, std::allocator<int> > &realvector)
{
	int i = 0;
	ft::vector<int>::iterator it;

	for (it = my_vector.begin(); it != my_vector.end(); it++)
	{
		if (my_vector.at(i) != realvector.at(i))
			return (FAIL);
		i++;
	}
	if (my_vector.capacity() != realvector.capacity())
	{
		std::cout << "your capatciy is = " << my_vector.capacity() << " and is suppose to be = " << realvector.capacity() << std::endl;
		return (FAIL);
	}
	else if (my_vector.size() != realvector.size())
	{
		// std::cout << "your size is = " << my_vector.size() << "and is suppose to be = " << realvector.size() << std::endl;
		return (FAIL);
	}
	return (SUCCESS);
}

static void	print(ft::vector<int, std::allocator<int> > &my_vector, std::vector<int, std::allocator<int> > &realvector)
{
	std::cout << "-----------------\nrealvector :" << std::endl;
	for (size_t i = 0; i < realvector.size(); i++)
	{
		std::cout << realvector.at(i) << " ";
	}
	std::cout << std::endl;

	std::cout << "my_vector :" << std::endl;
	for (size_t i = 0; i < my_vector.size(); i++)
	{
		std::cout << my_vector.at(i) << " ";
	}
	std::cout << "\n" << std::endl;
}

/************************************************************************************/
/*** TEST 1 : ***********************************************************************/
/*** create vector no args and check capacity size and check stack ******************/
/************************************************************************************/
static bool	test_v1()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;

	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}


/************************************************************************************/
/*** TEST 2 : ***********************************************************************/
/*** create vector no args push_back int 5 and check capacity size and check stack **/
/************************************************************************************/
static bool	test_v2()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;

	my_vector.push_back(5);

	realvector.push_back(5);

	print(my_vector, realvector);
	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 3 : ***********************************************************************/
/*** create vector no args push_back 3 time and check capacity size and check stack */
/************************************************************************************/
static bool	test_v3()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;

	my_vector.push_back(1);
	my_vector.push_back(2);
	my_vector.push_back(3);

	realvector.push_back(1);
	realvector.push_back(2);
	realvector.push_back(3);

	print(my_vector, realvector);
	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 4 : ***********************************************************************/
/*** create vector no args push_back 3 time and check capacity size and check stack */
/************************************************************************************/
static bool	test_v4()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;

	my_vector.push_back(1);
	my_vector.push_back(2);
	my_vector.pop_back();
	my_vector.push_back(5);


	realvector.push_back(1);
	realvector.push_back(2);
	realvector.pop_back();
	realvector.push_back(5);

	print(my_vector, realvector);
	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 5 : ***********************************************************************/
/*** create vector no args check front function return ******************************/
/************************************************************************************/
static bool	test_v5()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;

	realvector.push_back(5);
	my_vector.push_back(5);

	print(my_vector, realvector);
	if (my_vector.front() != realvector.front() )
		return (FAIL);
	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 6 : ***********************************************************************/
/*** create vector 0-9 element and  check resize 5 **********************************/
/************************************************************************************/
static bool	test_v6()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;

	for (size_t i = 0; i < 10; i++)
	{
		realvector.push_back(i);
		my_vector.push_back(i);
	}

	realvector.resize(5);

	my_vector.resize(5);

	print(my_vector, realvector);
	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 7 : ***********************************************************************/
/*** create vector 0-3 element and  check resize 5 **********************************/
/************************************************************************************/
static bool	test_v7()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;

	for (size_t i = 0; i < 3; i++)
	{
		realvector.push_back(i);
		my_vector.push_back(i);
	}

	realvector.resize(5);

	my_vector.resize(5);

	print(my_vector, realvector);
	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 8 : ***********************************************************************/
/*** create vector 0-3 element and check resize 5 witch value ***********************/
/************************************************************************************/
static bool	test_v8()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;

	for (size_t i = 0; i < 3; i++)
	{
		realvector.push_back(i);
		my_vector.push_back(i);
	}

	realvector.resize(5, 100);

	my_vector.resize(5, 100);

	print(my_vector, realvector);
	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 9 : ***********************************************************************/
/*** create vector 0-3 element and check reserve 3 differante time ******************/
/************************************************************************************/
static bool	test_v9()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;

	for (size_t i = 0; i < 3; i++)
	{
		realvector.push_back(i);
		my_vector.push_back(i);
	}

	realvector.reserve(6);
	my_vector.reserve(6);

	if (my_vector.capacity() != realvector.capacity()) { return (FAIL); }

	realvector.reserve(2);
	my_vector.reserve(2);

	if (my_vector.capacity() != realvector.capacity()) { return (FAIL); }

	realvector.reserve(14);
	my_vector.reserve(14);

	print(my_vector, realvector);
	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}


/************************************************************************************/
/*** TEST 10 : **********************************************************************/
/*** check empty function witch vector empty and not empty **************************/
/************************************************************************************/
static bool	test_v10()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;

	if (realvector.empty() != my_vector.empty())
		return (FAIL);

	for (size_t i = 0; i < 3; i++)
	{
		realvector.push_back(i);
		my_vector.push_back(i);
	}

	if (realvector.empty() != my_vector.empty())
		return (FAIL);

	print(my_vector, realvector);
	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 11 : **********************************************************************/
/*** check assign function - vector witch more element ******************************/
/************************************************************************************/
static bool	test_v11()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;

	for (size_t i = 0; i < 8; i++)
	{
		realvector.push_back(i);
		my_vector.push_back(i);
	}
	print(my_vector, realvector);
	realvector.assign(5, 100);
	my_vector.assign(5, 100);

	print(my_vector, realvector);
	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 12 : **********************************************************************/
/*** check assign function - vector witch less element ******************************/
/************************************************************************************/
static bool	test_v12()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;

	for (size_t i = 0; i < 2; i++)
	{
		realvector.push_back(i);
		my_vector.push_back(i);
	}
	realvector.assign(5, 100);
	my_vector.assign(5, 100);

	print(my_vector, realvector);
	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 13 : **********************************************************************/
/*** check assign function - vector empty *******************************************/
/************************************************************************************/
static bool	test_v13()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;

	realvector.assign(5, 100);
	my_vector.assign(5, 100);

	print(my_vector, realvector);
	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 14 : **********************************************************************/
/*** check insert function witch it and value ***************************************/
/************************************************************************************/
static bool	test_v14()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;
	std::vector<int>::iterator it;
	ft::vector<int>::iterator my_it;

	for (size_t i = 0; i < 3; i++)
	{
		realvector.push_back(i);
		my_vector.push_back(i);
	}

	it = realvector.begin();
	it++;
	realvector.insert(it,200);
	// realvector.insert(it,300);
	// realvector.insert(it,800);

	my_it = my_vector.begin();
	my_it++;
	my_vector.insert(my_it,200);
	// my_vector.insert(my_it,300);
	// my_vector.insert(my_it,800);

	print(my_vector, realvector);
	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 15 : **********************************************************************/
/*** check insert function witch it and value ***************************************/
/************************************************************************************/
static bool	test_v15()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;
	std::vector<int>::iterator it;
	ft::vector<int>::iterator my_it;

	for (size_t i = 0; i < 4; i++)
	{
		realvector.push_back(i);
		my_vector.push_back(i);
	}

	it = realvector.begin();
	it++;
	realvector.insert(it, 3, 200);
 	my_it = my_vector.begin();
	my_it++;
	my_vector.insert(my_it, 3, 200);
	print(my_vector, realvector);
	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}
bool ft_vector_test()
{
	std::cout << "\033[3;33m------- \033[3;34mStart \033[3;32mVector \033[3;35mTest \033[3;33m-------\033[0m\n" << std::endl;
	/*------------------------------------ test v1 ------------------------------------*/
	if (test_v1())
	{
		std::cout << "-----------------\nTest v1 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "-----------------\nTest v1 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	/*------------------------------------ test v2 ------------------------------------*/
	if (test_v2())
	{
		std::cout << "Test v2 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v2 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	/*------------------------------------ test v3 ------------------------------------*/
	if (test_v3())
	{
		std::cout << "Test v3 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v3 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	/*------------------------------------ test v4 ------------------------------------*/
	if (test_v4())
	{
		std::cout << "Test v4 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v4 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	/*------------------------------------ test v5 ------------------------------------*/
	if (test_v5())
	{
		std::cout << "Test v5 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v5 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v6())
	{
		std::cout << "Test v6 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v6 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v7())
	{
		std::cout << "Test v7 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v7 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v8())
	{
		std::cout << "Test v8 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v8 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v9())
	{
		std::cout << "Test v9 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v9 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v10())
	{
		std::cout << "Test v10 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v10 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v11())
	{
		std::cout << "Test v11 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v11 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v12())
	{
		std::cout << "Test v12 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v12 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v13())
	{
		std::cout << "Test v13 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v13 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v14())
	{
		std::cout << "Test v14 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v14 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;
	if (test_v15())
	{
		std::cout << "Test v15 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v15 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;
	/*------------------------------------ End test ------------------------------------*/
	std::cout << "\n\033[3;33m------- \033[3;34mEnd \033[3;32mVector \033[3;35mTest \033[3;33m-------\033[0m\n" << std::endl;

	return (SUCCESS);
}
