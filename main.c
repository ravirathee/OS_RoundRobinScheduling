//Ravi Rathee
//Round Robin Scheduling
//With Arrival Time != 0

#include <stdio.h>

int main() {
    int n = 0, tq = 0, i = 0;

    printf("Enter the Time Quantum : ");
    scanf("%d", &tq);


    printf("Enter the number of processes : ");
    scanf("%d", &n);
    printf("\nNumber of processes entered : %d\n", n);

    int AT[20] = {0}, at_i = 0;                 //Arrival Time
    int BT[20] = {0}, bt_i = 0;                 //Burst   Time
    int P[20] = {0}, p_i = 0;                   //Priority
    int RT[20] = {0};                           //Remaining Time
    int CT[20] = {0};                           //Completion Time
    int TAT[20] = {0};                          //Turn-Around Time
    int WT[20] = {0};                           //Waiting Time
    int RQ[100] = {-1}, rq_i = -1, rq_j = -1;   //Ready Queue
    int time = 0;                               //current time
    int prev_time = 0;                          //time in prev iteration
    int count = 0;                              //current process
    int remain = n;                             //remain processes with rt>0


    //Input Arrival Time
    printf("\nEnter Arrival time of processes: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &AT[i]);
    }

    printf("Arrival Time: ");
    for (i = 0; i < n; i++) {
        printf("%d ", AT[i]);
    }

    //Input Burst Time
    printf("\n\nEnter Burst time of processes: \n");

    for (i = 0; i < n; i++) {
        scanf("%d", &BT[i]);
        RT[i] = BT[i];
    }

    printf("\n");
    printf("Burst Time: ");
    for (i = 0; i < n; i++) {
        printf("%d ", BT[i]);
    }

    //Initializing Ready queue with -1
    for (i = 0; i < 100; i++) {
        RQ[i]=-1;
    }

    //My Ready Queue has atleast one process
    //at the starting of process
    RQ[0] = 0;
    rq_i = 0;
    rq_j = 0;


    printf("\n\n\nRemaining Time: ");
    for (i = 0; i < n; i++) {
        printf("%d ", RT[i]);
    }

    printf("\nCompletion Time: ");
    for (i = 0; i < n; i++) {
        printf("%d ", CT[i]);
    }

    printf("\nRequest Queue : ");
    for (i = 0; i < 20; i++) {
        printf("%d ", RQ[i]);
    }

    printf("\nCurrent  Time : %d",time);
    printf("\nPrevious Time : %d",prev_time);
    printf("\nrq_i : %d",rq_i);
    printf("\nrq_j : %d",rq_j);


    //Main Code
    for (time = 0, count = 0; remain != 0;) {

        printf("\n\n\ncount : %d",count);

        prev_time = time;

        if (RT[count] <= tq && RT[count] > 0) {
            time += RT[count];
            RT[count] = 0;
        } else if (RT[count] > 0) {
            time += tq;
            RT[count] -= tq;
        }

        if (RT[count] == 0) {
            remain--;
            CT[count] = time;
            TAT[count] = CT[count] - AT[count];
            WT[count] = TAT[count] - BT[count];
        }


        for (i = 0; i < n; i++) {
            if (AT[i] <= time && AT[i] > prev_time) {
                rq_j += 1;
                RQ[rq_j] = i;
            }
        }

        if (RT[count] != 0) {
            rq_j += 1;
            RQ[rq_j] = count;
        }


        if (rq_i <= rq_j) {
            rq_i += 1;
            count = RQ[rq_i];
        }



        printf("\nRemaining Time: ");
        for (i = 0; i < n; i++) {
            printf("%d ", RT[i]);
        }

        printf("\nCompletion Time: ");
        for (i = 0; i < n; i++) {
            printf("%d ", CT[i]);
        }

        printf("\nRequest Queue : ");
        for (i = 0; i < 20; i++) {
            printf("%d ", RQ[i]);
        }

        printf("\nCurrent  Time : %d",time);
        printf("\nPrevious Time : %d",prev_time);
        printf("\nrq_i : %d",rq_i);
        printf("\nrq_j : %d",rq_j);
        printf("\ncount : %d",count);
    }


    printf("\nCompletion Time: ");
    for (i = 0; i < n; i++) {
        printf("%d ", CT[i]);
    }

    printf("\nTurn Around Time: ");
    for (i = 0; i < n; i++) {
        printf("%d ", TAT[i]);
    }

    printf("\nWaiting Time: ");
    for (i = 0; i < n; i++) {
        printf("%d ", WT[i]);
    }

    printf("\n\nAverage Turn Around Time : ");
    float sum_TAT = 0;
    float avg_TAT = 0;
    for (i = 0; i < n; i++) {
        sum_TAT+=TAT[i];
    }
    avg_TAT = sum_TAT/n;
    printf("%4f",avg_TAT);

    printf("\nAverage Waiting Time : ");
    float sum_WT = 0;
    float avg_WT = 0;
    for (i = 0; i < n; i++) {
        sum_WT+=WT[i];
    }
    avg_WT = sum_WT/n;
    printf("%4f",avg_WT);


    return 0;
}

