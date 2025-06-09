/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgahrama <zgahrama@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:02:35 by zgahrama          #+#    #+#             */
/*   Updated: 2025/06/09 16:03:13 by zgahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (unsigned char)c)
            return (char *)s;
        s++;
    }
    if ((unsigned char)c == 0)
        return (char *)s;
    return 0;
}

size_t ft_strlen(const char *str)
{
    size_t i = 0;
    if(str == 0)
        return 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t lenS1 = ft_strlen(s1);
    size_t lenS2 = ft_strlen(s2);
    char *concatenated = malloc(lenS1 + lenS2 + 1);

    if (!concatenated)
        return 0;
    size_t i = 0;
    size_t j = 0;
    while(lenS1 > 0)
    {       
        concatenated[i] = s1[i];        
        lenS1--;
        i++;
    }
    while(lenS2 > 0)
    {
        concatenated[i] = s2[j];        
        lenS2--;
        i++;
        j++;
    }
    concatenated[i] = '\0';
    return concatenated;
}

char *extract_line(char *leftover)
{
    int i;
    int len;
    len = 0;
    
    while(leftover[len] != '\n' && leftover[len] != '\0')
    {
        len++;
    }
    char *line = malloc(len + (leftover[len] == '\n' ? 2 : 1));
    if(!line)
        return 0;
    i = 0;
    while(leftover[i] != '\n' && leftover[i] != '\0')
    {   
        line[i] = leftover[i];
        i++;
    }
    if(leftover[i] == '\n')
        line[i] = '\n';
    line[++i] = '\0';
    return line;
}
char *update_leftover(char *leftover)
{   
    int len = 0;
    char *new_leftover;
    int i = 0;

    while (leftover[len] != '\n' && leftover[len] != '\0')
        len++;
    if (leftover[len] == '\0') {
        free(leftover);
        return NULL;
    }
    new_leftover = malloc(ft_strlen(leftover + len + 1) + 1);
    if (!new_leftover) {
        free(leftover);
        return NULL;
    }
    len++;
    while (leftover[len]) {
        new_leftover[i++] = leftover[len++];
    }
    new_leftover[i] = '\0';

    free(leftover);
    return new_leftover;
}