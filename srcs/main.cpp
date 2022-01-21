# include "../includes/all.hpp"

uint64	get_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);

	uint64 ret = tv.tv_usec;
	/* Convert from micro seconds (10^-6) to milliseconds (10^-3) */
	ret /= 1000;

	/* Adds the seconds (10^0) after converting them to milliseconds (10^-3) */
	ret += (tv.tv_sec * 1000);

	return ret;
}

int main()
{
	std::cout << "\033[3;33m------- \033[3;34mStart \033[3;32mFt_Container \033[3;35mTest \033[3;33m-------\033[0m\n\n" << std::endl;
	if ((ft_vector_test()) != SUCCESS)
	{
		std::cout << "Error in vector test" << std::endl;
		return (EXIT_FAILURE);
	}

	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "------------------- Finish Vector Congratulation ---------------" << std::endl;
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	if ((ft_stack_test()) != SUCCESS)
	{
		std::cout << "Error in stack test" << std::endl;
		return (EXIT_FAILURE);
	}

	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "------------------- Finish Stack Congratulation ---------------" << std::endl;
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	if ((ft_map_test()) != SUCCESS)
	{
		std::cout << "Error in stack test" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
