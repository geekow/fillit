/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_to_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:22:18 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/24 17:01:28 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	check_and_put_tetri(char **r, int p[2], int c[4][2], char towrite)
{
	if ((!r[p[0]]) || (!r[p[0] + c[1][0]]) || (!r[p[0] + c[2][0]]) ||
			(!r[p[0] + c[3][0]]))
		return (0);
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

int		put_tetri(int coord[4][2], char tow, char **result)
{
	int	pos[2];

	pos[0] = 0;
	if (alr_pl(result, tow))
		while (result[pos[0]] && !(pos[1] = 0))
		{
			while (result[pos[0]][pos[1]] != '\n')
				if (result[pos[0]][pos[1]] == tow)
					return (move(pos, tow, result, coord));
				else
					pos[1]++;
			pos[0]++;
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

char	**try_to_place(t_list *list, char to_write, char **result)
{
	int		coord[4][2];

	if (!list)
		return (result);
	ft_memcpy((void*)coord, list->content, (sizeof(int) * 8));
	if (!put_tetri(coord, to_write, result))
		return (NULL);
	if (!try_to_place(list->next, to_write + 1, result))
		return (try_to_place(list, to_write, result));
	else
		return (result);
}
