#include "get_next_line.h"
#include <string.h>

int main() {
    int fd = open("hello.txt", O_RDONLY);

    char *ptr = (void*)1;
    /* while(ptr)
    {
        ptr = get_next_line(fd);
        printf("%s", ptr);
        free(ptr);
    } */
    printf("%s\n", get_next_line(fd));
    return 0;
}