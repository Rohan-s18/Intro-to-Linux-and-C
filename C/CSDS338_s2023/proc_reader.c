#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	FILE* r_ptr;
	r_ptr = fopen("/proc/self/maps","r");
	if(!r_ptr) return -1;
	char buff[2048];
	unsigned long long int high, low, prev_high, size, gap;
	prev_high = 0;
	while(fgets(buff,2048,r_ptr)!=NULL){
		sscanf(buff,"%llx-%llx",&low,&high);
		size = high-low;
		gap = low - prev_high;
		prev_high = high;
		fprintf(stdout,"Size of Segment: %llu\nGap between Segments: %llu\n\n",size,gap);
	}
	return 0;
}
