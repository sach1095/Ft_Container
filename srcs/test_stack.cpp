# include "../includes/all.hpp"

static bool check_equal(ft::vector<int, std::allocator<int> > &my_vector, std::vector<int, std::allocator<int> > &realvector)
{
	int i = 0;
	ft::vector<int>::iterator it;

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
		std::cout << "your size is = " << my_vector.size() << "and is suppose to be = " << realvector.size() << std::endl;
		return (FAIL);
	}
	return (SUCCESS);
}
/************************************************************************************/
/*** TEST 1 : ***********************************************************************/
/*** create vector no args and check capacity size and check stack ******************/
/************************************************************************************/
static bool	test_v1()
{


	// if (check_equal(, ))
	// 	return (FAIL);
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

	/*------------------------------------ End test ------------------------------------*/
	std::cout << "\n\033[3;33m------- \033[3;34mEnd \033[3;32mVector \033[3;35mTest \033[3;33m-------\033[0m\n" << std::endl;

	return (SUCCESS);
}
