/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalphanumeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 21:05:22 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/19 21:05:24 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_isalphanumeric(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '_' || str[i] == '/' || str[i] == ':' || str[i] == '-'
			|| str[i] == ',' || ft_isalnum(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
