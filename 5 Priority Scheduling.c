#include<stdio.h>
struct {
	int Pid;
	int pri;
	int btime;
	int wtime;
	int ttime;
} p[10], t;

void main(){
	int totttime = 0, totwtime = 0;
	int n, i, j;
	
	
	printf("Enter number of processes: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		printf("Enter burst time and priority of process %d: ", i+1);
		scanf("%d %d", &p[i].btime, &p[i].pri);
		p[i].Pid = i+1;
		p[i].wtime = 0;
	}
	
	for(i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			if(p[i].pri > p[j].pri){
				t = p[i];
				p[i]= p[j];
				p[j] = t;
			}
		}
	}
	
	printf("\n Process\tBurst Time\tWaiting Time\tTurn Around Time\n");
	for(i=0; i<n; i++){
	p[i].wtime = p[i-1].wtime + p[i-1].btime;
	p[i].ttime = p[i].wtime + p[i].btime;
	totttime += p[i].ttime;
	totwtime += p[i].wtime;
		
	printf("\n%d\t\t%d\t\t%d\t\t%d", p[i].Pid, p[i].btime, p[i].wtime, p[i].ttime);
	}

	printf("\nTotal waiting time is: %d", totwtime);
	printf("\nAverage waiting time is: %f", (float)totwtime/n);
	printf("\nTotal turn around time is: %d", totttime);
	printf("\nAverage turn around time is: %f", (float)totttime/n);
}
