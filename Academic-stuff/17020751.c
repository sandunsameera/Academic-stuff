#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include <time.h>
#include <unistd.h>
    int result;
    int i;

    int binarySearch(int arr[], int leftmost, int rightmost, int x) 
{ 
  time_t begin = time(NULL);
    while (leftmost <= rightmost) { 
        int middle = leftmost+ (rightmost - leftmost) / 2; 
        if (arr[middle] == x) 
            return middle; 
  
        if (arr[middle] < x) 
            leftmost = middle + 1; 
   
        else
            rightmost = middle - 1; 
    } 
    time_t end = time(NULL);
    printf("Time spent is %ld \n ",(end-begin));
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

void printArray(int arr[],int n){
  for (int i = 0; i < n; i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
  
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
    int x;
    int arr[] = { 3,1, 0, 1, 2,  5, 8, 13, 21, 
				34, 55, 89, 144, 233, 377,43,990,12,33,442,552,556,666,9,7,4,544,233,1213,4432,
        44454,76767,6656,65656,77442,23344,435323,54567,57785,7445,54342,656767,21121,21112 };
     int searchtype;

     printf("-------------Welcome !!----------------\n");

     printf("Enter number you want to search !!\n");
     scanf("%d",&x);

     printf("Enter 1 for print sorted array\n");
     printf("Enter 2 for binary search\n");
     printf("Enter 3 for linear search\n");
     printf("Enter 4 for jump search\n");
     printf("Enter 5 for interpolation search\n");
     scanf("%i",&searchtype);
    int n = sizeof(arr) / sizeof(arr[0]);  
    clock_t binarySearchTime;
    clock_t linierSearchTime;
    clock_t jumpSearchTime;
    clock_t interpolationSearchTime;

    double time_taken_binary;
    double time_taken_linier;
    double time_taken_jump;
    double time_taken_interpolation;

    clock_t start = clock();
    qsort(arr,sizeof(arr)/sizeof(*arr),sizeof(*arr),comparisonFuncrion);
    start = clock() - start;
    double time_taken = ((double)start)/CLOCKS_PER_SEC;

     switch (searchtype)
     {

    case 1:printArray(arr,n);
    printf("sorting took %f seconds to execute \n", time_taken);
    break;

    case 2:
    binarySearchTime = clock();
     result=binarySearch(arr, 0, n - 1, x);
     (result == -1) ? printf("Element is not present in array\n"): printf("Element is present at index %d\n",result);
     binarySearchTime = clock() -binarySearchTime;
    time_taken_binary = ((double)binarySearchTime)/CLOCKS_PER_SEC;
    printf("sorting took %f seconds to execute \n", time_taken);
    printf("Binary search took %f seconds to execute \n", time_taken_binary);
    break;

    case 3:
    linierSearchTime = clock();
    linearSearch(arr,n,x);
    linierSearchTime = clock() -linierSearchTime;
    time_taken_linier = ((double)linierSearchTime)/CLOCKS_PER_SEC;
    printf("sorting took %f seconds to execute \n", time_taken);
    printf("Linear search took %f seconds to execute \n", time_taken_linier);
    break;

    case 4: 
    jumpSearchTime = clock();
    jumpSearch(arr,n,x);
    jumpSearchTime = clock() -jumpSearchTime;
    time_taken_jump = ((double)jumpSearchTime)/CLOCKS_PER_SEC;
    printf("sorting took %f seconds to execute \n", time_taken);
    printf("jump search took %f seconds to execute \n", time_taken_jump);
    break;

    case 5:
    interpolationSearchTime = clock();
    result = interpolationSearch(arr, n, x);
    if (result!= -1) 
        printf("Element found at index %d\n", result); 
    else
        printf("Element not found."); 
    interpolationSearchTime = clock() -interpolationSearchTime;
    time_taken_interpolation = ((double)interpolationSearchTime)/CLOCKS_PER_SEC;
    printf("sorting took %f seconds to execute \n", time_taken);
    printf("interpolation search took %f seconds to execute \n", time_taken_interpolation);
        break;
     default:printf("Wrong option execute again\n");
         break;
     }
    return 0; 
 }

