# include "../includes/all.hpp"

#include <vector>

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

	for (size_t i = 0; i < 30; i++)
	{
		realvector.push_back(i);
	}

	for (size_t i = 0; i < 30; i++)
	{
		my_vector.push_back(i);
	}

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
/*** create vector no args check front function return ******************************/
/************************************************************************************/
static bool	test_v5()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;

	realvector.push_back(5);
	my_vector.push_back(5);

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
	realvector.assign(5, 100);
	my_vector.assign(5, 100);

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
	std::vector<int, std::allocator<int> > test;
	ft::vector<int, std::allocator<int> > mtest;
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite;
	ft::vector<int>::iterator mit;
	ft::vector<int>::iterator mite;


	for (size_t i = 50; i < 55; i++)
	{
		test.push_back(i);
		mtest.push_back(i);
	}

	it = test.begin();
	ite = test.end()--;

	mit = mtest.begin();
	mite = mtest.end()--;

	realvector.assign(it, ite);
	my_vector.assign(mit, mite);

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

	for (size_t i = 0; i < 5; i++)
	{
		realvector.push_back(i);
		my_vector.push_back(i);
	}

	it = realvector.begin()+1;
	it = realvector.insert(it,200);
	it = realvector.insert(it,300);
	it = realvector.insert(it,400);
	it = realvector.insert(it,500);

	my_it = my_vector.begin()+1;
	my_it = my_vector.insert(my_it,200);
	my_it = my_vector.insert(my_it,300);
	my_it = my_vector.insert(my_it,400);
	my_it = my_vector.insert(my_it,500);

	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 15 : **********************************************************************/
/*** check insert function witch it number of iteration of the value ****************/
/************************************************************************************/
static bool	test_v15()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;

	for (size_t i = 0; i < 5; i++)
	{
		realvector.push_back(i);
		my_vector.push_back(i);
	}
	realvector.insert(realvector.begin(), 10, 200);

	my_vector.insert(my_vector.begin(), 10, 200);

	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 16 : **********************************************************************/
