/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 18:34:45 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/20 22:03:43 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fcntl.h"

static t_list	*check_tetri(char *tocheck)
{
	t_list	*result;

	result = NULL;
	return (result);
}

static t_list	*read_and_save(int fd)
{
	t_list	*result;
	char	buf[21];
	int		tmp;

	tmp = read(fd, &buf, 21);
	buf[tmp] = '\0';
	result = check_tetri(buf);
	while ((tmp = read(fd, &buf, 21)))
	{
		buf[tmp] = '\0';
		ft_lstadd(&result, check_tetri(buf));
		if (result == NULL)
			return (NULL);
	}
	return (result);
}

t_list			*stock_tetri(char *filename)
{
	int		fd;
	t_list	*result;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	if ((result = read_and_save(fd)) == NULL)
		return (NULL);
	return (result);
}
