#include "./includes/mlx_boost.h"
#include "./includes/mlx_boost_utils.h"

#include <stdlib.h>

void	aa(void)
{
	system("leaks -q test");
}

int main()
{
	void	*boost;
	
	atexit(aa);
	boost = boost_init(400, 400, "hello");

	if (boost_add_component(boost, boost_set_pixel(400, 400), "some") == FALSE)
		return 0;
	boost_draw_pixel_to_component(boost, "some", boost_set_pixel(3,3), 1241241);
	boost_draw_pixel_to_component(boost, "some", boost_set_pixel(4,4), 1241241);
	//boost_del_component_by_name(boost, "some");

	boost_component_to_window(boost, "some", boost_set_pixel(0, 0));

	system("leaks -q test");
	boost_loop(boost);
}