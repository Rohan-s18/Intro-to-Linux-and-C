#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
struct Proc{
	int pid, ppid;
	char ruid [1024];
	char name [1024];
	unsigned long long int heap_loc, stack_loc;
};
void print_proc_1(struct Proc proc);
void print_proc_2(struct Proc* proc);
int main(){
	struct Proc p1 = {.pid=1234,.ppid=2345,.ruid="root",.heap_loc=0x4b209863,.stack_loc=0xF0F0F0F0,.name="lol"};	
	struct Proc p2 = {.pid=5678,.ppid=1234,.ruid="root",.heap_loc=0x5b209863,.stack_loc=0xD0F0F0F0,.name="lmao"};	
	print_proc_1(p1);
	print_proc_1(p2);
	print_proc_2(&p1);
	print_proc_2(&p2);
	return 0;
	return 0;
}
void print_proc_1(struct Proc proc){
	printf("Process Attributes: \nname:%s\npid:%d\nppid:%d\nruid:%s\nheap_loc:%llx\nstack_loc:%llx\n\n",proc.name,proc.pid,proc.ppid,proc.ruid,proc.heap_loc,proc.stack_loc);
}
void print_proc_2(struct Proc* proc){
	printf("Process Attributes: \nname:%s\npid:%d\nppid:%d\nruid:%s\nheap_loc:%llx\nstack_loc:%llx\n\n",proc->name,proc->pid,proc->ppid,proc->ruid,proc->heap_loc,proc->stack_loc);
}
