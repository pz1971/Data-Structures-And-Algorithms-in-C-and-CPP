#include <cstdio>
#include <climits>
#include <ctime>
#include <cstdlib>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int ar[], int l, int u){
    int p = u;              // taking last element as pivot
    int firstHigh = l;

    for(int i = l; i < u ; i++){
        if(ar[i] < ar[p]){
            swap(&ar[i] , &ar[firstHigh]);
            firstHigh++;
        }
    }

    swap(&ar[p] , &ar[firstHigh]);  // placing pivot in its right position

    return firstHigh;   // returning the sorted position of pivot
}

void quick_sort(int ar[], int l, int u){
    if(l < u){
        int p = partition(ar, l, u);    // takes the pivot element and inserts it in its right position, then returns that position
        quick_sort(ar, l, p - 1);
        quick_sort(ar, p + 1, u);
    }
}

int main(){

    int arr[100000];

    srand(time(0));
    for(auto &i: arr){
        i = ( rand() % 100000 ) + 1;       // generating array elements randomly
    }

    clock_t start_time = clock();

    quick_sort(arr, 0, 99999);

    printf("Total time for sorting = %.3lf sec.\n", (double)( clock() - start_time ) / CLOCKS_PER_SEC);

    for(int i=0; i<10000; i++)  printf("%d\n", arr[i]);

    return 0;
}