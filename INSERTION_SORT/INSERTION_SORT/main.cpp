/*
INSERTION-SORT
1. for j = 2 to A.length
2.		key = A[j];
3.		//Insert A[j] into the sorted sequence A[1 ... j - 1]
4.		i = j - 1
5.		while i > 0 and A[i] > key
6.			A[i + 1] = A[i]
7.			i = i - 1
8.		A[i + 1] = key
*/

#include <cstdlib>
#include <cstring>
#include <iostream>

template <typename T>
void InsertionSort(T* array, const size_t count){
	T temp;
	for(size_t i = 1,j ; i < count; ++i){
		for(j = i, temp = array[j]; (j > 0) && (array[j - 1] > temp); --j)
			array[j] = array[j - 1];
		array[j] = temp;
	}
}
template <typename T>
void InsertSort(T* array, const size_t count)  
{  
	for (size_t i = 1; i < count; i++){  
		T j = i - 1;  
		T temp = array[i];									//��¼Ҫ���������  
		while (j >= 0 && array[j] > temp){		//�Ӻ���ǰ���ҵ�����С������λ��    
			array[j+1] = array[j];							//���Ų��  
			j--;  
		}  
		array[j+1] = temp;  
	}  
}

int main(){
	int array[] = {9,58,7,46,5,34,23,32,11};
	//InsertionSort(array, sizeof(array)/sizeof(int));
	InsertSort(array,sizeof(array)/sizeof(int));

	for(size_t i = 0; i < (sizeof(array)/sizeof(int)); ++i)
		std::cout<< array[i]<<" ";

	return 1;
}
