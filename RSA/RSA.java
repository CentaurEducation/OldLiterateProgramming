import java.io.*;

public class RSA
{
  
public static int gcd( int A, int B )
{
if( A%B==0 ) return B;
else return gcd( B, A%B);
}

public static void main( String A[] ) throws IOException
{

BufferedReader br= 
new BufferedReader( 
new InputStreamReader( System.in )
);

int p= 
Integer.parseInt( br.readLine() );
int q=
Integer.parseInt( br.readLine() );
int n= p*q;

int phi_n= (p-1)*(q-1);

//To find 'e':
int e=1 /*Initialise to random value*/, 
i /*Index for searching 2,...,phi_n*/, 
m, N, r=1 /*Temporary variables*/; 

for( i=2; i< phi_n; i++ )
{ 
  if( gcd( i,phi_n )==1 )
  { e= i;}
}  

//Search for d such that ed%phi_n is unity
int d=1;
for( i=0; i< phi_n; i++ )
{ if( (i*e)%phi_n ==1 ) 
  { d= i;
    break; }
}   


double c= 
Math.pow( M,e ) %n;

System.out.println( 
"Encrypted text is:" + c 
);


double dec=
Math.pow( c,d ) %n;
System.out.println(
"Decrypted text is:" + dec
);


}

}
