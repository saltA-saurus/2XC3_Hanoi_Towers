#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int peg1[9], peg2[9], peg3[9];

void display_pegs(){

	int i, j;
	for(i = 8; i >= 0; i--){
		for(j = peg1[i]; j < 10; j++){
			printf(" ");
		}
		for(j = 0; j < peg1[i]; j++){
			printf("+");
		}
		printf("|");
		for(j = 0; j < peg1[i]; j++){
			printf("+");
		}
		for(j = peg1[i]; j < 10; j++){
			printf(" ");
		}
		printf("  "); /*end of peg1*/
		for(j = peg2[i]; j < 10; j++){
			printf(" ");
		}
		for(j = 0; j < peg2[i]; j++){
			printf("+");
		}
		printf("|");
		for(j = 0; j < peg2[i]; j++){
			printf("+");
		}
		for(j = peg2[i]; j < 10; j++){
			printf(" ");
		}
		printf("  ");/*end of peg 2*/
		for(j = peg3[i]; j < 10; j++){
			printf(" ");
		}
		for(j = 0; j < peg3[i]; j++){
			printf("+");
		}
		printf("|");
		for(j = 0; j < peg3[i]; j++){
			printf("+");
		}
		printf("\n");
	}
	for (i = 0; i < 3; i++){
		printf("XXXXXXXXXXXXXXXXXXXXX  ");
	}
	printf("\n\n");
	
}

void move(int pegA[9], int pegB[9]){
	int i, d;
	/* find the top disk of pegA */
	for(i = 8; pegA[i] == 0; i--){
	}
	d = pegA[i];
	pegA[i] = 0;
	/* find the top of pegB */
	for(i = 0; pegB[i] != 0; i++){
	}
	pegB[i] = d;
	
	display_pegs();
	
	sleep(1);
}

void hantow(int nod, int pego[9], int pegd[9], int pegh[9]){
	if(nod > 1){
		hantow(nod-1, pego, pegh, pegd);
	}
	move(pego, pegd);
	if(nod > 1){
		hantow(nod-1, pegh, pegd, pego);
	}
}

void init(int nod){
	int i;
	for(i = 0; i < nod; i++){
		peg1[i] = nod-i;
	}
}

int main(int argc, char* argv[]){
	int i;
	if(argc != 2){
		printf("Too many command line arguments");
		return 0;
	}

	if(strlen(argv[1]) != 1){
		printf("Incorrect arguments");
		return 0;
	}
	if(argv[1][0] < '1' || argv[1][0] > '9'){
		printf("Enter a number between 1 and 9");
		return 0;
	}
	int num_of_disks = argv[1][0]-'0';
	
	init(num_of_disks);
	display_pegs();
	hantow(num_of_disks, peg1, peg2, peg3);
	printf("done");
	printf("\n");
	return 0;
}

