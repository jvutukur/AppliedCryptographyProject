//import java.io.*;

public class ReadWriteOfFile {
	byte data[]=new byte[4];
	String fileName;
	byte cipherText[];
	byte decryptedPlainText[];
	String key="";
	
	public void readFileNameAndKey()
	{		
		System.out.println("Enter the file Name");
        java.util.Scanner s=new java.util.Scanner(System.in);
		fileName=s.nextLine();
        
    	System.out.println("Enter the key 4 charecters");
        key=s.next();
	}
	
	/*public void readFromFile()
	{
		System.out.println(fileName);
		File file=new File(fileName);
		try
		{
			FileInputStream fis = new FileInputStream(file);
			System.out.println("file Length is"+file.length());						
			data = new byte[(int) file.length()];		
			cipherText=new byte[(int) file.length()];
			decryptedPlainText=new byte[(int) file.length()];
			fis.read(data);
			fis.close();	
			//System.out.println("data is: "+data);
		}
		catch(Exception e)
		{
		e.printStackTrace();
	    }
	}
	public void writeToFile(byte modifiedData[],String outputFileName)
	{
		FileOutputStream fos;
		try {
			fos = new FileOutputStream(outputFileName);
			fos.write(modifiedData);
			fos.close();
		} 
		
		catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			
	}
				
		
		
	} 
*/
}
