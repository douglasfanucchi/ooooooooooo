#include "get_next_line.h"
#include "minunit.h"
#include "tests.h"

extern size_t buffer_size;

MU_TEST(test_if_buffer_returns_a_complete_line) {
	buffer_size = 621;
}

int	main()
{
	MU_RUN_TEST(test_if_buffer_returns_a_complete_line);
	MU_REPORT();
	return (0);
}
