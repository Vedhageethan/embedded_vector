#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    int rando = (rand() % 200) + 1;
    int gs,atp;
    atp = 0;
    printf("Guess the no btw 1 to 200\n");
    while(1)
    {
        atp+=1;
        printf("Enter the guess:");
        scanf("%d",&gs);
        if(rando<gs)
        {
            printf("too high\n");
        }  
        else if(rando>gs)
        {
            printf("too low\n");
        }
        else
        {
            printf("Correct Guess!\n");
            printf("attempts:%d",atp);
            break;
        }
    }
    return 0;
}