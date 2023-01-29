//  Author: Rohan Singh
//  Jan 28, 2023
//  Demonstration of a LinkedList to print the statistics of the virtual address space of a process 

//  Imports
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//  Struct to hold the Memory Segment information
struct Segment_info{
	//Segment data
	unsigned long long int low;
	unsigned long long int high;
	unsigned long long int size;
	unsigned long long int gap;
	unsigned long long int num_blocks;

	//Struct pointer to the next segment info, this is how you make linked lists in C
	struct Segment_info* next;
};

//  Method header for the method to print all the memory segments 	
void print_all_lines(struct Segment_info* procs, int num_lines);

//  Method header to print a single segment 
void print_procinfo(struct Segment_info* proc_line);
int main(){
	FILE* f;
	f = fopen("/proc/self/maps","r");
	if(!f){
		return -1;
		printf("Couldn't Open File");
	}
	struct Segment_info* procs;
	procs = malloc(sizeof(struct Segment_info));
	unsigned long long int seg_high, seg_low, seg_size, seg_gap,seg_num_blocks, seg_prev_high;
	char buff [2048];
	int ct = 0;
	struct Segment_info* first;
	first = procs;
	seg_prev_high = 0;
	while((fgets(buff,2048,f))!=NULL){
		sscanf(buff,"%llx-%llx",&seg_low,&seg_high);
		seg_size=seg_high-seg_low;
		seg_gap=seg_low-seg_prev_high;
		seg_prev_high=seg_high;
		seg_num_blocks=seg_size/4096;
		struct Segment_info line = {.low=seg_low,.high=seg_high,.gap=seg_gap,.size=seg_size,.num_blocks=seg_num_blocks};
		procs->next=&line;
		procs=procs->next;
		ct++;
		print_procinfo(&line);
	}
	int n = (sizeof(procs))/(sizeof(struct Segment_info));
	print_all_lines(first,n);
	return 0;
}
void print_all_lines(struct Segment_info* segs, int n){
	for(int i = 0; i < n; i++)print_procinfo(segs+i);
}
void print_procinfo(struct Segment_info* seg){
	printf("Segment low: %llu\tSegment high: %llu\tSegment size: %llu\tSegment gap: %llu\t Segment blocks:%llu\n",seg->low,seg->high,seg->size,seg->gap,seg->num_blocks);
}

