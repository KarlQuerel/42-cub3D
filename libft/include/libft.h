/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:10:46 by pcheron           #+#    #+#             */
/*   Updated: 2023/12/16 15:57:17 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include <limits.h>

typedef struct s_lst
{
	char			*content;
	struct s_lst	*next;
}					t_lst;

// str

char	*ft_strchr(const char *s, int c);
int		ft_strlen(char *str);
char	*ft_strdup(char *s);
int		ft_strconcat(char *str1, char *str2);
bool	ft_strjoin(char **dest, char *left, char *right, int option);
int		ft_is_char_in_str(char c, char const *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);
int		ft_is_str_in_strs(char *str, char **strs, int option);
void	ft_str_replace(char *str, char find, char replace);
bool	ft_endswith(char *str, char *end);
bool	ft_strcomp(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// strs
void	ft_free_strs(char **strs);
char	**ft_split(char const *s, char c);
int		ft_is_in_tab(char **tab, char *str);
void	ft_free_2d_array(void ***ptr);
int		ft_strs_len(char **strs);

// write
int		ft_in_str(char *str, char c, int l);
int		ft_putstr_fd(char *str, int fd);
void	ft_print_strs(char **strs);
char	*ft_argjoin(char *str, va_list args, va_list args_bis);
int		ft_print_fd(int fd, char *str, ...);
int		ft_arg_len(char c, va_list args);
void	ft_putnbr_fd(int n, int fd);

// is_type
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_issign(char c);
bool	is_a_white_space(char c);

// parse_utils
bool	ft_multisign(char *str);
bool	ft_multiple_numbers(char *str);

// lst
t_lst	*ft_lstnew(char *content);
t_lst	*ft_lstlast(t_lst *lst);
void	ft_lstclear(t_lst **lst);
void	ft_lstadd_back(t_lst **lst, t_lst *new);

// mem
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);

// convert
char	*ft_itoa(int n);
bool	ft_atof_bool(float *val, char **arr);
float	ft_atof(char **arr);
bool	ft_atoi(int *result, char *str);

// file
char	*ft_get_next_line(int fd);
size_t	ft_strlenmod(char *s);
char	*ft_substrmod(char *s, unsigned int start, size_t len);
int		ft_reschr(char *str);
void	ft_strlcpymod(char *dst, char *src, size_t size);
char	*ft_strjoinmod(char *s1, char *s2);

// iter
void	ft_str_check_iter(char **s, bool (*f)(char));

#endif
