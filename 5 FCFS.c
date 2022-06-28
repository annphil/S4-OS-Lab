#include<stdio.h>
#include<stdlib.h>

struct fcfs{
int pid;
int btime;
int ttime;
int wtime;
} p[10];

void main(){
  int totttime = 0, totwtime = 0;
  int n, i;
  printf("FCFS\n");
  printf("Enter number of processes: ");
  scanf("%d", &n);
  for(i=0; i<n; i++){
    p[i].pid = 1;
    printf("Enter burst time of process %d: ", i+1);
    scanf("%d", &p[i].btime);
  }


  p[0].wtime = 0;
  p[0].ttime = p[0].btime;
  totttime += p[0].ttime;

  for(i=1; i<n; i++){
    p[i].wtime = p[i-1].wtime + p[i-1].btime;
    p[i].ttime = p[i].wtime + p[i].btime;
    totttime += p[i].ttime;
    totwtime += p[i].wtime;
  }

  for(i=0; i<n; i++){
    printf("\nWaiting time for process %d is: %d", i+1, p[i].wtime);
    printf("\nTurn around time for process %d is: %d\n", i+1, p[i].ttime);
  }

  printf("\nTotal waiting time is: %d", totwtime);
  printf("\nAverage waiting time is: %f", (float)totwtime/n);
  printf("\nTotal turn around time is: %d", totttime);
  printf("\nAverage turn around time is: %f", (float)totttime/n);
}
