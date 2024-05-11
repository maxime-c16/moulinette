/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moulinette.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:26:45 by mcauchy           #+#    #+#             */
/*   Updated: 2024/05/11 12:27:52 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOULINETTE_H

# define MOULINETTE_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define FD_STDOUT 1
# define FD_STDIN 0
# define FD_STDERR 2

// c00

# define FT_PUTCHAR_TESTER 6
# define FT_PRINT_ALPHABET_TESTER 1
# define FT_PRINT_REVERSE_ALPHABET_TESTER 1
# define FT_PRINT_NUMBERS_TESTER 1
# define FT_IS_NEGATIVE_TESTER 5
# define FT_PRINT_COMB_TESTER 1
# define FT_PRINT_COMB2_TESTER 1
# define FT_PUTNBR_TESTER 5
# define FT_PRINT_COMBN_TESTER 1

// c01

# define FT_FT_TESTER 1
# define FT_ULTIMATE_FT_TESTER 1
# define FT_SWAP_TESTER 1
# define FT_DIV_MOD_TESTER 3
# define FT_ULTIMATE_DIV_MOD_TESTER 3
# define FT_PUTSTR_TESTER 3
# define FT_STRLEN_TESTER 2
# define FT_REV_INT_TAB_TESTER 2
# define FT_SORT_INT_TAB_TESTER 2

// c02

# define FT_STRCPY_TESTER 5
# define FT_STRNCPY_TESTER 1

extern int	g_value;

char	**ft_split(char const *s, char c);

//main.c

void	ft_print_tab(char **tab);
char	**ft_dup_tab(char **str);

//split_utils.c

void	ft_pass_quote(char *cmd, int *j);
int		count_utils(char *cmd, int *i);
int		ft_count(char *cmd);
int		ft_is_quote(char c);
void	ft_pass_quote_sp(char *cmd, int i, int *j);

//free.c

void	hasta_la_vista(int flag);
void	ft_free_tab(char **tab);
void	ft_print_lst(void);
void	free_env(t_dic *env);

//singleton.c

t_list	*_lst(void);
t_data	*_data(void);

//env_var.c

char	**expand(char **token);
char	*insert(char *token, int i);

//env_manipulating.c

char	*lcd_strcmp(char *s1, char *s2);
char	*get_value(char *key);

//env_parsing.c

int		test_env(char **env);
char	*ft_strndup(char *str, int n);
int		split_env(char **ev);
int		len_env(char **env);

//parsing.c

int		parsing(char *cmd);

//insertion.c

void	ft_insertion(char **token, int *i, t_list **lst, char **env);
void	init_new_token(void);

//data_struct.c

void	ft_parse_and_insert(char **token);
int		ft_count_cmd(char **token, int i);

//exec.c

void	ft_exec(void);
void	ft_exec_cmd(t_list *lst, char **cmd, int i);

//exec_utils.c

void	multi_cmd_exec(void);
void	ft_exec_builtin(char **cmd);
void	ft_exec_one_builtin(void);
void	help_exec(void);
void	super_exec_helper(char **cmd);
void	exec_utils(char **env, char **cmd);

//exec_utils2.c

void	free_exec(char **cmd, char **env);
void	ft_close_fd(void);
void	ft_link_fd(int i);

//paths.c

char	**ft_path(char **full_path, char *cmd, int *j);
void	free_data(void);
char	**ft_binary_path(char *cmd);

//init.c

void	init_pid(void);
void	init_fd(void);

//srcs lcd_better_split.c

char	**lcd_split(char *cmd);
int		is_space(char c);

//utils.c

int		ft_lst_size_without_pipe(void);
void	ft_waitpid(void);
void	ft_error(char *str, int ret);
void	ft_dup2(int in, int out);
void	init_heredocs(t_list **lst);
int		ft_tablen(char **cmd);
void	close_main(char *line);

//redirections.c

void	ft_redirections(t_list *lst);
void	ft_redirection_right(char **cmd, int i);
void	ft_redirection_right_right(char **cmd, int i);

//redirections_utils.c

int		redir_help(int *i, char **cmd);
char	**ft_clean_redirection(char **cmd);
int		ft_check_redir(char **cmd);
char	**ft_exec_redir(t_list **lst);
char	*lcd_strjoin3000(char *s1, char const *s2);

//utils2.c

int		ft_lst_heredocs(void);
void	unlink_hd(void);
void	search_and_replace_pwd(char *old_pwd, char *pwd);

//utils3.c

char	**ft_convert_dict_tab(void);
int		skip_spaces(char *line);
char	**ft_tabcpy(char **tab);

//heredocs.c

void	limit_heredocs(void);
void	close_hd(void);

//heredocs_utils.c

void	write_hd(void);
void	ft_dup_heredocs(t_list *tmp, char **cmd, int j);

//builtins.c

int		is_builtin(char *cmd);

//builtins_exec.c

void	echo_cmd(char **cmd);
void	exit_cmd(char **cmd);
void	pwd_cmd(void);
void	cd_cmd(char **cmd);

//signals.c

void	sig_choice(int sig);

//refacto_token.c

char	*refacto_token_space(char *cmd);
void	refacto_help(char **ad_cmd, char *cmd, int *j);
int		ft_refacto_len(char *cmd);
int		ft_first_quote(char *cmd, int index, char c);
int		is_token(char cmd);
int		is_in_quote(char *cmd, int index);

//ft_unquoting.c

void	ft_unquoting(void);
void	ft_unquote_error(void);
char	find_next_quote(char *cmd, int i);
char	*ft_unquote_join(char *str, char c, int is_in_quote);

//display_env.c

void	print_env(void);
void	add_to_env(char *str);

//unset_env.c

void	unset_var(char *str);
int		is_charset(char *str, char *charset);

#endif
