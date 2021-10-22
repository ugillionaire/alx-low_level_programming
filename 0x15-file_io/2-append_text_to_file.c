#include "main.h"
#include <string.h>
/**
 * append_text_to_file - creates and wrtes
 * @filename: file name
 * @text_content: of letters to print
 * Return: 1 0r -1
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, w;
	int len = strlen(text_content);


	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		w = write(fd, text_content, len);
		if (w == -1)
			return (-1);

	}
	close(fd);
	return (1);
}
