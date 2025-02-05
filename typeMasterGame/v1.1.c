#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define INPUT_LEN 10

int main()
{
    printf ("Please enter a line of text : ");
    // fflush(stdout);
    time_t end = time(0) + 5;  // 5 seconds time limit.

    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

    char answer[INPUT_LEN];
    int pos = 0;
    while(time(0) < end)
    {
        int c = getchar();
        if (c != EOF && c != 10 && pos < INPUT_LEN - 1) answer[pos++] = c;
        if (c == 10) break;
    }

    answer[pos] = '\0';

    if(pos > 0) printf("%s\n", answer);
    else puts("\nSorry, I got tired waiting for your input. Good bye!");
}