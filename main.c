/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:15:17 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/11/20 15:49:11 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize && src)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

int count_word(char *str, char c)
{
    int i;
    int on_off;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        if(str[i]  != c && on_off == 0)
        {
            count++;
            on_off = 1;
        }
        else if (str[i]  == c && on_off == 1)
            on_off = 0;
        i++;
    }
    return (count);
}

char    *ft_clean_arr(char **arr, int size)
{
    int i;

    i = 0;
    while (arr && i < size)
    {
        arr[i] = NULL;
        free(arr[i]);
    }
    arr = NULL;
    free(arr);
    return (NULL);
}
char *ft_safe_alloc(char **arr, int len, int arr_idx)
{
    char *new_str;
    int i;

    i = 0;
    if (arr_idx == 3)
    {
        printf("simultion d'une erreur\n");
        new_str = NULL;
    }
    else 
        new_str = malloc(sizeof(char) * len + 1);
    
    if(!new_str)
        return (ft_clean_arr(arr, arr_idx));
    return (new_str);
}
int index_off(char *str, char c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if( str[i] == c)
            return (i);
        i++;
    }
    return (-1);
}
//*****aaaa*****aaa*****aaaa****/
char **splitus(char *s, char c)
{
    int count;
    char **arr;
    int i;
    int len;
    int arr_idx;

    if (!s)
        return (NULL);
    i = 0;
    arr_idx = 0;
    count = count_word(s,c);
    arr = malloc(sizeof(char *) * (count + 1));

    if (!arr)
        return (NULL);
    while (s[i] != '\0')
    {
        while (s[i] && s[i] == c)
            i++;
        len = 0;
        while (s[i] && s[i] != c)
        {
            len++;
            i++;
        }
        if (len > 0)
        {
            char *new = ft_safe_alloc(arr,  len, arr_idx);
            if(!new)
                return (NULL);
            ft_strlcpy(new, &s[i -len], len);
            arr_idx++;
            printf("voici la new string %s\n", new);
        }
    }
    arr[arr_idx] = NULL;
    return (arr);
}
char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s1);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, len + 1);
	return (ptr);
}


int main()
{
    
    char *str = "aaa***xxx***ccc***qs****";
    char **s = splitus(str, '*');

    while (s && *s)
    {
        printf("voici la string %s\n", *s);
        s++;
    }
    
    char **arr2;
    arr2= malloc(sizeof(char *) * 4);

    arr2[0] = ft_strdup("hello");
    arr2[1] = ft_strdup("world");
    arr2[2] = ft_strdup("de merde");
    arr2[3] = NULL;

    int i;

    i = 0;
    while (arr2[i])
    {

        printf("voici l'adresse avant nettoyage %p et la string %s \n", arr2[i], arr2[i]);
        arr2[i] = NULL;
        free(arr2[i]);
        printf("voici l'adresse avant nettoyage %p et la string %s \n", arr2[i], arr2[i]);
        i++;
    }
    arr2 = NULL;
    free(arr2);
    printf("voici arr[0] %p\n ", arr2);
}