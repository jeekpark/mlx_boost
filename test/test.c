#include "./includes/mlx_boost.h"

int main()
{
	void	*boost;

	boost = boost_init(400, 400, "hello");

	boost_loop(boost);
}