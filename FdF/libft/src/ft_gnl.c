/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:56:05 by qbanet            #+#    #+#             */
/*   Updated: 2023/06/20 09:11:09 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void ft_list_add_last(t_gnl **save, t_gnl *elem)
{
	t_gnl *list;

	list = *save;
	while (list->next)
		list = list->next;
	list->next = elem;
}

static t_gnl *ft_create_list(int fd)
{
	t_gnl *list;

	list = (t_gnl *)malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->fd = fd;
	list->tempo = ft_calloc(1, sizeof(char *));
	list->next = NULL;
	list->text = NULL;
	return (list);
}

t_gnl *ft_check_fd(t_gnl *save, int fd)
{
	t_gnl *tmp;
	t_gnl *d_list;

	tmp = NULL;
	d_list = save;
	while (d_list)
	{
		if (d_list->fd == fd)
			return (d_list);
		if (!d_list->next)
		{
			tmp = ft_create_list(fd);
			ft_list_add_last(&d_list, tmp);
			return (tmp);
		}
		d_list = d_list->next;
	}
	return (NULL);
}

static int ft_check(char *save, char **line)
{
	char *end;

	if (!save)
		return (0);
	end = ft_strchr(save, '\n');
	if (end)
	{
		*end = 0;
		*line = ft_strdup(save);
		ft_strncpy(save, &end[1], ft_strlen(&end[1]) + 1);
		return (1);
	}
	else if (ft_strlen(save) > 0)
	{
		*line = ft_strdup(save);
		return (1);
	}
	return (0);
}

t_gnl *ft_free_gnl(t_gnl *lst)
{
	t_gnl *next;

	while (lst)
	{
		//		if (lst->text)
		//			free(lst->text);
		free(lst->tempo);
		next = lst->next;
		free(lst);
		lst = next;
	}
	return (NULL);
}

int ft_gnl(int fd, char **line, int n)
{
	char *buf;
	static t_gnl *save = NULL;
	t_gnl *temp;
	int rt;

	if (n)
		save = ft_free_gnl(save);
	if (n)
		return (0);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!save)
		save = ft_create_list(fd);
	if (fd == -1 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	temp = ft_check_fd(save, fd);
	while (!(ft_strchr(temp->tempo, '\n')))
	{
		rt = read(fd, buf, BUFFER_SIZE);
		if (rt == -1)
		{
			free(buf);
			return (-1);
		}
		if (rt == 0)
		{
			free(buf);
			return (ft_check(temp->text, line));
		}
		buf[rt] = '\0';
		temp->text = ft_strjoin(temp->tempo, buf);
		free(temp->tempo);
		temp->tempo = temp->text;
	}
	free(buf);
	return (ft_check(temp->text, line));
}
