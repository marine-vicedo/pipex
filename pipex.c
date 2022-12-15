/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:43:49 by mvicedo           #+#    #+#             */
/*   Updated: 2022/12/14 16:08:26 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_data *data)
{
	data->paths = get_paths(data->envp);
	data->pid1 = fork();
	if (data->pid1 < 0)
		msg_error(ERR_FORK, 1);
	if (data->pid1 == 0)
		first_child(data);
	data->pid2 = fork();
	if (data->pid2 < 0)
		msg_error(ERR_FORK, 1);
	if (data->pid2 == 0)
		second_child(data);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	waitpid(data->pid1, NULL, 0);
	waitpid(data->pid2, NULL, 0);
	free_strs(data->paths);
}

void	init_data(t_data *data, int argc, char **argv, char **envp)
{
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	data->infile = -1;
	data->outfile = -1;
	data->cmd_path = NULL;
	data->cmd = NULL;
	data->paths = NULL;
	data->pid1 = -1;
	data->pid2 = -1;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 5)
		msg_error(ERR_ARGS, 1);
	if (!*envp || !envp[0][0])
		msg_error(ERR_ENV, 127);
	init_data(&data, argc, argv, envp);
	if (pipe(data.pipefd) < 0)
		msg_error(ERR_PIPE, 1);
	pipex(&data);
}
