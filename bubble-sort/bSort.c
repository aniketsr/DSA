#include "bSort.h"
#include "stdlib.h"
#include "memory.h"

void bSort(void** base,int noOfElements, Compare compare){
	int i,j;
	void* temp;
	int compareResult;
	for (i = 1; i < noOfElements; i++){
		for (j = 0; j < noOfElements-i; j++){
			compareResult = compare(base[j],base[j+1]);
			if(compareResult > 0){
				temp = base[j];
				base[j] = base[j+1];
				base[j+1] = temp;				
			}
		}
	}

}