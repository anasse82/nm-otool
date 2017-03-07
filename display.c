/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 19:08:06 by ael-hana          #+#    #+#             */
/*   Updated: 2017/03/06 21:12:04 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void		display_list(t_nm *ptr)
{
	while (ptr)
	{
		if (ptr->type == '*')
			(void)ptr;
		else if (ptr->type != 'U')
		{
			if (ptr->hex > 0)
				ft_printf("%016llx %c %s\n", ptr->hex, ptr->type, ptr->name);
			else
				ft_printf("%015x %c %s\n", ptr->hex, ptr->type, ptr->name);
		}
		else
			ft_printf("%s %c %s\n", "                ", ptr->type, ptr->name);
		ptr = ptr->next;
	}
}

int			reverse_int(int x)
{
	x = ((x << 8) & 0xFF00FF00) | ((x >> 8) & 0xFF00FF);
	return (x << 16) | (x >> 16);
}

void		ft_printname(char *str, char *str2)
{
	ft_putstr("\n");
	ft_putstr(str);
	ft_putstr("(");
	ft_putstr(str2);
	ft_putstr("):\n");
}

void		ft_putnbr_base(unsigned long long int num, int base)
{
	char	*str;

	str = "0123456789abcdef";
	if (num / base)
		ft_putnbr_base(num / base, base);
	write(1, str + (num % base), 1);
}
