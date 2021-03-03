#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    double d = 0;
    int cnt = 1;
    union {
        double d;
        unsigned long l;
    } u;
    if (argc > 1) {
        d = atof(argv[1]);
    }
    if (argc > 2) {
        cnt = atoi(argv[2]);
    }
    printf("START  : %0.10lf\n", d);
    u.d = d;
    for(int i = 0; i<cnt; i++) {
        ++ u.l;
        printf("NEXT-%02d: %0.10lf\n", i+1, u.d);
    }
    return 0;
}
