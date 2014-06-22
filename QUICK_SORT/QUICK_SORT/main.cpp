/*
QUICKSORT(A, p, r)
1.		if p < r
2.			q = PARTITION(A, p, r)
3.			QUICKSORT(A, p, q - 1)
4.			QUICKSORT(A, q + 1, r)
*/

/*
PARTITION(A, p, r)
1.		x = A[r]
2.		i = p - 1;
3.		for j = p to r - 1
4.			if A[j] <= x
5.				i = i + 1
6.				exchange A[i] with A[j]
7.		exchange A[i + 1] with A[r]
8.		return i + 1
*/
#include <iostream>
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

template <typename T>
void QUICKSORT(T* array, int p, int r){
	if(p < r){
		int q = PARTITION(array, p, r);
		QUICKSORT(array, p, q - 1);
		QUICKSORT(array, q + 1, r);
	}
}

int main(){
	int A[] = {9,8,7,6,5,4,3,2,1};
	int count = sizeof(A) / sizeof(int);
	QUICKSORT(A, 0, count - 1);
	for(int i = 0; i< count; ++i)
		cout<<A[i]<<" ";
	cout<<endl;
	return 1;
}