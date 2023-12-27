/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:07:51 by luguimar          #+#    #+#             */
/*   Updated: 2023/10/11 16:04:16 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <sys/wait.h>

static void	exec_command(char *path, char **envp, char **args, int isparent)
{
	if (!path || !envp || !args)
	{
		if (isparent)
			wait(NULL);
		dup2(STDERR_FILENO, STDOUT_FILENO);
		if (args)
			ft_printf("%s: command not found\n", args[0]);
		else
			ft_printf("pipex: '' : command not found\n");
		if (path)
			free(path);
		free_array_of_strings(args);
		exit(127);
	}
	execve(path, args, envp);
	if (isparent)
		wait(NULL);
	dup2(STDERR_FILENO, STDOUT_FILENO);
	perror("pipex");
	free(path);
	free_array_of_strings(args);
	exit(1);
}

static void	check_error(int status, char *message, char **args, char *path)
{
	if (status == -1)
	{
		if (args)
			free_array_of_strings(args);
		if (path)
			free(path);
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		perror(message);
		exit(1);
	}
	return ;
}

static char	*get_right_path(char **cmd, char **envp, char *right_path)
{
	int		i;
	char	**path;

	i = 0;
	if (!envp || !cmd)
		return (NULL);
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", 5))
		i++;
	path = ft_split(envp[i] + 5, ':');
	i = -1;
	while (cmd && path[++i] && *cmd[0] != '/')
	{
		right_path = ft_strjoin(path[i], "/");
		right_path = ft_strjoinfree(right_path, *cmd);
		if (access(right_path, F_OK) == 0)
		{
			free_array_of_strings(path);
			return (right_path);
		}
		free(right_path);
	}
	free_array_of_strings(path);
	if (cmd && *cmd[0] == '/' && access(*cmd, F_OK) == 0)
		return (ft_strdup(*cmd));
	return (NULL);
}

static void	redirect_files(int argc, char *argv[], char **envp, char **args)
{
	int		cid;
	int		pipefd[2];
	char	*path;

	path = NULL;
	check_error(pipe(pipefd), "pipe", args, path);
	cid = fork();
	if (cid == 0)
	{
		args = ft_splitquote_nulls(argv[2], ' ');
		path = get_right_path(args, envp, path);
		check_error(access(argv[1], R_OK), argv[1], args, path);
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		exec_command(path, envp, args, 0);
	}
	else if (cid == -1)
		check_error(-1, "fork", args, path);
	else
	{
		check_error(access(argv[argc - 1], W_OK), argv[argc - 1], args, path);
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		waitpid(cid, NULL, WNOHANG);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_in;
	int		fd_out;
	char	*path;
	char	**args;

	if (argc == 5)
	{
		path = NULL;
		args = NULL;
		fd_in = open(argv[1], O_RDONLY);
		fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0664);
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		redirect_files(argc, argv, envp, args);
		args = ft_splitquote_nulls(argv[3], ' ');
		path = get_right_path(args, envp, path);
		exec_command(path, envp, args, 1);
	}
	else
		ft_printf("Wrong number of arguments!\n");
	return (1);
}
