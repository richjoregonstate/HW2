/* bag2set.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynArray.h"


void sort(struct DynArr *da, int n){
     int i,j;
		 double tmp;
     for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
          if (da->data[j] > da->data[j+1]) {
              tmp = da->data[j];
              da->data[j] = da->data[j+1];
              da->data[j+1] = tmp;
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
	int i = 0;
	sort(da,da->size);
	i = 0;
	while(i < da->size-1) {
		if (da->data[i] == da->data[i+1]) {
			removeAtDynArr(da,i);
			i--;
		}
		i++;
	}
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
          printf("%g  ", da.data[i]);
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
