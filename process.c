/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:23:33 by mvicedo           #+#    #+#             */
/*   Updated: 2022/12/14 17:17:18 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(t_data *data)
{
	if (data->cmd[0])
	{	
		data->cmd_path = get_cmd_path(data->paths, data->cmd[0]);
		if (data->cmd_path)
			execve(data->cmd_path, data->cmd, data->envp);
		else
		{
			perror(ERR_CMD);
			free_data(data);
		}
	}
	else
	{
		free_data(data);
		free_strs(data->paths);
		msg_error(ERR_CMD, 127);
	}
}

void	first_child(t_data *data)
{
	data->infile = open(data->argv[1], O_RDONLY);
	if (data->infile < 0)
		access_error(data);
	dup2(data->infile, STDIN_FILENO);
	dup2(data->pipefd[1], STDOUT_FILENO);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	close(data->infile);
	data->cmd = ft_split(data->argv[2], ' ');
	execute_cmd(data);
}

void	second_child(t_data *data)
{
	data->outfile = open(data->argv[4], O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (data->outfile < 0)
		access_error_2(data);
	dup2(data->outfile, STDOUT_FILENO);
	dup2(data->pipefd[0], STDIN_FILENO);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	close(data->outfile);
	data->cmd = ft_split(data->argv[3], ' ');
	execute_cmd(data);
}
