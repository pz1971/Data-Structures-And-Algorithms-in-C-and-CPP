#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <climits>

void merge(int ar[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int left[ n1 + 1 ], right[ n2 + 1 ];    // new arrays

    // copying items to the new arrays
    for(int i = 0; i < n1; i++)
        left[i] = ar[p + i];
    for(int i = 0; i < n2; i++)
        right[i] = ar[q + i + 1];

    left[n1] = right[n2] = INT_MAX;

    int i = 0, j = 0;

    for(int k = p; k <= r; k++){
        
        if(left[i] <= right[j]){
            ar[k] = left[i];
            i++;
        }
        else{
            ar[k] = right[j];
            j++;
        }
    }
}

void merge_sort(int ar[] , int l, int u){
    if(l < u){
        int mid = (l + u) / 2;
        
        merge_sort(ar, l, mid);         // sorting left half
        merge_sort(ar, mid + 1, u);     // sorting right half
        
        merge(ar, l, mid, u);           // merging 2 sorted sub-arrays
    }
}

int main(){

    int arr[100000];

    srand(time(0));
    for(auto &i: arr){
        i = ( rand() % 100000 ) + 1;       // generating array elements randomly
    }

    clock_t start_time = clock();

    merge_sort(arr, 0, 99999);

    printf("Total time for sorting = %.3lf sec.\n", (double)( clock() - start_time ) / CLOCKS_PER_SEC);

    return 0;
}