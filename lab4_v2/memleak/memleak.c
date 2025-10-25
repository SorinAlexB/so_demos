#include <stdio.h>
#include <stdlib.h>

int *still_reach;
int *possibly_lost;

int main(void) {
    /* 1) Definitely lost */
    int *def_lost = malloc(5 * sizeof(int));
    def_lost[0] = 1;
    def_lost = NULL;

    /* 2) Still reachable */
    still_reach = malloc(10 * sizeof(int));
    still_reach[0] = 2;

    /* 3) Possibly lost */
    int *tmp = malloc(20 * sizeof(int));
    possibly_lost = tmp + 5;
    tmp = NULL;
    possibly_lost[0] = 5;
    
    return 0;
}
