/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:06:49 by zmunkhja          #+#    #+#             */
/*   Updated: 2022/06/27 14:28:19 by zmunkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*find_new_line(int fd, char *buf, char *backup)
{
	int	line;
	char	*temp;

	line = 1;
	while (line != '\0')
	{
		line = read(fd, buf, BUFFER_SIZE);
		if (line < 0)
			return (0);
		else if (line == 0)
			break ;
		buf[line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buf);
		free(temp);
		temp = 0;
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (backup);
}

static	char	*extract(char *line)
{
	size_t	i;
	char	*backup;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[i] != '\0')
		return (0);
	backup = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*backup == '\0')
	{
		free(backup);
		backup = 0;
	}
	line[i + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char*) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = find_new_line(fd, buf, backup);
	free(buf);
	buf = 0;
	if (!line)
		return (0);
	backup = extract(line);
	return (line);
}
