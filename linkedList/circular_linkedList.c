/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_linkedList.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:21:01 by ajaidi            #+#    #+#             */
/*   Updated: 2022/03/18 23:05:04 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
	First we need to create  a structure
	Type of next pointer
	→ we know that pointer type mean that this pointer should be point on specific type of data int* ⇒ point on int var float......
	so struct node pointer should point to a struct node
 */
typedef struct s_list{
	struct s_list	*prev;
	int				data;
	struct s_list	*next;
}	t_list;

t_list	*new_node(int data)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	tmp->prev = tmp;
	tmp->data = data;
	tmp->next = tmp;
	return (tmp);
}

void	append_in_end(t_list **root, int data)
{
	t_list	*tmp;
	t_list	*p;

	tmp = new_node(data);
	if (!*root)
		*root = tmp;
	else
	{
		p = (*root)->prev;
		tmp->next = *root;
		(*root)->prev = tmp;
		p->next = tmp;
		tmp->prev = p;
	}
}

/*
	here we check if list is empt 
	if yes we print it if no we print node data and jump to the next node by pointing temp to the next node
*/

void	display_node(t_list *root)
{
	t_list	*temp;

	temp = root;
	if (!root)
		printf("List is empty\n");
	else
	{
		printf("tmp is %d\n", root->data);
		printf("tmp is %d\n", root->prev->data);
		while(temp != root->prev)
		{
			printf("%d\n", temp->data);
 			temp = temp->next;
			usleep(500000);
		}
		//printf("%d\n", temp->data);
	}
}

// here we count how many node can p point before point to null 

int	find_len(t_list *root)
{
	int		c;
	t_list	*p;

	c = 0;
	p = root;
	while (p != root->prev)
	{
		p = p->next;
		c++;
	}
	printf("c = %d\n", c);
	return (++c);
}

/*
	also here we create a node set node→link to null check root if point to a node or not 
	if point to node we point our node to the first node and set root pointer to our node
*/

void	append_start(t_list	**root, int data)
{
	t_list	*tmp;

	tmp = new_node(data);
	if (!*root)
		*root = tmp;
	else
	{
		tmp->prev = (*root)->prev;
		(*root)->prev = tmp;
		tmp->next = *root;
		(*root)->prev->next = tmp;
		*root = tmp;
	}
}

void	append_nth(t_list **top, int data, int nth)
{
	t_list	*node;
	t_list	*tmp;
	int		i;

	node = new_node(data);
	if (!(*top) || nth <= 1)
	{
		append_start(top, data);
		return ;
	}
	if (nth >= find_len(*top))
		return (append_in_end(top, data));
	tmp = *top;
	i = -1;
	while (++i < nth - 2)
		tmp = tmp->next;
	node->next = tmp->next;
	tmp->next->prev = node;
	node->prev = tmp;
	tmp->next = node;
}

void	delete_nth(t_list **root, int n)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		i;

	tmp = *root;
	if (!*root || n == 0)
		return ;
	else if (n == 1)
	{
		*root = tmp->next;
		tmp->next->prev = (*root)->prev;
		(*root)->prev->next = tmp->next;
		return (free(tmp));
	}
	i = -1;
	while (++i < n - 2 && tmp->next)
		tmp = tmp->next;
	tmp1 = tmp->next;
	tmp->next = tmp1->next;
	tmp1->next->prev = tmp;
	free(tmp1);
}

void	reverse_iterate_linkedlist(t_list **root)
{
	t_list	*cur;
	t_list	*next;
	t_list	*prev;

	cur = *root;
	prev = NULL;
	while (cur)
	{
		next = cur->next;
		cur->prev = next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*root = prev;
}

void	display_node_forward_recursion(t_list *root)
{
	if (!root)
		return ;
	else
	{
		printf("%d\n", root->data);
		display_node_forward_recursion(root->next);
	}
}

void	display_node_reversed_recursion(t_list *root)
{
	if (!root)
		return ;
	else
	{
		display_node_reversed_recursion(root->next);
		printf("%d\n", root->data);
	}
}

void	reverse_recursion_linkedlist(t_list **head, t_list *node)
{
	t_list	*tmp;

	if (!node->next)
	{
		node->prev = NULL;
		*head = node;
		return ;
	}
	reverse_recursion_linkedlist(head, node->next);
	tmp = node->next;
	tmp->next = node;
	node->prev = tmp;
	node->next = NULL;
}

int	main(void)
{
	t_list	*a;

	a = NULL;
	// for (int i = 0; i < 10; i++)
	// 	append_in_end(&a, i);
	//  append_in_end(&a, 10);
	append_start(&a, -1);
	append_start(&a, -2);
	// append_start(&a, -2);
	// append_start(&a, -2);
	// append_in_end(&a, 11);
	// append_start(&a, -3);
	// append_in_end(&a, 12);
	//append_nth(&a, 90, 122);
	// append_nth(&a, 91, 122);
	// append_nth(&a, 92, 122);
	//append_nth(&a, 93, 2);
	//delete_nth(&a, 5);
	//reverse_iterate_linkedlist(&a);
	//reverse_recursion_linkedlist(&a, a);
	display_node(a);
	//delete_nth(&a, 4);
	//display_node_reversed_recursion(a);
	//printf("%d\n", find_len(a));
}
