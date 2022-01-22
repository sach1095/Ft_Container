# include "../includes/all.hpp"

typedef size_t	Index;

static void the_display( std::stack<int, std::vector<int> > const& numbers )
{
    struct Hack
        : public std::stack<int, std::vector<int> >
    {
        static int item( Index const i, std::stack<int, std::vector<int> > const& numbers )
        {
            return (numbers.*&Hack::c)[i];
        }
    };

    std::cout << "-----------------\nrealstack :" << std::endl;
    for( Index i = 0;  i < numbers.size();  ++i )
    {
        std::wcout << Hack::item( i, numbers ) << " ";
    }
	std::wcout << std::endl;
}

static void my_display( ft::stack<int, ft::vector<int> > const& numbers )
{
    struct MyHack
        : public ft::stack<int>
    {
        static int item( Index const i, ft::stack<int> const& numbers )
        {
            return (numbers.*&MyHack::_my_stack_tab)[i];
        }
    };

    std::cout << "my_stack :" << std::endl;
    for( Index i = 0;  i < numbers.size();  ++i )
    {
        std::wcout << MyHack::item( i, numbers ) << " ";
    }
	std::wcout << std::endl;
}

static bool check_equal(ft::stack<int, ft::vector<int> > &my_stack, std::stack<int, std::vector<int> > &realstack)
{
	the_display(realstack);
	my_display((my_stack));
	if (my_stack.size() != realstack.size())
		return (FAIL);
	if (!my_stack.empty())
		if (my_stack.top() != realstack.top())
			return (FAIL);
	return (SUCCESS);
}

/************************************************************************************/
/*** TEST 1 : ***********************************************************************/
/*** create stack no args and check size and check last element *********************/
/************************************************************************************/
static bool	test_v1()
{
	ft::stack<int, ft::vector<int> > my_stack;
	std::stack<int, std::vector<int> > realstack;

	if (check_equal(my_stack, realstack))
		return (FAIL);
	return (SUCCESS);
}


/************************************************************************************/
/*** TEST 2 : ***********************************************************************/
/*** create stack push element and check size and check last element ****************/
/************************************************************************************/
static bool	test_v2()
{
	ft::stack<int, ft::vector<int> > my_stack;
	std::stack<int, std::vector<int> > realstack;

	for (size_t i = 0; i < 5; i++)
	{
		realstack.push(i);
		my_stack.push(i);
		if (my_stack.top() != realstack.top())
			return (FAIL);
	}

	if (check_equal(my_stack, realstack))
		return (FAIL);
	return (SUCCESS);
}

/**************************************************************************************/
/*** TEST 3 : *************************************************************************/
/*** create stack push element and push pop one and check size and check last element */
/**************************************************************************************/
static bool	test_v3()
{
	ft::stack<int, ft::vector<int> > my_stack;
	std::stack<int, std::vector<int> > realstack;

	for (size_t i = 0; i < 5; i++)
	{
		realstack.push(i);
		my_stack.push(i);
		if (my_stack.top() != realstack.top())
			return (FAIL);
	}
	realstack.pop();
	my_stack.pop();

	if (check_equal(my_stack, realstack))
		return (FAIL);
	return (SUCCESS);
}

/**************************************************************************************/
/*** TEST 4 : *************************************************************************/
/*** create stack push element and push pop one and check size and check last element */
/**************************************************************************************/
static bool	test_v4()
{
	ft::stack<int, ft::vector<int> > my_stack;
	std::stack<int, std::vector<int> > realstack;

	if (!my_stack.empty())
		return (FAIL);
	if (!realstack.empty())
		return (FAIL);

	realstack.push(5);
	my_stack.push(5);

	if (my_stack.empty())
		return (FAIL);
	if (realstack.empty())
		return (FAIL);

	if (check_equal(my_stack, realstack))
		return (FAIL);
	return (SUCCESS);
}

/**************************************************************************************/
/*** TEST 5 : *************************************************************************/
/*** create stack push element and push pop one and check size and check last element */
/**************************************************************************************/
static bool	test_v5()
{
	ft::stack<int, ft::vector<int> > my_foo;
	ft::stack<int, ft::vector<int> > my_bar;

	std::stack<int, std::vector<int> > foo;
	std::stack<int, std::vector<int> > bar;

	for (size_t i = 0; i < 3; i++)
	{
		my_foo.push(100);
		foo.push(100);
	}
	for (size_t i = 0; i < 2; i++)
	{
		my_bar.push(200);
		bar.push(200);
	}

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
	return (SUCCESS);
}

bool ft_stack_test()
{
	std::cout << "\033[3;33m------- \033[3;34mStart \033[3;32mStack \033[3;35mTest \033[3;33m-------\033[0m\n" << std::endl;
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

	/*------------------------------------ End test ------------------------------------*/
	std::cout << "\n\033[3;33m------- \033[3;34mEnd \033[3;32mStack \033[3;35mTest \033[3;33m-------\033[0m\n" << std::endl;

	return (SUCCESS);
}
