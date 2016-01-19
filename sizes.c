#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
//#include <unistd.h>
#include <wchar.h>
#include <time.h>

#define TMIN(typ) ((typ)(((typ)1) << ((sizeof(typ)*8)-1)))
#define TMAX(typ) ((typ)~TMIN(typ))

int main()
{
#ifdef __USE_GNU
    printf( "Using GNU!!!\n");
#else
    printf( "no GNU :(\n" );
#endif
    printf( "char  : %lu (S=%hhd...%hhd US=0...%hhu)\n"
            , sizeof(char), TMIN(char), TMAX(char), ~('\0') );
    printf( "char* : %lu\n", sizeof(char*) );
    printf( "short : %lu (S=%hd...%hd US=0...%hu)\n"
            , sizeof(short), TMIN(short), TMAX(short), ~(unsigned short)0 );
    printf( "int   : %lu (S=%d...%d US=0...%u)\n"
            , sizeof(int), TMIN(int), TMAX(int), ~(unsigned int)0 ); 
    printf( "long  : %lu (S=%ld...%ld US=0...%lu)\n"
            , sizeof(long), TMIN(long), TMAX(long), ~0L ); 
//    printf( "llong : %lu (S=%lld...%lld US=0...%llu)\n"
//            , sizeof(long long), TMIN(long long), TMAX(long long), ~0LL ); 
    printf( "float : %lu\n", sizeof(float) );
    printf( "doubl : %lu\n", sizeof(double) );
    printf( "void* : %lu\n", sizeof(void*) );
    printf( "time_t: %lu\n", sizeof(time_t) );
//    printf( "pid_t : %d\n", sizeof(pid_t) );
    printf( "size_t: %lu (US=0...%zu)\n"
            , sizeof(size_t), ~(size_t)0 );

    // Check endian stuff
    {
        union { int ival; unsigned char bytes[4]; } endian;
        endian.ival = 0x01020304;
        printf( "Endian: dec(%d) hex(0x%08x) bytes(x%02x x%02x x%02x x%02x)\n"
              , endian.ival, endian.ival
              , endian.bytes[0], endian.bytes[1]
              , endian.bytes[2], endian.bytes[3]
              );
    }
    return 0;
}
