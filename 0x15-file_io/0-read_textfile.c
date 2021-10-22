#include "main.h"
/**
 * read_textfile - read and print
 * @filename: file name
 * @letters: of letters to print
 * Return: string buffer
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer;
	ssize_t rcount, wcount;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDWR);

	if (fd == -1)
		return (0);
	buffer = malloc(letters);
	if (buffer == NULL)
		return (0);


	rcount = read(fd, buffer, letters);
	if (rcount == -1)
		return (0);
	wcount = write(STDOUT_FILENO, buffer, rcount);

	if (wcount == -1 || rcount != wcount)
		return (0);
	free(buffer);

	close(fd);
	return (wcount);
}
