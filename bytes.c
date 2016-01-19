#include <stdlib.h>
#include <stdio.h>

int main( int argc, char* argv[] )
{
	int i,j;
	for( i=1; i<argc; i++ )
	{
        union { unsigned long ival; unsigned char bytes[sizeof(long)]; } val;
		val.ival = strtoul( argv[i], NULL, 10 );
        printf( "Value: dec(%10lu) hex(0x%0*lx) "
				" bytes( "
              , val.ival, (int)(sizeof(long)*2), val.ival );
        for( j=0; j<sizeof(long); j++ )
        {
            printf( "x%02x ", val.bytes[j] );
        }
        printf( ")\n" );
    }
	return 0;
}


