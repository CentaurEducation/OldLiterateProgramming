#include<stdio.h>//stdio
int main()
{

int N, a, b, c;
printf( "Enter the size of the bitstring:" );
scanf( "%d", &N );

for( a= 1; a<=N-3; a++ )
{ 
/*b+c+d= N-a.*/
for( b= 1; b<=N-a-2; b++ )
{
/*c+d= N-a-b.*/
for( c= 1; c<=N-a-b-1; c++ )
{

printf( "\n(%d,%d,%d,%d)", a, b, c, N-a-b-c );

}}}

int count=0;
for( a= 1; a<=N-3; a++ )
{ 
/*b+c+d= N-a.*/
for( b= 1; b<=N-a-2; b++ )
{
/*c+d= N-a-b.*/
for( c= 1; c<=N-a-b-1; c++ )
{

count++;

}}}
printf( "\n\nNumber of solutions: %d", count );

return 0;
}
