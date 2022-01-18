# include "../includes/all.hpp"

# include <map>

// static bool check_equal(ft::map<char, int> &my_map, std::map<char,int> &realmap)
// {
// 	std::map<char,int>::iterator it = realmap.begin();
// 	ft::map<char,int>::iterator mit = my_map.begin();

// 	std::cout << "-----------------\nrealmap :" << std::endl;
// 	for (it = realmap.begin(); it != realmap.end(); ++it)
// 		std::cout << it->first << " => " << it->second << '\n';

// 	std::cout << "my_map :" << std::endl;
// 	for (mit = my_map.begin(); mit! = my_map.end(); ++it)
// 		std::cout << it->first << " => " << it->second << '\n';

// 	// if (my_map.size() != realmap.size())
// 	// 	return (FAIL);
// 	return (SUCCESS);
// }


/************************************************************************************/
/*** TEST 1 : ***********************************************************************/
/*** create stack no args and check size and check last element *********************/
/************************************************************************************/
// static bool	test_v1()
// {
// 	// std::map<char,int> realmap;
// 	// ft::map<char, int> my_map;

// 	if (check_equal(my_map, realmap))
// 		return (FAIL);
// 	return (SUCCESS);
// }

bool ft_map_test()
{
	std::cout << "\033[3;33m------- \033[3;34mStart \033[3;32mMap \033[3;35mTest \033[3;33m-------\033[0m\n" << std::endl;
	// /*------------------------------------ test v1 ------------------------------------*/
	// if (test_v1())
	// {
	// 	std::cout << "-----------------\nTest v1 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
	// 	return (FAIL);
	// }
	// else
	// 	std::cout << "-----------------\nTest v1 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	// if (test_v2())
	// {
	// 	std::cout << "-----------------\nTest v2 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
	// 	return (FAIL);
	// }
	// else
	// 	std::cout << "-----------------\nTest v2 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	// if (test_v3())
	// {
	// 	std::cout << "-----------------\nTest v3 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
	// 	return (FAIL);
	// }
	// else
	// 	std::cout << "-----------------\nTest v3 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	// if (test_v4())
	// {
	// 	std::cout << "-----------------\nTest v4 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
	// 	return (FAIL);
	// }
	// else
	// 	std::cout << "-----------------\nTest v4 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	// if (test_v5())
	// {
	// 	std::cout << "-----------------\nTest v5 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
	// 	return (FAIL);
	// }
	// else
	// 	std::cout << "-----------------\nTest v5 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	/*------------------------------------ End test ------------------------------------*/
	std::cout << "\n\033[3;33m------- \033[3;34mEnd \033[3;32mMap \033[3;35mTest \033[3;33m-------\033[0m\n" << std::endl;

	return (SUCCESS);
}
