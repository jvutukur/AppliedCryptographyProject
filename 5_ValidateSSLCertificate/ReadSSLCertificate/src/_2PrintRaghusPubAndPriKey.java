import java.io.FileInputStream;
import java.security.Key;
import java.security.KeyStore;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.cert.CertificateFactory;
import java.security.cert.X509Certificate;
import java.util.Scanner;

public class _2PrintRaghusPubAndPriKey {

	public static void main(String[] args) {
		try {

			FileInputStream fis = new FileInputStream("Raghupri.pfx");
			KeyStore ks = KeyStore.getInstance("pkcs12", "SunJSSE");
			ks.load(fis, "raghu".toCharArray());
			String alias = ks.aliases().nextElement();

			X509Certificate certificate = (X509Certificate) ks
					.getCertificate(alias);
			PublicKey pubkey = certificate.getPublicKey();			

			System.out
					.println("Encoded Public Key of Raghu in hex -- contains both modulus and exponent(pub key)");
			byte pubKeyBytes[] = pubkey.getEncoded();
			int i = 0;
			while (i < pubKeyBytes.length) {
				System.out.print(String.format("%02x ", pubKeyBytes[i]));
				i++;
			}

			System.out.println("\n\nPUBLIC KEY OF RAGHU IS");
			System.out.println(pubkey);

			PrivateKey priKey = (PrivateKey) ks.getKey(alias,
					"raghu".toCharArray());
			i = 0;
			byte priKeyBytes[] = priKey.getEncoded();
			System.out.println("\nEncoded Private Key of Raghu in Hex -- contains both modulus and Decrytion key");
			while (i < priKeyBytes.length) {
				System.out.print(String.format("%02x ", priKeyBytes[i]));
				i++;
			}
			

		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}