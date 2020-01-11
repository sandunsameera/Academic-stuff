#include<stdio.h>
#include<stdlib.h>

typedef struct  Node node;

struct Node{
    node* next;
    int value;
};

int to_hashed(int num){
    return num%7; 
}

int main(){
    node array[7];
    int numarray = {962712, 308682, 203292, 368620, 315274, 425493, 258944, 681200, 626376, 876039,
                948267, 994726, 900631, 632986, 504507, 819596, 29333, 729171, 422843, 692730, 675279, 99683, 426655,
                814586, 561288, 231395, 102916, 443695, 277089, 492037, 893523};

    for(int i =0;i<7;i++){
        array[i].value == NULL;
        array[i].next == NULL;
    }

    for(int i =0;i<31;i++){
        if (array[to_hashed(numarray[i])].value == NULL)
        {
            /* code */
        }
        
        
    }


}
