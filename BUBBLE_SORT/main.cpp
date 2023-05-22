
#include <stdio.h>

void BubbleSort(int arr[], int len) 
{
  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < len - i - 1; ++j) {
        if (arr[j] > arr[j+1]) {
	  int tmp;
	  tmp = arr[j+1];
	  arr[j+1] = arr[j];
	  arr[j] = tmp;
	}
    }
  }
}
