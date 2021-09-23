void	check_quote(char c, char *bitflag_quote);
void	check_quote2(char c, char *bitflag_quote);
int is_blank(char c);
int is_same_extension(char *s, char *extension);
unsigned long long int str2long(char *s);
int input_existing_func(char *argv, unsigned long long int *func_name);
int is_func_existing(unsigned long long int *func_name, int func_num, char *s);
int is_generated_h(char *s);
