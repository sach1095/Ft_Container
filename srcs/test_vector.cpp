# include "../includes/all.hpp"

/**********************************************************************************/
/*** TEST 1 : *********************************************************************/
/*** create vector no args and check capacity size and at index 0 *****************/
/**********************************************************************************/
static bool	test_v1()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;

	if (my_vector.capacity() != realvector.capacity())
		return (FAIL);
	else if (my_vector.size() != realvector.size())
		return (FAIL);
	return (SUCCESS);
}


/**********************************************************************************/
/*** TEST 2 : *********************************************************************/
/*** create vector no args push_back int 5 and check capacity size and at index 0 */
/**********************************************************************************/
static bool	test_v2()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;

	my_vector.push_back(5);

	realvector.push_back(5);

	if (my_vector.capacity() != realvector.capacity())
		return (FAIL);
	else if (my_vector.size() != realvector.size())
		return (FAIL);
	else if (my_vector.at(0) != realvector.at(0))
		return (FAIL);
	return (SUCCESS);
}

/***********************************************************************************/
/*** TEST 3 : **********************************************************************/
/*** create vector no args push_back string and check capacity size and at index 0 */
/***********************************************************************************/
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

	if (my_vector.capacity() != realvector.capacity())
		return (FAIL);
	else if (my_vector.size() != realvector.size())
		return (FAIL);
	else if (my_vector.at(0) != realvector.at(0))
		return (FAIL);
	return (SUCCESS);
}

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

	if (my_vector.capacity() != realvector.capacity())
		return (FAIL);
	else if (my_vector.size() != realvector.size())
		return (FAIL);
	else if (my_vector.at(0) != realvector.at(0))
		return (FAIL);
	return (SUCCESS);
}

static bool	test_v5()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;
	return (SUCCESS);
}

bool ft_vector_test()
{
	std::cout << "------- Start Vector test -------\n" << std::endl;

	if (test_v1())
	{
		std::cout << "Test v1 : \033[1;31m[X]\033[0m" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v1 : \033[1;32m[√]\033[0m" << std::endl;

	if (test_v2())
	{
		std::cout << "Test v2 : \033[1;31m[X]\033[0m" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v2 : \033[1;32m[√]\033[0m" << std::endl;
	if (test_v3())
	{
		std::cout << "Test v3 : \033[1;31m[X]\033[0m" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v3 : \033[1;32m[√]\033[0m" << std::endl;
	if (test_v4())
	{
		std::cout << "Test v4 : \033[1;31m[X]\033[0m" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v4 : \033[1;32m[√]\033[0m" << std::endl;
	if (test_v5())
	{
		std::cout << "Test v5 : \033[1;31m[X]\033[0m" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v5 : \033[1;32m[√]\033[0m" << std::endl;
	std::cout << "End of vector test" << std::endl;
	return (SUCCESS);
}
