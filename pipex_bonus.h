/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:22:52 by luguimar          #+#    #+#             */
/*   Updated: 2023/10/14 16:45:19 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>

void	dup2stdout(int *pipefd);
void	dup2stdin(int *pipefd);
void	dup2redirect(int *fd, char **argv, char **envp, int i);
void	redirect_files(int i, char *argv[], char **envp);
void	heredoc(char *limiter);
char	*get_right_path(char **cmd, char **envp, char *right_path);
char	**last_one(char **argv, char **path, char **envp, int i);
void	check_error(int status, char *message, char **args, char *path);

#endif
