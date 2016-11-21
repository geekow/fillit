/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:26:50 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/21 20:56:32 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "stdio.h"

static int	put_tetri(char **result, size_t pos[2], int coord[4][2],
						char towrite)
{
	if ((!result[pos[0] + coord[1][0]]) || (!result[pos[0] + coord[2][0]]) ||
			(!result[pos[0] + coord[3][0]]))
		return (0);
	if (result[pos[0] + coord[0][0]][pos[1] + coord[0][1]] == '.' &&
		result[pos[0] + coord[1][0]][pos[1] + coord[1][1]] == '.' &&
		result[pos[0] + coord[2][0]][pos[1] + coord[2][1]] == '.' &&
		result[pos[0] + coord[3][0]][pos[1] + coord[3][1]] == '.')
	{
		result[pos[0] + coord[0][0]][pos[1] + coord[0][1]] = towrite;
		result[pos[0] + coord[1][0]][pos[1] + coord[1][1]] = towrite;
		result[pos[0] + coord[2][0]][pos[1] + coord[2][1]] = towrite;
		result[pos[0] + coord[3][0]][pos[1] + coord[3][1]] = towrite;
		return (1);
	}
	return (0);
}

static char	**try_to_place(t_list *list, char **result, char towrite)
{
	int		coord[4][2];
	size_t	pos[2];

	if (!list)
		return (result);
	ft_memcpy((void*)coord, list->content, (sizeof(int) * 8));
	pos[0] = 0;
	while (result[pos[0]])
	{
		pos[1] = 0;
		while (result[pos[0]][pos[1]])
		{
			if (put_tetri(result, pos, coord, towrite))
				return (try_to_place(list->next, result, towrite + 1));
			pos[1] = pos[1] + 1;
		}
		pos[0] = pos[0] + 1;
	}
	return (NULL);
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
