/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:26:50 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/21 20:35:55 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "stdio.h"

static int	put_tetri(char **result, size_t i, size_t j, int coord[4][2],
		char towrite)
{
	if ((!result[i + coord[1][0]]) || (!result[i + coord[2][0]]) ||
			(!result[i + coord[3][0]]))
		return (0);
	if (result[i + coord[0][0]][j + coord[0][1]] == '.' &&
		result[i + coord[1][0]][j + coord[1][1]] == '.' &&
		result[i + coord[2][0]][j + coord[2][1]] == '.' &&
		result[i + coord[3][0]][j + coord[3][1]] == '.')
	{
		result[i + coord[0][0]][j + coord[0][1]] = towrite;
		result[i + coord[1][0]][j + coord[1][1]] = towrite;
		result[i + coord[2][0]][j + coord[2][1]] = towrite;
		result[i + coord[3][0]][j + coord[3][1]] = towrite;
		return (1);
	}
	return (0);
}

static char	**try_to_place(t_list *list, char **result, char towrite)
{
	int		coord[4][2];
	size_t	i;
	size_t	j;

	if (!list)
		return (NULL);
	ft_memcpy((void*)coord, list->content, (sizeof(int) * 8));
	i = 0;
	while (result[i])
	{
		j = 0;
		while (result[i][j])
		{
			if (put_tetri(result, i, j, coord, towrite))
				return (try_to_place(list->next, result, towrite + 1));
			j++;
		}
		i++;
	}
	return (result);
}

static char	**calc_tab(size_t nb_tetri, size_t nb_try)
{
	char	**result;
	size_t	size;
	size_t	i;
	size_t	tmp;

	size = 0;
	while (!ft_sqrt(nb_tetri * 4 + size))
		size++;
	size = ft_sqrt(nb_tetri * 4 + size) + nb_try;
	if (!(result = (char**)malloc(sizeof(*result) * (size + 1))))
		return (NULL);
	result[size] = NULL;
	i = 0;
	while (i < size)
	{
		if (!(result[i] = (char*)malloc(sizeof(*result) * (size + 2))))
			return (NULL);
		tmp = 0;
		while (tmp < size)
			result[i][tmp++] = '.';
		result[i][size + 1] = '\0';
		result[i++][size] = '\n';
	}
	return (result);
}

void		fillit(t_list *list, size_t nb_tetri)
{
	char	**result;
	size_t	index;

	result = NULL;
	index = 0;
	while (!result)
	{
		result = calc_tab(nb_tetri, index++);
		result = try_to_place(list, result, 'A');
	}
	index = 0;
	while (result[index])
		ft_putstr(result[index++]);
}
