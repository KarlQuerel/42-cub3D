/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 03:03:40 by pcheron           #+#    #+#             */
/*   Updated: 2023/07/30 16:53:50 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_add_arg(char *print, char c, va_list args)
{
	int	r;

	r = 0;
	if (c == 's')
		return (ft_strconcat(print, va_arg(args, char *)));
	else if (c == 'c')
		print[ft_strlen(print)] = va_arg(args, int);
	return (1);
}

static char	*ft_malloc_args_size(char *str, va_list args)
{
	int	i;
	int	size;
	int	size_arg;

	i = 0;
	size = 0;
	size_arg = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			size_arg = ft_arg_len(str[i], args);
			if (size_arg < 0)
				return (NULL);
			size += size_arg;
		}
		else
			size++;
		i++;
	}
	return ((char *)malloc(size + 1));
}

static void	ft_build_joined_str(char *joined, char *str, va_list args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			joined[j] = 0;
			i++;
			j += ft_add_arg(joined, str[i], args);
		}
		else
		{
			joined[j] = str[i];
			j++;
		}
		i++;
	}
	joined[j] = 0;
}

char	*ft_argjoin(char *str, va_list args, va_list args_bis)
{
	char	*joined;

	joined = ft_malloc_args_size(str, args);
	if (!str)
		return (NULL);
	ft_build_joined_str(joined, str, args_bis);
	return (joined);
}

int	ft_print_fd(int fd, char *str, ...)
{
	va_list	args;
	va_list	args_bis;
	char	*print;
	int		r;

	if (fd < 0 || fd >= 1024)
		return (-1);
	va_start(args, str);
	va_start(args_bis, str);
	print = ft_argjoin(str, args, args_bis);
	va_end(args);
	va_end(args_bis);
	if (!print)
		return (-1);
	r = ft_putstr_fd(print, fd);
	free(print);
	return (r);
}
