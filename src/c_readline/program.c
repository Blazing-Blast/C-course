#include <stdio.h>

char* readline() {
    char *line = NULL;
    size_t length;

    getline(&line, &length, stdin);

    return line;
}

int main() {
    printf("Your input: ");
    char* input = readline();
    printf("You said: %s", input);
    return 0;
}