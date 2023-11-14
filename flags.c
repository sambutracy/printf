#include "main.h"

/**
 * get_flags - to calculate the active flags
 * @format: Formatted string to print arguments
 * @i: value for a parameter.
 * Return: Flags
 */

int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, flam_i;
	int flag_ = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (flam_i = *i + 1; format[flam_i] != '\0'; flam_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[flam_i] == FLAGS_CH[j])
			{
				flag_ |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = flam_i - 1;

	return (flag_);
}
