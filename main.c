#include <stdio.h>
#include <malloc.h>

int *merge_arrays(int *a, int *b, int na, int nb) {
    int *res = malloc(sizeof(int) * (na + nb));
    if (a[0] > a[1]) {
        int temp;
        a[0] = temp;
        a[0] = a[1];
        a[1] = temp;
    }
    if (b[0] > b[1]) {
        int temp;
        b[0] = temp;
        b[0] = b[1];
        b[1] = temp;
    }
    int i = 0, j = 0;
    int index = 0;
    for (i, j;i < na && j < nb;) {
        if (a[i] < b[j]) {
            res[index] = a[i];
            i++;
        } else {
            res[index] = b[j];
            j++;
        }
        index++;
    }
    return *res;
}

 void mergesort(int *a, int n) {
    if(n == 1){
        return;
    }
    int k1 =n / 2;
    int k2 = n - k1;
    int *first_part = malloc(sizeof(int) * (k1));
    int *second_part = malloc(sizeof(int) * (k2));
    for(int i = 0; i < n / 2; i++){
        int j = n - i - 1;
        first_part[i] = a[i];
        second_part[j] = a[j];
    }
    second_part[0] = a[n / 2];
    mergesort(first_part, k1);
    mergesort(second_part, k2);
    int *res = merge_arrays(first_part, second_part, k1, k2);
    free(first_part);
    free(second_part);
    for(int i = 0; i < n; i++){
        a[i] = res[i];
    }
    free(res);
}

int main() {
    int *a = malloc(sizeof(int) * 10);
    for(int i = 0; i < 10; i++){
        scanf("%d", &a[i]);
    }
    //конвейеризация, git, github
    mergesort(a, 10);
    for(int i = 0; i < 10; i++){
        printf("%d", a[i]);
    }
    return 0;
}