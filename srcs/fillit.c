/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:26:50 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/22 19:22:25 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int	rm_from_matrice(char **result, char to_rm, int force)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_rm >= 'A')
	{
		while (result[i])
		{
			j = 0;
			while (result[i][j])
				if (result[i][j++] == to_rm)
				{
					result[i][j - 1] = '.';
					force = 0;
				}
			i++;
		}
		if (force)
			return (rm_from_matrice(result, to_rm - 1, 1));
		else
			return (to_rm);
	}
	return (0);
}

static int	already_placed(char **r, char to_find)
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

int			put_tetri(char **r, int c[4][2], char towrite, t_list **begin)
{
	size_t	p[2];
	char	exit;

	p[0] = 0;
	exit = 0;
	if (already_placed(r, towrite))
		return (1);
	while (r[p[0]] && !exit && !(p[1] = 0))
	{
		while (r[p[0]][p[1]] && !exit)
			if (check_no_overflow(r, p, c))
				exit = 1;
			else if (check_and_put_tetri(r, p, c, towrite))
				return (1);
			else
				p[1] = p[1] + 1;
		p[0] = p[0] + 1;
	}
	exit = rm_from_matrice(r, towrite - 1, 0);
	if (put_tetri(r, c, towrite + 'A', begin) &&
			(try_to_place(begin, r, towrite - 1 - 'A', 0)))
		return (1);
	return (0);
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
		result = try_to_place(&list, result, 0, 1);
	}
	index = 0;
	while (result[index])
		ft_putstr(result[index++]);
}
