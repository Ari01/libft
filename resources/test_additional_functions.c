/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_additional_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 21:36:38 by user42            #+#    #+#             */
/*   Updated: 2020/11/30 09:43:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

void	print_test_result(char const *s, char const *expected)
{
	printf("s = %s, expected = %s\n", s, expected);
	if (ft_strncmp(s, expected, ft_strlen(expected)))
		printf("test ko\n\n");
	else
		printf("test ok\n\n");
}

void	test_substr(char const *s, unsigned int start, size_t len, char const *expected)
{
	char *sub;

	sub = ft_substr(s, start, len);
	printf("s = %s, start = %u, size = %zu\n", s, start, len);
	if (sub)
		print_test_result(sub, expected);
	else
		printf("substr nul\n\n");
}

void	test_strjoin(char const *s1, char const *s2, char const *expected)
{
	char *join;

	join = ft_strjoin(s1, s2);
	printf("s1 = %s, s2 = %s\n", s1, s2);
	if (join)
		print_test_result(join, expected);
	else
		printf("join nul\n\n");
}

void	test_strtrim(char const *s1, char const *set, char const *expected)
{
	char *trim;

	trim = ft_strtrim(s1, set);
	printf("s1 = %s, set = %s\n", s1, set);
	print_test_result(trim, expected);
}

void	test_split(char const *s, char c, char *e1, char *e2, char *e3)
{
	char *expected[] = {e1, e2, e3};
	char **split;
	int i;
	int test_res;

	i = 0;
	test_res = 1;
	split = ft_split(s, c);
	printf("s = %s, c = %c\n", s, c);
	while (split[i])
	{
		printf("split[%d] = %s, expected[%d] = %s\n", i, split[i], i, expected[i]);
		if (ft_strncmp(split[i], expected[i], ft_strlen(expected[i])))
			test_res = 0;
		i++;
	}
	if (test_res)
		printf("test ok\n\n");
	else
		printf("test ko\n\n");
}

void	test_itoa(int n, char *expected)
{
	char *itoa;

	itoa = ft_itoa(n);
	printf("n = %d\n", n);
	print_test_result(itoa, expected);
}

char	mapifunc(unsigned int i, char c)
{
	if (!(i % 2))
		return (c + 32);
	return (c);
}

void	test_strmapi(char const *s, char (*f)(unsigned int, char), char *expected)
{
	char *map;

	map = ft_strmapi(s, f);
	printf("s = %s\n", s);
	print_test_result(map, expected);
}

int		main(void)
{
	printf("\n-------------------------- SUBSTR -------------------------\n");
	char *src = "il etait une fois 42";
	size_t len = ft_strlen(src);
	test_substr(src, 0, len, src);
	test_substr(src, 3, len, "etait une fois 42");
	test_substr(src, 2, len, " etait une fois 42");
	test_substr(src, len - 5, len - 3, "is 42");
	test_substr("", 5, len, "");
	test_substr(src, 0, 0, "");
	test_substr("", 0, 0, "");
	test_substr(0, 5, len, 0);

	printf("\n-------------------------- STRJOIN -------------------------\n");
	test_strjoin("ab", "cd", "abcd");
	test_strjoin("ab", "", "ab");
	test_strjoin("", "ab", "ab");
	test_strjoin("", "", "");
	test_strjoin(0, "ab", 0);
	test_strjoin("ab", 0, "ab");
	test_strjoin(0, 0, 0);

	printf("\n-------------------------- STRTRIM -------------------------\n");
	test_strtrim(" - + -  abcde  - + ", " +-", "abcde");
	test_strtrim(" - + -  abcde", " +-", "abcde");
	test_strtrim(" a ", " ", "a");
	test_strtrim(" a", " ", "a");
	test_strtrim("a ", " ", "a");
	test_strtrim(" a b c d e ", " ", "a b c d e");
	test_strtrim("", " ", "");
	test_strtrim(" a b c d e ", "", " a b c d e ");
	test_strtrim("", "", "");

	printf("\n-------------------------- SPLIT -------------------------\n");
	test_split(" abc def ghi ", ' ', "abc", "def", "ghi");
	test_split("abc def", ' ', "abc", "def", 0);
	test_split("abc def", 0, "abc def", 0, 0);
	test_split("a ", ' ', "a", 0, 0);
	test_split(" a", ' ', "a", 0, 0);
	test_split("", ' ', "", 0, 0);
	test_split("", 0, "", 0, 0);

	printf("\n-------------------------- ITOA -------------------------\n");
	test_itoa(2147483647, "2147483647");
	test_itoa(-2147483648, "-2147483648");
	test_itoa(-0, "0");
	test_itoa(+0, "0");
	test_itoa(-0001, "-1");
	test_itoa(+0001, "1");
	test_itoa(0001, "1");
	test_itoa(0, "0");

	printf("\n-------------------------- MAPI -------------------------\n");
	test_strmapi("AbCdEfG", &mapifunc, "abcdefg");
	test_strmapi("", &mapifunc, "");

	printf("\n-------------------------- PUT -------------------------\n");
	ft_putchar_fd('a', STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	ft_putstr_fd("il etait une fois 42", STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	ft_putendl_fd("il etait une fois 42", STDOUT_FILENO);
	ft_putnbr_fd(-3, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);

	return (0);
}
