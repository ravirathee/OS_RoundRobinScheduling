
#include <stdio.h>

int main() {
    int n = 0, tq = 0, i = 0;

    printf("Enter the Time Quantum : ");
    scanf("%d", &tq);


    printf("Enter the number of processes : ");
    scanf("%d", &n);
    printf("\nNumber of processes entered : %d\n", n);

    int AT[20] = {0}, at_i = 0;             //Arrival Time
    int BT[20] = {0}, bt_i = 0;             //Burst   Time
    int P[20] = {0}, p_i = 0;               //Priority
    int RT[20] = {0};                       //Remaining Time
    int CT[20] = {0};                       //Completion Time
    int TAT[20] = {0};                      //Turn-Around Time
    int WT[20] = {0};                       //Waiting Time
    int RQ[100] = {-1}, rq_i = -1, rq_j = -1;  //Ready Queue
    int time = 0;                           //current time
    int prev_time = 0;                      //time in prev iteration
    int count = 0;                          //current process
    int remain = n;                         //remain processes with rt>0


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

    //Input Priority
    printf("\n\nEnter Priority of processes: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &P[i]);
    }

    printf("\n");
    printf("Priority : ");
    for (i = 0; i < n; i++) {
        printf("%d ", P[i]);
    }
    printf("\n");

    //My Ready Queue has atleast one process
    //at the starting of process
    RQ[0] = 0;
    rq_i = 0;
    rq_j = 0;

    for (time = 0, count = 0; remain != 0;) {

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
            if (AT[i] <= time && AT[i] > time - prev_time) {
                rq_j += 1;
                RQ[rq_j] = i;
            }
        }
        if (RT[count] != 0) {
            rq_j += 1;

        }


        if (count == n - 1)
            count = 0;
        else if (AT[count + 1] <= time)
            count++;
        else
            count = 0;
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


    return 0;
}