import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.security.cert.CertificateFactory;
import java.security.cert.X509Certificate;
import java.security.Key;
import java.security.KeyStore;

import javax.crypto.Cipher;

import org.omg.CORBA.Environment;

import java.security.PublicKey;

public class _5EncryptAndDecryptUsingRSA {

	public static byte[] rsaEncryption(byte msgBytes[]) {
		byte encMsgBytes[] = null;
		try {
			FileInputStream certificateFis = new FileInputStream("raghuPub.cer");
			CertificateFactory cf = CertificateFactory.getInstance("X509");
			X509Certificate certificate = (X509Certificate) cf
					.generateCertificate(certificateFis);

			PublicKey pubkey = certificate.getPublicKey();
			Cipher cipher = Cipher.getInstance("RSA");

			// String encMsg=encrypt(textByte, pubkey, cipher);
			cipher.init(Cipher.ENCRYPT_MODE, pubkey);
			encMsgBytes = cipher.doFinal(msgBytes);

		} catch (Exception e) {
			e.printStackTrace();
		}
		return encMsgBytes;
	}

	public static byte[] rsaDecryption(byte[] encMsgBytes) throws Exception {
		byte[] decMsgBytes = null;

		FileInputStream fis = new FileInputStream("Raghupri.pfx");
		KeyStore ks = KeyStore.getInstance("pkcs12", "SunJSSE");
		ks.load(fis, "raghu".toCharArray());
		String alias = ks.aliases().nextElement();
		Key key = ks.getKey(alias, "raghu".toCharArray());
		Cipher cipher = Cipher.getInstance("RSA");

		cipher.init(Cipher.DECRYPT_MODE, key);
		decMsgBytes = cipher.doFinal(encMsgBytes);

		return decMsgBytes;
	}

	public static void main(String[] args) throws Exception {
		String msg = "Our Names are Jaya Venkat and Ishan. We are enrolled in CSE 539";
		System.out.println("Input Message\n"+msg);
		byte[] msgBytes = msg.getBytes();
		byte[] encMsgBytes = rsaEncryption(msgBytes);
		
		int i=0;
		System.out.print("\nEncrypte message hex value is \n");
		while(i<encMsgBytes.length)
		{
			System.out.print(String.format("%02x ",encMsgBytes[i]));
			i++;
		}
		
		String encMsgString = new String(encMsgBytes);
		System.out.println("\n\nEncrypted Message conveted to String is \n" + encMsgString);
		
		byte[] decMsgBytes = rsaDecryption(encMsgBytes);
		System.out.println("\nDecrypted Message is \n"
				+ new String(decMsgBytes));
	}

}
