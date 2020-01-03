import java.util.*;

public class Question {
    public static void main(String[] args) {

        int array[] = new int[] { 962712, 308682, 203292, 368620, 315274, 425493, 258944, 681200, 626376, 876039,
                948267, 994726, 900631, 632986, 504507, 819596, 29333, 729171, 422843, 692730, 675279, 99683, 426655,
                814586, 561288, 231395, 102916, 443695, 277089, 492037, 893523 };

        int sums[] = new int[] { 31552, 234756, 596873, 648219, 726312, 981237, 988331, 1277361, 1283379 };
        _hashFunction(array);
    }

    static void _hashFunction(int arr[]) {
        int n = 31;

        int [][] hashedtable = new int [31][2];
        for (int i = 0; i < arr.length; i++) {
            int hashedvalue = (arr[i] % 31); // 0-11 between values
            System.out.println(hashedvalue + " - " + arr[i]);

            for (int k = 0; k < arr.length; k++) {
                hashedtable = new int[hashedvalue][arr[i]];
            }
            for(int h=0;h<31;h++){
                for(int j=0;j<2;j++){
                    System.out.println(hashedtable[h][j]);
                }
            }
        }

    }

    static void _isduplicate(int arr[]) {
        for (int k = 0; k < arr.length; k++) {
            for (int j = k + 1; j < arr.length; j++) {
                if (arr[k] == (arr[j])) {
                    System.out.println(arr[k]);
                }
            }
        }
    }
}
