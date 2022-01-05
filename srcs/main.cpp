# include "../includes/all.hpp"

int main()
{
	std::cout << "\033[3;33m------- \033[3;34mStart \033[3;32mFt_Container \033[3;35mTest \033[3;33m-------\033[0m\n" << std::endl;
	if ((ft_vector_test()) != SUCCESS)
	{
		std::cout << "Error in vector test" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