/*
OUTPUT

Enter the Time Quantum : 2
Enter the number of processes : 6

Number of processes entered : 6

Enter Arrival time of processes:
0
1
2
3
4
6
Arrival Time: 0 1 2 3 4 6

Enter Burst time of processes:
4
5
2
1
6
3

Burst Time: 4 5 2 1 6 3


Remaining Time: 4 5 2 1 6 3
Completion Time: 0 0 0 0 0 0
Request Queue : 0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
Current  Time : 0
Previous Time : 0
rq_i : 0
rq_j : 0


count : 0
Remaining Time: 2 5 2 1 6 3
Completion Time: 0 0 0 0 0 0
Request Queue : 0 1 2 0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
Current  Time : 2
Previous Time : 0
rq_i : 1
rq_j : 3
count : 1


count : 1
Remaining Time: 2 3 2 1 6 3
Completion Time: 0 0 0 0 0 0
Request Queue : 0 1 2 0 3 4 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
Current  Time : 4
Previous Time : 2
rq_i : 2
rq_j : 6
count : 2


count : 2
Remaining Time: 2 3 0 1 6 3
Completion Time: 0 0 6 0 0 0
Request Queue : 0 1 2 0 3 4 1 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
Current  Time : 6
Previous Time : 4
rq_i : 3
rq_j : 7
count : 0


count : 0
Remaining Time: 0 3 0 1 6 3
Completion Time: 8 0 6 0 0 0
Request Queue : 0 1 2 0 3 4 1 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
Current  Time : 8
Previous Time : 6
rq_i : 4
rq_j : 7
count : 3


count : 3
Remaining Time: 0 3 0 0 6 3
Completion Time: 8 0 6 9 0 0
Request Queue : 0 1 2 0 3 4 1 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
Current  Time : 9
Previous Time : 8
rq_i : 5
rq_j : 7
count : 4


count : 4
Remaining Time: 0 3 0 0 4 3
Completion Time: 8 0 6 9 0 0
Request Queue : 0 1 2 0 3 4 1 5 4 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
Current  Time : 11
Previous Time : 9
rq_i : 6
rq_j : 8
count : 1


count : 1
Remaining Time: 0 1 0 0 4 3
Completion Time: 8 0 6 9 0 0
Request Queue : 0 1 2 0 3 4 1 5 4 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
Current  Time : 13
Previous Time : 11
rq_i : 7
rq_j : 9
count : 5


count : 5
Remaining Time: 0 1 0 0 4 1
Completion Time: 8 0 6 9 0 0
Request Queue : 0 1 2 0 3 4 1 5 4 1 5 -1 -1 -1 -1 -1 -1 -1 -1 -1
Current  Time : 15
Previous Time : 13
rq_i : 8
rq_j : 10
count : 4


count : 4
Remaining Time: 0 1 0 0 2 1
Completion Time: 8 0 6 9 0 0
Request Queue : 0 1 2 0 3 4 1 5 4 1 5 4 -1 -1 -1 -1 -1 -1 -1 -1
Current  Time : 17
Previous Time : 15
rq_i : 9
rq_j : 11
count : 1


count : 1
Remaining Time: 0 0 0 0 2 1
Completion Time: 8 18 6 9 0 0
Request Queue : 0 1 2 0 3 4 1 5 4 1 5 4 -1 -1 -1 -1 -1 -1 -1 -1
Current  Time : 18
Previous Time : 17
rq_i : 10
rq_j : 11
count : 5


count : 5
Remaining Time: 0 0 0 0 2 0
Completion Time: 8 18 6 9 0 19
Request Queue : 0 1 2 0 3 4 1 5 4 1 5 4 -1 -1 -1 -1 -1 -1 -1 -1
Current  Time : 19
Previous Time : 18
rq_i : 11
rq_j : 11
count : 4


count : 4
Remaining Time: 0 0 0 0 0 0
Completion Time: 8 18 6 9 21 19
Request Queue : 0 1 2 0 3 4 1 5 4 1 5 4 -1 -1 -1 -1 -1 -1 -1 -1
Current  Time : 21
Previous Time : 19
rq_i : 12
rq_j : 11
count : -1
Completion Time: 8 18 6 9 21 19
Turn Around Time: 8 17 4 6 17 13
Waiting Time: 4 12 2 5 11 10

Average Turn Around Time : 10.833333
Average Waiting Time : 7.333333
Process finished with exit code 0


*/