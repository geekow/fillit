/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:26:50 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/23 19:33:17 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static void	rm_from_matrice(char **result, char to_rm, int *pos, int c)
{
	size_t	i;
	size_t	j;
	int 	t;

	t = 0;
	i = 0;
	while (result[i])
	{
		j = 0;
		while (result[i][j])
		{
			if (result[i][j] == to_rm)
			{
				result[i][j] = '.';
				if (!t++)
					*pos -= c;
			}
			j++;
		}
		i++;
	}
}

static int		alr_pl(char **r, char to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (r[i])
	{
		j = 0;
		while (r[i][j])
		{
			if (r[i][j] == to_find)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int				test(int pos[2], char tow, char **result, int coord[4][2])
{
		rm_from_matrice(result, tow, &pos[1], coord[0][1]);
		while (result[pos[0]])
		{
			while (result[pos[0]][pos[1]++] != '\n')
			{
				if (check_and_put_tetri(result, pos, coord, tow))
					return (1);
			}
			pos[1] = -1;
			pos[0]++;
		}
		return (0);
}

int				put_tetri(int coord[4][2], char tow, char **result)
{
	int	pos[2];

	pos[0] = 0;
	if (alr_pl(result, tow))
	{
		while (result[pos[0]] && !(pos[1] = 0))
		{
			while (result[pos[0]][pos[1]])
				if (result[pos[0]][pos[1]] == tow)
					return (test(pos, tow, result, coord));
				else
					pos[1]++;
			pos[0]++;
		}
	}
	else
		while (result[pos[0]] && !(pos[1] = 0))
		{
			while (result[pos[0]][pos[1]] != '\n')
				if (check_and_put_tetri(result, pos, coord, tow))
					return (1);
				else
					pos[1] = pos[1] + 1;
			pos[0] = pos[0] + 1;
		}
	return (0);
}

static char		**calc_tab(size_t nb_tetri, size_t nb_try)
{
	char	**result;
	size_t	size;
	size_t	i;
	size_t	tmp;

	size = 0;
	while (!ft_sqrt(nb_tetri * 4 + size))
		size++;
	size = ft_sqrt(nb_tetri * 4 + size) + nb_try;
	if (!(result = (char**)malloc(sizeof(char**) * (size + 3))))
		return (NULL);
	result[size] = NULL;
	i = 0;
	while (i < size)
	{
		if (!(result[i] = (char*)malloc(sizeof(char*) * (size + 2))))
			return (NULL);
		tmp = 0;
		while (tmp < size)
			result[i][tmp++] = '.';
		result[i][size + 1] = '\0';
		result[i++][size] = '\n';
	}
	return (result);
}

void			fillit(t_list *list, size_t nb_tetri)
{
	char	**result;
	size_t	index;

	result = NULL;
	index = 0;
	while (!result)
	{
		result = calc_tab(nb_tetri, index++);
		result = try_to_place(list, 'A', result);
	}
	index = 0;
	while (result[index])
		ft_putstr(result[index++]);
}