/*** check insert function witch range iterator *************************************/
/************************************************************************************/
static bool	test_v16()
{
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;
	std::vector<int, std::allocator<int> > test;
	ft::vector<int, std::allocator<int> > mtest;
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite;
	ft::vector<int>::iterator mit;
	ft::vector<int>::iterator mite;

	for (size_t i = 0; i < 5; i++)
	{
		realvector.push_back(i);
		my_vector.push_back(i);
	}
	for (size_t i = 50; i < 55; i++)
	{
		test.push_back(i);
		mtest.push_back(i);
	}

	it = test.begin();
	ite = test.end()--;

	mit = mtest.begin();
	mite = mtest.end()--;

	realvector.insert(realvector.begin()+2, it, ite);

	my_vector.insert(my_vector.begin()+2, mit, mite);

	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 17 : **********************************************************************/
/*** check constructor witch range iterator *****************************************/
/************************************************************************************/
static bool	test_v17()
{
	std::vector<int, std::allocator<int> > test;
	ft::vector<int, std::allocator<int> > mtest;
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite;
	ft::vector<int>::iterator mit;
	ft::vector<int>::iterator mite;

	for (size_t i = 50; i < 55; i++)
	{
		test.push_back(i);
		mtest.push_back(i);
	}

	it = test.begin();
	ite = test.end()--;

	mit = mtest.begin();
	mite = mtest.end()--;

	std::vector<int, std::allocator<int> > realvector(it, ite);
	ft::vector<int, std::allocator<int> > my_vector(mit, mite);

	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}

/*** TEST 18 : **********************************************************************/
/*** check fuction swap *************************************************************/
/************************************************************************************/
static bool	test_v18()
{
	ft::vector<int, std::allocator<int> > my_vector;
	ft::vector<int, std::allocator<int> > my_ref;
	ft::vector<int, std::allocator<int> > my_vector_afther;

	std::vector<int, std::allocator<int> > realvector;
	std::vector<int, std::allocator<int> > real_ref;
	std::vector<int, std::allocator<int> > realvector_afther;
	for (size_t i = 0; i < 5; i++)
	{
		my_vector.push_back(i);
		realvector.push_back(i);

		my_ref.push_back(i);
		real_ref.push_back(i);
	}
	for (size_t i = 10; i < 5; i++)
	{
		my_vector_afther.push_back(i);
		realvector_afther.push_back(i);
	}

	my_vector.swap(my_vector_afther);
	realvector.swap(realvector_afther);

	std::cout << "\nrealvector befor swap :" << std::endl;
	for (size_t i = 0; i < realvector.size(); i++)
	{
		std::cout << realvector.at(i) << " ";
	}
	std::cout << std::endl;
	std::cout << "real_ref the result we need :" << std::endl;
	for (size_t i = 0; i < real_ref.size(); i++)
	{
		std::cout << real_ref.at(i) << " ";
	}
	std::cout << std::endl;
	std::cout << "realvector afther swap :" << std::endl;
	for (size_t i = 0; i < realvector_afther.size(); i++)
	{
		std::cout << realvector_afther.at(i) << " ";
	}
	std::cout << std::endl;

	std::cout << "-----------------\nmy_vector befor swap:" << std::endl;
	for (size_t i = 0; i < my_vector.size(); i++)
	{
		std::cout << my_vector.at(i) << " ";
	}
	std::cout << std::endl;
	std::cout << "my_ref the result we need " << std::endl;
	for (size_t i = 0; i < my_ref.size(); i++)
	{
		std::cout << my_ref.at(i) << " ";
	}
	std::cout << "\nmy_vector afther swap :" << std::endl;
	for (size_t i = 0; i < my_vector_afther.size(); i++)
	{
		std::cout << my_vector_afther.at(i) << " ";
	}
	std::cout << "\n" << std::endl;
	ft::vector<int>::iterator it;
	int i = 0;
	for (it = my_ref.begin(); it != my_ref.end(); it++)
	{
		if (my_ref.at(i) != my_vector_afther.at(i))
			return (FAIL);
		i++;
	}
	if (my_ref.capacity() != my_vector_afther.capacity())
	{
		std::cout << "your capatciy is = " << my_ref.capacity() << " and is suppose to be = " << my_vector_afther.capacity() << std::endl;
		return (FAIL);
	}
	else if (my_ref.size() != my_vector_afther.size())
	{
		std::cout << "your size is = " << my_ref.size() << "and is suppose to be = " << my_vector_afther.size() << std::endl;
		return (FAIL);
	}
	return (SUCCESS);
}

/*** TEST 19 : **********************************************************************/
/*** check overload function ********************************************************/
/************************************************************************************/
static bool	test_v19()
{
	ft::vector<int, std::allocator<int> > my_foo(3,100);
	ft::vector<int, std::allocator<int> > my_bar(2,200);

	std::vector<int, std::allocator<int> > foo(3,100);
	std::vector<int, std::allocator<int> > bar(2,200);

	std::cout << "--------------------- Real vector -------------------------------- " << std::endl;
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	std::cout << "--------------------- My vector -------------------------------- " << std::endl;
	if (my_foo==my_bar) std::cout << "foo and bar are equal\n";
	if (my_foo!=my_bar) std::cout << "foo and bar are not equal\n";
	if (my_foo< my_bar) std::cout << "foo is less than bar\n";
	if (my_foo> my_bar) std::cout << "foo is greater than bar\n";
	if (my_foo<=my_bar) std::cout << "foo is less than or equal to bar\n";
	if (my_foo>=my_bar) std::cout << "foo is greater than or equal to bar\n";
	std::cout << "\n" << std::endl;
	return (SUCCESS);
}

/*** TEST 20 : **********************************************************************/
/*** check erase witch pos iterator *************************************************/
/************************************************************************************/
static bool	test_v20()
{
	std::vector<int, std::allocator<int> > realvector;
	ft::vector<int, std::allocator<int> > my_vector;

	for (size_t i = 0; i < 5; i++)
	{
		my_vector.push_back(i);
		realvector.push_back(i);
	}

	realvector.erase(realvector.begin()+2);
	my_vector.erase(my_vector.begin()+2);
	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}

/*** TEST 21 : **********************************************************************/
/*** check erase witch range of iterator ********************************************/
/************************************************************************************/
static bool	test_v21()
{
	std::vector<int, std::allocator<int> > realvector;
	ft::vector<int, std::allocator<int> > my_vector;

	for (size_t i = 0; i < 5; i++)
	{
		my_vector.push_back(i);
		realvector.push_back(i);
	}

	realvector.erase(realvector.begin(), realvector.begin()+2);
	my_vector.erase(my_vector.begin(), my_vector.begin()+2);

	if (check_equal(my_vector, realvector))
		return (FAIL);
	return (SUCCESS);
}

/*** TEST 22 : **********************************************************************/
/*** check clear function ***********************************************************/
/************************************************************************************/
static bool	test_v22()
{
	std::vector<int, std::allocator<int> > realvector;
	ft::vector<int, std::allocator<int> > my_vector;

	for (size_t i = 0; i < 5; i++)
	{
		my_vector.push_back(i);
		realvector.push_back(i);
	}

	realvector.clear();
	my_vector.clear();

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

	if (test_v16())
	{
		std::cout << "Test v16 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v16 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v17())
	{
		std::cout << "Test v17 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v17 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v18())
	{
		std::cout << "Test v18 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v18 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v19())
	{
		std::cout << "Test v19 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v19 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v20())
	{
		std::cout << "Test v20 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v20 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v21())
	{
		std::cout << "Test v21 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v21 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;

	if (test_v22())
	{
		std::cout << "Test v22 : \033[1;31m[X]\033[0m\n-----------------\n" << std::endl;
		return (FAIL);
	}
	else
		std::cout << "Test v22 : \033[1;32m[√]\033[0m\n-----------------\n" << std::endl;
	/*------------------------------------ End test ------------------------------------*/
	std::cout << "\n\033[3;33m------- \033[3;34mEnd \033[3;32mVector \033[3;35mTest \033[3;33m-------\033[0m\n" << std::endl;

	return (SUCCESS);
}
