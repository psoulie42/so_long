/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:05:57 by psoulie           #+#    #+#             */
/*   Updated: 2025/01/18 15:22:18 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*ft_strstr(const char *hst, const char *ndl)
{
	size_t	i;
	size_t	j;

	if (ndl[0] == 0)
		return ((char *)hst);
	i = 0;
	while (hst[i])
	{
		j = 0;
		if (hst[i] == ndl[j])
		{
			while (hst[i + j] && ndl[j] && hst[i + j] == ndl[j] && i)
				j++;
			if (!ndl[j])
				return ((char *)&hst[i]);
		}
		i++;
	}
	return (NULL);
}

/* int main()
{
	char ndl[] = "ow";
	char hst[] = "powerbomb";
	printf("%s\n", ft_strnstr(hst, ndl, 15));
} */