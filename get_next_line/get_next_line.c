/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgahrama <zgahrama@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:48:13 by zgahrama          #+#    #+#             */
/*   Updated: 2025/06/09 16:11:25 by zgahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *leftover = 0;
    char *buffer;
    char *line;
    int bytes_read;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return 0;
    if (!leftover)
    {
        leftover = malloc(1);
        if (!leftover)
        {
            free(buffer);
            return 0;
        }
    leftover[0] = '\0';
    }
    while(!ft_strchr(leftover, '\n') && (bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        leftover = ft_strjoin(leftover, buffer);
    }
    free(buffer);
    if(!leftover || leftover[0] == '\0')
        return 0;
    line = extract_line(leftover);
    leftover = update_leftover(leftover);
    return line;
}
