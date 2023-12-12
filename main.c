#include "main.h"

int main(int argc, char **argv)
{
    int fd;

    if (argc < 2)
    {
        dprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    read_file_and_execute(fd);

    close(fd);
    return (0);
}