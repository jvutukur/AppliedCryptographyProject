
public class Decryption extends ReadWriteOfFile {
	byte output32Bit[]=new byte[4];
	int count;
	
public byte[] blockDecryption(byte input32Bit[],byte key32Bit[])
{
	
	byte reverseKey32Bit[]=reverseKey(key32Bit);
	for(int i = 0; i < 4; i++)
	{
		output32Bit[i]=(byte)(input32Bit[i] ^ reverseKey32Bit[i]);					
		
	}
	input32Bit=shiftBitsRight(output32Bit,2);
		
	
	for(int i = 0; i < 4; i++)
	{
		output32Bit[i]=(byte)(input32Bit[i] ^ key32Bit[i]);					
		
	}
	input32Bit=shiftBitsRight(output32Bit,1);
	
	for(int i = 0; i < 4; i++)
	{
		output32Bit[i]=(byte)(input32Bit[i] ^ key32Bit[i]);					
		count++;
	}
	return output32Bit;
	/*for(int j=count-4,i=0;i<4;j++,i++)
    {
		decryptedPlainText[j]=output32Bit[i];
	}*/
	        
		
	
}

public byte[] shiftBitsRight(byte input[],int shiftValue) 
{ //http://www.herongyang.com/Java/Byte-Data-Type-Shift-Operations.html
	      byte[] out = new byte[4];
	      for (int i=0;i<shiftValue;i++)
	      {
	    	  int val=getBit(input,(32-shiftValue+i));
	    	  setBit(out,i,val);
	      }
	      for (int i=shiftValue; i<32; i++) {
	         int val = getBit(input,(i-shiftValue));
	         setBit(out,i,val);
	      }
	      return out;
}
	
private static void setBit(byte[] data, int pos, int val) {
    // http://www.herongyang.com/Java/Bit-String-Get-Bit-from-Byte-Array.html
	int posByte = pos/8; 
    int posBit = pos%8;
    byte oldByte = data[posByte];
    oldByte = (byte) (((0xFF7F>>posBit) & oldByte) & 0x00FF);
    byte newByte = (byte) ((val<<(8-(posBit+1))) | oldByte);
    data[posByte] = newByte;
 }
private static int getBit(byte[] data, int pos) {
	//http://www.herongyang.com/Java/Bit-String-Get-Bit-from-Byte-Array.html
	int posByte = pos/8; 
    int posBit = pos%8;
    byte valByte = data[posByte];
    int valInt = valByte>>(8-(posBit+1)) & 0x0001;
    return valInt;
 }
public byte[] reverseKey(byte input[])
{
	byte reverseKey[]=new byte[4];
	reverseKey[0]=input[3];
	reverseKey[1]=input[2];
	reverseKey[2]=input[1];
	reverseKey[3]=input[0];
	
	return reverseKey;
}


}
