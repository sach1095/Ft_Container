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
		return (set_c3d_error(Error_test_v1));
	else if (my_vector.size() != realvector.size())
		return (set_c3d_error(Error_test_v1));
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
		return (set_c3d_error(Error_test_v2));
	else if (my_vector.size() != realvector.size())
		return (set_c3d_error(Error_test_v2));
	else if (my_vector.at(0) != realvector.at(0))
		return (set_c3d_error(Error_test_v2));
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
		return (set_c3d_error(Error_test_v3));
	else if (my_vector.size() != realvector.size())
		return (set_c3d_error(Error_test_v3));
	else if (my_vector.at(0) != realvector.at(0))
		return (set_c3d_error(Error_test_v3));
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

	for (size_t i = 0; i < my_vector.size(); i++)
	{
		std::cout << "my stocket = " << i << " = " << my_vector.at(i) << std::endl;
	}

	realvector.push_back(1);
	realvector.push_back(2);

	realvector.pop_back();

	realvector.push_back(5);

	for (size_t i = 0; i < realvector.size(); i++)
	{
		std::cout << "stocket = " << i << " = " << realvector.at(i) << std::endl;
	}

	if (my_vector.capacity() != realvector.capacity())
		return (set_c3d_error(Error_test_v4));
	else if (my_vector.size() != realvector.size())
		return (set_c3d_error(Error_test_v4));
	else if (my_vector.at(0) != realvector.at(0))
		return (set_c3d_error(Error_test_v4));
	return (SUCCESS);
}

bool ft_vector_test()
{
	std::cout << "------- Start Vector test -------\n" << std::endl;
	if (test_v1())
		return (FAIL);
	if (test_v2())
		return (FAIL);
	if (test_v3())
		return (FAIL);
	if (test_v4())
		return (FAIL);
	std::cout << "End of vector test" << std::endl;
	return (SUCCESS);
}
