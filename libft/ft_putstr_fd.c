/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:39:29 by eproust           #+#    #+#             */
/*   Updated: 2024/11/29 01:32:54 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(const char *s, int fd)
{
	while (*s)
		ft_putchar_fd(*s++, fd);
}

/*
#include <stdio.h>

int	open_error()
{
	printf("Open error\n");
	return (1);
}

int	main(void)
{
	char *str = "Hello, World!";
	char *filename = "test.txt";
	char buf[1024];

	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (open_error());
	ft_putstr_fd(str, fd);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (open_error());
	int bytes_read = read(fd, buf, sizeof(buf));
	while (bytes_read > 0)
	{
		write(1, buf, bytes_read);
		bytes_read = read(fd, buf, sizeof(buf));
	}
	close(fd);

	return (0);
}
*/
