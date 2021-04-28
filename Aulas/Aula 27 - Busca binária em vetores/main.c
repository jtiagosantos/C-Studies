#include <stdio.h>

int binarySearch(int vector[], int sizeVector, int key) {
    int min = 0;
    int max = sizeVector - 1;
    int middle;

    while(min <= max) {
        middle = (min + max) / 2;
        if(vector[middle] == key) {
            return middle;
        }else if(key < vector[middle]) {
            max = middle - 1;
        }else {
            min = middle + 1;
        }
    }

    return -1;
}

int main() {
    int vector[11] = {2, 5, 7, 19, 36, 44, 76, 91, 114, 237, 499};

    int pos = binarySearch(vector, 11, 9546451);
    printf("%d\n", pos);
    
    return 0;
}