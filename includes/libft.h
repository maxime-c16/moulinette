/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:45:04 by mcauchy           #+#    #+#             */
/*   Updated: 2024/11/22 15:48:37 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>

# define C_RESET "\e[0m"
# define C_PURPLE "\e[34m"
# define C_RED "\e[31m"
# define C_GREEN "\e[32m"

typedef struct s_heredocs
{
	char		**limit_herdocs;
	int			*fd;
	char		**file_n;
}				t_heredocs;

typedef struct s_dic
{
	char	*key;
	char	*value;
}			t_dic;

typedef struct s_data
{
	t_dic				*env;
	int					*pid;
	int					nb_cmd;
	int					nb_pipe;
	int					*fd;
	int					nb_hd;
	int					save_in;
	int					save_out;
	int					env_len;
	int					error;
}			t_data;

typedef struct s_token
{
	char	**cmd;
	int		type;
}	t_token;

typedef struct s_list
{
	t_token				*token;
	int					hd_node;
	struct s_heredocs	*h_docs;
	struct s_list		*next;
}						t_list;

typedef struct s_help
{
	int		i;
	int		j;
	int		k;
	int		p;
	char	c;
}	t_help;

int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_strcmp(char *s1, char *s2);
int		ft_memcmp(const void *s1, const void *s2, int n);
int		ft_atoi(char *str);
char	ft_isalpha(char c);
char	ft_isalnum(char c);
char	ft_isprint(char c);
char	ft_tolower(char c);
char	ft_isdigit(char c);
char	ft_isascii(char c);
char	ft_toupper(char c);
int		ft_str_is_numeric(char *str);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, int n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *b, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_char(char *str, char c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
char	**ft_split_parsing(char const *s, char c);
char	*ft_strcpy(char *str, char *old_str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcat(char *dst, char *src, unsigned int size);

// liste chainee

void	ft_lstclear(t_list **alst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void);
t_list	*ft_lstlast(t_list *lst);

#endif
