/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 23:01:01 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/05 17:39:38 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	i2;

	if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	if (s1 != NULL && s2 == NULL)
		return (ft_strdup(s1));
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	result = (char*)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	i2 = 0;
	while (s2[i2] != '\0')
		result[i++] = s2[i2++];
	result[i] = '\0';
	return (result);
}
