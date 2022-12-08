#include <stdio.h>
#include <stdlib.h>

int main(){
	
	char *str;

	str = (char *) malloc(15);
	str =  "Lmao";
	fprintf(stderr,"String = %s, Address = %u\n", str,&str);

	str = (char *) realloc(str, 25);
	str = "Lmfao";
	fprintf(stderr,"String =%s, Address = %u\n",str,&str);

	free(str);
	

	return 0;

}
