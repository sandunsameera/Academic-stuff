#include<stdio.h>

void hashFunction(int arr[]);
int main(int argc, char const *argv[])
{
    int array[] = {962712, 308682, 203292, 368620, 315274, 425493, 258944, 681200, 626376, 876039,
                948267, 994726, 900631, 632986, 504507, 819596, 29333, 729171, 422843, 692730, 675279, 99683, 426655,
                814586, 561288, 231395, 102916, 443695, 277089, 492037, 893523 };

    int sums[] = { 31552, 234756, 596873, 648219, 726312, 981237, 988331, 1277361, 1283379 }; 

    hashFunction(array); 
}
void hashFunction(int arr[]){
    int n = 23;
    for (int i = 0; i < 31; i++) {
            int hashedvalue = (arr[i] % n); // 0-11 between values
            printf("%d\n",hashedvalue);
        }
}
