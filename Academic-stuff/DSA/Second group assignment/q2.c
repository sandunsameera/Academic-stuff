#include<stdio.h>
#include<string.h>
typedef struct job job;
struct job{
    char jobId[2];
    int deadline;
    int profit;
};

int bestJob;
int searched;
int lowest_deadline = 100;
char Id[2];
int pro;

#define MAX(x, y) (((x) > (y)) ? (x) : (y))


int comparator(const void *p, const void *q)  
{ 
    int l = ((struct job *)p)->deadline; 
    int r = ((struct job *)q)->deadline;  
    return (l - r); 
} 


int main(int argc, char const *argv[])
{
    job array[7] = {
        {"J1",2,90},
        {"J2",2,20},
        {"J3",1,40},
        {"J4",1,30},
        {"J5",4,65},
        {"J6",1,35},
        {"J7",3,50}
    };

    job sorted_array[7];

    for (int i = 0; i <7; i++){
        for (int k = i; k < 7; k++)
        {
            // lowest_deadline = array[0].deadline;
            if (lowest_deadline<array[i].deadline)
            {
                lowest_deadline = array[k].deadline;
                printf("%d\n",lowest_deadline);
                strcpy(Id,array[k].jobId);
                pro = array[k].profit;

            }
            
        }

        sorted_array[i].deadline = lowest_deadline;
        strcpy(sorted_array[i].jobId,Id);
        sorted_array[i].profit = pro;
        
        
    }
    for (int i = 0; i < 7; i++)
    {
        printf("%d\n",sorted_array[i].deadline);
    }
    
    
}
