import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.security.cert.CertificateFactory;
import java.security.cert.X509Certificate;
import java.util.Scanner;
import java.security.Signature;

public class _4PrintSignatureOnCertificate {
public static void main(String[] args) {
	Scanner s;
	try {
		System.out.println("Enter the name of certificate which need to be printed");
		s = new Scanner(System.in);
		String fname=s.next();
		FileInputStream fis = new FileInputStream(fname);
		CertificateFactory cf = CertificateFactory.getInstance("X509");
		X509Certificate certificate = (X509Certificate) cf.generateCertificate(fis);
		
		byte sig[]=certificate.getSignature();
		System.out.println("Signature on Certificate is");
		int i=0;		
		while(i<sig.length)
		{
			System.out.print(String.format("%02x ",sig[i]));
			i++;
		}
		
	} 
	catch (Exception e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
	
}
}
