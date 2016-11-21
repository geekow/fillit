/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 18:34:45 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/21 15:54:02 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fcntl.h"

#include "stdio.h"

static t_list	*reg_tetri(char *buf, size_t blocks, size_t connections)
{
	int		coord[4][2];
	size_t	i;

	i = 0;
	if (blocks == 4 && (connections == 6 || connections == 8))
	{
		blocks = 0;
		while (buf[i])
			if (buf[i++] == '#')
			{
				coord[blocks][0] = (i - 1) / 5;
				coord[blocks++][1] = (i - 1) % 5;
			}
		while (coord[0][0] != 0 && !(blocks = 0))
			while (blocks++ < 4)
				coord[blocks - 1][0] = coord[blocks - 1][0] - 1;
		while (coord[0][1] != 0 && coord[2][1] != 0 && coord[3][1] != 0
				&& !(blocks = 0))
			while (blocks++ < 4)
				coord[blocks - 1][1] = coord[blocks - 1][1] - 1;
		return (ft_lstnew(coord, sizeof(coord)));
	}
	else
		return (NULL);
}

static t_list	*check_tetri(char *b)
{
	size_t	i;
	size_t	blocks;
	size_t	connections;

	i = 0;
	blocks = 0;
	connections = 0;
	while (b[i])
		if ((b[i] == '\n' && !((i + 1) % 5)) || (b[i] == '.' && ((i + 1) % 5)))
			i++;
		else if (b[i] == '#' && ++blocks)
		{
			if (i > 0 && b[i - 1] == '#')
				connections++;
			if (i < 19 && b[i + 1] == '#')
				connections++;
			if (i > 4 && b[i - 5] == '#')
				connections++;
			if (i < 15 && b[i + 5] == '#')
				connections++;
			i++;
		}
		else
			return (NULL);
	return (reg_tetri(b, blocks, connections));
}

static t_list	*check_buf(char *tocheck)
{
	size_t	len;

	len = ft_strlen(tocheck);
	if (len == 21)
	{
		if (tocheck[20] != '\n')
			return (NULL);
		else
		{
			tocheck[20] = '\0';
			return (check_tetri(tocheck));
		}
	}
	else if (len == 20)
		return (check_tetri(tocheck));
	else
		return (NULL);
}

static t_list	*read_and_save(int fd)
{
	t_list	*result;
	t_list	*cache;
	char	buf[21];
	size_t	tmp;
	size_t	nb_tetri;

	tmp = read(fd, &buf, 21);
	buf[tmp] = '\0';
	result = check_buf(buf);
	cache = result;
	nb_tetri = 1;
	if (result == NULL)
		return (NULL);
	while ((tmp = read(fd, &buf, 21)))
	{
		if (++nb_tetri > 26)
			return (NULL);
		buf[tmp] = '\0';
		cache->next = check_buf(buf);
		if (cache->next == NULL)
			return (NULL);
		cache = cache->next;
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
