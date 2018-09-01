
#include <stdio.h>

int main() {
    printf("Hello, World!\n");

    int n = 0, tq = 0, i=0;

    printf("Enter the Time Quantum : ");
    scanf("%d",&tq);


    printf("Enter the number of processes : ");
    scanf("%d",&n);
    printf("\nNumber of processes entered : %d\n",n);

    int A[20]={0}, at_i=0;       //Arrival Time
    int B[20]={0}, bt_i=0;       //Burst   Time
    int P[20]={0}, p_i=0;        //Priority
    int R[20]={0};               //Remaining Time
    int RQ[100]={0}, rq_i=-1 , rq_j=-1 ;   //rq is Request Queue

    //Input Arrival Time
    printf("\nEnter Arrival time of processes: \n");
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    printf("Arrival Time: ");
    for(i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    //Input Burst Time
    printf("\n\nEnter Burst time of processes: \n");

    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
        R[i]=B[i];
    }

    printf("\n");
    printf("Burst Time: ");
    for(i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    //Input Priority
    printf("\n\nEnter Priority of processes: \n");
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    printf("\n");
    printf("Priority : ");
    for(i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");













    return 0;
}