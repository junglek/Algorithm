/*Uncle T
MERGE(A, p, q, r)
1. n1 = q - p + 1
2. n2 = r - q
3. Let L[1 . . n1 + 1] and R[1 . . n2 + 1] be new arrays
4. for i = 1 to n1
5.		L[i] = A[p + i - 1]
6. for j = 1 to n2
7. 		R[j] = A[q + j]
8. L[n1 + 1] = ¡Þ
9. R[n2 + 1] = ¡Þ
10. i = 1
11. j = 1
12. for k = p to r
13. 	if L[i] <= R[j]
14. 		A[k] = L[i]
15. 		i = i + 1
16. 	else A[k] = R[j]
17. 		j = j + 1
*/
#include <iostream>
#include <vector>

const float MAX = 10e5;
template <typename T>
void MERGE(T* array, int start, int mid, int end){
	std::vector<T> L;
	std::vector<T> R;
	int n1 = mid - start + 1;
	int n2 =end - mid;
	for(int i = 0; i < n1; ++i)
		L.push_back(array[start + i]);
	for(int j = 0; j < n2; ++j)
		R.push_back(array[mid + j + 1]);
	L.push_back(static_cast<T>(MAX));
	R.push_back(static_cast<T>(MAX));

	for(int k = start, i = 0, j = 0; k <= end; ++k){
		if(L[i] <= R[j]){
			array[k] = L[i];
			i++;
		}else{
			array[k] = R[j];
			j++;
		}
	}
}
template <typename T>
void MERGE_SORT(T* array, int start, int end){
	if(start < end){
		int mid;
		mid = (end + start) / 2;
		MERGE_SORT(array, start,mid);
		MERGE_SORT(array,mid+1,end);
		MERGE(array,start,mid,end);
	}
}

int main(){
	int array[] = {11,22,34,43,5,6,7,8,9};
	MERGE_SORT(array, 0,8);
	for(int i = 0; i<9; ++i)
		std::cout<< array[i]<<" ";

	return 1;
}