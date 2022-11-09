#include <stdlib.h>
#include <stdio.h>

#define MINPID 0
#define MAXPID 300
#define ARRAYNUMBER 4

void setBit(int *a, int k);
void clearBit(int *bitmap, int k);
int testBit(int *bitmap, int k);
int allocate_map(void);
int allocate_pid(void);
void realse_pid(int pid);

int *bitmap = NULL; 

int main(){  
    int tmp = 0;
    tmp = allocate_map();
    if (!tmp) {
        printf("allocate fail");
    }
    while(1){
        int userAns = 0;
        printf("----------------------------------------\n");
        printf("(1)creat process  (2)delete process (3)exit \n Please enter your choise : ");
        scanf("%d",&userAns);
        if (userAns == 3){
            printf("Exit this Process !");
            break;
        } 

        if (userAns == 1){
            int error = 0;
            error = allocate_pid();
            if (!error){
                printf("allocate pid fail");
                break;
            }
            for(int i = 0; i < ARRAYNUMBER; i++){
                printf("bitmap[%d] = %d\n", i, bitmap[i]);
            }
        }
        if (userAns == 2){
            int del_PID = 0;
            printf("Please enter the PID you want delete : ");
            scanf("%d",&del_PID);
            if (testBit(bitmap, del_PID) == 0){
                printf("\nThis Pid hasn't allocate\n\n");
                continue;
            }
            realse_pid(del_PID);
            for(int i = 0; i < ARRAYNUMBER; i++){
                printf("bitmap[%d] = %d\n", i, bitmap[i]);
            }
        }
    }
    


}
int allocate_map(void){
    printf("-----------Allocating bitmap---------------- \n");
    bitmap = malloc(ARRAYNUMBER * sizeof(int));
    for(int i = 0; i < ARRAYNUMBER; i++){
        bitmap[i] = 0;
        printf("bitmap[%d] = %d\n", i, bitmap[i]);
    }

    if(!bitmap){
        return -1;                  //malloc fault
    }
    return 1;
}
int allocate_pid(void){
    for (int i = MINPID; i<MAXPID;i++){
        if (!(testBit(bitmap, i))){
            setBit(bitmap, i);
            return 1;
        }
    }
    return 0;
}
void realse_pid(int pid){
    clearBit(bitmap, pid);
}

void setBit (int *a,int k){
    a[(k / 32)] |= (1 << (k % 32));
}
void clearBit (int *a ,int k){
    a[(k / 32)] &= ~(1 << (k % 32));
}
int testBit (int *bitmap ,int k){
    int re;
    re = bitmap[(k / 32)] & (1 << (k % 32));
    return re;
}
