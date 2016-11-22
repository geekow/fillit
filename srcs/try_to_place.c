/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_to_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:22:18 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/22 19:21:58 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	check_and_put_tetri(char **r, size_t p[2], int c[4][2], char towrite)
{
	if (r[p[0] + c[0][0]][p[1] + c[0][1]] == '.' && \
			r[p[0] + c[1][0]][p[1] + c[1][1]] == '.' && \
			r[p[0] + c[2][0]][p[1] + c[2][1]] == '.' && \
			r[p[0] + c[3][0]][p[1] + c[3][1]] == '.')
	{
		r[p[0] + c[0][0]][p[1] + c[0][1]] = towrite;
		r[p[0] + c[1][0]][p[1] + c[1][1]] = towrite;
		r[p[0] + c[2][0]][p[1] + c[2][1]] = towrite;
		r[p[0] + c[3][0]][p[1] + c[3][1]] = towrite;
		return (1);
	}
	else
		return (0);
}

char	check_no_overflow(char **r, size_t p[2], int c[4][2])
{
	if ((!r[p[0] + c[1][0]]) || (!r[p[0] + c[2][0]]) || (!r[p[0] + c[3][0]]))
		return (1);
	else
		return (0);
}

char	**try_to_place(t_list **begin, char **result, char nb, int loop)
{
	int		coord[4][2];
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
	if (put_tetri(result, coord, index + 'A', begin))
		if (loop == 0)
			return (result);
		else
			return (try_to_place(begin, result, index + 1, 1));
	else
		return (NULL);
}
