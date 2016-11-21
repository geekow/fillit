/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:26:50 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/21 18:11:54 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char **try_to_place(t_list *list, char **result)
{
	list = NULL;
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
		result = try_to_place(list, result);
	}
	index = 0;
	while (result[index])
		ft_putstr(result[index++]);
}
