#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
#include "./libft/libft.h"
# define FLAG_DOUBLE_QUOTE 2
# define FLAG_SINGLE_QUOTE 1
# define FLAG_MINUS_ONE 4
# define FLAG_ESCAPE 8

# define MAX_FUNC 5000
# define MAX_FILE 2000

int tmpstrstr(char *s, char c)
{
	int ret;

	ret = -1;
	while (s[++ret])
		if (s[ret] == c)
			return (ret + 1);
	return (ret);
}

void ft_strcpy(char *dest, char *src)
{
	while (*src)
		*(dest++) = *(src++);
	*dest = '\0';
}

void	check_quote(char c, char *bitflag_quote)
{
	if (c == '\\')
		*bitflag_quote ^= FLAG_ESCAPE;
	else if (*bitflag_quote & FLAG_ESCAPE)
	{
		*bitflag_quote &= ~FLAG_ESCAPE;
		return ;
	}
	if (c == '\'' && *bitflag_quote < 4 && !(*bitflag_quote
				& FLAG_DOUBLE_QUOTE))
		*bitflag_quote ^= FLAG_SINGLE_QUOTE;
	if (c == '\"' && *bitflag_quote < 4 && !(*bitflag_quote
				& FLAG_SINGLE_QUOTE))
		*bitflag_quote ^= FLAG_DOUBLE_QUOTE;
}

void	check_quote2(char c, char *bitflag_quote)
{
	return;
	if (c == '\\' && (*bitflag_quote < 4 || *bitflag_quote >= FLAG_ESCAPE)
			&& !(*bitflag_quote & FLAG_SINGLE_QUOTE))
		*bitflag_quote ^= FLAG_ESCAPE;
	else if (*bitflag_quote & FLAG_ESCAPE)
	{
		*bitflag_quote &= ~FLAG_ESCAPE;
		return ;
	}
	if (c == '\'' && *bitflag_quote < 4 && !(*bitflag_quote
				& FLAG_DOUBLE_QUOTE))
		*bitflag_quote ^= FLAG_SINGLE_QUOTE;
	if (c == '\"' && *bitflag_quote < 4 && !(*bitflag_quote
				& FLAG_SINGLE_QUOTE))
		*bitflag_quote ^= FLAG_DOUBLE_QUOTE;
	if (c == -1)
		*bitflag_quote ^= FLAG_MINUS_ONE;
}

int find_bracket(char *s)
{
	static char bitflag_quote = 0;
	int i;

	i = -1;
	while (s[++i])
	{
		check_quote(s[i], &bitflag_quote);
		if (!bitflag_quote && s[i] == '(')
			return (i);
	}
	return (-1);
}

char *newstrcat(char *s1, char *s2)
{
	char *ret;
	int i;

	if ((ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2)))
	{
		i = -1;
		while (s1[++i])
			ret[i] = s1[i];
		ret[i++] = '\n';
		while (*s2)
		{
			ret[i++] = *s2;
			s2++;
		}
		ret[i] = 0;
	}
	free(s1);
	return (ret);
}

int bracket_num(char *s)
{
	static int num = 0;
	static char bitflag_quote = 0;
	int i;

	i = -1;
	while (s[++i])
	{
		check_quote(s[i], &bitflag_quote);
		if (!bitflag_quote)
		{
			if (s[i] == '(')
				num++;
			else if (s[i] == ')')
				num--;
		}
	}
	return (num);
}



int is_blank(char c)
{
	if (c <= 32 && c)
		return (1);
	else
		return (0);
}

int is_next_curly_bracket(int fd)
{
	char *line;
	int i;
	int ret;

	i = -1;
	while (get_next_line(fd, &line) > 0)
	{
		while (is_blank(line[++i]))
			;
		if (line[i] == '\0')
		{
			free(line);
			break;
		}
		ret = (line[i] == '{');
		free(line);
		return (ret);
	}
	return (0);
}

