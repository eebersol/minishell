/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 19:36:13 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/19 19:36:14 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_free_node(void *content, size_t size)
{
	t_env	*env;

	(void)size;
	env = content;
	if (!content)
		return ;
	if (env->var)
		ft_strdel(&(env->var));
	if (env->value)
		ft_strdel(&(env->value));
	free(env);
}
