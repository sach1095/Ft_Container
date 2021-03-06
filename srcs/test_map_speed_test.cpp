# include "../includes/all.hpp"

# define NB_TO_ERASE 49
# define ON_MILI / 1000
# define SIZE_TAB_INSERT 1000000

// static uint64 tab_dico[SIZE_TAB_INSERT];

static bool check_equal(ft::map<int, int> &my_map, std::map<int,int> &realmap)
{
	std::cout << "-----------------\nrealmap two first occurence :" << std::endl;
	std::map<int,int>::iterator it = realmap.begin();
	int i = 0;
	while (i < 2)
	{
		std::cout << it->first << " => " << it->second << '\n';
		i++;
		it++;
	}

	std::cout << "\ntwo last occurence :" << std::endl;
	std::map<int,int>::reverse_iterator rit = realmap.rbegin();
	i = 0;
	while (i < 2)
	{
		std::cout << rit->first << " => " << rit->second << '\n';
		i++;
		rit++;
	}

	std::cout << "\nmy_map two first occurence :" << std::endl;
	ft::map<int,int>::iterator mit = my_map.begin();
	i = 0;
	while (i < 2)
	{
		std::cout << mit->first << " => " << mit->second << '\n';
		i++;
		mit++;
	}

	std::cout << "\ntwo last occurence :" << std::endl;
	ft::map<int,int>::reverse_iterator mrit = my_map.rbegin();
	i = 0;
	while (i < 2)
	{
		std::cout << mrit->first << " => " << mrit->second << '\n';
		i++;
		mrit++;
	}

	mit = my_map.begin();
	for (std::map<int,int>::iterator it = realmap.begin(); it != realmap.begin(); it++)
	{
		if (mit->first != it->first && mit->second != it->second)
			return (FAIL);
		mit++;
	}

	if (my_map.size() != realmap.size())
		return (FAIL);
	return (SUCCESS);
}

void test_real_map(std::map<int, int> &realmap, uint64 *tab_key, uint64 *tab_value, uint64 *tab_to_erase)
{
	// test insert SIZE_TAB_INSERT elements
	for (size_t i = 0; i < SIZE_TAB_INSERT - 1; i++)
	{
		realmap.insert(realmap.begin(), std::pair<int, int>(tab_key[i], tab_value[i]));
	}

	// test find and erase on 50 elements
	std::map<int,int>::iterator it;
	for (size_t i = 0; i < NB_TO_ERASE; i++)
	{
		it = realmap.find(tab_to_erase[i]);
		if (it == realmap.end())
			realmap.erase(tab_to_erase[i]);
	}

	// test clear all the map
	realmap.clear();

	// test re insert 1000 elements
	for (size_t i = 0; i < 1000; i++)
	{
		realmap[tab_key[i]] = tab_value[i];
	}
}

void test_my_map(ft::map<int, int> &my_map, uint64 *tab_key, uint64 *tab_value, uint64 *tab_to_erase)
{
	// test insert SIZE_TAB_INSERT elements
	for (size_t i = 0; i < SIZE_TAB_INSERT - 1; i++)
	{
		my_map.insert(ft::pair<int,int>(tab_key[i], tab_value[i]));
	}

	// test find and erase on 50 elements
	ft::map<int,int>::iterator it;
	for (size_t i = 0; i < NB_TO_ERASE; i++)
	{
		it = my_map.find(tab_to_erase[i]);
		if (it == my_map.end())
			my_map.erase(tab_to_erase[i]);
	}

	// test clear all the map
	my_map.clear();

	// test re insert 1000 elements
	for (size_t i = 0; i < 1000; i++)
	{
		my_map[tab_key[i]] = tab_value[i];
	}
}

bool ft_map_speed_test()
{
	std::cout << "\033[3;33m------- \033[3;34mStart \033[3;32mMap Speed \033[3;35mTest \033[3;33m-------\033[0m\n" << std::endl;

	std::map<int, int> realmap;
	ft::map<int, int> my_map;

	uint64 *tab_key = NULL;
	uint64 *tab_value = NULL;
	uint64 tab_to_erase[50];
	uint64 key_to_insert = 0;

	if ((!(tab_key = (uint64*)malloc(sizeof(uint64) * (SIZE_TAB_INSERT + 1)))) || (!(tab_value = (uint64*)malloc(sizeof(uint64) * SIZE_TAB_INSERT + 1))))
	{
		std::cout << "error malloc no engout space" << std::endl;
		return (FAIL);
	}
	for (size_t i = 0; i < (SIZE_TAB_INSERT - 1); i++)
	{
		key_to_insert = rand() % SIZE_TAB_INSERT * 5;
		tab_key[i] = key_to_insert;
		tab_value[i] = rand() % SIZE_TAB_INSERT * 5;
	}

	for (size_t i = 0; i < NB_TO_ERASE; i++)
	{
		tab_to_erase[i] = tab_key[rand() % 1000];
	}

	uint64 start = get_time();

	test_real_map(realmap, tab_key, tab_value, tab_to_erase);
	uint64 time_real_map = get_time() - start;
	
	start = get_time();

	test_my_map(my_map, tab_key, tab_value, tab_to_erase);
	uint64 time_my_map = get_time() - start;

	printf("test for %d inserts\n\nThe real map = %.5f seconde.\nMy map = %.5f seconde.\n\n", SIZE_TAB_INSERT ,(double)time_real_map ON_MILI, (double)time_my_map ON_MILI);

	free(tab_key);
	free(tab_value);
	if (time_real_map > (time_my_map * 20))
	{
		std::cout << "Your map are to slow" << std::endl;
		return (FAIL);
	}
	else if (check_equal(my_map, realmap))
	{
		std::cout << "The two map are not equal" << std::endl;
		return (FAIL);
	}

	/*------------------------------------ End test ------------------------------------*/
	std::cout << "\n\033[3;33m------- \033[3;34mEnd \033[3;32mMap Speed \033[3;35mTest \033[3;33m-------\033[0m\n" << std::endl;

	return (SUCCESS);
}