int is_func_dec(char *s, int fd)
{
	int i;
	char bitflag_quote;

	i = -1;
	bitflag_quote = 0;
	while (s[++i])
	{
		check_quote(s[i], &bitflag_quote);
		if (!bitflag_quote && s[i] == ')')
		{
			while (is_blank(s[++i]))
				;
			if (s[i] == '{')
				return (1);
			else if (s[i] == '\0')
				return (is_next_curly_bracket(fd));
			else
				return (0);
		}
	}
	return (0);
}

void write_to_header(int fd, char *s, int i)
{
	int len;
	char **line;

	line = ft_split(s, '\n');
	while (line[++i] && (len = -1))
	{
		while (is_blank(line[i][++len]))
			;		
		if (ft_isalnum(line[i][len]) && !ft_strchr(line[i], ';'))
		{
			write(fd, line[i], tmpstrstr(line[i], ')'));
			if (ft_strchr(line[i], ')'))
			{
				write(fd, ";\n", 2);
				free(line[i]);
				free(line);
				return;
			}
			write(fd, "\n", 1);
		}
		free(line[i]);
	}
}

int is_same_extension(char *s, char *extension)
{
	int i;
	int extension_len;

	extension_len = -1;
	i = -1;
	while (extension[++extension_len])
		;
	while (s[++i])
		;
	if (extension_len > i)
		return (0);
	while (extension_len)
		if (extension[--extension_len] != s[--i])
			break;
	return (extension[extension_len] == s[i]);
}

void	ft_qsort(unsigned long long int *array, int left, int right)
{
	int i;
	int last;
	unsigned long long int tmp;

	if (left < right)
	{
		last = left;
		i = left;
		while (++i <= right)
		{
			if (array[i] < array[left])
			{
				last++;
				tmp = array[i];
				array[i] = array[last];
				array[last] = tmp;
			}
		}
		tmp = array[last];
		array[last] = array[left];
		array[left] = tmp;
		ft_qsort(array, left, last-1);
		ft_qsort(array, last+1, right);
	}
}

unsigned long long int ft_pow(unsigned long long int base, unsigned long long int n)
{
	unsigned long long int tmp[30];
	unsigned long long int sq_two[30];
	unsigned long long int ret;
	int i;

	i = 0;
	tmp[0] = base;
	sq_two[0] = 1;
	while (sq_two[i++] < n && i < 30)
	{
		tmp[i] = tmp[i - 1] * tmp[i - 1];
		sq_two[i] *= 2;
	}
	ret = 1;
	while (i-- > 0)
	{
		if (n > sq_two[i])
		{
			ret *= tmp[i];
			n -= sq_two[i];
		}
	}
	return (ret);
}

unsigned long long int str2long(char *s)
{
	unsigned long long int ret;

	ret = 100;
	while (*s)
	{
		if (!is_blank(*s))
			ret = (ret + 1) * ft_pow(ret + (unsigned long long int)*s, (unsigned long long)*s * (unsigned long long)*s);
		s++;
	}
	return (ret);
}

char *extract_func_name(char *s)
{
	int i;
	int j;

	if ((i = find_bracket(s) - 1) >= 0)
	{
		while (i > 0 && is_blank(s[i]))
			i--;
		while (i > 0 && !is_blank(s[i]))
			i--;
		j = 0;
		while (s[i] != '(')
			s[j++] = s[i++];
		s[j] = '\0';
	}
	else
		ft_strcpy(s, "if");
	return (s);
}

int input_existing_func(char *argv, unsigned long long int *func_name)
{
	int fd;
	char *line[2];
	int i;
	int ret;

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (0);
	ret = 0;
	while (get_next_line(fd, line) > 0)
	{
		i = 0;
		while (bracket_num(line[!!i++]))
			if (get_next_line(fd, line + 1) <= 0)
				return (-1);
			else if (!(line[0] = newstrcat(line[0], line[1])))
				return (-1);
		if (i > 1)
			free(line[1]);
		if (find_bracket(line[0]) >= 0)
			func_name[ret++] = str2long(extract_func_name(line[0]));
		free(line[0]);
	}
	close(fd);
	return (ret);
}

int nibun_find(unsigned long long int *array, int num, unsigned long long int n)
{
	int mid;
	int left;
	int right;

	right = num - 1;
	left = 0;
	while (right - left > 1)
	{
		mid = (right + left) / 2;
		if (array[mid] > n)
			right = mid;
		else
			left = mid;
	}
	if (array[left] == n || array[right] == n)
		return (1);
	else
		return (0);
}

