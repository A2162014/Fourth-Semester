/*
Experiment Name: Program for Round Robin for Scheduling.
Algorithm:
    1. The queue structure in ready queue is of First In First Out (FIFO) type.
    2. A fixed time is allotted to every process that arrives in the queue. This fixed time is known as time slice or time quantum.
    3. The first process that arrives is selected and sent to the processor for execution. If it is not able to complete
        its execution within the time quantum provided, then an interrupt is generated using an automated timer.
    4. The process is then stopped and is sent back at the end of the queue. However, the state is saved and context is thereby
        stored in memory. This helps the process to resume from the point where it was interrupted.
    5. The scheduler selects another process from the ready queue and dispatches it to the processor for its execution. It is executed until the time Quantum does not exceed.
    6. The same steps are repeated until all the process are finished.
*/
#include <stdio.h>
int main()
{
    int count, j, n, time, remain, flag = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0, at[10], bt[10], rt[10];
    printf("Enter Total process:\t ");
    scanf("%d", &n);
    remain = n;
    for (count = 0; count < n; count++)
    {
        printf("Enter Arrival Time and Burst Time for process process Number %d:", count + 1);
        scanf("%d", &at[count]);
        scanf("%d", &bt[count]);
        rt[count] = bt[count];
    }
    printf("Enter Time Quantum:\t");
    scanf("%d", &time_quantum);
    printf("\n\nprocess\t|Turnaround Time|Waiting Time\n\n");
    for (time = 0, count = 0; remain != 0;)
    {
        if (rt[count] <= time_quantum && rt[count] > 0)
        {
            time += rt[count];
            rt[count] = 0;
            flag = 1;
        }
        else if (rt[count] > 0)
        {
            rt[count] -= time_quantum;
            time += time_quantum;
        }
        if (rt[count] == 0 && flag == 1)
        {
            remain--;
            printf("P[%d]\t|\t%d\t|\t%d\n", count + 1, time - at[count], time - at[count] - bt[count]);
            wait_time += time - at[count] - bt[count];
            turnaround_time += time - at[count];
            flag = 0;
        }
        if (count == n - 1)
            count = 0;
        else if (at[count + 1] <= time)
            count++;
        else
            count = 0;
    }
    printf("\nAverage Waiting Time= %f\n", wait_time * 1.0 / n);
    printf("Avg Turnaround Time = %f", turnaround_time * 1.0 / n);
    return 0;
}