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

t_list	*stock_tetri(char *file_name, size_t *nb_tetri);
void	fillit(t_list *list, size_t nb_tetri);

#endif
