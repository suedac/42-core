/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgahrama <zgahrama@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:48:30 by zgahrama          #+#    #+#             */
/*   Updated: 2025/06/09 16:17:01 by zgahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 31
#endif

#include <unistd.h>
#include<stdlib.h>


char *get_next_line(int fd);
char *ft_strchr(const char *s, int c);
char *extract_line(char *leftover);
char *update_leftover(char *leftover);
char *ft_strjoin(char const *s1, char const *s2);

#endif