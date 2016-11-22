/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 18:39:56 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/22 19:22:11 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

t_list	*stock_tetri(char *file_name, size_t *nb_tetri);
void	fillit(t_list *list, size_t nb_tetri);
char	**try_to_place(t_list **begin, char **result, char nb, int l);
char	check_and_put_tetri(char **r, size_t p[2], int c[4][2], char towrite);
char	check_no_overflow(char **r, size_t p[2], int c[4][2]);
int		put_tetri(char **r, int c[4][2], char towrite, t_list **begin);

#endif
