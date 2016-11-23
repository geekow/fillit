/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 18:39:56 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/23 20:40:13 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

t_list	*stock_tetri(char *file_name, size_t *nb_tetri);
void	fillit(t_list *list, size_t nb_tetri);
char	**try_to_place(t_list *list, char to_write, char **result);
char	check_and_put_tetri(char **r, int p[2], int c[4][2], char towrite);
int		put_tetri(int coord[4][2], char towrite, char **result);
int		alr_pl(char **r, char to_find);
int		move(int pos[2], char tow, char **result, int coord[4][2]);

#endif
