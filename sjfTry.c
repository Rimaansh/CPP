#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdlib.h>

void main()
{
    int max = 30;
    int i, j, n, temp;
    printf("Enter the number of processes - \n");
    scanf("%d", &n);
    int p[max], bt[max], wt[max], tat[max];
    float awt = 0.0f, atat = 0.0f;
    printf("Enter the process no. and burst time - \n");
    for(i = 0; i<n; i++){
        scanf("%d %d", &p[i], &bt[i]);
    }

    for(i = 0; i<n; i++)
    {
        for(j = 0; j<n-i-1; j++)
        {
            if(bt[j]>bt[j+1]){
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
                //now swapping process numbers
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    printf("ProcessNo. \tBurstTime \tWaitingTime \t TurnaroundTime\t\n");
    for(i = 0; i<n; i++)
    {
          wt[i] = tat[i] = 0;
          for(j = 0; j<i; j++) wt[i] += bt[j]; 
          tat[i] = wt[i] + bt[i];
          awt += wt[i];
          atat  += tat[i];
          printf("%d\t\t  %d\t\t  %d\t\t %d\t\t\n", p[i], bt[i], wt[i], tat[i]);
    }

    awt/=n;
    atat/=n;

    printf("\nAverage Waiting Time - %fs",awt);
    printf("\nAverage Turnaround Time - %fs",atat);
}
