#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signalHand(int signum)
{
    if (signum == SIGUSR1)
        printf("Se sericibio SIGUSR1. Procedemos a hacer PLAN A");
    else if (signum == SIGUSR2)
        printf("Se sericibio SIGUSR2. Procedemos a hacer PLAN B");
}

int main()
{
    signal(SIGUSR1, signalHand);
    signal(SIGUSR2, signalHand);

    printf("Esperando señales SIGUSR1 y SIGUSR2. PID: %d\n", getpid());

    while(1)
        sleep(1);
    return 0;
}
