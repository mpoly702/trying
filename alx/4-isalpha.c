#include "main.h"

/**
 * _isalpha - this program is an afabet checker
 * @c: the input to be checked
 * Return: if character is afabet return 1 otherwise 0.
 */

int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
