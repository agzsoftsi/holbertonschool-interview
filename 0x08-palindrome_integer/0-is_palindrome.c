#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * is_palindrome - Function to check palindromes
 * @n: Number to be checked
 * Return: integer 1 or 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long num, valr = 0;

	num = n;

	while (num != 0)
	{
		valr = valr * 10;
		valr = valr + num % 10;
		num = num / 10;
	}
	if (n == valr)
		return (1);
	else
		return (0);
}
