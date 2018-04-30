/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2018/05/01 09:49:59 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*void        destroylinks(t_antfarm *farm)
{

}

void        destroyrooms(t_antfarm *farm)
{
}*/

void		destroyapath(t_path **allpaths)
{
	t_path	*head;

	head = poppath(allpaths);
	head->roomsinpath = (char**)ft_clear_2d((void**)head->roomsinpath);
	free(head);
}

/*void        destroyants(t_antfarm *farm)
{

}

void        destroyfarm(t_antfarm *farm)
{

}*/
