#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "C3.h"

void quickSort(double *arr, int left, int right) {
    int i = left, j = right;
    double tmp, pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j) {
        quickSort(arr, left, j);
    }
    if (i < right) {
        quickSort(arr, i, right);
    }
}

int main() {
    char fileName[256];
    char *line = NULL;
    size_t len = 0;
    double numbers[1000];
    int n = 0;
    FILE *fp;

    printf("Enter the file name: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    while (getline(&line, &len, fp) != -1) {
        char *end;
        double num = strtod(line, &end);
        if (end != line) {
            numbers[n] = num;
            n++;
        } else {
            printf("Error: File contains non-numeric values.\n");
            return 1;
        }
    }
    fclose(fp);
    quickSort(numbers, 0, n - 1);

    printf("Sorted numbers: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", numbers[i]);
    }
    printf("\n");
    return 0;
}