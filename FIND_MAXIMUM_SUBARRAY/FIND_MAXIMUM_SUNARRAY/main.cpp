/*
FIND-MAX-CROSSING-SUNARRAY(A, low, mid, high)
1.	left-sum = -∞	//已经找到的最大和
2.	sum = 0		//i to mid 所有值的和
3.	for i = mid downto low
4.		sum = sum + A[i]
5.		if sum > left-sum
6.			left-sum = sum
7.			max-left = i
8.	right-sum = -∞
9.	sum = 0
10.for j = mid + 1 to high
11.	sum = sum + A[j]
12.	if sum > right-sum
13.		right-sum = sum
14.		max-right = j
15.return (max-left, max-right, left-sum + right-sum)
*/

/*
FIND-MAXIMUM-SUNARRAY(A, low, high)
1.		if high == low
2.			return (low, high, A[low])
3.		else mid = floor((low + high) / 2)
4.			(left-low, left-high, left-sum) = FIND-MAXIMUM-SUBARRAY(A, low, mid)
5.			(right-low, right-high, right-sum) = FIND-MAXIMUM-SUBARRAY(A, mid + 1, high)
6.			(cross-low, cross-high, cross-sum) = FIND-MAX-CROSSING-SUNARRAY(A, low, mid, high)
7.			if left-sum >= right-sum and left-sum >= cross-sum
8.				return (left-low, left-high, left-sum)
9.			else if right-sum >= left-sum and right-sum >= cross-sum
10.			return (right-low, right-high, right-sum)
11.		else return (cross-low, cross-high, cross-sum)
*/

#include <iostream>

using namespace std;
const float MAX = 10e3;

template <typename T>
T FIND_MAX_CROSSING_SUBARRAY(T* array, int low, int mid, int high, int& max_left, int& max_right){
	T left_sum = static_cast<T>(-MAX);
	T right_sum = static_cast<T>(-MAX);
	T sum = 0;
	for(int i = mid; i >= low; --i){
		sum += array[i];
		if(sum > left_sum){
			left_sum = sum;
			max_left = i;
		}
	}
	sum = 0;				//very fucking important!!!!!!!!!!
	for(int j = mid+1; j <= high; ++j){
		sum += array[j];
		if(sum > right_sum){
			right_sum = sum;
			max_right = j;
		}
	}

	return (left_sum + right_sum);
}

template <typename T>
T FIND_MAXIMUM_SUBARRAY(T* array, int low, int high, int& max_left, int& max_right){
	if(high == low){
		max_left = low;
		max_right = high;
		return array[low];
	}else{
		int mid = (low + high)/2;
		int left_low, left_high;
		T left_sum;
		left_sum = FIND_MAXIMUM_SUBARRAY(array, low, mid,left_low, left_high);

		int right_low, right_high;
		T right_sum;
		right_sum = FIND_MAXIMUM_SUBARRAY(array, mid + 1, high,right_low, right_high);

		int cross_low, cross_high;
		T cross_sum;
		cross_sum = FIND_MAX_CROSSING_SUBARRAY(array, low, mid, high, cross_low, cross_high);

		if(left_sum >= right_sum && left_sum >= cross_sum){
			max_left = left_low;
			max_right = left_high;
			return left_sum;
		}else if(right_sum >= left_sum && right_sum >= cross_sum){
			max_left = right_low;
			max_right = right_high;
			return right_sum;
		}else{
			max_left = cross_low;
			max_right = cross_high;
			return cross_sum;
		}
	}
}

int main(){
	int A[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	int count = sizeof(A)/sizeof(int);
	int low , high, sum;

	sum = FIND_MAXIMUM_SUBARRAY(A, 0,count- 1,low, high);
	
	cout<<"sum = "<<sum<<endl;
	cout<<"low = "<<low<<endl;
	cout<<"high = "<<high<<endl;

	return 1;
}