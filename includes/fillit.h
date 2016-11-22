/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 18:39:56 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/21 16:52:32 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define CHECK_NO_OVERFLOW()	 (!r[p[0] + c[1][0]]) || (!r[p[0] + c[2][0]]) \
					|| (!r[p[0] + c[3][0]])

# define CHECK_SPACE_FOR_TETRI() r[p[0] + c[0][0]][p[1] + c[0][1]] == '.' && \
				r[p[0] + c[1][0]][p[1] + c[1][1]] == '.' && \
				r[p[0] + c[2][0]][p[1] + c[2][1]] == '.' && \
				r[p[0] + c[3][0]][p[1] + c[3][1]] == '.'

# define PUT_TETRI()	r[p[0] + c[0][0]][p[1] + c[0][1]] = towrite; \
			r[p[0] + c[1][0]][p[1] + c[1][1]] = towrite; \
			r[p[0] + c[2][0]][p[1] + c[2][1]] = towrite; \
			r[p[0] + c[3][0]][p[1] + c[3][1]] = towrite; \
			ft_putchar(towrite);

t_list		*stock_tetri(char *file_name, size_t *nb_tetri);
void		fillit(t_list *list, size_t nb_tetri);
static char	**try_to_place(t_list **begin, char **result, char nb, int loop);

#endif
