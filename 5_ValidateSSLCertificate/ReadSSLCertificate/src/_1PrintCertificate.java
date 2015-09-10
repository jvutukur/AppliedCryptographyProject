import java.io.FileInputStream;
import java.util.Scanner;
import java.security.cert.CertificateFactory;
import java.security.cert.X509Certificate;
import java.security.KeyStore;
//import java.security.PublicKey;
//import java.security.PublicKey;
import java.security.*;
public class _1PrintCertificate {

	private static Scanner s;

	public static void main(String[] args) {
		try {
			System.out.println("Enter the name of certificate which needs to be printed");
			s = new Scanner(System.in);
			String fileName=s.next();
			FileInputStream certificateFis = new FileInputStream(fileName);
			CertificateFactory cf = CertificateFactory.getInstance("X509");
			X509Certificate certificate = (X509Certificate) cf.generateCertificate(certificateFis);							
									
			System.out.println(certificate.toString());
			System.out.println("\nSERIAL NUMBER\n" + String.format("%x", certificate.getSerialNumber()));
			
			/*System.out.println("\nVERSION\n" + certificate.getVersion());
			System.out.println("\nSERIAL NUMBER\n" + String.format("%x", certificate.getSerialNumber()));
			System.out.println("\nSIGNATRUE ALGORITHM\n" + certificate.getSigAlgName());
			System.out.println("\nISSURER \n" + certificate.getIssuerDN());
			System.out.println("\nVALID FROM\n" + certificate.getNotBefore());
			System.out.println("\nVALID TO\n" + certificate.getNotAfter());
			System.out.println("\nSUBJECT \n" + certificate.getSubjectDN());
			System.out.println("\nPUBLIC KEY\n" + certificate.getPublicKey());	*/				
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
