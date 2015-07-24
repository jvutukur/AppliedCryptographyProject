import java.io.FileInputStream;
import java.security.cert.CertificateFactory;
import java.security.cert.X509Certificate;


public class _3PrintPubKeyOfCA {
public static void main(String[] args) throws Exception{
	FileInputStream certificateFis = new FileInputStream("Trustcenter.cer");
	CertificateFactory cf = CertificateFactory.getInstance("X509");
	X509Certificate certificate = (X509Certificate) cf.generateCertificate(certificateFis);
	System.out.println("Public Key of CA");
	System.out.println(certificate.getPublicKey());
	
}
}
