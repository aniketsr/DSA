#include "mSort.h"
#include <memory.h>
#include <stdlib.h>

int merge(void** base, void** left, void** right, size_t lLength, size_t rLength, Compare compare){
	int i=0,j=0,k=0;
	int res;
	while(i < lLength && j < rLength){
		res = compare(left[i], right[j]);
        if(res)	base[k++] = left[i++];
        else	base[k++] = right[j++];
	}
	while( j < rLength)    base[k++] = right[j++];
	while(i < lLength)    base[k++] = left[i++];
	return 1;
}

void sort(void** base, int noOfElements, Compare compare){
	int i,j,lLength,rLength;
	int mid = noOfElements/2;
	void** right = calloc(mid+1,sizeof(void*));
	void** left = calloc(mid,sizeof(void*));

	if(noOfElements < 2) return;
	lLength = mid;
	rLength = noOfElements-mid;
	
	for(i=0;i<mid;i++)
        left[i] = base[i];
	for(i=mid;i<noOfElements;i++)
        right[i-mid] = base[i];
	
	sort(left,lLength,compare);
	sort(right,rLength,compare);
	merge(base, left, right, lLength, rLength, compare);
	free(left);
	free(right);
}