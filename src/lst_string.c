/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:19:48 by david             #+#    #+#             */
/*   Updated: 2025/02/22 22:19:33 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	*lst_new(t_printf *data, const char *ptr);
void		lst_add_back(t_string **head, t_string *node);
void		lst_free(t_string **head);
t_string	*lst_last(t_string *lst);
void		free_mem(t_printf *data);

t_string	*lst_new(t_printf *data, const char *ptr)
{
	t_string	*new;

	new = malloc(sizeof(*new));
	if (!new)
		free_mem(data);
	else
		*new = (t_string){.raw_string = ptr, .accuracy_size = -1};
	return (new);
}

void	lst_add_back(t_string **head, t_string *node)
{
	t_string	*last;

	if (!head)
		return ;
	if (!*head)
		*head = node;
	else
	{
		last = *head;
		while (last->next)
			last = last->next;
		last->next = node;
	}
}

void	lst_free(t_string **head)
{
	t_string	*free_node;

	while (*head)
	{
		free_node = *head;
		*head = (*head)->next;
		if (free_node->alt)
			free(free_node->alt);
		if (free_node->format_string)
			free(free_node->format_string);
		free(free_node);
	}
	*head = NULL;
}

t_string	*lst_last(t_string *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	free_mem(t_printf *data)
{
	lst_free(&data->strings);
	if (data->output)
		free(data->output);
	va_end(data->args);
}
