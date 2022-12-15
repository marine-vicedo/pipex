/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:35:40 by mvicedo           #+#    #+#             */
/*   Updated: 2022/12/14 17:19:55 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>//perror
# include <unistd.h>//write, acess, dup2..
# include <stdlib.h>//malloc, free, exit
# include <sys/types.h>//write, acess, dup2..
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>//open

# define ERR_ARGS "Error : must be executed as ./pipex file1 cmd1 cmd2 file2"
# define NO_ARG "Argument invalid"
# define ERR_OPEN_IN "Infile error"
# define ERR_ACCESS_IN "Infile"
# define ERR_OPEN_OUT "Outfile error"
# define ERR_ACCESS_OUT "Outfile"
# define ERR_PIPE "Pipe error"
# define ERR_FORK "Fork error"
# define ERR_DUP1 "child1 Dup2 error"
# define ERR_DUP2 "child2 Dup2 error"
# define ERR_CMD "Command error"
# define ERR_ENV "No environnement"

typedef struct s_data
{
	int		argc;
	char	**argv;
	char	**envp;
	int		infile;
	int		outfile;
	int		pipefd[2];
	char	*cmd_path;
	char	**paths;
	char	**cmd;
	pid_t	pid1;
	pid_t	pid2;
}	t_data;

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char sep);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putendl_fd(char *s, int fd);
void	open_files(t_data *data);
void	access_error(t_data *data);
void	access_error_2(t_data *data);

void	pipex(t_data *data);
void	first_child(t_data *data);
void	second_child(t_data *data);
void	parent_process(t_data *data);

char	*get_cmd_path(char **paths, char *cmd);
char	**get_paths(char **envp);
void	free_strs(char	**strs);
void	child_close_fds(t_data *data);
void	free_data(t_data *data);
int		msg_error(char *msg, int code);

#endif
