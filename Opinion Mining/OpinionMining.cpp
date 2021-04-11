#include<stdio.h>
#include<string.h>
#include<ctype.h>


int main( int argc, char *argv [] )
{

FILE *Adj_file = fopen ( argv [2], "r" );
char c, temp [1000], adj [1000], T [1000] ;
int i, j, word_no, word_count ;

char word_list [1000][1000];
FILE *F = fopen( argv[1], "r");
word_no = 0;

while( ! feof( F ) )
{

fscanf( F, "%s", &word_list[ word_no ] );
word_no = word_no + 1;

c = word_list[ word_no - 1 ][ strlen( word_list [ word_no - 1 ] ) - 1 ];
if( ispunct( c ) ) 
word_list[ word_no - 1 ][ strlen( word_list [ word_no - 1 ] ) - 1 ] = '\0' ;

}

word_count = word_no;

i = 1;
while( i < word_count )
{
j = i;

while( (j > 0) && (word_list [ j - 1 ] > word_list [ j ]) )
{
/*Swap:*/
strcpy( temp, word_list [ j ]);
strcpy( word_list [ j ], word_list [ j - 1 ]);
strcpy( word_list [ j - 1 ], temp);
j = j - 1;
}

i = i + 1;
}

for( word_no = 0; word_no < word_count ; word_no = word_no + 1 )
{

strcpy ( T, word_list [ word_no ] );

/*Linear Search:*/
fscanf ( Adj_file, "%s", &adj ); 

while( !feof ( Adj_file ) )
{
if( strcmp ( adj, T ) == 0 ) printf ( "\n%s", adj );
fscanf ( Adj_file, "%s", &adj ); 
}

/*Start again at top of file.*/
fseek ( Adj_file, 0, SEEK_SET );

}


End:
return 0;
}
