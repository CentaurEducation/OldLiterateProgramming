
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main ( int argc , char *argv [] )
{

int i, j, t, word_no, word_count, noun_count, cutoff, repeated, freq [1000];
char c, noun [1000], T [1000], temp [1000], Nouns [1000][1000];

FILE *Noun_file = fopen ( argv [2], "r" );
char word_list [1000][1000];
FILE *F = fopen( argv[1], "r");
word_no = 0;

while( ! feof( F ) )
{

fscanf( F, "%s", &temp );

/*Remove punctuation at the end of the word.*/
c = temp [ strlen( temp ) - 1 ];
if( ispunct( c ) ) 
temp [ strlen( temp ) - 1 ] = '\0' ;

/*Record frequency of occurence.*/
repeated = 0;
for( i = 0; i <= word_no; i = i + 1 )
if( strcmp ( temp, word_list [ i ] ) == 0 )
{ freq [ i ] = freq [ i ] + 1; repeated = 1; }

if( repeated == 0 )
{ strcpy ( word_list [ word_no ], temp ); freq [ word_no ] = 1; 
word_no = word_no + 1; }

}
word_count = word_no;

i = 1;
while( i < word_count )
{
j = i;

while( (j > 0) && (freq [ j - 1 ] > freq [ j ]) )
{
/*Swap:*/
strcpy( temp, word_list [ j ]);
strcpy( word_list [ j ], word_list [ j - 1 ]);
strcpy( word_list [ j - 1 ], temp);
t = freq [ j ];
freq [ j ] = freq [ j - 1 ];
freq [ j - 1 ] = t ;

j = j - 1;
}

i = i + 1;
}
word_no = 0; i = 0;

for( word_no = 0; word_no < word_count ; word_no = word_no + 1 )
{

strcpy ( T, word_list [ word_no ] );

/*Linear Search:*/
fscanf ( Noun_file, "%s", &noun ); 

while( !feof ( Noun_file ) )
{
if( strcmp ( noun, T ) == 0 )
{ strcpy ( Nouns [ i ], T ); i = i + 1; }
fscanf ( Noun_file, "%s", &noun ); 
}

/*Start again at top of file.*/
fseek ( Noun_file, 0, SEEK_SET );

}

noun_count = i;

cutoff = atoi ( argv [3] ) /*Read integer valued argument- cutoff.*/ ;
for( j = 0; j <= (int)( cutoff * noun_count / 100); j = j + 1 )
printf ( "\n%s", Nouns [ noun_count - 1 - j ] );

return 0;
}
