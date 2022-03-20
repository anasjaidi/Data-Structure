/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:07:56 by ajaidi            #+#    #+#             */
/*   Updated: 2022/03/20 16:20:28 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define SIZE 1000
int top = -1;
int tab[1000];

void    push(int x)
{
    tab[++top] = x;
}

void    pop()
{
    if (top != -1)
        top--;
}

int the_top()
{
    return (tab[top]);
}
int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int main()
{
    for (size_t i = 0; i < 100; i++)
    {
        push(i);
    }
    for (size_t i = 0; i < 100; i++)
    {
        printf("%d\n", the_top());
        pop();
    }
    // pop();
    // pop();
    // pop();
    // pop();
    // pop();
    // pop();
    // pop();
    printf("empty %d\n", top);
    
}