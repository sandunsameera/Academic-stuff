#include<stdio.h>
#include<stdlib.h>

typedef struct Node node;

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
    int numarray[] = {962712, 308682, 203292, 368620, 315274, 425493, 258944, 681200, 626376, 876039,
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

    for(int i = 0; i <7 ; i++){
        printf("%d ",i);
        node* ptr = &array[i];
        while (ptr->next != NULL){
            printf("%d ",ptr->value);
            ptr = ptr->next;
        }
        printf("\n");
    }

    for (int i = 0; i < sizeof(sums); i++)
    {
        for (int k = 0; k < sizeof(numarray); k++)
        {
            int secondnumber = (sums[i]- numarray[k]);
            if (secondnumber>0)
            {
            // printf("%d - %d\n",i,secondnumber);
            int hashedsecondNumber=hash(secondnumber);
            // printf("%d - %d\n",hashedsecondNumber,secondnumber);
                node* ptr = &array[hashedsecondNumber];
                while (ptr->next != NULL){
                    if(ptr->value == secondnumber){

                printf("found");
                    }
                ptr = ptr->next;
        }
            
            break;
            }
        }
        
    }
    
}