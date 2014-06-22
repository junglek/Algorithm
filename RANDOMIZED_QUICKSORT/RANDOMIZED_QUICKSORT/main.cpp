/*
RANDOMIZED-PARTITION(A, p, r)
1.		i = RANDOM(p ,r)
2.		exchange A[r] with A[i]
3.		return PARTITION(A, p ,r)
*/

/*
RANDOMIZED-QUICKSORT
1.		if p < r
2.			q = RANDOMIZED-PARTITION(A, p, r)
3.			RANDOMIZED-QUICKSORT(A, p, q - 1)
4.			RANDOMIZED-QUICKSORT(A, q + 1, r)
*/

#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
int PARTITION(T* array, int p, int r){
	T x = array[r];
	int i = p - 1;
	for(int j = p; j <= r - 1; ++j){
		if(array[j] <= x){
			++i;
			swap(array[i], array[j]);
		}
	}
	swap(array[i + 1], array[r]);

	return (i + 1);
}

int RANDOM(int m,int n)
{
	srand((unsigned)time(NULL));
	return m + (rand()%(n-m+1));
}

template <typename T>
int RANDOMIZED_PARTITION(T* array, int p, int r){
	int i = RANDOM(p, r);
	swap(array[r], array[i]);
	return PARTITION(array, p, r);
}

template <typename T>
void RANDOMIZED_QUICKSORT(T* array, int p, int r){
	if(p < r){
		int q = RANDOMIZED_PARTITION(array, p, r);
		RANDOMIZED_QUICKSORT(array, p, q - 1);
		RANDOMIZED_QUICKSORT(array, q + 1, r);
	}
}

int main(){
	int A[] = {9,8,7,6,5,4,3,2,1};
	int count = sizeof(A) / sizeof(int);
	RANDOMIZED_QUICKSORT(A, 0, count - 1);
	for(int i = 0; i< count; ++i)
		cout<<A[i]<<" ";
	cout<<endl;

	return 1;
}