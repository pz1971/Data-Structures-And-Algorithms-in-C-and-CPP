#include <cstdio>
#include <climits>
#include <ctime>
#include <cstdlib>

int max_in_the_array(int ar[], int n){
    int ret = ar[0];
    
    for(int i=1; i<n; i++)
        if(ar[i] > ret)
            ret = ar[i];
    
    return ret;
}

int pockets[10][100000];
int count[10];

void radix_sort(int ar[], int n){
    int mx = max_in_the_array(ar, n);

    int thDig = 1;
    for( ; thDig <= mx; thDig *= 10){
        for(int i=0; i<n; i++){                 // putting into pockets
            pockets[ (ar[i]/thDig) % 10 ][ count[ (ar[i]/thDig) % 10 ] ] = ar[i];
            count[ (ar[i]/thDig) % 10 ]++;
        }

        int in = 0;
        for(int i=0; i < 10 ; i++){
            for(int j = 0; j<count[i]; j++){        // back to the array
                ar[in] = pockets[i][j];
                in++;
            }
            count[i] = 0;
        }
    }
}

int main(){

    int arr[100000];

    srand(time(0));
    for(auto &i: arr){
        i = ( rand() % 100000 ) + 1;       // generating array elements randomly
    }

    clock_t start_time = clock();

    radix_sort(arr, 100000);

    printf("Total time for sorting = %.3lf sec.\n", (double)( clock() - start_time ) / CLOCKS_PER_SEC);

    // for(int i=0; i<10000; i++)  printf("%d\n", arr[i]);

    return 0;
}