#include "main.h"
#include <stdio.h>

int read_file_and_execute(int fd)
{
    char ch;
    char* buff = malloc(sizeof(char));
    if(buff == NULL)
    {
        dprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    while(read(fd, &ch, sizeof(char)))
    {
        printf("Char %c\n", ch);
    }

    return (0);
}