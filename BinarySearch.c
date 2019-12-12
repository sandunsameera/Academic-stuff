#include<stdio.h>
#include<math.h>
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
      printf("%d is present at location %d.\n", search, i+1);
      break;
    }
  }
  if (i == n)
    printf("%d isn't present in the array.\n", search);

  return 0;

}

int jumpSearch(int arr[], int x, int n) 
{ 
	int step = sqrt(n); 

	int prev = 0; 
	// while (arr[min(step, n)-1] < x) 
	{ 
		prev = step; 
		step += sqrt(n); 
		if (prev >= n) 
			return -1; 
	} 

	while (arr[prev] < x) 
	{ 
		prev++; 
		// if (prev == min(step, n)) 
			return -1; 
	} 
	if (arr[prev] == x) 
		return prev; 

	return 0; 
} 

 int main(){
     int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 
				34, 55, 89, 144, 233, 377, 610 }; 
     int searchtype;

     printf("-------------Welcome !!----------------\n");
     printf("Enter 1 for binary search\n");
     printf("Enter 2 for linear search\n");
     printf("Enter 3 for jump search\n");
     printf("Enter 4 for interpolation search\n");
     scanf("%i",&searchtype);
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 13; 

     switch (searchtype)
     {
     case 1:
     result=binarySearch(arr, 0, n - 1, x);
     (result == -1) ? printf("Element is not present in array\n"): printf("Element is present at index %d\n",result);
    break;

    case 2:linearSearch(arr,n,x);
    break;

    case 3: result=jumpSearch(arr,n,x);
    (result == -1) ? printf("Element is not present in array\n"): printf("Element is present at index %d\n",result);
    break;

     
     default:
         break;
     }

    
    return 0; 
 }

