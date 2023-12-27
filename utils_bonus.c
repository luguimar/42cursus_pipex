/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:18:14 by luguimar          #+#    #+#             */
/*   Updated: 2023/10/14 17:25:52 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	dup2stdout(int *pipefd)
{
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
}

void	dup2stdin(int *pipefd)
{
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
}

void	dup2redirect(int *fd, char **argv, char **envp, int i)
{
	fd[0] = open(argv[1], O_RDONLY);
	if (i != 3)
		fd[1] = open(argv[ft_matrixlen((void **)argv) - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0664);
	else
		fd[1] = open(argv[ft_matrixlen((void **)argv) - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0664);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	if (i == 3)
		redirect_files(-3, argv, envp);
	else
		redirect_files(i, argv, envp);
}

void	heredoc(char *limiter)
{
	int		heredoc_fd;
	char	*line;

	heredoc_fd = open("here_doc", O_RDWR | O_TRUNC | O_CREAT, 0664);
	ft_printf("> ");
	line = get_next_line(0);
	while (line && ft_strncmp(line, limiter, ft_strlen(limiter)))
	{
		ft_putstr_fd(line, heredoc_fd);
		free(line);
		ft_printf("> ");
		line = get_next_line(0);
	}
	free(line);
	close (heredoc_fd);
}

char	**last_one(char **argv, char **path, char **envp, int i)
{
	char	**args;
	int		argc;

	argc = ft_matrixlen((void **)argv);
	args = ft_splitquote_nulls(argv[i], ' ');
	*path = get_right_path(args, envp, *path);
	check_error(access(argv[argc - 1], W_OK), argv[argc - 1], args, *path);
	return (args);
}
