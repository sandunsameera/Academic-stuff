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