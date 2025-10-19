#include <stdio.h>

int a = 4;
int b;
char buf[] = "C is love";
char buf2[] = "Hello";
const char *cp1 = buf;
char *const cp2 = buf;

int main(){
    
    const int c = 12;
    int d;
    int e = 0;
    int v[] = {1, 2, 3};

    //cp1[0] = 'D';
    cp1 = buf2;

    cp2[0] = 'D';
    //cp2 = buf2;

    printf("%s\n", cp1);
    printf("%s\n", cp2);    

    sleep(100);

}
