#include <stdio.h>
#include "stack.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define LEN 200


int main() {
	stack mystack;
	initStack(&mystack, N);
	char line[LEN];

	fprintf(stderr, "Please enter 'nf', when you want to do Nuclear Fusion.\n");

		while(1){
			fgets(line, LEN, stdin);
			double data = atof(line);
			if(strcmp(line, "nf\n") == 0){

				fusion myFusion;
				myFusion = input();
				output(fusionEne(myFusion), conversion(fusionEne(myFusion)), sv(myFusion));
			}else if(strcmp(line, "ALICE\n") == 0){

				//ALICE();

			}else if(strcmp(line, "-\n") == 0){

				subStack(&mystack);

			}else if(strcmp(line, "+\n") == 0){
			
				addStack(&mystack);
		
			}else if(strcmp(line, "*\n") == 0){
			
				mulStack(&mystack);
		
			}else if(strcmp(line, "/\n") == 0){
		
				divStack(&mystack);
		
			}else if(strcmp(line, "d\n") == 0){
		
				pull(&mystack);
		
			}else if(strcmp(line, "e\n") == 0){
		
				break;
		
			}else {
		
				push(&mystack, data);

			}

			printStack(&mystack);
			}
  		
	

}