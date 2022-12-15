/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:31:23 by mvicedo           #+#    #+#             */
/*   Updated: 2022/12/14 17:21:03 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_strs(char	**strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	free_data(t_data *data)
{
	if (data->cmd != NULL)
		free_strs(data->cmd);
	if (data->cmd_path != NULL)
		free(data->cmd_path);
}

int	msg_error(char *msg, int code)
{
	perror(msg);
	exit(code);
}
