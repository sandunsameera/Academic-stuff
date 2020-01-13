#include<stdio.h>
#include<stdlib.h>

typedef struct Node node;

int flag;
int found = 0;

struct Node
{
    node* next;
    int value;
};

int hash(int num){
    num = num%101;
    return num;
}

int read_text_file(int arr[]){
  int c;
  FILE *file;
  int i =0;
  file = fopen("HashInt.txt","r");
  if (file){
      while ((c = fgetc(file))!=EOF){
      fscanf(file, "%d", &c);
      arr[i] = c;
      i++;
    }
      fclose(file);
  }
}

int main(){
    node array[101];
    for(int i=0;i<101;i++){
        array[i].value = NULL;
    }
    int numarray[100000];
    read_text_file(numarray);

    int sums[] = {231552,234756,596873,648219,726312,981237,988331,1277361,1283379 };

    for(int i=0 ; i<100000;i++){
        
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

    //print hashtable
    for(int i = 0; i < 101; i++){
        printf("\n\n");
        printf("index %d ---\n ",i);
        printf("\n\n");
        node* ptr = &array[i];
        while (ptr->next != NULL){
            printf("%d ",ptr->value);
            ptr = ptr->next;
        }
        printf("------------------------------------------------------------------------------------------------------------------------------------------");
        printf("\n");
    }  

    for (int i = 0; i < 9; i++)
    {   found = 0;
        for (int k = 0; k < 100000; k++){
            if(found == 0){
            int secondnumber = (sums[i] - numarray[k]);
            if (secondnumber>0)
            {
            int hashedSecondNumber = hash(secondnumber);
            node* ptr;
            ptr = array;
            for(int i=0;i<hashedSecondNumber;i++){
                ptr++;
            }
            ptr = ptr->next;
            while (ptr->next != NULL){
                if(ptr->value == secondnumber){
                    printf("1");
                    ptr = ptr->next;
                    found = 1;
                }else{
                    ptr = ptr->next;
                }
            }
        }   
      }
    }
    if(found == 0){
        printf("0");
    }
    
    }
}
