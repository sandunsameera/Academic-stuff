#include<stdio.h>
#include<stdlib.h>

typedef struct Node node;

int flag ;

struct Node
{
    node* next;
    int value;
};

int hash(int num){
    num = num%7;
    return num;
}
int main(){
    node array[7];
    for(int i=0;i<7;i++){
        array[i].value = NULL;
    }
    int numarray[] = {962712, 2219,307131,308682, 203292, 368620, 315274, 425493, 258944, 681200, 626376, 876039,
                948267, 994726, 900631, 632986, 504507, 819596, 29333, 729171, 422843, 692730, 675279, 99683, 426655,
                814586, 561288, 231395, 102916, 443695, 277089, 492037, 893523 };

    int sums[] = { 31552, 234756, 596873, 648219, 726312, 981237, 988331, 1277361, 1283379 };

    for(int i=0 ; i<31;i++){
        
        if(array[hash(numarray[i])].value == NULL){
            array[hash(numarray[i])].value = numarray[i];
            array[hash(numarray[i])].next = NULL;
        }else{
            node* newNode = (node*)malloc(sizeof(node));
            newNode->value = numarray[i];
            newNode->next = NULL;

            node* ptr = &array[hash(numarray[i])];
            while (ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }

    }

    for(int i = 0; i < 7; i++){
        printf("%d ",i);
        node* ptr = &array[i];
        while (ptr->next != NULL){
            printf("%d ",ptr->value);
            ptr = ptr->next;
        }
        printf("\n");
    }  

    for (int i = 0; i < 9; i++)
    {
        for (int k = 0; k < 31; k++)
        {
            int secondnumber = (sums[i] - numarray[k]);
            if (secondnumber>0)
            {
            int hashedSecondNumber = hash(secondnumber);
            // printf("%d - %d\n",hashedSecondNumber,secondnumber);
            node* ptr =&array[i];
            if (ptr->value == secondnumber)
            {
                flag =1;
            }else
            {
                // printf("Not Found\n");
                ptr = ptr->next;
                flag =0;
            }
        }
            
    }

    if (flag ==0)
    {
    printf("%d",0);
    }else
    {
    printf("%d",1);   
    }
    
    
        
}
    
  
}
