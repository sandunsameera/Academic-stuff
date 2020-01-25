#include<stdio.h>
#include<string.h>
typedef struct job job;
struct job{
    char jobId[2];
    int deadline;
    int profit;
};

int bestJob1;
char jobID[2];
struct job temp;
int best_index =0;
int next_index =1;
// int bestJobIndex =0;

#define MAX(x, y) (((x) > (y)) ? (x) : (y))


void sort_struct_array(struct job arr[]){
    for(int a=0;a<7;a++){
        for(int b=a+1;b<7;b++){
            if(arr[a].deadline>arr[b].deadline)
            {
                temp=arr[a];
                arr[a]=arr[b];
                arr[b]=temp;
            }
        }

        printf("%d\t",arr[a].profit);
    }
        printf("\n");
}


int main(int argc, char const *argv[]){
    job array[7] = {
        {"J1",2,90},
        {"J2",2,20},
        {"J3",1,40},
        {"J4",1,30},
        {"J5",4,65},
        {"J6",1,35},
        {"J7",3,50},
    };

    sort_struct_array(array);
    

    while (next_index < 8){
        // bestJob1 = array[best_index].profit;
        // printf("\n");
        strcpy(jobID,array[best_index].jobId);
        if (array[best_index].deadline == array[next_index].deadline){
            if (array[best_index].profit>array[next_index].profit){
                bestJob1 = array[best_index].profit;
                strcpy(jobID,array[best_index].jobId);
                next_index++;
               
            }else{
                best_index = next_index;
                bestJob1 = array[best_index].profit; 
                next_index++;
            }

        }else{
                // printf("%d\t",bestJob1);
                printf("%s\t",jobID);
                best_index = next_index;
                next_index++;
               
        }
    }
}