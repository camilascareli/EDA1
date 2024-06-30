#include <stdio.h>

typedef long Element;
#define less(A,B) (A < B)
#define exchange(A,B){Element temp = A; A = B; B = temp;}
#define compareAndExchange(A,B) {if (less(B,A)) exchange(A,B);}

void insertionSort(Element *array, int left, int right) {
    compareAndExchange(array[left], array[right]);
    for (int i = left+2; i <= right; i++) {
        int j = i;
        Element currentValue = array[j];
        while (less(currentValue, array[j-1])) {
            array[j] = array[j-1];
            j--;
        }
        array[j] = currentValue;
    }
}

int main() {
    Element vehicles[102], plateNumber;
    int operation, count = 0;
    while (scanf("%d %ld", &operation, &plateNumber) == 2) {
        if (operation == 1) {
            if (count < 101) {
                vehicles[count++] = plateNumber;
                insertionSort(vehicles, 0, count-1);
            } else {
                Element tempPlate = plateNumber;
                if (less(plateNumber, vehicles[100])) {
                    exchange(plateNumber, vehicles[100]);
                    insertionSort(vehicles, 0, 100);
                }
            }
        } else {
            int numOutput = plateNumber;
            for (int j = 0; j < numOutput; j++)
                printf("%ld ", vehicles[j]);
            printf("\n");
        }
    }
    for(int i = 0; i<5000;i++);

    return 0;
}