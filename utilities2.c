#include "holberton.h"

/**
 * _strdup - _strdup
 * @s: string to dup
 * Return: dupped string
 */
char *_strdup(char *s)
{
	int i;
	char *tmp;

	tmp = malloc(sizeof(char) * (_strlen(s) + 1));
	if (tmp == NULL)
		return (0);
	for (i = 0; s[i]; i++)
		tmp[i] = s[i];
	tmp[i] = '\0';
	return (tmp);
}
/**
<<<<<<< HEAD
 * _itoa - convert integer to string
 *
 * @num : interger to converted
 * @str: string to converted
 *
 * Return: new string containing the integer num
 */
char *_itoa(int num, char *str)
{
	int i = 0;
	int rem = 0;
	int begin = 0;
	char *r = NULL;
	int end = 0;

	if (num == 0)
	{
		str[i] = '0';
		str[i + 1] = '\0';
		return (str);
	}
	while (num)
	{
		rem = num % 10;
		if (rem >= 10)
			str[i] = ('a' + (rem - 10));
		else
			str[i] = ('0' + rem);
		num = num / 10;
		i++;
	}
	i++;
	str[i] = '\0';
	r = malloc(sizeof(char) * (i));
	i--;
	end = i - 1;
	for (begin = 0; begin < i; begin++)
	{
		r[begin] = str[end];
		end--;
	}
	r[begin] = '\0';
	return (r);
}
/*
 *_mconcat - concatain source with destination
 * @src: source
 * @dest: destination
 * Return: resultat
 */

char *_mconcat(char *src, char *dest)
{
	int i;
	int j;
	char *res;

	res = malloc(sizeof(char) * (_strlen(src) + _strlen(dest) + 1));
	if (res == NULL)
		return (0);
	for (i = 0; src[i]; i++)
		res[i] = src[i];
	for (j = 0; dest[j]; j++)
	{   
		res[i] = dest[j];
		i++;
	}   
	res[i] = '\0';
	return (res);
}
