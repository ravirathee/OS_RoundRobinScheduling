
#include <stdio.h>

int main() {
    printf("Hello, World!\n");

    int n = 0, tq = 0, i = 0;

    printf("Enter the Time Quantum : ");
    scanf("%d", &tq);


    printf("Enter the number of processes : ");
    scanf("%d", &n);
    printf("\nNumber of processes entered : %d\n", n);

    int AT[20] = {0}, at_i = 0;       //Arrival Time
    int BT[20] = {0}, bt_i = 0;       //Burst   Time
    int P[20] = {0}, p_i = 0;         //Priority
    int RT[20] = {0};                 //Remaining Time
    int CT[20] = {0};                 //Completion Time
    int TAT[20] = {0};                //Turn-Around Time
    int WT[20] = {0};                 //Waiting Time
    int time = 0;                     //current time
    int count = 0;                    //current process
    int remain = n;                   //remain processes with rt>0

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


    for (time = 0, count = 0; remain != 0;) {
        if ( RT[count])
    }


    return 0;
}