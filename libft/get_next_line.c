/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 03:35:51 by luguimar          #+#    #+#             */
/*   Updated: 2023/08/08 23:11:15 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*clean_stash(char *stash)
{
	int	end;
	int	stash_len;
	int	i;

	end = ft_strchrnum(stash, '\n');
	if (end == -1)
	{
		free(stash);
		return (NULL);
	}
	stash_len = ft_strchrnum(stash, '\0');
	i = 0;
	while (i < stash_len - end)
	{
		stash[i] = stash[end + 1 + i];
		i++;
	}
	stash[i] = '\0';
	return (stash);
}

static char	*get_line(char *stash)
{
	char	*line;
	int		end;
	int		i;

	if (ft_strchrnum(stash, '\n') == -1)
		end = ft_strchrnum(stash, '\0');
	else
		end = ft_strchrnum(stash, '\n') + 1;
	line = malloc(sizeof(char) * (end + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < end)
	{
		line[i] = stash[i];
		i++;
	}
	line[end] = '\0';
	if (ft_strchrnum(line, '\0') == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*get_stash(int fd, char *stash)
{
	char	*temp;
	int		bytes;

	bytes = 1;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temp == NULL)
		return (NULL);
	while (bytes > 0 && ft_strchrnum(stash, '\n') == -1 && stash != NULL)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(temp);
			free(stash);
			return (NULL);
		}
		temp[bytes] = '\0';
		stash = ft_strjoinfree(stash, temp);
	}
	free(temp);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	if (stash[fd] == NULL)
	{
		stash[fd] = malloc(sizeof(char) * 1);
		if (stash[fd] == NULL)
			return (NULL);
		stash[fd][0] = '\0';
	}
	stash[fd] = get_stash(fd, stash[fd]);
	if (stash[fd] == NULL)
		return (NULL);
	line = get_line(stash[fd]);
	stash[fd] = clean_stash(stash[fd]);
	return (line);
}
