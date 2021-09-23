int tmpstrstr(char *s, char c);
void ft_strcpy(char *dest, char *src);
void	check_quote(char c, char *bitflag_quote);
void	check_quote2(char c, char *bitflag_quote);
int find_bracket(char *s);
	while (s[++i]);
char *newstrcat(char *s1, char *s2);
		while (*s2);
int bracket_num(char *s);
	while (s[++i]);
int is_blank(char c);
int is_next_curly_bracket(int fd);
int is_func_dec(char *s, int fd);
	while (s[++i]);
void write_to_header(int fd, char *s, int i);
int is_same_extension(char *s, char *extension);
void	ft_qsort(unsigned long long int *array, int left, int right);
		while (++i <= right);
unsigned long long int ft_pow(unsigned long long int base, unsigned long long int n);
	while (sq_two[i++] < n && i < 30);
	while (i-- > 0);
unsigned long long int str2long(char *s);
	while (*s);
char *extract_func_name(char *s);
int input_existing_func(char *argv, unsigned long long int *func_name);
int nibun_find(unsigned long long int *array, int num, unsigned long long int n);
	while (right - left > 1);
int is_func_existing(unsigned long long int *func_name, int func_num, char *s);
void process_main(unsigned long long int *func_name, int func_num, int fd_read, int fd_write);
int ini_func_name(unsigned long long int *func_name);
int is_generated_h(char *s);
int some_args(int argc, char *argv[]);
void free_gnl(int argc, char **argv);
void no_args(int argc, int i);
int main(int argc, char *argv[]);
int	get_next_line2(int fd, char **line, char *s);
	while (1);
int	get_next_line(int fd, char **line);
int	ft_njoin(char **line, char *s, int n, int tmpi);
int	search(char *s, t_s *ss, int fd);
int	ft_ini(char **line, char *s, t_s *ss, int fd);
int	ft_save(t_s *ss, char *s, int fd, int *f);
int	ft_atoi(const char *str);
	while (*str >= '0' && *str <= '9');
void	ft_bzero(void *s, size_t n);
	while (n > 0);
void	*ft_calloc(size_t n, size_t size);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
static long	count(long tmp, int f);
	while (tmp > 0);
char		*convert_nb(char *str, long tmp, long ftlog10, int f);
		while (ftlog10 > 0 && tmp);
char		*ft_itoa(int n);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
		while (tmp);
		while (lst);
t_list	*ft_lstlast(t_list *lst);
	while (lst);
t_list		*ft_lstnew(void *content);
int	ft_lstsize(t_list *lst);
	while (lst->next);
void	*ft_memccpy(void *buf1, const void *buf2, int c, size_t n);
	while (n > 0);
void	*ft_memchr(const void *buf, int ch, size_t n);
	while (n > 0);
int	ft_memcmp(const void *buf1, const void *buf2, size_t n);
void		*ft_memcpy(void *buf1, const void *buf2, size_t n);
	while (n > 0);
void		*ft_memmove(void *buf1, const void *buf2, size_t n);
	while (n > 0);
void		*ft_memset(void *buf, int ch, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
static int	ft_count(char const *s, char c);
	while (*s);
char		**ft_split(char const *s, char c);
	while (s[j]);
char		*ft_strchr(const char *s, int c);
static	char	*ft_strcpy(char *dest, char *src);
char			*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
	while (s1[i] != '\0');
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t					ft_strlcpy(char *dest, const char *src, size_t size);
	while (src[i] && i < size - 1);
size_t	ft_strlen(const char *s);
	while (*s != '\0');
	while (s[i]);
int							ft_strncmp(const char *s1, const char *s2, size_t n);
	while (*ss == *ss2 && *ss != '\0' && --n != 0);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
char		*ft_strrchr(const char *s, int c);
	while (*s != '\0');
char		*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
		while (len-- > 0 && s[start + i] != '\0');
int	ft_tolower(int c);
int	ft_toupper(int c);
