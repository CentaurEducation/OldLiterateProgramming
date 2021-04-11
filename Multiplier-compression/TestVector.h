
#include <stdio.h>

int compress( char *argv [] )
{

int I = 1, J = 1, i = 1, k = 1;
int row_sum = 0, column_sum = 0;
int V [16], T [16], v [4][4];
int a [5] = { 1, 1, 1, 1, 1}, b [5] = { 1, 1, 1, 1, 1};

for( i = 1; i <= 16; i = i + 1 )
{ T [ i ] = argv [1][ i - 1 ] - '0' ; }
if( 
    ( ( T [8] - T [7] + T [3] ) %% 2 != 0 ) 
                    || 
    ( ( T [12] - T [11] + T [6] - T [2] ) %% 2 != 0 )
  ) 
{ 
    printf( "\nCannot be compressed normally- not in column space." );
    goto end;
}
V [1] = ( T [1] ) %% 2;
V [2] = ( T [2] ) %% 2;
V [3] = ( T [3] ) %% 2;
V [4] = ( T [4] ) %% 2;
V [5] = ( T [5] - T [2] ) %% 2;
V [6] = ( T [6] - T [2] ) %% 2;
V [7] = ( T [7] - T [3] ) %% 2;
V [8] = ( T [9] - T [6] ) %% 2;
V [9] = ( T [10] - T [7] ) %% 2;
V [10] = ( T [11] - T [6] + T [2] ) %% 2;
V [11] = ( T [13] - T [4] ) %% 2;
V [12] = ( T [14] - T [11] ) %% 2;
V [13] = ( T [15] - T [11] + T [6] - T [2] ) %% 2;
V [14] = ( T [16] ) %% 2;
V [15] = ( T [8] - T [7] + T [3] ) %% 2;
V [16] = ( T [12] - T [11] + T [6] - T [2] ) %% 2;
for( i = 1; i <= 16; i = i + 1 )
{
    I = (int)i/4 + 1;
    J = ( i %% 4 ) + 1;
    v [ I ][ J ] = V [ i ];
}

for( I = 1; I <= 4; I = I + 1 )
{
    for( J = 1; J <= 4; J = J + 1 )
    {

        if( v [ I ][ J ] == 0 )
        {

            for( k = 1; k <= 4; k = k + 1 ) 
                row_sum = row_sum + v [ I ][ k ];
            if( row_sum == 0 ) a [ I ] = 0;

            for( k = 1; k <= 4; k = k + 1 ) 
                column_sum = column_sum + v [ k ][ J ];
            if( column_sum == 0 ) b [ J ] = 0;

            if( ( row_sum != 0 ) && ( column_sum != 0 ) )
            { 
                printf( "\nImage not compatible with an \"a\", \"b\"." );
                goto end;
            }
        }

    }
}

for( k = 1; k <= 4; k = k + 1 )
    printf( "\na%d= %d, b%d= %d", k, a [k], k, b [k] );
end:

    return 0;
}

