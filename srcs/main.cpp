# include "../includes/all.hpp"

bool	set_c3d_error(int	c3d_error_to_set)
{
	g_current_error = c3d_error_to_set;
	return (1);
}

bool	show_c3d_error(void)
{
	std::cout << g_error[g_current_error] << std::endl;
	return (1);
}

int main()
{
	std::cout << "------- Start Ft_Container -------\n" << std::endl;
	if ((ft_vector_test()) != SUCCESS)
	{
		std::cout << "test" << std::endl;
		std::cout << "vector error  '" << g_error[g_current_error] << "'. Please check error_code for now." << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
