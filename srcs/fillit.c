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

static int	put_tetri(char **r,  int c[4][2], char towrite, t_list **begin)
{
	size_t	p[2];
	char	exit;

	p[0] = 0;
	towrite += 'A';
	exit = 0;
	if (already_placed(r, towrite))
		return (1);
	while (r[p[0]] && !exit)
	{
		p[1] = 0;
		while (r[p[0]][p[1]] && !exit)
		{
			if (CHECK_NO_OVERFLOW())
				exit = 1;
			else if (CHECK_SPACE_FOR_TETRI())
			{
				PUT_TETRI()
				return (1);
			}
			else
				p[1] = p[1] + 1;
		}
		p[0] = p[0] + 1;
	}
	exit = rm_from_matrice(r, towrite - 1, 0);
	if (put_tetri(r, c, towrite, begin))
	{
		if (try_to_place(begin, r, towrite - 1 - 'A', 0))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

char	**try_to_place(t_list **begin, char **result, char nb, int loop)
{
	int	coord[4][2];
	char	index;
	t_list	*list;
	
	index = 0;
	list = *begin;
	while (list && index < nb)
	{
		list = list->next;
		index++;
	}
	if (!list)
		return (result);
	ft_memcpy((void*)coord, list->content, (sizeof(int) * 8));
	if (put_tetri(result, coord, index, begin))
		if (loop == 0)
			return (result);
		else
			return (try_to_place(begin, result, index + 1, 1));
	else
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
		result = try_to_place(&list, result, 0, 1);
	}
	index = 0;
	while (result[index])
		ft_putstr(result[index++]);
}
