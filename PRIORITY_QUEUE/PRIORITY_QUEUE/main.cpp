/*
INSERT(S, x)
MAXIMUM(S)
EXTRACT-MAX(S)
INCREASE-KEY(S, x, k)
*/
#include <iostream>
#include <iomanip>
#include <assert.h>
using namespace std;


template <class T>
class PRIORITY_QUEUE{
public:
	PRIORITY_QUEUE(int maxSize = 20);
	void ENQUEUE(T* ele);
	void DEQUEUE(T* ele);
	void HEAPIFY(T* array, const int length, int i);
	inline T* TOP();
	void  PRINT();
private:
	inline int PARENT(int i);
	int m_pHeapSize;
	int m_pMaxSize;
	T* m_pHeap;
};

template <class T>
PRIORITY_QUEUE<T>::PRIORITY_QUEUE(int maxSize):
m_pHeapSize(0), m_pMaxSize(maxSize){
	m_pHeap = new T[maxSize];
}

template <class T>
void PRIORITY_QUEUE<T>::ENQUEUE(T *ele){
	if(m_pHeapSize + 1 > m_pMaxSize){
		T* oldHeap = m_pHeap;
		m_pHeap = new T[m_pMaxSize * 2];
		for(int i = 0; i< m_pHeapSize; ++i)
			m_pHeap[i] = oldHeap[i];
		delete oldHeap;
		oldHeap = NULL;
	}
	m_pHeap[m_pHeapSize] = *ele;
	int curIndex = m_pHeapSize;
	int parIndex = PARENT(m_pHeapSize);
	++m_pHeapSize;
	while(parIndex >= 0 && m_pHeap[curIndex] > m_pHeap[parIndex]){
		swap(m_pHeap[curIndex], m_pHeap[parIndex]);
		curIndex = parIndex;
		parIndex = PARENT(curIndex);
	}
}

template <class T>
void PRIORITY_QUEUE<T>::HEAPIFY(T* array, const int length, int i){
	if( i < length )
	{
		int extre_ele_index;
		extre_ele_index = i;
		if( i*2+1 < length )//×óº¢×Ó
		{		
			if( array[extre_ele_index] < array[ i*2+1 ] )
				extre_ele_index = i*2+1;
		
			if( array[extre_ele_index ] > array[ i*2+1 ] )
				extre_ele_index = i*2+1;
		}
		if( i*2+2 < length )//ÓÒº¢×Ó
		{	
			if( array[extre_ele_index] < array[ i*2+2 ] )
				extre_ele_index = i*2+2;
		
			if( array[extre_ele_index ] > array[ i*2+2 ] )
				extre_ele_index = i*2+2;
		}
		if( extre_ele_index != i )
		{
			T extre_ele; 
			extre_ele = array[i];
			array[i] = array[extre_ele_index];
			array[extre_ele_index] = extre_ele;
			HEAPIFY( array, length, extre_ele_index );
		}
	}
}

template <class T>
void PRIORITY_QUEUE<T>::DEQUEUE(T *ele){
	m_pHeap[0] = m_pHeap[m_pHeapSize - 1];
	--m_pHeapSize;
	HEAPIFY(m_pHeap,m_pHeapSize,0);
}

template <class T>
T* PRIORITY_QUEUE<T>::TOP(){
	return &m_pHeap[0];
}

template <class T>
int PRIORITY_QUEUE<T>::PARENT(int i){
	return i%2 ? (i - 2)/2 : (i - 1) / 2;
}
template <class T>
void PRIORITY_QUEUE<T>::PRINT(){
	for( int i = 0; i < m_pHeapSize; ++i ){
		if( 2*i+1 < m_pHeapSize )
			assert( m_pHeap[i] > m_pHeap[2*i+1] );
		if(2*i+2 < m_pHeapSize )
			assert( m_pHeap[i] > m_pHeap[2*i+2] );
	}
}

int main(){
	const int length = 10;
	int array2[length] = {15, 13, 9, 5, 12, 8, 7, 4, 0, 6,  };
	int *array = new int[length];
	int array_length=0;
	//	Priority_Queue<int> priority_queue(20, Maximum_Priority_Queue);
	PRIORITY_QUEUE<int> priority_queue;
	for( int i = 0; i < length; ++i )
		priority_queue.ENQUEUE( &array2[i] );
	priority_queue.PRINT();
	//return 1;
}
