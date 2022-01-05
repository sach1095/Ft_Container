# include "../includes/all.hpp"

static bool check_equal(ft::vector<int, std::allocator<int> > &my_vector, std::vector<int, std::allocator<int> > &realvector)
{
	if (my_vector.capacity() != realvector.capacity())
		return (FAIL);
	else if (my_vector.size() != realvector.size())
		return (FAIL);

	for (size_t i = 0; i < realvector.size(); i++)
	{
		if (my_vector.at(i) != realvector.at(i))
			return (FAIL);
	}
	return (SUCCESS);
}

/**********************************************************************************/
/*** TEST 1 : *********************************************************************/
/*** create vector no args and check capacity size and check stack ****************/
/**********************************************************************************/
static bool	test_v1()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;

	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}


/***********************************************************************************/
/*** TEST 2 : **********************************************************************/
/*** create vector no args push_back int 5 and check capacity size and check stack */
/***********************************************************************************/
static bool	test_v2()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;

	my_vector.push_back(5);

	realvector.push_back(5);

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

	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 5 : ***********************************************************************/
/*** create vector no args check max_size function return ***************************/
/************************************************************************************/
static bool	test_v5()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;

	if (my_vector.max_size() != realvector.max_size() )
		return (FAIL);
	return (SUCCESS);
}

bool ft_vector_test()
{
		std::cout << "\033[3;33m------- \033[3;34mStart \033[3;32mVector \033[3;35mTest \033[3;33m-------\033[0m\n" << std::endl;
	/*------------------------------------ test v1 ------------------------------------*/
	if (test_v1())
	{
		std::cout << "Test v1 : \033[1;31m[X]\033[0m" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v1 : \033[1;32m[√]\033[0m" << std::endl;

	/*------------------------------------ test v2 ------------------------------------*/
	if (test_v2())
	{
		std::cout << "Test v2 : \033[1;31m[X]\033[0m" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v2 : \033[1;32m[√]\033[0m" << std::endl;

	/*------------------------------------ test v3 ------------------------------------*/
	if (test_v3())
	{
		std::cout << "Test v3 : \033[1;31m[X]\033[0m" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v3 : \033[1;32m[√]\033[0m" << std::endl;

	/*------------------------------------ test v4 ------------------------------------*/
	if (test_v4())
	{
		std::cout << "Test v4 : \033[1;31m[X]\033[0m" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v4 : \033[1;32m[√]\033[0m" << std::endl;

	/*------------------------------------ test v5 ------------------------------------*/
	if (test_v5())
	{
		std::cout << "Test v5 : \033[1;31m[X]\033[0m" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v5 : \033[1;32m[√]\033[0m" << std::endl;

	std::vector<int> myvector (5);  // 5 default-constructed ints

	 int i = 0;

	 std::vector<int>::reverse_iterator rit = myvector.rbegin();
	 for (; rit!= myvector.rend(); ++rit)
	   *rit = ++i;

	 std::cout << "myvector contains:";
	 for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
	   std::cout << ' ' << *it;
	 std::cout << '\n';


	/*------------------------------------ End test ------------------------------------*/
	std::cout << "\n\033[3;33m------- \033[3;34mEnd \033[3;32mVector \033[3;35mTest \033[3;33m-------\033[0m\n" << std::endl;

	return (SUCCESS);
}
