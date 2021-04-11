import java.io.*;

public class HC
{
 public static void main( String[] A ) throws Exception, IOException
 {

  //Beginning:

  int i, det, Mul_inv= 0;
  String Message;
  char[] Cipher= new char[1000], Decrypt= new char[1000];
  int[] _C= new int[1000], _D= new int[1000], _M= new int[1000];
  int[][] Key= new int[2][2], Key_Inv= new int[2][2];


  BufferedReader br= new BufferedReader( new InputStreamReader( System.in ) );

  System.out.println( "Enter plaintext:" );
  Message= br.readLine();
  
  System.out.println( "Enter key matrix:" );
  Key[0][0]= Integer.parseInt(br.readLine());
  Key[0][1]= Integer.parseInt(br.readLine());
  Key[1][0]= Integer.parseInt(br.readLine());
  Key[1][1]= Integer.parseInt(br.readLine());
  
  /*Convert Message into integer array:*/
  for( i=0; i< Message.length(); i++ )
  {
   _M[i]= (int) Message.charAt(i)-97;
  }

//------------------------------------------------------------

  /*Encryption.
  Take two characters at a time. 
  Assume the plaintext has an even number of characters. */
  for( i=0; i<Message.length(); i+=2 )
  {
   _C[i]= ( Key[0][0]*_M[i] + Key[0][1]*_M[i+1] )%26;
   _C[i+1]= ( Key[1][0]*_M[i] + Key[1][1]*_M[i+1] )%26;
  }
 
  /*Convert number version into string of characters.*/
  for( i=0; i<Message.length(); i++ )
  { Cipher[i]= (char)(_C[i]+97); }	


  /*Print ciphertext.*/
  System.out.println( "\nCiphertext:" );
  for( i=0; i<Message.length(); i++ )
  { System.out.print( Cipher[i] ); }

//---------------------------------------------------------------

  /*Decryption.*/
    	
  /*Finding multiplicative inverse.*/
  /* Call this quantity (ad-bc) “det”. */
  det=                    Key[0][0]*Key[1][1]-Key[0][1]*Key[1][0]; 

  for( i=0; i<26; i++ )
  {
   if( (i*det)%26 == 1 ) Mul_inv= i;
  }
 
  /*Using the formula for inverse of a 2X2 matrix, modulo 26.*/
  Key_Inv[0][0]= (Key[1][1]*Mul_inv);
  Key_Inv[0][1]= (-1*Key[0][1]*Mul_inv);
  Key_Inv[1][0]= (-1*Key[1][0]*Mul_inv);
  Key_Inv[1][1]= (Key[0][0]*Mul_inv);	

  /*And finally,..
  Just like in encryption: Take two characters at a time. */
  for( i=0; i<Message.length(); i+=2 )
  {	
   _D[i]= ( Key_Inv[0][0]*_C[i] + Key_Inv[0][1]*_C[i+1] )%26;
   _D[i+1]= ( Key_Inv[1][0]*_C[i] + Key_Inv[1][1]*_C[i+1] )%26;
  }
  
  /*Convert number version into string of characters.*/
  for( i=0; i<Message.length(); i++ )
  { Decrypt[i]= (char)(_D[i]+97); } 

  /*Print decrypted text.*/
  System.out.println( "\nDecrypted text:" );
  for( i=0; i<Message.length(); i++ )
  { System.out.print( Decrypt[i] ); }

 }
}

