#include "monty.h"
/**
 * _isalpha - checks if int is in alphabet
 * @c: int
 * Return: 1 if yes, 0 if no
 */
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}

