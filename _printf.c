#include "main.h"

/**
 * _printf - function that produces output according to format
 * @format: it's the format
 *
 * Return: number of character printed. Exclude \0
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int count = 0;

	const char *ptr = format;

	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			ptr++;
			switch (*ptr)
			{
				case 'c':
					count += putchar(va_args(args, int));
					break;
				case 's':
					count += printf("%s", va_arg(args, char *));
					break;
				case '%':
					count += putchar('%');
					break;
				default:
					putchar('%');
					count++;
					break;
			}
		}
		else
		{
			putchar(*ptr);
			count++;
		}
		ptr++;
	}
	va_end(args);

	return (count);
}

/**
 * main - main header
 *
 * Return: 0.
 */
int main(void)
{
	int num = 42;
	char *str = "Hello";

	int printed = _printed("Number: %d, and String: %s%%\n, num, str");

	printf("Number of characters printed: %d\n", printed);

	return (0);
}
