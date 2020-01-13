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

int read_text_file(int arr[]){
  int c;
  FILE *file;
  int i =0;
  file = fopen("HashInt.txt","r");
  if (file){
      while ((c = fgetc(file))!=EOF){
      fscanf(file, "%d", &c);
    //   printf("%d\n",c);
      arr[i] = c;
    //   printf("%d\n",i,arr[i]);
      i++;
      }
      fclose(file);
  }
}

int main(){
    node array[7];
    for(int i=0;i<7;i++){
        array[i].value = NULL;
    }
    int numarray[100000];
    read_text_file(numarray);

    int sums[] = { 31552, 234756, 596873, 648219, 726312, 981237, 988331, 1277361, 1283379 };

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
    for(int i = 0; i < 10001; i++){
        // printf("%d ",i);
        node* ptr = &array[i];
        while (ptr->next != NULL){
            // printf("%d ",ptr->value);
            ptr = ptr->next;
        }
        // printf("\n");
    }  

    for (int i = 0; i < 9; i++)
    {
        for (int k = 0; k < 100000; k++)
        {
            int secondnumber = (sums[i] - numarray[k]);
            if (secondnumber>0)
            {
            int hashedSecondNumber = hash(secondnumber);
            node* ptr =&array[i];
            if (ptr->value == secondnumber)
            {
                flag =1;
            }else
            {
                ptr = ptr->next;
                flag =0;
            }
        }
            
    }

        if (flag ==0){
            printf("%d",0);
        }
        else{
            printf("%d",1);   
        }
    }
}
