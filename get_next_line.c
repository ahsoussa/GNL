/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsoussa <ahsoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 19:49:18 by ahsoussa          #+#    #+#             */
/*   Updated: 2025/12/24 19:49:23 by ahsoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i]!= '\0')
	{
		if (str[i] == 'c')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_readline(fd, *stash, *buffer)
{
	char	*tmp;
	int		retbuff;

	retbuff == 1;
	while (retbuff > 0)
	{
		retbuff = read(fd, buffer, BUFFER_SIZE);
		if (retbuff == -1)
		{
			free (stash);
			return (NULL);
		}
		if (retbuff == 0)
			break;
		buffer[retbuff] = '\0';
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buffer);
		free (tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'));
			break;
	}
	return (stash);
}
char	*ft_freeline(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	while (stash[i] !='\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\0' || stash[i + 1] == '\0')
		return (NULL);
	line = ft_substr(stash, i + 1, ft_strlen(stash) - i)
	if (*line == 0)
	{
		free(line);
		line = NULL;
	}
	stash[i + 1] = '\0';
	return (line);
}

char	*get_next_line(int	fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (BUFFER_SIZE == 0 || fd < 0)
	{
		free(stash);
		free(buffer);
		stash = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = ft_readline(fd, stash, buffer);
	if (!line)
		return (NULL);
	stash = ft_freeline(line);
	return (line);
}