int is_func_existing(unsigned long long int *func_name, int func_num, char *s)
{
	char tmp[MAX_FUNC];

	ft_strcpy(tmp, s);
	if (!func_num)
		return (0);
	return (nibun_find(func_name, func_num, str2long(extract_func_name(tmp))));
}

void process_main(unsigned long long int *func_name, int func_num, int fd_read, int fd_write)
{
	char *line[2];
	int i;

	while (get_next_line(fd_read, line) > 0)
	{
		i = 0;
		while (bracket_num(line[!!i++]))
		{
			if (get_next_line(fd_read, line + 1) <= 0)
				return;
			if (!(line[0] = newstrcat(line[0], line[1])))
				return;
		}
		if (i > 1)
			free(line[1]);
		if (is_func_dec(line[0], fd_read) && !is_func_existing(func_name, func_num, line[0]))
			write_to_header(fd_write, line[0], -1);
		free(line[0]);
	}
	free(line[0]);
	close(fd_read);
}

int ini_func_name(unsigned long long int *func_name)
{
	func_name[0] = str2long("if");
	func_name[1] = str2long("while");
	func_name[2] = str2long("for");
	func_name[3] = str2long("do");
	func_name[4] = str2long("else");
	func_name[5] = str2long("else if");
	func_name[6] = str2long("main");
	return (7);
}

int is_generated_h(char *s)
{
	int i;
	int len;

	i = -1;
	while (s[++i])
		;
	if ((len = ft_strlen("generated_header.h")) > i)
		return (0);
	while (len > 0)
		if ("generated_header.h"[--len] != s[--i])
			return (0);
	return (i == 0 || s[i - 1] == '/');
}

int some_args(int argc, char *argv[])
{
	int i;
	unsigned long long int func_name[MAX_FUNC];
	int func_num;
	int fd_write;

	func_num = ini_func_name(func_name);
	i = 0;
	while (++i < argc)
		if (is_same_extension(argv[i], ".h") && !is_generated_h(argv[i]))
			func_num += input_existing_func(argv[i], func_name + func_num);
	if (func_num)
		ft_qsort(func_name, 0, func_num - 1);
	if ((fd_write = open("./generated_header.h", O_CREAT|O_WRONLY|O_TRUNC)) == -1)
		return (-1);
	i = 0;
	while (++i < argc)
		if (is_same_extension(argv[i], ".c"))
			process_main(func_name, func_num, open(argv[i], O_RDONLY), fd_write);
	close(fd_write);
	return (0);
}

void free_gnl(int argc, char **argv)
{
	while (--argc > 0)
		free(argv[argc]);
}

void no_args(int argc, int i)
{
	unsigned long long int func_name[MAX_FUNC];
	char *argv[MAX_FILE];
	int func_num;
	int fd_write;

	system("find | grep -e \"\\.c\" -e \"\\.h\" | grep -v \"\\.c.\" | grep -v \"\\.h.\" > ./generated_header.h");
	fd_write = open("./generated_header.h", O_RDONLY);
	while (get_next_line(fd_write, argv + ++i) > 0)
		argc++;
	close(fd_write);
	func_num = ini_func_name(func_name);
	i = 0;
	while (++i < argc)
		if (is_same_extension(argv[i], ".h") && !is_generated_h(argv[i]))
			func_num += input_existing_func(argv[i], func_name + func_num);
	if (func_num)
		ft_qsort(func_name, 0, func_num - 1);
	if ((fd_write = open("./generated_header.h", O_CREAT|O_WRONLY|O_TRUNC)) == -1)
		return;
	i = 0;
	while (++i < argc)
		if (is_same_extension(argv[i], ".c"))
			process_main(func_name, func_num, open(argv[i], O_RDONLY), fd_write);
	close(fd_write);
	free_gnl(argc, argv);
}

int main(int argc, char *argv[])
{
	if (argc == 1)
		no_args(1, 0);
	else
		return (some_args(argc, argv));
	return (0);
}