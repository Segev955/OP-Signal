#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void sig_handler(int signum) {
    int i = 5;
    int j = 0;
    int k;
    switch (signum) {
        case SIGCHLD:
            printf("I am in SIGCHLD\n");
            fflush(stdout);
            kill(getpid(), SIGUSR1);
            break;
        case SIGUSR1:
            printf("I am in SIGUSR1\n");
            fflush(stdout);
            k = i / j;
            printf("lalala\n");
            fflush(stdout);
            break;
        case SIGFPE:
            printf("I am in SIGFPE\n");
            fflush(stdout);
            exit(1);
        case SIGTSTP:
            printf("\nI am in SIGTSTP\n");
            printf("Allow pause for SIGCONT\n");
            printf("write 'fg' to continue\n");
//            break;
            raise(SIGSTOP);
        case SIGCONT:
            printf("I am in SIGCONT\n");
            printf("input num: ");
            fflush(stdout);
    }
}

int main() {
    int status;
    signal(SIGCHLD, sig_handler);
    signal(SIGUSR1, sig_handler);
    signal(SIGFPE, sig_handler);
    signal(SIGTSTP, sig_handler);
//    signal(SIGCONT, sig_handler);

    int x;
    printf("input num: (ctrl+z to pause)");
    scanf("%d", &x);
    printf("number: %d\n", x);
    if (!(fork())) {
        exit(1);
    }

    wait(&status);


}
