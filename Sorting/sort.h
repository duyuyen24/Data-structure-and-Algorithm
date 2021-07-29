#ifndef SORT_H
#define SORT_H
#include<stdio.h>
#include<cstdlib>
void printArr(int *arr, int n){
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void bubbleS(int *a, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[j] > a[j+1]){
				swap(a[j], a[j+1]);
			}
		}
	}
}

void selectionS(int *a, int n){
	int min = 0;
	for(int i = 0; i < n; i++){
		min = i;
		for(int j = i+1; j < n; j++){
			if(a[min] > a[j]){
				swap(a[min], a[j]);
			}
		}
	}
}

void insertionS(int *a, int n){
	int k = 0, j = 0;
	for(int i = 0; i < n; i++){
		k = a[i+1];
		j = i;
		while(j >= 0 && a[j] > k){
			swap(a[j+1], a[j]);
			j--;
		}
	}
}

void merge(int *a, int low, int mid, int high){
	int helper[high+1];
	for(int i = low; i <= high; i++){
		helper[i] = a[i];
	}

	int helpLeft = low;
	int helpRight = mid + 1;
	int cur = low;

	while (helpLeft <= mid && helpRight <= high) {
		if(helper[helpLeft] <= helper[helpRight]){
			a[cur] = helper[helpLeft];
			helpLeft++;
		}else{
			a[cur] = helper[helpRight];
			helpRight++;
		}
		cur++;
	}
	int size = mid - helpLeft;
	for(int i = 0; i <= size; i++){
		a[cur + i] = helper[helpLeft + i];
	}
}

void mergeS(int *a, int low, int high){
	if(low < high){
		int mid = (low + high)/2;
		mergeS(a, low, mid);
		mergeS(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}

int partitionMid(int *a, int left, int right){
	int pivot = a[(left + right)/2]; //3
	while (left <= right) {
		while (a[left] < pivot) {
			left++;//1
		}
		while (a[right] > pivot) {
			right--;
		}
		if(left <= right){
			swap(a[left], a[right]);
			left++;
			right--;
		}
	}
	return left;
}

void quickSMid(int *a, int left, int right){
	int index = partitionMid(a, left, right);
	printf("%d\n", index);
	if(left < index - 1){
		quickSMid(a, left, index - 1);
	}
	if(index < right){
		quickSMid(a, index, right);
	}
}


int partitionHigh(int a[], int low, int high){
	int pivot, index;
	index = low;
	pivot = high;

	for(int i = low; i < high; i++)
	{
		if(a[i] < a[pivot])
		{
			swap(a[i], a[index]);// 1 ben nho hon pivot
			index++;
		}
	}
	swap(a[pivot], a[index]);// ben con lai lon hon pivot

	return index;
}

int partitionLow(int *a,int low,int high){
	int pivot = a[low];
	int index = low+1;

	for(int i= low+1;i <= high; i++)
	{
		if(a[i] < pivot)
		{
			swap(a[index], a[i]);
			index++;
		}
	}
	swap(a[low], a[index-1]);
	return index-1;
}


void quickS(int arr[], int low, int high){
	if (low < high)
	{
		int pi = partitionLow(arr, low, high);
		quickS(arr, low, pi - 1);
		quickS(arr, pi + 1, high);
	}
}
#endif // SORT_H
