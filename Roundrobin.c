#include <stdio.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
};

int main() {
    int n, quantum;
    float avg_wait_time = 0, avg_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process processes[n];
    for(int i=0; i<n; i++) {
        processes[i].pid = i+1;
        printf("Enter arrival time and burst time for process %d: ", processes[i].pid);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    int current_time = 0, completed = 0;
    while(completed < n) {
        for(int i=0; i<n; i++) {
            if(processes[i].remaining_time > 0) {
                int execution_time = quantum;
                if(processes[i].remaining_time < execution_time) {
                    execution_time = processes[i].remaining_time;
                }
                current_time += execution_time;
                processes[i].remaining_time -= execution_time;
                if(processes[i].remaining_time == 0) {
                    completed++;
                    int turnaround_time = current_time - processes[i].arrival_time;
                    int wait_time = turnaround_time - processes[i].burst_time;
                    avg_turnaround_time += turnaround_time;
                    avg_wait_time += wait_time;
                    printf("Process %d completed.\n", processes[i].pid);
                    printf("Turnaround Time: %d\n", turnaround_time);
                    printf("Waiting Time: %d\n", wait_time);
                }
            }
        }
    }

    avg_wait_time /= n;
    avg_turnaround_time /= n;
    printf("Average Waiting Time: %f\n", avg_wait_time);
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);
    return 0;
}

