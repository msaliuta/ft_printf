/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 16:31:55 by msaliuta          #+#    #+#             */
/*   Updated: 2018/11/04 16:32:11 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_size_array(char const *s, char c)
{
	size_t		size_array;
	char const	*temp_s;

	size_array = 0;
	temp_s = s;
	while (*temp_s != '\0')
	{
		if (*temp_s != c && (*(temp_s - 1) == c || (temp_s - 1) < s))
			size_array++;
		temp_s++;
	}
	return (size_array);
}

static int		ft_copy_str(char const *s, char c, size_t size_array,
				char **ret)
{
	size_t	i;
	size_t	len_str;

	i = 0;
	len_str = 0;
	while (i < size_array)
	{
		if (*s != c && *s != '\0')
			len_str++;
		else if (len_str)
		{
			if ((ret[i] = (char *)malloc(sizeof(**ret) * len_str + 1)) == NULL)
				return (1);
			ft_strncpy(ret[i], s - len_str, len_str);
			ret[i++][len_str] = '\0';
			len_str = 0;
		}
		s++;
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**ret;
	size_t		size_array;

	if (s == NULL)
		return (NULL);
	size_array = ft_get_size_array(s, c);
	ret = (char **)malloc(sizeof(*ret) * (size_array + 1));
	if (ret == NULL)
		return (NULL);
	if (ft_copy_str(s, c, size_array, ret))
		return (NULL);
	ret[size_array] = NULL;
	return (ret);
}
