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

static int	rm_from_matrice(char **result, char to_rm, int tmp)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_rm >= 'A')
	{
		while (result[i])
		{
			j = 0;
			while (result[i][j++])
				if (result[i][j - 1] == to_rm)
				{
					result[i][j - 1] = '.';
					tmp = 1;
				}
			i++;
		}
		if (tmp == 0)
			return (rm_from_matrice(result, to_rm - 1, 0));
		else
			return (to_rm - 'A');
	}
	return (0);
}

static int	put_tetri(char **r,  int c[4][2], char towrite)
{
	size_t	p[2];

				size_t	i;
				
				i = 0;
				while (r[i])
					ft_putstr(r[i++]);				
				ft_putchar('\n');
	p[0] = 0;
	towrite += 'A';
	rm_from_matrice(r, towrite, 1);
	while (r[p[0]])
	{
		p[1] = 0;
		while (r[p[0]][p[1]])
		{
			if ((!r[p[0] + c[1][0]]) || (!r[p[0] + c[2][0]]) ||
				(!r[p[0] + c[3][0]]))
				return (0);
			else if (r[p[0] + c[0][0]][p[1] + c[0][1]] == '.' &&
	r[p[0] + c[1][0]][p[1] + c[1][1]] == '.' && r[p[0] + c[2][0]]
	[p[1] + c[2][1]] == '.' && r[p[0] + c[3][0]][p[1] + c[3][1]] == '.')
			{
				r[p[0] + c[0][0]]
					[p[1] + c[0][1]] = towrite;
				r[p[0] + c[1][0]]
					[p[1] + c[1][1]] = towrite;
				r[p[0] + c[2][0]]
					[p[1] + c[2][1]] = towrite;
				r[p[0] + c[3][0]]
					[p[1] + c[3][1]] = towrite;
				i = 0;
				while (r[i])
					ft_putstr(r[i++]);				
				ft_putchar('\n');
				return (1);
			}
			else
				p[1] = p[1] + 1;
		}
		p[0] = p[0] + 1;
	}
	return (0);
}

static char	**try_to_place(t_list **begin, char **result, char index)
{
	int		coord[4][2];
	t_list	*list;
	int	i;

	list = *begin;
	i = 0;
	while (i++ < index && list)
		list = list->next;
	if (!list)
		return (result);
	ft_memcpy((void*)coord, list->content, (sizeof(int) * 8));
	if (put_tetri(result, coord, index))
		return (try_to_place(begin, result, (index + 1)));
	i = rm_from_matrice(result, ('A' + index - 1), 0);
	if (i)
	{
		if (put_tetri(result, coord, index))
			return (try_to_place(begin, result, i));
		else
			return (try_to_place(begin, try_to_place(begin, result, index), index));
	}
	else
		return (try_to_place(begin, result, index));
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
	if (!result) /** replace with while **/
	{
		result = calc_tab(nb_tetri, index++);
		result = try_to_place(&list, result, 0);
	}
	index = 0;
	while (result[index])
		ft_putstr(result[index++]);
}
