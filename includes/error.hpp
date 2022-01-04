#ifndef _ERROR_HPP_
#define _ERROR_HPP_

# define Error_ok 0
# define Error_test_v1 1
# define Error_test_v2 2
# define Error_test_v3 3
# define Error_test_v4 4

bool	set_c3d_error(int	c3d_error_to_set);
bool	show_c3d_error(void);

static int	g_current_error = Error_ok;

static const char	*g_error[] = {
	[Error_ok] = "No Error",
	[Error_test_v1] = "Error in vecetor test_v1",
	[Error_test_v2] = "Error in vecetor test_v2",
	[Error_test_v3] = "Error in vecetor test_v3",
	[Error_test_v4] = "Error in vecetor test_v4",

};



#endif
