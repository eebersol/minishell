/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 19:36:22 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/19 19:36:23 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_join_path(char *path, char *str)
{
	char *tmp;

	tmp = ft_strjoin(path, "/");
	tmp = ft_strjoin(tmp, str);
	return (tmp);
}
