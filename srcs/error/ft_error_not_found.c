/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_not_found.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:33:15 by eebersol          #+#    #+#             */
/*   Updated: 2016/04/25 16:33:16 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_error_not_found(char *varname)
{
	ft_putstr_fd(varname, 2);
	ft_putendl_fd(": command not found", 2);
}
