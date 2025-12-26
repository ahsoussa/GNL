/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsoussa <ahsoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 19:49:18 by ahsoussa          #+#    #+#             */
/*   Updated: 2025/12/26 20:30:20 by ahsoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readline(int fd, char *stash, char *buffer)
{
	char		*tmp;
	ssize_t		retbuff;

	retbuff = 1;
	while (retbuff > 0)
	{
		retbuff = read(fd, buffer, BUFFER_SIZE);
		if (retbuff == -1)
		{
			free (stash);
			return (NULL);
		}
		if (retbuff == 0)
			break ;
		buffer[retbuff] = '\0';
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buffer);
		free (tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

char	*ft_freeline(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\0' || stash[i + 1] == '\0')
		return (NULL);
	line = ft_substr(stash, i + 1, ft_strlen(stash) - i);
	if (*line == 0)
	{
		free(line);
		line = NULL;
	}
	stash[i + 1] = '\0';
	return (line);
}

char	*get_next_line(int fd)
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

// int main(int argc, char **argv)
// {
//     int   fd;
//     char  *line;

//     if (argc != 2)
//     {
//         printf("Usage: %s <filename>\n", argv[0]);
//         return (1);
//     }

//     fd = open(argv[1], O_RDONLY);
//     if (fd < 0)
//     {
//         perror("Error opening file");
//         return (1);
//     }

//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);  // line contient déjà le '\n' si présent
//         free(line);
//     }

//     close(fd);
//     return (0);
// }