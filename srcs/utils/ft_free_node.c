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
	printf("BEFORE FREE %s ----- %s\n", env->value, env->var);
	if (!content)
		return ;
	if (env->var)
	{
		printf("FREE VAR - > %s\n", env->var);
		free(env->var);
		printf("2FREE VAR - > %s\n", env->var);
	}
	if (env->value)
	{
		printf("3FREE VAR - > %s\n", env->var);
		printf("FREE VALUE - > %s\n", env->value);
		free(env->value);
		printf("2FREE VALUE - > %s\n", env->value);
	}
	printf("AFTER FREE %s ----- %s\n", env->value, env->var);
	/*free(content);*/
	free(env);
}
