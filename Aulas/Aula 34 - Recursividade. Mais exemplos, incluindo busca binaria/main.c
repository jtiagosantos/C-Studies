#include <stdio.h>

int binarySearch(int vector[], int start, int end, int key) {
    int middle;

    if(start <= end) {
        middle = (start + end) / 2;
        if(vector[middle] == key) {
            return middle;
        }else if(key < vector[middle]) {
            return binarySearch(vector, start, middle-1, key);
        }else {
            return binarySearch(vector, middle+1, end, key);
        }
    }
    return -1;
}

int main() {
    int vector[11] = {2, 5, 7, 19, 36, 44, 76, 91, 114, 237, 499};

    int pos = binarySearch(vector, 0, 11, 00);
    printf("%d\n", pos);

    return 0;
}