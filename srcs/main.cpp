# include "../includes/vector.hpp"

int main()
{
	std::cout << "------- Start Ft_Container -------" << std::endl;
	ft::vector<int, std::allocator<int> > test(5);

	for (size_t i = 0; i < 5; ++i)
	{
		std::cout << test.at(i) << ";\n";
	}
	std::cout << "end of vector" << std::endl;
}
