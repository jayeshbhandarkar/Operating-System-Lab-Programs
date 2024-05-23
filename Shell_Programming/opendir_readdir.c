// opendir() and readdir()

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char filename[] = "output.txt";
    char buffer[BUFFER_SIZE];
    int fd, nbytes;

    // Open file for writing
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    printf("Enter text to write to file (type 'quit' to stop):\n");

    // Read input from user and write to file
    while (1) {
        fgets(buffer, BUFFER_SIZE, stdin);
        if (strcmp(buffer, "quit\n") == 0)
            break;
        if (write(fd, buffer, strlen(buffer)) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    // Close file
    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    // Open file for reading
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    printf("\nContents of file '%s':\n", filename);

    // Read from file and print to stdout
    while ((nbytes = read(fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buffer, nbytes) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    // Close file
    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    return 0;
}


/* **** Output **** 

Enter text to write to file (type 'quit' to stop):
Hello, How are you
quit

Contents of file 'output.txt':
Hello, How are you

*/