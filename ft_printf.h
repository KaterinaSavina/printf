#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_format
{
	int	minus;
	int	zero;
	int	width;
	int	precision;
	int	star;
	int	type;
	int	hex;
	int	base;
	int	lenght;
}	t_sf;

int		ft_printf(const char *format, ...);
void	ft_parser_str(const char *format, t_sf *flags, va_list ap);
int		ft_check_type(const char *format, int x, t_sf *flags, va_list ap);
void	ft_init_flags(t_sf *flags);
int		ft_flag(int i);
int		ft_type(int i);
int		ft_precision(const char *format, int x, t_sf *flags, va_list ap);
t_sf	ft_hex(t_sf flags, char c);
t_sf	ft_minus(t_sf flags);
t_sf	ft_star(t_sf flags, va_list ap);
t_sf	ft_width(t_sf flags, char c);
int		ft_putchar(char c);
int		print_me(t_sf flags, va_list ap);
int		ft_print_w(int width, int min, int x);
int		ft_print_c(char c, t_sf flags);
int		ft_print_str(char *str, t_sf flags);
int		ft_printer_str(t_sf flags, char *str, int len);
int		ft_print_precision(int precision, char *str);
int		ft_print_p(unsigned long long p, t_sf flags);
int		ft_zero_ptr(t_sf flags);
char	*ft_str_maker(unsigned long long t, t_sf flags);
char	*ft_do_string(unsigned long long tmp, int i, char *str, t_sf flags);
int		ft_ptr_printer(int n, int len, char *ptr, t_sf flags);
int		ft_ptr(int len, char *ptr, t_sf flags);
int		ft_print_int(long d, t_sf flags);
int		ft_int(char *str, long tmp, t_sf flags);
int		ft_printer_int(char *str, long tmp, t_sf flags);
int		ft_print_uint(unsigned int u, t_sf flags);
char	*ft_long_itoa(long u);
int		ft_u_int(int len, char *str, t_sf flags);
int		ft_printer_uint(int len, char *str, t_sf flags);
int		ft_print_h(unsigned int hex, t_sf flags);
int		ft_change_hex(int len, char *str, t_sf flags);
int		ft_printer_hex(int len, char *str, t_sf flags);
int		ft_digit(int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_toupper(int c);

#endif
