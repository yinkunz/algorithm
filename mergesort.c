/*
 * 
 * @copyright Yinkun
 * @Date 2018-8-24
 * @Merge Sort example
 *  
 * 
 */
  
#include <stdio.h>

void merge(int arr2[], int len, int arrLeft[], int arrRight[]){
	int i,j,k = 0;
	for (i = 0, j = 0; i < len/2 && j < len - len/2; ){
		if(arrLeft[i] > arrRight[j]){
			arr2[k++] = arrRight[j++];
		} else {
			arr2[k++] = arrLeft[i++];
		} 
	}
	if(i < len/2) {
		for(; i< len/2; i++){
			arr2[k++] = arrLeft[i];
		}
	}
	if(j < len - len/2){
		for(; j < len - len/2; j ++){
			arr2[k++] = arrRight[j];
		}
	}
}

void msort(int arr[], int start, int end, int arr2[]){
	printf("start:%d;end:%d\n", start, end);
	if( end - start == 1) { 
		if (arr[start] > arr[end-1]){
			arr2[0] = arr[end-1];
			arr2[1] = arr[start];
		} else {
			arr2[0] = arr[start];
			arr2[1] = arr[end-1];
		}
	} else {
		int len = (end - start ) ;
		int arrLeft[len/2];
		int arrRight[len - len/2];
		for(int i=0; i<len/2; i++) arrLeft[i] = -1;
		for(int i=0; i<len - len/2; i++) arrRight[i] = -1;

		msort(arr, start, start + len/2, arrLeft);
		msort(arr, start + len/2, start + len, arrRight);
		
		merge(arr2, len, arrLeft, arrRight);
	}
}


int main(){

	int arr[] = {998877,23,24,121,1324,222,387,387,387,2,90,921,11,21,31,221,32,41,232};
	int len = sizeof(arr)/sizeof(arr[0]);
	int arrLeft[len/2];
	int arrRight[len-len/2];
	
	for(int i=0; i<len/2; i++) arrLeft[i] = -1;
	for(int i=0; i<len-len/2; i++) arrRight[i] = -1;
	
	printf("before:\n");
	for(int i=0; i<len; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	
	msort(arr, 0, len/2, arrLeft);
	msort(arr, len/2, len, arrRight);
	
	printf("after arrLeft:\n");
	for(int i=0; i<len/2; i++){
		printf("%d ",arrLeft[i]);
	}
	printf("\n");
	printf("after arrRight:\n");
	for(int i=0; i<len - len/2; i++){
		printf("%d ",arrRight[i]);
	}
	printf("\n");
	
	merge(arr, len, arrLeft, arrRight);
	printf("after:\n");
	for(int i=0; i<len; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	
	return 0;
}
