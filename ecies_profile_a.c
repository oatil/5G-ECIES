/**
The ME and SIDF shall implement this profile.The ECIES parameters for this profile shall be the following :
- EC domain parameters : Curve25519[46]
- EC Diffie - Hellman primitive : X25519[46]
- point compression : N / A
- KDF : ANSI - X9.63 - KDF[29]
- Hash : SHA - 256
- SharedInfo1 : (the ephemeral public key octet string – see[29] section 5.1.3)
- MAC: HMAC–SHA - 256
- mackeylen : 32 octets(256 bits)
- maclen : 8 octets(64 bits)
- SharedInfo2 : the empty string
- ENC : AES–128 in CTR mode
- enckeylen : 16 octets(128 bits)
- icblen : 16 octets(128 bits)
- backwards compatibility mode : false
**/

#include <stdio.h>
#include <string.h>

#include <openssl/bn.h>
#include <openssl/ec.h>
#include <openssl/ecdh.h>
#include <openssl/pem.h>
#include <openssl/rand.h>
#include <openssl/evp.h>

int encrypt(uint8_t* msg,
	size_t          msg_len,
	int             curve,
	const uint8_t* peer_pubk,
	const uint8_t   peer_pubk_len,
	uint8_t** epubk,          // out (must free)
	size_t* epubk_len,      // out
	uint8_t** iv,             // out (must free)
	uint8_t* iv_len,         // out
	uint8_t** tag,            // out (must free)
	uint8_t* tag_len,        // out
	uint8_t** ciphertext,     // out (must free)
	uint8_t* ciphertext_len) // out
{
        return 0;
}

int decrypt(const EC_KEY* ec_key,
	const uint8_t* peer_pubk,
	const uint8_t  peer_pubk_len,
	uint8_t* iv,
	uint32_t       iv_len,
	uint8_t* tag,
	uint32_t       tag_len,
	uint8_t* ciphertext,
	uint32_t       ciphertext_len)
{
        return 0;
}
int main(int argc, char * argv[])
{
        return 0;
}
