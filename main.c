
#include <stdio.h>

int main() {
    printf("Hello, World!\n");

    int n,i=0;

    printf("Enter the number of processes : ");
    scanf("%d",&n);
    printf("\nNumber of processes entered : %d\n",n);

    int A[20]={0},B[20]={0},P[20]={0},temp[20]={0};

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