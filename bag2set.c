/* bag2set.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynArray.h"


void sort(struct DynArr* da, int n){
	int i, j;
	for (i = 0; i < n-1; i++){
			for (j = 0; j < n-i-1; j++){
				if (students[j].initials[0] == students[j+1].initials[0]) {
					if (students[j].initials[1] > students[j+1].initials[1]){
						swap(&students[j], &students[j+1]);
					}
				}
				else if (students[j].initials[0] > students[j+1].initials[0]){
					swap(&students[j], &students[j+1]);
				}
			}
		}
}

/* Converts the input bag into a set using dynamic arrays
	param: 	da -- pointer to a bag
	return value: void
        result: after exiting the function da points to a set
*/
void bag2set(struct DynArr *da)/* FIXME: You will write this function */
{
	sort(da,da->size);

}



/* An example how to test your bag2set() */
int main(int argc, char* argv[]){

	int i;
        struct DynArr da;  /* bag */

        initDynArr(&da, 100);
        da.size = 10;
        da.data[0] = 1.3;
	for (i=1;i<da.size;i++){
	    da.data[i] = 1.2;
	 }

        printf("Bag:\n\n");
	for (i=0;i<da.size;i++){
          printf("%g  \n", da.data[i]);
        }

        printf("\n\n\n");
        printf("Set:\n\n");
        bag2set(&da);
	for (i=0;i<da.size;i++){
          printf("%g ", da.data[i]);
        }
        printf("\n");

	return 0;
}
