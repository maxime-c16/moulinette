/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:39:44 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/28 16:46:58 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H

# define TESTER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

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

#endif
