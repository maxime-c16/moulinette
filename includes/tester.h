/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:39:44 by mcauchy           #+#    #+#             */
/*   Updated: 2024/06/28 17:55:15 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H

# define TESTER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>
# include <readline/readline.h>

# define BUFF_SIZE 4096

// c00

void			ft_putchar(char c);
void			ft_print_alphabet(void);
void			ft_print_reverse_alphabet(void);
void			ft_print_numbers(void);
void			ft_is_negative(int n);
void			ft_print_comb(void);
void			ft_print_comb2(void);
void			ft_putnbr(int nb);
void			ft_print_combn(int n);

// c01

void			ft_ft(int *nbr);
void			ft_ultimate_ft(int *********nbr);
void			ft_swap(int *a, int *b);
void			ft_div_mod(int a, int b, int *div, int *mod);
void			ft_ultimate_div_mod(int *a, int *b);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
void			ft_rev_int_tab(int *tab, int size);
void			ft_sort_int_tab(int *tab, int size);

// c02

char			*ft_strcpy(char *dest, char *src);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
int				ft_str_is_alpha(char *str);
int				ft_str_is_numeric(char *str);
int				ft_str_is_lowercase(char *str);
int				ft_str_is_uppercase(char *str);
int				ft_str_is_printable(char *str);
char			*ft_strupcase(char *str);
char			*ft_strlowcase(char *str);
char			*ft_strcapitalize(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
void			ft_putstr_non_printable(char *str);
void			*ft_print_memory(void *addr, unsigned int size);

//print memory utils
void			ft_print_hex(unsigned char c);
void			print_hex_line(void *addr, unsigned int size);
void			print_char_line(void *addr, unsigned int size);
void			print_address(void *addr);

// c03

int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strcat(char *dest, char *src);
char			*ft_strncat(char *dest, char *src, unsigned int nb);
char			*ft_strstr(char *str, char *to_find);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

// c04

int				ft_atoi(char *str);
void			ft_putnbr_base(int nbr, char *base);
int				ft_atoi_base(char *str, char *base);

// c05

int				ft_iterative_factorial(int nb);
int				ft_recursive_factorial(int nb);
int				ft_iterative_power(int nb, int power);
int				ft_recursive_power(int nb, int power);
int				ft_fibonacci(int index);
int				ft_sqrt(int nb);
int				ft_is_prime(int nb);
int				ft_find_next_prime(int nb);
int				ft_ten_queens_puzzle(void);

// c06 not listed because they are programs

// c07

char			*ft_strdup(char *str);
int				*ft_range(int min, int max);
int				ft_ultimate_range(int **range, int min, int max);
char			*ft_strjoin(int size, char **strs, char *sep);
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);

// c08

typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
void				ft_show_tab(struct s_stock_str *par);

// c09 not needed

// c10

// ft_tail
void	ft_error(char *filename);

// c11

void	ft_foreach(int *tab, int length, void (*f)(int));
int		*ft_map(int *tab, int length, int (*f)(int));
int		ft_any(char **tab, int (*f)(char*));
int		ft_count_if(char **tab, int length, int (*f)(char*));
int		ft_is_sort(int *tab, int length, int (*f)(int, int));

// do-op utils

int		add(int a, int b);
int		sub(int a, int b);
int		mul(int a, int b);
int		divi(int a, int b);
int		mod(int a, int b);

void	ft_sort_string_tab(char **tab);
void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *));

// c12

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
t_list	*ft_list_last(t_list *begin_list);
void	ft_list_push_back(t_list **begin_list, void *data);
t_list	*ft_list_push_strs(int size, char **strs);
void	ft_list_clear(t_list *lst, void (*free_fct)(void *));
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);
void	ft_list_reverse(t_list **begin_list);

#endif
