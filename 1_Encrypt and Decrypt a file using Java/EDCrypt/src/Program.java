//import java.io.FileNotFoundException;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.*;




public class Program {
public static void main(String[] args) throws IOException {
	System.out.println("Type 1 for Encrypting and 2 for Decrypting");
	java.util.Scanner s=new java.util.Scanner(System.in);	
	int option=s.nextInt();
	if(option==1)
	{
		 Encrypt e=new Encrypt();
		 e.readFileNameAndKey();
		 //e.readFromFile();		
		 
		 System.out.println("Data Length is: "+e.data.length);
		 System.out.println("Enter OutputFile Name");
     	String outputFileName=s.next();
     	File file=new File(e.fileName);
     	File outputFile=new File(outputFileName);
     	FileOutputStream fos = new FileOutputStream(outputFile);
     	FileInputStream fis=new FileInputStream(file);
     	System.out.println("Input file Length is"+file.length());
		 byte key32Bit[]= e.key.getBytes();
		 //e.count=0;
		 for(int i=0;i<file.length();i+=4)
         {
        	 byte input32Bit[];        	 
        	 fis.read(e.data);
        	 if(file.length()>i+3)        	 
        		input32Bit =new byte[]{e.data[0],e.data[1],e.data[2],e.data[3]};        	 
         	else if(file.length()==i+3)
         		input32Bit =new byte[]{e.data[0],e.data[1],e.data[2],0};
     		else if(file.length()==i+2)
     			input32Bit =new byte[]{e.data[0],e.data[1],0,0};
     		else
     			input32Bit =new byte[]{e.data[0],0,0,0};
        	// System.out.println(input32Bit.length);
        	
        	 //e.writeToFile(e.cipherText, outputFileName);
        	 byte output32Bit[]=e.blockEncrypt(input32Bit,key32Bit);
        	 fos.write(output32Bit);
        	 
        	 
         }
		 System.out.println("Output File Length is: "+outputFile.length());
		 fos.close();
         fis.close();	
         
        	
        	
        	
     		
         }
         
	
	else if(option==2)
	{
		 Decryption d=new Decryption();
		 d.readFileNameAndKey();
		 //d.readFromFile();		
		 //System.out.println("Data Length is: "+d.data.length);
		 System.out.println("Enter OutputFile Name");
	     	String outputFileName=s.next();
	     	File file=new File(d.fileName);
	     	File outputFile=new File(outputFileName);
	     	FileOutputStream fos = new FileOutputStream(outputFile);
	     	FileInputStream fis=new FileInputStream(file);
	     	System.out.println("file Length is"+file.length());
	     	byte key32Bit[]= d.key.getBytes();
		 //d.count=0;
		 for(int i=0;i<file.length();i+=4)
         {
        	 byte input32Bit[];        	 
        	 fis.read(d.data);
        	 if(file.length()>i+3)        	 
        		input32Bit =new byte[]{d.data[0],d.data[1],d.data[2],d.data[3]};        	 
         	else if(file.length()==i+3)
         		input32Bit =new byte[]{d.data[0],d.data[1],d.data[2],0};
     		else if(file.length()==i+2)
     			input32Bit =new byte[]{d.data[0],d.data[1],0,0};
     		else
     			input32Bit =new byte[]{d.data[0],0,0,0};
        	// System.out.println(input32Bit.length);
        	 byte output32Bit[]=d.blockDecryption(input32Bit, key32Bit); 
        	 fos.write(output32Bit);
         }
		 System.out.println("output File lenght is: "+outputFile.length());
        	 fos.close();
             fis.close();    	
        	
     		
	}
}
}
