import java.io.*;
public class CC
{ 
 public static void main( String a[] ) throws Exception
 {
   BufferedReader br= 
   new BufferedReader( 
   new InputStreamReader( System.in )
   );
   
   int i,shift;
   
System.out.println("Enter shift:");
shift= Integer.parseInt( br.readLine() );

System.out.println("Enter message:");    
String Message= br.readLine();

int[] M={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};// Treating message as number array
//Convert into integer array (assuming all 
//lowercase characters.)
for( i=0; i< Message.length(); i++ )
{ 
 M[i]= (int) Message.charAt(i)-97;
}


//Encryption
for( i=0; i< Message.length(); i++ )
{ M[i]= ( M[i]+shift )%26 +97; }


   //2.1.Convert back:
   char[] _M={'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'};
   for( i=0; i<Message.length(); i++ )
   { _M[i]= (char)M[i]; }
   //2.2.Print result: 
   System.out.println("Encryption:\n");
   for( i=0; i<Message.length(); i++ )
   { System.out.println( _M[i] ); }


//Decryption
for( i=0; i< Message.length(); i++ )
{ M[i]= ( M[i]-97-shift )%26 + 97; }


   //3.1. Convert back:
   for( i=0; i<Message.length(); i++ )
   { _M[i]= (char)M[i]; }
   //3.2.Print result: 
   System.out.println("Decryption:\n"); 
   for( i=0; i<Message.length(); i++ )
   { System.out.println( _M[i] ); }


   
 }
}




