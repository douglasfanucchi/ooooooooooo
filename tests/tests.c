#include "../get_next_line.h"
# include "minunit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define FIRST_LINE_EXPECTED "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent interdum ipsum vitae diam pharetra venenatis. Curabitur ornare accumsan eros. Morbi auctor nisl lacus, quis luctus nisi ultrices vitae. Praesent nisi nisi, congue vitae commodo id, porta in risus. Quisque vel lacinia est. Fusce gravida interdum nibh, ac convallis lorem dapibus ut. Morbi dolor ex, cursus vitae diam a, ultrices bibendum magna. Donec sollicitudin libero vitae est venenatis aliquet. Donec a lorem nec turpis ultricies vestibulum ultricies sit amet lectus. Nam vitae lectus elit. Cras vitae elit eget mi tempus vestibulum tempor nec purus."
# define SECOND_LINE_EXPECTED "Suspendisse rhoncus viverra molestie. Integer placerat quam risus, at ultricies justo pulvinar eu. Nulla mattis ex in euismod iaculis. Ut at ante eget metus porttitor viverra a sit amet justo. Pellentesque volutpat, nibh eu finibus accumsan, lacus nibh blandit sem, vel efficitur nisi augue at massa. Ut non vestibulum ante, ac consequat tellus. In a erat ligula. Vestibulum a porta est. Etiam mi metus, bibendum nec elit et, dictum accumsan nibh. Pellentesque viverra lacus ipsum, et posuere turpis lobortis in. Cras eu egestas turpis. Pellentesque placerat fringilla malesuada."
# define GUI_FILE_EXPECTED "0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789"

char	ft_isline(char *str)
{
	while (*str)
		if (*str++ == '\n')
			return (1);
	return (0);
}

MU_TEST(test_invalid_file) {
	char *str = get_next_line(-1);
	mu_check(str == NULL);
}

MU_TEST(test_file_gui) {
	int fd = open("./tests/arquivodogui.txt", O_RDONLY);
	char *str = get_next_line(fd);
	mu_check(ft_strncmp(str, GUI_FILE_EXPECTED, ft_strlen(GUI_FILE_EXPECTED)) == 0);
	free(str);
	while ((str = get_next_line(fd)))
		free(str);
}

MU_TEST(test_zerolines_file) {
	
	int	fd = open("./tests/zerolines.txt", O_RDONLY);
	char *str = get_next_line(fd);
	if (str != NULL)
		mu_fail("Retorno precisa ser NULL");
	mu_check(str == NULL);
	free(str);
}

MU_TEST(test_oneline_file) {
	int	fd = open("./tests/oneline.txt", O_RDONLY);
	char *str = get_next_line(fd);
	if (str == NULL)
		mu_fail("Retornou NULL");
	char *expected = FIRST_LINE_EXPECTED;
	mu_check(ft_strncmp(str, expected, ft_strlen(expected)) == 0);
	free(str);
}

MU_TEST(test_oneline_with_jumpline) {
	
	int	fd = open("./tests/onelinew\\n.txt", O_RDONLY);
	char *str = get_next_line(fd);
	mu_check(str != NULL);

	char *expected = ft_strjoin(ft_strdup(FIRST_LINE_EXPECTED), ft_strdup("\n"), ft_strlen(FIRST_LINE_EXPECTED));
	mu_check(ft_strncmp(str, expected, ft_strlen(expected)) == 0);
	free(expected);
	free(str);
	while((str = get_next_line(fd)))
		free(str);
}

MU_TEST(test_oneline_with_n_before) {
	
	int	fd = open("./tests/onelinewnbefore.txt", O_RDONLY);
	char *str = get_next_line(fd);
	mu_check(str != NULL);
	mu_check(!ft_strncmp(str, "\n", 1));
	free(str);
	free(get_next_line(fd));
	
	str = get_next_line(fd);
	char *expected = ft_strjoin(ft_strdup(FIRST_LINE_EXPECTED), ft_strdup("\n"), ft_strlen(FIRST_LINE_EXPECTED));
	mu_check(ft_strncmp(str, expected, ft_strlen(expected)) == 0);
	free(str);
	free(expected);
}

