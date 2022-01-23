# include "../includes/all.hpp"

static bool check_equal(ft::map<int, int> &my_map, std::map<int,int> &realmap)
{
	std::cout << "-----------------\nrealmap :" << std::endl;
	for (std::map<int,int>::iterator it = realmap.begin(); it != realmap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "\nmy_map :" << std::endl;
	for (ft::map<int,int>::iterator mit = my_map.begin(); mit != my_map.end(); ++mit)
		std::cout << mit->first << " => " << mit->second << '\n';

	if (my_map.size() != realmap.size())
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 1 : ***********************************************************************/
/*** create map no args and check size **********************************************/
/************************************************************************************/
static bool	test_v1()
{
	std::map<int,int> 			realmap;
	ft::map<int,int> 			my_map;

	if (check_equal(my_map, realmap))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 2 : ***********************************************************************/
/*** create map no args and check insert 3 element size *****************************/
/************************************************************************************/
static bool	test_v2()
{
	std::map<int,int> 			realmap;
	ft::map<int,int> 			my_map;

	realmap.insert(std::pair<int,int>(0,100));
	realmap.insert(std::pair<int,int>(1,200));
	realmap.insert(std::pair<int,int>(2,300));

	my_map.insert(ft::pair<int,int>(0,100));
	my_map.insert(ft::pair<int,int>(1,200));
	my_map.insert(ft::pair<int,int>(2,300));

	if (check_equal(my_map, realmap))
		return (FAIL);
	return (SUCCESS);
}

/**************************************************************************************/
/*** TEST 3 : *************************************************************************/
/*** create map no args and insert 3 element and copy to new map witch contructor ptr */
/**************************************************************************************/
static bool	test_v3()
{
	std::map<int,int> 			realmap;
	ft::map<int,int> 			my_map;

	realmap.insert(std::pair<int,int>(0,100));
	realmap.insert(std::pair<int,int>(1,200));
	realmap.insert(std::pair<int,int>(2,300));

	my_map.insert(ft::pair<int,int>(0,100));
	my_map.insert(ft::pair<int,int>(1,200));
	my_map.insert(ft::pair<int,int>(2,300));

	ft::map<int,int> 			my_copy(my_map.begin(), my_map.end());

	if (check_equal(my_copy, realmap))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 4 : ***********************************************************************/
/*** create map no args and check insert 3 element size *****************************/
/************************************************************************************/
static bool	test_v4()
{
	ft::map<int,int> 	my_map;

	if (!my_map.empty())
		return (FAIL);

	my_map.insert(ft::pair<int,int>(0,100));

	if (my_map.empty())
		return (FAIL);


	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 5 : ***********************************************************************/
/*** create map and check insert 3 element and insert existing value key from begin */
/************************************************************************************/
static bool	test_v5()
{
	std::map<int,int> 			realmap;
	ft::map<int,int> 			my_map;

	realmap.insert(std::pair<int,int>(0,100));
	realmap.insert(std::pair<int,int>(1,200));
	realmap.insert(std::pair<int,int>(2,300));

	std::cout << "try insert (0,500)" << std::endl;
	std::pair<std::map<int,int>::iterator,bool> ret;
	ret = realmap.insert(std::pair<int,int>(0,500));
	if (ret.second==false) {
		std::cout << "element '0' already existed";
	std::cout << " with a value of " << ret.first->second << "\n\n";
	}

	my_map.insert(ft::pair<int,int>(0,100));
	my_map.insert(ft::pair<int,int>(1,200));
	my_map.insert(ft::pair<int,int>(2,300));
	
	std::cout << "try insert (0,500)" << std::endl;
	ft::pair<ft::map<int,int>::iterator,bool> myret;
	myret = my_map.insert(ft::pair<int,int>(0,500));
	if (myret.second==false) {
		std::cout << "element '0' already existed";
	std::cout << " with a value of " << myret.first->second << '\n';
	}

	if (check_equal(my_map, realmap))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 6 : ***********************************************************************/
/*** create map and insert 3 element and insert value key from begin ****************/
/************************************************************************************/
static bool	test_v6()
{
	
	std::map<int,int> 			realmap;
	ft::map<int,int> 			my_map;

	realmap.insert(std::pair<int,int>(0,100));
	realmap.insert(std::pair<int,int>(2,300));
	realmap.insert(realmap.begin(), std::pair<int,int>(1,200));
	realmap.insert(realmap.begin(), std::pair<int,int>(3,400));

	my_map.insert(ft::pair<int,int>(0,100));
	my_map.insert(ft::pair<int,int>(2,300));
	my_map.insert(my_map.begin(), ft::pair<int,int>(1,200));
	my_map.insert(my_map.begin(), ft::pair<int,int>(3,400));

	if (check_equal(my_map, realmap))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 7 : ***********************************************************************/
/*** create map and insert 3 element and try find function **************************/
/************************************************************************************/
static bool	test_v7()
{
	
	std::map<int,int> 			realmap;
	ft::map<int,int> 			my_map;

	realmap.insert(std::pair<int,int>(0,100));
	realmap.insert(std::pair<int,int>(1,100));
	realmap.insert(std::pair<int,int>(2,300));

	std::map<int,int>::iterator it = realmap.find(2);
	if (it != realmap.end())
		std::cout << "find real = " << it->first << " => " << it->second << '\n';

	my_map.insert(ft::pair<int,int>(0,100));
	my_map.insert(ft::pair<int,int>(1,100));
	my_map.insert(ft::pair<int,int>(2,300));

	ft::map<int,int>::iterator mit = my_map.find(2);
	if (mit != my_map.end())
		std::cout << "find my_m = " << mit->first << " => " << mit->second << "\n\n";
	
	it = realmap.find(5);
	if (it == realmap.end())
		std::cout << "try find 5.\ndis occurence not existe "<< '\n';
	mit = my_map.find(5);
	if (mit == my_map.end())
		std::cout << "try find 5.\ndis occurence not existe "<< '\n';

	if (check_equal(my_map, realmap))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 8 : ***********************************************************************/
/*** create map and insert 3 element and clear **************************************/
/************************************************************************************/
static bool	test_v8()
{
	std::map<int,int> 			realmap;
	ft::map<int,int> 			my_map;

	realmap.insert(std::pair<int,int>(0,100));
	realmap.insert(std::pair<int,int>(2,300));
	realmap.clear();

	my_map.insert(ft::pair<int,int>(0,100));
	my_map.insert(ft::pair<int,int>(2,300));
	my_map.clear();


	if (check_equal(my_map, realmap))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 9 : ***********************************************************************/
/*** create map and insert 3 element and test count *********************************/
/************************************************************************************/
static bool	test_v9()
{
	std::map<int,int> 			realmap;
	ft::map<int,int> 			my_map;

	realmap.insert(std::pair<int,int>(0,100));
	realmap.insert(std::pair<int,int>(3,300));
	

	my_map.insert(ft::pair<int,int>(0,100));
	my_map.insert(ft::pair<int,int>(3,300));
	
	std::cout << "test count realmap\n";
	for (int c = 0 ; c < 4; c++)
	{
		std::cout << c;
		if (realmap.count(c) > 0)
			std::cout << " is an element of the map.\n";
		else
			std::cout << " is not an element of the map.\n";
	}

	std::cout << "\ntest count realmap\n";
	for (int c = 0 ; c < 4; c++)
	{
		std::cout << c;
		if (my_map.count(c) > 0)
			std::cout << " is an element of the map.\n";
		else
			std::cout << " is not an element of the map.\n";
	}

	if (check_equal(my_map, realmap))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 10 : **********************************************************************/
/*** create map and insert 3 element and test swap function *************************/
/************************************************************************************/
static bool	test_v10()
{
	ft::map<int, int> my_map;
	ft::map<int, int> my_ref;
	ft::map<int, int> my_map_afther;

	std::map<int, int> realmap;
	std::map<int, int> real_ref;
	std::map<int, int> realmap_afther;

	for (size_t i = 0; i < 4; i++)
	{
		my_map.insert(ft::pair<int,int>(i, i + 100));
		realmap.insert(std::pair<int,int>(i, i + 100));

		my_ref.insert(ft::pair<int,int>(i, i + 100));
		real_ref.insert(std::pair<int,int>(i, i + 100));
	}
	for (size_t i = 0; i < 2; i++)
	{
		my_map_afther.insert(ft::pair<int,int>(i, i + 10));
		realmap_afther.insert(std::pair<int,int>(i, i + 10));
	}

	my_map.swap(my_map_afther);
	realmap.swap(realmap_afther);

	std::cout << "-----------------\nrealmap befor :" << std::endl;
	for (std::map<int,int>::iterator it = realmap.begin(); it != realmap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "-----------------\nrealmap need to be :" << std::endl;
	for (std::map<int,int>::iterator it = real_ref.begin(); it != real_ref.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "-----------------\nrealmap afther :" << std::endl;
	for (std::map<int,int>::iterator it = realmap_afther.begin(); it != realmap_afther.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	if (realmap_afther.size() != real_ref.size())
		return (FAIL);

	std::cout << "----------------\nmy_map befor :" << std::endl;
	for (ft::map<int,int>::iterator mit = my_map.begin(); mit != my_map.end(); ++mit)
		std::cout << mit->first << " => " << mit->second << '\n';
	std::cout << "-----------------\nmy_map need to be :" << std::endl;
	for (ft::map<int,int>::iterator it = my_ref.begin(); it != my_ref.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "-----------------\nmy_map afther :" << std::endl;
	for (ft::map<int,int>::iterator it = my_map_afther.begin(); it != my_map_afther.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	if (my_map_afther.size() != my_ref.size())
		return (FAIL);

	return (SUCCESS);
}

/*************************************************************************************/
/*** TEST 11 : ***********************************************************************/
/*** create map and insert 3 element and try operator [] *****************************/
/*************************************************************************************/
static bool	test_v11()
{
	
	std::map<int,int>			realmap;
	ft::map<int,int>			my_map;

	realmap[0]= 10;
	realmap[1]= 20;
	realmap[3]= 30;

	my_map[0]= 10;
	my_map[1]= 20;
	my_map[3]= 30;

	if (check_equal(my_map, realmap))
		return (FAIL);
	return (SUCCESS);
}
 

/*************************************************************************************/
/*** TEST 12 : ***********************************************************************/
/*** create map and insert 3 element and try all comparaison operator ****************/
/*************************************************************************************/
static bool	test_v12()
{
	std::cout << "Test operator (test from cplusplus) witch real map :\n\n";
	std::map<int,int> foo,bar;
	foo[1]=100;
	foo[2]=200;
	bar[1]=10;
	bar[4]=1000;

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	std::cout << "\nTest operator (test from cplusplus) witch my map :\n\n";
	ft::map<int,int> my_foo,my_bar;
	my_foo[1]=100;
	my_foo[2]=200;
	my_bar[1]=10;
	my_bar[4]=1000;

	if (my_foo==my_bar) std::cout << "foo and my_bar are equal\n";
	if (my_foo!=my_bar) std::cout << "foo and my_bar are not equal\n";
	if (my_foo< my_bar) std::cout << "foo is less than bar\n";
	if (my_foo> my_bar) std::cout << "foo is greater than bar\n";
	if (my_foo<=my_bar) std::cout << "foo is less than or equal to bar\n";
	if (my_foo>=my_bar) std::cout << "foo is greater than or equal to bar\n";

	return (SUCCESS);
}

/*************************************************************************************/
/*** TEST 13 : ***********************************************************************/
/*** create map and insert 3 element and try operator [] *****************************/
/*************************************************************************************/
static bool	test_v13()
{
	
	std::map<int,int>			realmap;
	ft::map<int,int>			my_map;

	realmap[0]= 10;
	realmap[1]= 20;
	realmap[3]= 30;

	my_map[0]= 10;
	my_map[1]= 20;
	my_map[3]= 30;

	if (check_equal(my_map, realmap))
		return (FAIL);
	return (SUCCESS);
}

/*************************************************************************************/
/*** TEST 14 : ***********************************************************************/
/*** create map and insert 3 element and erase the midle *****************************/
/*************************************************************************************/
static bool	test_v14()
{
	std::map<int,int>			realmap;
	ft::map<int,int>			my_map;

	realmap[0]= 10;
	realmap[1]= 20;
	realmap[3]= 30;

	my_map[0]= 10;
	my_map[1]= 20;
	my_map[3]= 30;

	realmap.erase(1);
	my_map.erase(1);

	if (check_equal(my_map, realmap))
		return (FAIL);
	return (SUCCESS);
}

/*************************************************************************************/
/*** TEST 15 : ***********************************************************************/
/*** create map and insert 3 element and erase witch it ******************************/
/*************************************************************************************/
static bool	test_v15()
{
	std::map<int,int>			realmap;
	std::map<int,int>::iterator	it;

	ft::map<int,int>			my_map;
	ft::map<int,int>::iterator	mit;
	realmap[0]= 10;
	realmap[1]= 20;
	realmap[3]= 30;

	my_map[0]= 10;
	my_map[1]= 20;
	my_map[3]= 30;

	it = realmap.find(1);
	if (it != realmap.end())
		realmap.erase(it);

	mit = my_map.find(1);
	if (mit != my_map.end())
		my_map.erase(mit);

	if (check_equal(my_map, realmap))
		return (FAIL);
	return (SUCCESS);
}

/*************************************************************************************/
/*** TEST 16 : ***********************************************************************/
/*** create map and insert 3 element and erase witch it ******************************/
/*************************************************************************************/
static bool	test_v16()
{
	std::map<int,int>					realmap;
	std::map<int,int>::iterator			it;

	ft::map<int,int>					my_map;
	ft::map<int,int>::iterator			mit;

	realmap[0]= 10;
	realmap[1]= 20;
	realmap[2]= 25;
	realmap[3]= 30;
	realmap[4]= 40;

	my_map[0]= 10;
	my_map[1]= 20;
	my_map[2]= 25;
	my_map[3]= 30;
	my_map[4]= 40;

	it = realmap.find(3);
	realmap.erase(it, realmap.end());
	mit = my_map.find(3);
	my_map.erase(mit, my_map.end());

	if (check_equal(my_map, realmap))
		return (FAIL);
	return (SUCCESS);
}

/*************************************************************************************/
/*** TEST 17 : ***********************************************************************/
/*** create map and insert 3 element and erase witch range it ************************/
/*************************************************************************************/
static bool	test_v17()
{
	std::map<int,int>					realmap;
	std::map<int,int>::iterator			it;

	ft::map<int,int>					my_map;
	ft::map<int,int>::iterator			mit;

	realmap[0]= 10;
	realmap[1]= 20;
	realmap[2]= 25;
	realmap[3]= 30;
	realmap[4]= 40;

	my_map[0]= 10;
	my_map[1]= 20;
	my_map[2]= 25;
	my_map[3]= 30;
	my_map[4]= 40;

	it = realmap.find(3);
	realmap.erase(it, realmap.end());
	mit = my_map.find(3);
	my_map.erase(mit, my_map.end());

	if (check_equal(my_map, realmap))
		return (FAIL);
	return (SUCCESS);
}

/*************************************************************************************/
/*** TEST 18 : ***********************************************************************/
/*** create map and insert 3 element and erase witch range it ************************/
/*************************************************************************************/
static bool	test_v18()
{
	std::map<int,int>					realmap;
	std::map<int,int>::iterator			itlow, itup;

	ft::map<int,int>					my_map;
	ft::map<int,int>::iterator			mitlow, mitup;

	realmap[0]= 10;
	realmap[1]= 20;
	realmap[2]= 25;
	realmap[3]= 30;
	realmap[4]= 40;

	my_map[0]= 10;
	my_map[1]= 20;
	my_map[2]= 25;
	my_map[3]= 30;
	my_map[4]= 40;

	itlow = realmap.lower_bound(1);
	mitlow = my_map.lower_bound(1);

	itup = realmap.upper_bound(2);
	mitup = my_map.upper_bound(2);

	std::cout << "real lower is = " << itlow->first;
	std::cout << "\nreal upper is = " << itup->first;

	std::cout << "\n\nmy lower is = " << mitlow->first;
	std::cout << "\nmy upper is = " << mitup->first << std::endl;

	if (itlow->first != mitlow->first)
		return (FAIL);
	if (itup->first != mitup->first)
		return (FAIL);

	if (check_equal(my_map, realmap))
		return (FAIL);
	return (SUCCESS);
}

/*************************************************************************************/
/*** TEST 19 : ***********************************************************************/
/*** create map and insert 3 element and erase witch range it ************************/
/*************************************************************************************/
static bool	test_v19()
{
	std::map<int,int>														realmap;
	std::pair<std::map<int,int>::iterator,std::map<int,int>::iterator>	it;

	ft::map<int,int>														my_map;
	ft::pair<ft::map<int,int>::iterator,ft::map<int,int>::iterator>		mit;

	realmap[0]= 10;
	realmap[1]= 20;
	realmap[2]= 25;
	realmap[3]= 30;
	realmap[4]= 40;

	my_map[0]= 10;
	my_map[1]= 20;
	my_map[2]= 25;
	my_map[3]= 30;
	my_map[4]= 40;

	it = realmap.equal_range(1);
	mit = my_map.equal_range(1);

	std::cout << "Real equal first is = " << it.first->first << " => " << it.first->second;
	std::cout << "\nReal equal second is = " << it.second->first << " => " << it.second->second;

	std::cout << "\n\nMy equal first is = " << mit.first->first << " => " << mit.first->second;
	std::cout << "\nMy equal second is = " << mit.second->first << " => " << mit.second->second << std::endl;

	if ((it.first->first != mit.first->first) && (it.first->second != mit.first->second))
		return (FAIL);
	if ((it.second->first != mit.second->first) && (it.second->second != mit.second->second))
		return (FAIL);

	if (check_equal(my_map, realmap))
		return (FAIL);
	return (SUCCESS);
}

bool ft_map_test()
{
	std::cout << "\033[3;33m------- \033[3;34mStart \033[3;32mMap \033[3;35mTest \033[3;33m-------\033[0m\n" << std::endl;
	/*------------------------------------ test v1 ------------------------------------*/
	if (test_v1())
	{
		std::cout << "-----------------\nTest v1 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "-----------------\nTest v1 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v2())
	{
		std::cout << "-----------------\nTest v2 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "-----------------\nTest v2 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v3())
	{
		std::cout << "-----------------\nTest v3 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "-----------------\nTest v3 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v4())
	{
		std::cout << "-----------------\nTest v4 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "-----------------\nTest v4 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v5())
	{
		std::cout << "-----------------\nTest v5 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "-----------------\nTest v5 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v6())
	{
		std::cout << "-----------------\nTest v6 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "-----------------\nTest v6 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v7())
	{
		std::cout << "-----------------\nTest v7 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "-----------------\nTest v7 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;
	
	if (test_v8())
	{
		std::cout << "-----------------\nTest v8 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "-----------------\nTest v8 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v9())
	{
		std::cout << "-----------------\nTest v9 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "-----------------\nTest v9 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v10())
	{
		std::cout << "-----------------\nTest v10 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "-----------------\nTest v10 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v11())
	{
		std::cout << "-----------------\nTest v11 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "-----------------\nTest v11 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v12())
	{
		std::cout << "-----------------\nTest v12 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "-----------------\nTest v12 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v13())
	{
		std::cout << "-----------------\nTest v13 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "-----------------\nTest v13 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v14())
	{
		std::cout << "-----------------\nTest v14 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "-----------------\nTest v14 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v15())
	{
		std::cout << "-----------------\nTest v15 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "-----------------\nTest v15 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v16())
	{
		std::cout << "-----------------\nTest v16 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "-----------------\nTest v16 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v17())
	{
		std::cout << "-----------------\nTest v17 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "-----------------\nTest v17 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v18())
	{
		std::cout << "-----------------\nTest v18 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "-----------------\nTest v18 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v19())
	{
		std::cout << "-----------------\nTest v19 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "-----------------\nTest v19 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	/*------------------------------------ End test ------------------------------------*/
	std::cout << "\n\033[3;33m------- \033[3;34mEnd \033[3;32mMap \033[3;35mTest \033[3;33m-------\033[0m\n" << std::endl;

	return (SUCCESS);
}
