#include <stdio.h>
#include <math.h>

int main() {
    double sum = 0, harmonic_sum = 0, number, average, harmonic_average;
    int count = 0, choice;
    char file_name[100];
    FILE *fp;

    printf("Wybierz 1 dla obliczenia sredniej harmonicznej, 2 dla obliczenia sredniej arytmetycznej: ");
    scanf("%d", &choice);

    printf("Podaj nazwe pliku: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "r");

    if (fp == NULL) {
        printf("Nie mozna otworzyc pliku\n");
        return 0;
    }

    while (fscanf(fp, "%lf", &number) != EOF) {
        if (choice == 1) {
            harmonic_sum += 1/number;
        }
        else {
            sum += number;
            count++;
        }
    }

    if (choice == 1) {
        harmonic_average = count / harmonic_sum;
        printf("Srednia harmoniczna: %lf\n", harmonic_average);
    }
    else {
        average = sum / count;
        printf("Srednia arytmetyczna: %lf\n", average);
    }

    fclose(fp);
    return 0;
}