MU_TEST(test_multiple_lines) {
	int	fd = open("./tests/multiplelines.txt", O_RDONLY);
	char *str = get_next_line(fd);
	mu_check(str != NULL);

	char *expected = ft_strjoin(ft_strdup(FIRST_LINE_EXPECTED), ft_strdup("\n"), ft_strlen(FIRST_LINE_EXPECTED));
	mu_check(ft_strncmp(str, expected, ft_strlen(FIRST_LINE_EXPECTED) + 1) == 0);
	free(str);
	free(expected);

	str = get_next_line(fd);
	mu_check(ft_strncmp(str, "\n", 1) == 0);
	free(str);

	str = get_next_line(fd);
	mu_check(ft_strncmp(str, SECOND_LINE_EXPECTED, ft_strlen(SECOND_LINE_EXPECTED)) == 0);
	free(str);
}

MU_TEST(test_read_buffer_first_line) {
	int	fd = open("./tests/multiplelines.txt", O_RDONLY);
	char *buffer = ft_calloc(4096 + 1, sizeof(char));
	read(fd, buffer, 4096);
	char *str = read_buffer(buffer);
	if (str == NULL)
		mu_fail("Retorno NULL");
	mu_check(ft_strncmp(str, FIRST_LINE_EXPECTED, ft_strlen(FIRST_LINE_EXPECTED)) == 0);
	free(str);
	close(fd);
	free(buffer);
}

MU_TEST(test_read_buffer_single_line) {
	char *buffer = ft_calloc(4096 + 1, sizeof(char));
	int fd = open("./tests/oneline.txt", O_RDONLY);
	read(fd, buffer, 4096);

	char *readed = read_buffer(buffer);

	mu_check(ft_strncmp(FIRST_LINE_EXPECTED, readed, ft_strlen(FIRST_LINE_EXPECTED)) == 0);
	mu_check(ft_strlen(buffer) == 0);

	free(buffer);
	free(readed);
	
	char *tmp = NULL;
	while ((tmp = get_next_line(fd)))
		free(tmp);
	close(fd);
}

MU_TEST(test_current_buffer_position) {
	char *s = ft_strdup("ola meu nome e douglas\n e estou apenas fazendo um teste");
	free(read_buffer(s));
	mu_check(ft_strncmp(s, " e estou apenas fazendo um teste", 32) == 0);
	free(s);

	s = ft_strdup("ola este eh apenas outro teste\n\nooooooo");
	free(read_buffer(s));
	mu_check(*s == '\n');
	mu_check(*(s+1) == 'o');
	free(s);
}

MU_TEST(test_current_string_is_line) {
	mu_check(ft_isline("douglas\n"));
	mu_check(!ft_isline("douglas de lima fanucchi"));
	mu_check(!ft_isline("douglas\0\n"));
}

MU_TEST(test_42_with_nl) {
	if (BUFFER_SIZE > 42)
		return ;
	int fd = open("./tests/42_with_nl.txt", O_RDONLY);
	char *str = get_next_line(fd);
	
	mu_check(str != NULL);
	mu_check(!ft_strncmp(str, "01234567890123456789012345678901234567890\n", 42));

	char c = 0;
	read(fd, &c, 1);
	mu_check(c == '1');

	char *tmp;
	while ((tmp = get_next_line(fd)))
		free(tmp);
	free(str);
	close(fd);
}

int	main()
{
	MU_RUN_TEST(test_file_gui);
	MU_RUN_TEST(test_invalid_file);
	MU_RUN_TEST(test_zerolines_file);
	MU_RUN_TEST(test_oneline_file);
	MU_RUN_TEST(test_oneline_with_jumpline);
	MU_RUN_TEST(test_oneline_with_n_before);
	MU_RUN_TEST(test_multiple_lines);
	MU_RUN_TEST(test_read_buffer_first_line);
	MU_RUN_TEST(test_read_buffer_single_line);
	MU_RUN_TEST(test_current_buffer_position);
	MU_RUN_TEST(test_current_string_is_line);
	MU_RUN_TEST(test_42_with_nl);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
