/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:23:20 by mvicedo           #+#    #+#             */
/*   Updated: 2022/12/15 15:10:47 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	access_error(t_data *data)
{
	if (access(data->argv[1], F_OK) == -1)
	{
		perror(ERR_OPEN_IN);
		free_strs(data->paths);
		close(data->pipefd[0]);
		close(data->pipefd[1]);
		exit(126);
	}
	else if (access(data->argv[1], X_OK) == -1)
	{
		perror(ERR_ACCESS_IN);
		free_strs(data->paths);
		close(data->pipefd[0]);
		close(data->pipefd[1]);
		exit(1);
	}
}

void	access_error_2(t_data *data)
{
	if (access(data->argv[4], F_OK) == -1)
	{
		perror(ERR_OPEN_OUT);
		free_strs(data->paths);
		close(data->pipefd[0]);
		close(data->pipefd[1]);
		exit(126);
	}
	else if (access(data->argv[4], X_OK) == -1)
	{
		perror(ERR_ACCESS_OUT);
		free_strs(data->paths);
		close(data->pipefd[0]);
		close(data->pipefd[1]);
		exit(1);
	}
}
