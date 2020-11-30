/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_part1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:30:25 by user42            #+#    #+#             */
/*   Updated: 2020/11/30 12:24:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <bsd/string.h>
#include "libft.h"

// MEM TESTS
void	print_tab(const int *t, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		printf("t[%zu] = %d ", i, t[i]);
		i++;
	}
	printf("\n");
}

void	print_test_result(const void *man, const void *ft, size_t n)
{
	char	*mancpy;
	char	*ftcpy;

	mancpy = (char *)man;
	ftcpy = (char *)ft;

	printf("man = %s, ft = %s\n", mancpy, ftcpy);

	if (strncmp(mancpy, ftcpy, n))
		printf("test ko\n");
	else
		printf("test ok\n");
}

void	test_memset(int c, size_t n)
{
	unsigned char	*ft;
	unsigned char	*man;

	man = malloc(n);
	ft = malloc(n);

	memset(man, c, n);
	ft_memset(ft, c, n);

	printf("init value = %d, size = %zu\n", c, n);
	print_test_result(man, ft, n);
	printf("\n");
}

void	test_bzero(size_t n)
{
	unsigned char	*man;
	unsigned char	*ft;

	ft = malloc(n);
	man = malloc(n);

	bzero(man, n);
	ft_bzero(ft, n);

	printf("size = %zu\n", n);
	print_test_result(man, ft, n);
	printf("\n");
}

void	test_memcpy(const void *src, size_t n)
{
	unsigned char	*mandest;
	unsigned char	*ftdest;

	mandest = malloc(n);
	ftdest = malloc(n);

	printf("src = %s, size = %zu\n", (const unsigned char *)src, n);

	memcpy(mandest, src, n);
	ft_memcpy(ftdest, src, n);
	print_test_result(mandest, ftdest, n);
	printf("\n");
}

void	test_memccpy(const void *src, int c, size_t n)
{
	unsigned char *man;
	unsigned char *ft;
	unsigned char *mandest;
	unsigned char *ftdest;

	mandest = malloc(n);
	ftdest = malloc(n);

	printf("src = %s, tofind c = %c, size = %zu\n", (const unsigned char *)src, c, n);

	man = memccpy(mandest, src, c, n);
	ft = ft_memccpy(ftdest, src, c, n);
	if ((!man && ft) || (man && !ft))
	{
		printf("%c found in man or ft function but not both\n", c);
		printf("test ko\n");
	}
	else if (man && ft)
	{
		printf("return value comparison\n");
		print_test_result(man, ft, n);
	}
	printf("dest string comparison\n");
	print_test_result(mandest, ftdest, n);
	printf("\n");
}

void	test_memmove(const void *src, int overlap, size_t n)
{
	unsigned char *mandest;
	unsigned char *mansrc;
	unsigned char *ftdest;
	unsigned char *ftsrc;

	ftsrc = malloc(n);
	mansrc = malloc(n);
	memcpy(mansrc, src, n);
	memcpy(ftsrc, src, n);
	printf("src = %s, overlap = %d, size = %zu\n", mansrc, overlap, n);
	
	mandest = mansrc + overlap;
	ftdest = ftsrc + overlap;
	mandest = memmove(mandest, mansrc, n);
	ftdest = ft_memmove(ftdest, ftsrc, n);
	if (mandest && ftdest)
		print_test_result(mandest, ftdest, n);
	printf("\n");
}

void	test_memchr(const void *s, int c, size_t n)
{
	void *man;
	void *ft;

	man = memchr(s, c, n);
	ft = ft_memchr(s, c, n);
	printf("s = %s, tofind = %c, size = %zu\n", s, c, n);
	if ((!man && ft) || (man && !ft))
	{
		printf("%c found in man or ft function but not in both\n", c);
		printf("test ko\n");
	}
	else if (man && ft)
		print_test_result(man, ft, n);
	else
	{
		printf("%c not found in both man and ft function\n", c);
		printf("test ok\n");
	}
	printf("\n");
}

void	test_memcmp(const void *s1, const void *s2, size_t n)
{
	int man;
	int ft;

	man = memcmp(s1, s2, n);
	ft = ft_memcmp(s1, s2, n);
	printf("s1 = %s, s2 = %s, size = %zu\n", (const char*)s1, (const char *)s2, n);

	printf("man = %d, ft = %d\n", man, ft);
	if ((man >= 0 && ft < 0) || (man <= 0 && ft > 0))
		printf("test ko\n\n");
	else
		printf("test ok\n\n");
}

// IS TESTS
void	test_is(int c, int (*man)(int), int (*ft)(int))
{
	printf("char = %c, man = %d, ft = %d\n", c, man(c), ft(c));
	if ((!man(c) && ft(c)) || (man(c) && !ft(c)))
		printf("test ko\n\n");
	else
		printf("test ok \n\n");
}

void	test_to(int c, int (*man)(int), int (*ft)(int))
{
	printf("char = %c, man = %c, ft = %c\n", c, man(c), ft(c));
	if ((man(c) != ft(c)))
		printf("test ko\n\n");
	else
		printf("test ok \n\n");
}

// STRING TESTS
void	test_strchr(const char *s, int c, char *(*manf)(const char *, int), char *(*ftf)(const char *, int))
{
	char *man;
	char *ft;

	man = manf(s,c);
	ft = ftf(s,c);

	printf("s = %s, tofind = %c\n", s, c);
	printf("man = %s, ft = %s\n", man, ft);

	if (man != ft)
		printf("test ko\n\n");
	else
		printf("test ok\n\n");
}

void	test_strncmp(const char *s1, const char *s2, size_t n)
{
	int man;
	int ft;

	man = strncmp(s1, s2, n);
	ft = ft_strncmp(s1, s2, n);
	
	printf("s1 = %s, s2 = %s, nbytes to search = %zu\n", s1, s2, n);
	printf("man = %d, ft = %d\n", man, ft);

	if ((man >= 0 && ft < 0) || (man <= 0 && ft > 0))
		printf("test ko\n\n");
	else
		printf("test ok\n\n");
}

void	test_strlcpy(const char *src, size_t size)
{
	char	*man;
	char	*ft;
	size_t	manres;
	size_t	ftres;

	man = malloc(size);
	ft = malloc(size);
	manres = strlcpy(man, src, size);
	ftres = ft_strlcpy(ft, src, size);

	printf("src = %s, size = %zu\n", src, size);
	printf("man string = %s, ft string = %s\n", man, ft);
	printf("man return value = %zu, ft return value = %zu\n", manres, ftres);

	if (ft_strncmp(man, ft, size) || manres != ftres)
		printf("test ko\n\n");
	else
		printf("test ok\n\n");
}

void	test_strlcat(char *mandst, const char *src, size_t size)
{
	size_t	manres;
	size_t	ftres;
	char	*ftdst;

	ftdst = malloc(sizeof(*ftdst) * ft_strlen(mandst) + 1);
	strlcpy(ftdst, mandst, ft_strlen(mandst) + 1);

	printf("dest = %s, src = %s, size = %zu\n", mandst, src, size);

	manres = strlcat(mandst, src, size);
	ftres = ft_strlcat(ftdst, src, size);
	printf("man dest = %s, ft dest = %s\n", mandst, ftdst);
	printf("man return value = %zu, ft return value = %zu\n", manres, ftres);

	if (strcmp(mandst, ftdst) || manres != ftres)
		printf("test ko\n\n");
	else
		printf("test ok\n\n");
	free(ftdst);
}

void	test_strnstr(const char *big, const char *little, size_t len)
{
	char *man;
	char *ft;

	printf("big = %s, little = %s, len = %zu\n", big, little, len);
	man = strnstr(big, little, len);
	ft = ft_strnstr(big, little, len);

	printf("man = %s, ft = %s\n", man, ft);

	if (man != ft)
		printf("test ko\n\n");
	else
		printf("test ok\n\n");
}

void	test_atoi(const char *s)
{
	int man;
	int ft;

	printf("s = %s\n", s);
	man = atoi(s);
	ft = ft_atoi(s);
	printf("man = %d, ft = %d\n", man, ft);

	if (man != ft)
		printf("test ko\n\n");
	else
		printf("test ok\n\n");
}

void	test_calloc(size_t nmemb, size_t size)
{
	char	*ft;
	char	*man;
	size_t	i;
	int		test_res;

	man = calloc(nmemb, size);
	ft = ft_calloc(nmemb, size);
	test_res = 1;
	i = 0;
	printf("nmemb = %zu, size = %zu\n", nmemb, size);
	while (i < nmemb * size)
	{
		if (man[i] != ft[i])
			test_res = 0;
		i++;
	}
	if (test_res)
		printf("test ok\n\n");
	else
		printf("test ko\n\n");
}

void	test_strdup(const char *s)
{
	char *man;
	char *ft;

	man = ft_strdup(s);
	ft = ft_strdup(s);
	printf("s = %s\n", s);
	print_test_result(man, ft, ft_strlen(man));
	printf("\n");
}

int		main(void)
{
	// MEM TESTS
	printf("\n--------------------- MEMSET ---------------------\n");
	test_memset(0, 10);
	test_memset('a', 10);
	test_memset(2147483647, 10);
	test_memset(-2147483648, 10);
	test_memset(-2147483648, 0);

	printf("\n--------------------- BZERO ---------------------\n");
	test_bzero(0);
	test_bzero(10);

	printf("\n--------------------- MEMCPY --------------------\n");
	char *src = "il etait une fois 42";
	size_t n = sizeof(*src) * (ft_strlen(src) + 1);
	test_memcpy(src, n);
	test_memcpy(src, n);
	test_memcpy(src, n);
	test_memcpy(src, n);
	test_memcpy(src, n);
	test_memcpy(src, 0);

	printf("\n--------------------- MEMCCPY --------------------\n");
	test_memccpy(src, 'i', n);
	test_memccpy(src, ' ', n);
	test_memccpy(src, 's', n);
	test_memccpy(src, '2', n);
	test_memccpy(src, '3', n);
	test_memccpy(src, '0', n);
	test_memccpy(src, 0, n);
	test_memccpy(src, 0, 0);

	printf("\n--------------------- MEMMOVE --------------------\n");
	test_memmove(src, 0, n);
	test_memmove(src, 2, n);
	test_memmove(src, 5, n);
	test_memmove(src, 10, n);
	test_memmove(src, 19, n);
	test_memmove(src, 20, n);
	test_memmove(src, 0, 0);
	test_memmove(src, 10, 0);

	printf("\n--------------------- MEMCHR --------------------\n");
	test_memchr(src, 'i', n);
	test_memchr(src, ' ', n);
	test_memchr(src, 's', n);
	test_memchr(src, '2', n);
	test_memchr(src, '3', n);
	test_memchr(src, '0', n);
	test_memchr(src, 0, n);
	test_memchr(src, 0, 0);

	printf("\n--------------------- MEMCMP --------------------\n");
	test_memcmp("abc", "abc", 4);
	test_memcmp("abc", "abc", 3);
	test_memcmp("abc", "abd", 2);
	test_memcmp("abc", "abd", 3);
	test_memcmp("abd", "abc", 3);
	test_memcmp("abc", "abd", 0);
	test_memcmp("", "", 1);
	test_memcmp("", "abc", 3);
	test_memcmp("abc", "", 3);

	// IS TESTS
	printf("\n--------------------- IS --------------------\n");
	printf("----------------------- isalpha --------------------------\n");
	test_is('a', &isalpha, &ft_isalpha);
	test_is('z', &isalpha, &ft_isalpha);
	test_is('A', &isalpha, &ft_isalpha);
	test_is('Z', &isalpha, &ft_isalpha);
	test_is('0', &isalpha, &ft_isalpha);
	test_is('9', &isalpha, &ft_isalpha);
	test_is(' ', &isalpha, &ft_isalpha);
	test_is('~', &isalpha, &ft_isalpha);
	test_is(0, &isalpha, &ft_isalpha);
	test_is(10, &isalpha, &ft_isalpha);
	test_is(127, &isalpha, &ft_isalpha);
	test_is(128, &isalpha, &ft_isalpha);
	test_is(-1, &isalpha, &ft_isalpha);
	test_is('\0', &isalpha, &ft_isalpha);

	printf("----------------------- isdigit --------------------------\n");
	test_is('a', &isdigit, &ft_isdigit);
	test_is('z', &isdigit, &ft_isdigit);
	test_is('A', &isdigit, &ft_isdigit);
	test_is('Z', &isdigit, &ft_isdigit);
	test_is('0', &isdigit, &ft_isdigit);
	test_is('9', &isdigit, &ft_isdigit);
	test_is(' ', &isdigit, &ft_isdigit);
	test_is('~', &isdigit, &ft_isdigit);
	test_is(0, &isdigit, &ft_isdigit);
	test_is(10, &isdigit, &ft_isdigit);
	test_is(127, &isdigit, &ft_isdigit);
	test_is(128, &isdigit, &ft_isdigit);
	test_is(-1, &isdigit, &ft_isdigit);
	test_is('\0', &isdigit, &ft_isdigit);

	printf("----------------------- isalnum --------------------------\n");
	test_is('a', &isalnum, &ft_isalnum);
	test_is('z', &isalnum, &ft_isalnum);
	test_is('A', &isalnum, &ft_isalnum);
	test_is('Z', &isalnum, &ft_isalnum);
	test_is('0', &isalnum, &ft_isalnum);
	test_is('9', &isalnum, &ft_isalnum);
	test_is(' ', &isalnum, &ft_isalnum);
	test_is('~', &isalnum, &ft_isalnum);
	test_is(0, &isalnum, &ft_isalnum);
	test_is(10, &isalnum, &ft_isalnum);
	test_is(127, &isalnum, &ft_isalnum);
	test_is(128, &isalnum, &ft_isalnum);
	test_is(-1, &isalnum, &ft_isalnum);
	test_is('\0', &isalnum, &ft_isalnum);

	printf("----------------------- isascii --------------------------\n");
	test_is('a', &isascii, &ft_isascii);
	test_is('z', &isascii, &ft_isascii);
	test_is('A', &isascii, &ft_isascii);
	test_is('Z', &isascii, &ft_isascii);
	test_is('0', &isascii, &ft_isascii);
	test_is('9', &isascii, &ft_isascii);
	test_is(' ', &isascii, &ft_isascii);
	test_is('~', &isascii, &ft_isascii);
	test_is(0, &isascii, &ft_isascii);
	test_is(10, &isascii, &ft_isascii);
	test_is(127, &isascii, &ft_isascii);
	test_is(128, &isascii, &ft_isascii);
	test_is(-1, &isascii, &ft_isascii);
	test_is('\0', &isascii, &ft_isascii);

	printf("----------------------- isprint --------------------------\n");
	test_is('a', &isprint, &ft_isprint);
	test_is('z', &isprint, &ft_isprint);
	test_is('A', &isprint, &ft_isprint);
	test_is('Z', &isprint, &ft_isprint);
	test_is('0', &isprint, &ft_isprint);
	test_is('9', &isprint, &ft_isprint);
	test_is(' ', &isprint, &ft_isprint);
	test_is('~', &isprint, &ft_isprint);
	test_is(0, &isprint, &ft_isprint);
	test_is(10, &isprint, &ft_isprint);
	test_is(127, &isprint, &ft_isprint);
	test_is(128, &isprint, &ft_isprint);
	test_is(-1, &isprint, &ft_isprint);
	test_is('\0', &isprint, &ft_isprint);

	printf("----------------------- TO --------------------------\n");
	printf("----------------------- toupper --------------------------\n");
	test_to('a', &toupper, &ft_toupper);
	test_to('z', &toupper, &ft_toupper);
	test_to('A', &toupper, &ft_toupper);
	test_to('Z', &toupper, &ft_toupper);
	test_to('0', &toupper, &ft_toupper);
	test_to('9', &toupper, &ft_toupper);
	test_to(' ', &toupper, &ft_toupper);
	test_to('~', &toupper, &ft_toupper);

	printf("----------------------- tolower --------------------------\n");
	test_to('a', &tolower, &ft_tolower);
	test_to('z', &tolower, &ft_tolower);
	test_to('A', &tolower, &ft_tolower);
	test_to('Z', &tolower, &ft_tolower);
	test_to('0', &tolower, &ft_tolower);
	test_to('9', &tolower, &ft_tolower);
	test_to(' ', &tolower, &ft_tolower);
	test_to('~', &tolower, &ft_tolower);

	// STRING TESTS
	printf("\n------------------------ STRCHR -------------------------\n");
	test_strchr(src, 'i', &strchr, &ft_strchr);
	test_strchr(src, ' ', &strchr, &ft_strchr);
	test_strchr(src, 's', &strchr, &ft_strchr);
	test_strchr(src, '2', &strchr, &ft_strchr);
	test_strchr(src, 0, &strchr, &ft_strchr);
	test_strchr(src, 'a', &strchr, &ft_strchr);
	test_strchr(src, '9', &strchr, &ft_strchr);

	printf("\n------------------------ STRCHR -------------------------\n");
	test_strchr(src, 'i', &strrchr, &ft_strrchr);
	test_strchr(src, ' ', &strrchr, &ft_strrchr);
	test_strchr(src, 's', &strrchr, &ft_strrchr);
	test_strchr(src, '2', &strrchr, &ft_strrchr);
	test_strchr(src, 0, &strrchr, &ft_strrchr);
	test_strchr(src, 'a', &strrchr, &ft_strrchr);
	test_strchr(src, '9', &strrchr, &ft_strrchr);

	printf("\n --------------------- STRNCMP ------------------------\n");
	test_strncmp("abc", "abc", 4);
	test_strncmp("abc", "abc", 3);
	test_strncmp("abc", "abd", 2);
	test_strncmp("abc", "abd", 3);
	test_strncmp("abd", "abc", 3);
	test_strncmp("abc", "abd", 0);
	test_strncmp("", "", 1);
	test_strncmp("", "abc", 3);
	test_strncmp("abc", "", 3);

	printf("\n --------------------- STRLCPY ------------------------\n");
	test_strlcpy(src, 0);
	test_strlcpy(src, 5);
	test_strlcpy(src, 10);
	test_strlcpy(src, 20);
	test_strlcpy(src, 21);
	test_strlcpy("", 0);

	printf("\n --------------------- STRLCAT ------------------------\n");
	char *dst = malloc(sizeof(*dst) * 7);
	char *src2 = "def";
	strcpy(dst, "abc");

	test_strlcat(dst, src2, 5);
	test_strlcat(dst, src2, 7);
	test_strlcat(dst, src2, 10);
	test_strlcat(dst, src2, 0);

	strcpy(dst, "abc");
	test_strlcat(dst, src2, 2);
	strcpy(dst, "");
	test_strlcat(dst, src2, 7);
	test_strlcat(dst, "", 7);

	printf("\n --------------------- STRNSTR ------------------------\n");
	char *big = "il etait une fois 42";
	size_t len = ft_strlen(big);

	test_strnstr(big, "il", len);
	test_strnstr(big, "i", len);
	test_strnstr(big, " ", len);
	test_strnstr(big, "il etait une fois 42", len);
	test_strnstr(big, "42", len);
	test_strnstr(big, "2", len);
	test_strnstr(big, "il etait une fois 42", 5);
	test_strnstr(big, "il etait une fois 42", 10);
	test_strnstr(big, "il", 0);

	char *test = "Hello wworld";
	test_strnstr(test, "world", 100);
	test_strnstr(test, "he", 100);
	test_strnstr(test, "hl", 100);
	test_strnstr(test, "ld", 100);
	test_strnstr(test, "wld", 100);
	test_strnstr(test, "world", 6);
	test_strnstr(test, "he", 6);
	test_strnstr(test, "hl", 6);
	test_strnstr(test, "ld", 6);
	test_strnstr(test, "wld", 6);

	test_strnstr("", "world", 100);
	test_strnstr("", "world", 0);
	test_strnstr("world", "", 100);
	test_strnstr("world", "", 0);
	test_strnstr("", "", 100);
	test_strnstr("", "", 0);

	printf("\n --------------------- ATOI ------------------------\n");
	test_atoi("2147483647");
	test_atoi("-2147483648");
	test_atoi("0");
	test_atoi("00");
	test_atoi("01");
	test_atoi("-0");
	test_atoi("+0");
	test_atoi(" \t \v \f \r \n -2147483648");
	test_atoi(" \t \v \f \r \n -2147483648\t \v \f \r \n");
	test_atoi(" \t \v \f \r \n -214748364 \t \v \f \r \n8");
	test_atoi(" -2147483648");
	test_atoi(" -2147483648abc");
	test_atoi(" -2147483648abc9");
	test_atoi(" -+-+2147483648");
	test_atoi("2147483647 ");
	test_atoi("-5");
	test_atoi("-10");
	test_atoi("+42");
	test_atoi("42");
	test_atoi("-42");
	test_atoi("");

	printf("\n --------------------- CALLOC ------------------------\n");
	test_calloc(10, sizeof(int));
	test_calloc(10, 0);
	test_calloc(0, 10);
	test_calloc(0, 0);

	printf("\n --------------------- STRDUP ------------------------\n");
	test_strdup("abc");
	test_strdup("");

	return (0);
}
