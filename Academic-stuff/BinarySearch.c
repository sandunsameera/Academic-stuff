#include<stdio.h>
#include<math.h>
#include<stdlib.h>
    int result;
    int i;

    int binarySearch(int arr[], int leftmost, int rightmost, int x) 
{ 
    while (leftmost <= rightmost) { 
        int middle = leftmost+ (rightmost - leftmost) / 2; 
        if (arr[middle] == x) 
            return middle; 
  
        if (arr[middle] < x) 
            leftmost = middle + 1; 
   
        else
            rightmost = middle - 1; 
    } 
    return -1; 
} 

int linearSearch(int arr[],int n,int search){
    for (i = 0; i < n; i++)
  {
    if (arr[i] == search)
    {
      printf("%d is present at index %d.\n", search, i);
      break;
    }
  }
  if (i == n)
    printf("%d isn't present in the array.\n", search);

  return 0;

}

int jumpSearch(int arr[],int n,int x)
{ 
	int root = sqrt(n); 
	int prev =0; 
  int step=0;
  int location=0;
  
  for (int i = 0; i < n; i++)
  {
    if (root*i*step<=x)
    {
      step++;
    }
    else
    {
      prev = root*(i-1);
      location = prev;
      for (int j = prev; j <=prev+root ; j++)
      {
          location++;
        if (arr[j] == x)
        {
          printf("%d is present in the array in the location of %d.\n",x,location);
          exit(0);
        }
 
      }            
    }
  }
  printf("Element not found in array.\n");
  
} 

int interpolationSearch(int arr[], int n, int x) 
{  
    int lowEnd = 0, highEnd = (n - 1); 

    while (lowEnd <= highEnd && x >= arr[lowEnd] && x <= arr[highEnd]) 
    { 
        if (lowEnd == highEnd){ 
            if (arr[lowEnd] == x) return lowEnd; 
            return -1; 
        } 
        int pos = lowEnd + (((double)(highEnd-lowEnd) / 
              (arr[highEnd]-arr[lowEnd]))*(x - arr[lowEnd])); 
  
        if (arr[pos] == x) 
            return pos; 
  
        if (arr[pos] < x) 
            lowEnd = pos + 1; 
  
        else
            highEnd = pos - 1; 
    } 
    return -1; 
} 

int comparisonFuncrion (const void * element1, const void * element2) 
{
    int first = *((int*)element1);
    int second = *((int*)element2);
    if (first > second) return  1;
    if (first < second) return -1;
    return 0;
}


 int main(){
     int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 
				34, 55, 89, 144, 233, 377 };
     int searchtype;

     printf("-------------Welcome !!----------------\n");
     printf("Enter 1 for binary search\n");
     printf("Enter 2 for linear search\n");
     printf("Enter 3 for jump search\n");
     printf("Enter 4 for interpolation search\n");
     scanf("%i",&searchtype);
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 21; 

    qsort(arr,sizeof(arr)/sizeof(*arr),sizeof(*arr),comparisonFuncrion);

     switch (searchtype)
     {
     case 1:
     result=binarySearch(arr, 0, n - 1, x);
     (result == -1) ? printf("Element is not present in array\n"): printf("Element is present at index %d\n",result);
    break;

    case 2:linearSearch(arr,n,x);
    break;

    case 3: result=jumpSearch(arr,n,x);

    case 4: result = interpolationSearch(arr, n, x);

    if (result!= -1) 
        printf("Element found at index %d\n", result); 
    else
        printf("Element not found."); 
     default:
         break;
     }
    return 0; 
 }

