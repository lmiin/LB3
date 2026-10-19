#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void Calculations(int *group, int *variant, double *course) {
    double sum = *group + *variant + *course;
    double product = (double)(*group) * (*variant) * (*course);
    double result;

    if (*variant % 2 == 0) {
        result = sin(sum);
    } else {
        result = cos(product);
    }

    *group = (int)sum;
    *variant = (int)product;
    *course = result;
}

int sum_of_digits(int n) {
    if (n < 0) {
        return sum_of_digits(-n);
    }
    if (n == 0) {
        return 0;
    }
    return n % 10 + sum_of_digits(n / 10);
}

void print_array(const double *arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%g", arr[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }
    printf("]\n");
}

void task2() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    printf("Sum of digits of %d is: %d\n", n, sum_of_digits(n));
}

void task4() {
    int n;
    printf("Enter array size N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size\n");
        return;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed\n");
        return;
    }

    srand((unsigned)time(NULL));
    for (int *p = arr; p < arr + n; p++) {
        *p = rand() % 100;
    }

    printf("\n=== 1. Initial array ===\n");
    for (int i = 0; i < n; i++) {
        printf("Element %3d: value = %d | address = %p\n",
               i, *(arr + i), (void *)(arr + i));
    }

    int *min_ptr = arr;
    int *max_ptr = arr;
    for (int *p = arr; p < arr + n; p++) {
        if (*p < *min_ptr) {
            min_ptr = p;
        }
        if (*p > *max_ptr) {
            max_ptr = p;
        }
    }

    printf("\n=== 2. Search results ===\n");
    printf("Minimum element: value = %d | address = %p\n",
           *min_ptr, (void *)min_ptr);
    printf("Maximum element: value = %d | address = %p\n",
           *max_ptr, (void *)max_ptr);

    int tmp = *min_ptr;
    *min_ptr = *max_ptr;
    *max_ptr = tmp;

    printf("\n=== 3. Resulting array after swap ===\n");
    for (int i = 0; i < n; i++) {
        printf("Element %3d: value = %d | address = %p\n",
               i, *(arr + i), (void *)(arr + i));
    }

    free(arr);
}

int main() {
    int group_number = 79;
    int variant_number = 11;
    double course_number = 4;

    int original_group = group_number;
    int original_variant = variant_number;
    double original_course = course_number;

    printf("Initial values: group = %d, variant = %d, course = %g\n",
           group_number, variant_number, course_number);

    Calculations(&group_number, &variant_number, &course_number);

    printf("New values: group = %d, variant = %d, course = %f\n",
           group_number, variant_number, course_number);

    task2();

    double arr[] = {1, 2, group_number, variant_number, course_number};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array before changes: ");
    print_array(arr, size);

    arr[0] = original_group;
    arr[1] = original_course;

    for (int i = 0; i < size; i++) {
        arr[i] += original_variant;
    }

    printf("Array after changes: ");
    print_array(arr, size);

    task4();

    return 0;
}