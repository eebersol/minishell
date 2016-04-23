/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 19:36:49 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/19 19:36:50 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		ft_lstlen(t_list *list)
{
	int		i;
	t_env	*env;

	i = 0;
	while (list)
	{
		env = list->content;
		i++;
		list = list->next;
	}
	return (i);
}
