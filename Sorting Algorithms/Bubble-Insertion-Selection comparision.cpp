#include<stdio.h>
#include<time.h>
#include<stdlib.h>
typedef long long LL;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp; 
}

namespace _bubble_sort{

	LL swapCount, compCount;
	double timePassed;

	void bubbleSort(int ar[], int len){
		swapCount = compCount = 0;

		clock_t start = clock();

		for(int i = 0; i < len; i++){
			for(int j = 0; j < len - i - 1; j++){
				if(ar[j] > ar[j + 1]){
					swap(&ar[j], &ar[j+1]);
					
					swapCount++;
				}
				compCount++;
			}
		}

		timePassed = (double)(clock() - start) / CLOCKS_PER_SEC ;
	}

}

namespace _insertion_sort{

	LL swapCount, compCount;
	double timePassed;

	void insertionSort(int ar[], int len) {
		swapCount = compCount = 0;
		
		clock_t start = clock();

		for(int i = 1; i < len ; i++){
			int key = ar[i];
			
			int j = i - 1;
			for( ; j >= 0 && ar[j] > key ; j--){
				ar[j + 1] = ar[j];
				
				compCount++;
				swapCount++;
			}
			
			ar[j] = key;
		}
		
		timePassed = (double)(clock() - start) / CLOCKS_PER_SEC ;
	}

}

namespace _selection_sort{

	LL swapCount = 0, compCount = 0;
	double timePassed;

	int minIndex(int ar[], int loc, int len){
		for(int i = loc + 1; i < len ; i++){
			if(ar[loc] > ar[i]){
				loc = i;
			}
			
			compCount++;
		}
		return loc;
	}

	void selectoinSort(int ar[], int len){
		clock_t start = clock();

		for(int i = 0; i < len - 1; i++){
			int minLoc = minIndex(ar, i, len);

			if(minLoc != i){
				swap(&ar[i] , &ar[minLoc]);
				swapCount++;
			}
		}
		
		timePassed = (double)(clock() - start) / CLOCKS_PER_SEC ;
	}

}

int main(){
	
	int ar[100000], ar1[100000], ar2[100000];
	
	srand(time(0));

	int len = 1000, range = 50'000; // the array size

	for(int i=0; i<len; i++)       // generating the array
		ar[i] = ar1[i] = ar2[i] = (rand() % range) + 1 ;

	_bubble_sort:: bubbleSort(ar, len);
	_insertion_sort:: insertionSort(ar1, len);
	_selection_sort:: selectoinSort(ar2, len);

	printf("time:\n");
	printf("Bubble sort   : %.3lf\n", _bubble_sort::timePassed);
	printf("insertion sort: %.3lf\n", _insertion_sort::timePassed);
	printf("selection sort: %.3lf\n", _selection_sort::timePassed);
	printf("\n");
	
	printf("swap:\n");
	printf("Bubble sort   : %I64d\n", _bubble_sort::swapCount);
	printf("insertion sort: %I64d\n", _insertion_sort::swapCount);
	printf("selection sort: %I64d\n", _selection_sort::swapCount);
	printf("\n");
	
	printf("comparisions:\n");
	printf("Bubble sort   : %I64d\n", _bubble_sort::compCount);
	printf("insertion sort: %I64d\n", _insertion_sort::compCount);
	printf("selection sort: %I64d\n", _selection_sort::compCount);
	printf("\n");

	return 0;
}