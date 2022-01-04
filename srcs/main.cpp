# include "../includes/vector.hpp"

int main()
{
	std::cout << "------- Start Ft_Container -------" << std::endl;
	ft::vector<int, std::allocator<int> > my_vector;
	std::vector<int, std::allocator<int> > realvector;


	my_vector.push_back(1);
	my_vector.push_back(2);
	my_vector.push_back(3);
	my_vector.push_back(4);
	my_vector.push_back(5);
	for (size_t i = 0; i < my_vector.size(); ++i)
	{
		std::cout << "index num = " << i << " = " << my_vector.at(i) << ";\n";
	}
	std::cout << "capacity = " << my_vector.capacity() << std::endl;
	std::cout << "size = " << my_vector.size() << std::endl;
	// std::cout << "max_size = " << my_vector.max_size() << std::endl;
	std::cout << "end of vector" << std::endl;

}
