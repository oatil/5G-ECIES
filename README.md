# Elliptic Curve Integrated Encryption Scheme (ECIES)



## UE侧加密处理流程

The ECIES scheme shall be implemented such that for computing a fresh SUCI, the UE shall use the provisioned public key of the home network and freshly generated ECC (elliptic curve cryptography) ephemeral public/private key pair according to the ECIES parameters provisioned by home network. 

UE使用归属网络提供的预配公钥和ECIES参数生成的ECC（椭圆曲线密码术）短暂的公钥/私钥对，用于计算SUCI。



![ecies-ue](.\pic\ecies-ue.png)



<center>UE侧</center>





![suci](.\pic\suci.png)

<center>SUCI</center>

​										（其中，UE的公有密钥，在SUCI的Scheme Output中，具体可参见测试数据中的数据）





## 归属网络侧解密处理流程

The ECIES scheme shall be implemented such that for deconcealing a SUCI, the home network shall use the received ECC ephemeral public key of the UE and the private key of the home network.

归属网络使用所接收的UE的公钥和归属网络的私钥，用来对SUCI进行解密。



![](.\pic\ecies-hn.png)





<center>HomeNetwork侧</center>



## ECIES Profile A

Profile A shall use its own standardized processing for key generation (section 6 of RFC 7748 [46]) and shared secret calculation (section 5 of RFC 7748 [46]). The Diffie-Hellman primitive X25519 (section 5 of RFC 7748 [46]) takes two random octet strings as input, decodes them as scalar and coordinate, performs multiplication, and encodes the result as an octet string. The shared secret output octet string from X25519 shall be used as the input Z in the ECIES KDF (section 3.6.1 of [29]).

Profile A使用自己的标准化处理生成密钥（RFC 7748 [46]的第6节）和共享密钥（RFC 7748 [46]的第5节）。 Diffie-Hellman X25519（RFC 7748 [46]的第5节）将两个随机八位字节串作为输入，将它们解码为标量和坐标，执行乘法，并将结果编码为八位字节串。来自X25519的共享密钥作为ECIES KDF中的输入Z（[29]的第3.6.1节）。

### ECIES参数

- EC domain parameters							: Curve25519 [46]

-	EC Diffie-Hellman primitive					: X25519 [46]

-	point compression								: N/A

-	KDF												: ANSI-X9.63-KDF [29]

-	Hash												: SHA-256

-	SharedInfo1										:  the ephemeral public key octet string – see [29] section 5.1.3

-	MAC												: HMAC–SHA-256

-	mackeylen										: 32 octets (256 bits)

-	maclen											: 8 octets (64 bits)

-	SharedInfo2										: the empty string

-	ENC												: AES–128 in CTR mode

-	enckeylen											: 16 octets (128 bits)

-	icblen												: 16 octets (128 bits)

-	backwards compatibility mode					: false

### 测试数据

- IMSI consists of MCC|MNC: '274012' and MSIN: '001002086'

- Home Network Private Key:

  'c53c22208b61860b06c62e5406a7b330c2b577aa5558981510d128247d38bd1d'

- Home Network Public Key:

  '5a8d38864820197c3394b92613b20b91633cbd897119273bf8e4a6f4eec0a650'

- Eph. Private Key:

  'c80949f13ebe61af4ebdbd293ea4f942696b9e815d7e8f0096bbf6ed7de62256'

- Eph. Public Key://64字节

  'b2e92f836055a255837debf850b528997ce0201cb82adfe4be1f587d07d8457d'

- Eph. Shared Key://64字节

  '028ddf890ec83cdf163947ce45f6ec1a0e3070ea5fe57e2b1f05139f3e82422a'

-  Eph. Enc. Key://32字节

  '2ba342cabd2b3b1e5e4e890da11b65f6'

- ICB://32字节

  'e2622cb0cdd08204e721c8ea9b95a7c6'

- Plaintext block://10字节

  '00012080f6'

-  Cipher-text vaue://10字节

  'cb02352410'

-  Eph. mac key://64字节

  'd9846966fb7cf5fcf11266c5957dea60b83fff2b7c940690a4bfe57b1eb52bd2'

- MAC-tag value://16字节

  'cddd9e730ef3fa87'

-  Scheme Output://90字节

  'b2e92f836055a255837debf850b528997ce0201cb82adfe4be1f587d07d8457d***\*cb02352410\****cddd9e730ef3fa87’

## ECIES Profile B

Profile B shall use point compression to save overhead and shall use the Elliptic Curve Cofactor Diffie-Hellman Primitive (section 3.3.2 of [29]) to enable future addition of profiles with cofactor h ≠ 1. For curves with cofactor h = 1 the two primitives (section 3.3.1 and 3.3.2 of [29]) are equal.

Profile B使用点压缩来节省开销，并应使用椭圆曲线辅助因子Diffie-Hellman原语（[29]的第3.3.2节），以便将来添加具有辅因子h≠1的轮廓。对于具有辅因子h = 1的曲线两个原语（[29]的3.3.1和3.3.2节）是相等的

### ECIES参数

- EC domain parameters							: secp256r1 [30]

-	EC Diffie-Hellman primitive					: Elliptic Curve Cofactor Diffie-Hellman Primitive [29]

- point compression								: true

- KDF												: ANSI-X9.63-KDF [29]

-	Hash												: SHA-256

-	SharedInfo1										: the ephemeral public key octet string – see [29] section 5.1.3

-	MAC												: HMAC–SHA-256

-	mackeylen										: 32 octets (256 bits)

-	maclen											: 8 octets (64 bits)

-	SharedInfo2										: the empty string

-	ENC												: AES–128 in CTR mode

-	enckeylen											: 16 octets (128 bits)

-	icblen												: 16 octets (128 bits)

-	backwards compatibility mode					: false

### 测试数据

- IMSI consists of MCC|MNC: '274012' and MSIN: '001002086'

- Home Network Public Key: 

  if compressed: '0272DA71976234CE833A6907425867B82E074D44EF907DFB4B3E21C1C2256EBCD1', 

  otherwise uncompressed: '0472DA71976234CE833A6907425867B82E074D44EF907DFB4B3E21C1C2256EBCD15A7DED52FCBB097A4ED250E036C7B9C8C7004C4EEDC4F068CD7BF8D3F900E3B4'

- Home Network Private Key: 

  'F1AB1074477EBCC7F554EA1C5FC368B1616730155E0041AC447D6301975FECDA'

- Eph. Public Key: 

  If compressed: '039AAB8376597021E855679A9778EA0B67396E68C66DF32C0F41E9ACCA2DA9B9D1'

  Otherwised uncompressed: '049AAB8376597021E855679A9778EA0B67396E68C66DF32C0F41E9ACCA2DA9B9D1D1F44EA1C87AA7478B954537BDE79951E748A43294A4F4CF86EAFF1789C9C81F'

-  Eph. Private Key: 

  '99798858A1DC6A2C68637149A4B1DBFD1FDFF5ADDD62A2142F06699ED7602529'

- Eph. Shared Key:

   '6C7E6518980025B982FBB2FF746E3C2E85A196D252099A7AD23EA7B4C0959CAE'	

- Eph. Enc. Key:

   '8A65C3AED80295C12BD55087E965702A'

- ICB: 

  'EF285B4061C3BAEE858AB6EC68487DAE'

-  Scheme-input corresponding to the plaintext-block:

   '00012080F6'

- Cipher-text vaue:

  '46A33FC271'

-  Eph. mac key: 

   'A5EBAC0BC48D9CF7AE5CE39CD840AC6C761AEC04078FAB954D634F923E901C64'

-  MAC-tag value:

  '6AC7DAE96AA30A4D'

- Scheme Output: 

  '039AAB8376597021E855679A9778EA0B67396E68C66DF32C0F41E9ACCA2DA9B9D146A33FC2716AC7DAE96AA30A4D'



## Decoding of SUCI

![img](./pic/suci.png)

**SUPI Type:** consisting in a value in the range 0 to 7. It identifies the type of the SUPI concealed in the SUCI. The following values are defined

– 0: IMSI
– 1: Network Specific Identifier
– 2 to 7: spare values for future use.

**Home Network Identifier:** identifying the home network of the subscriber.

When the SUPI Type is an IMSI, the Home Network Identifier is composed of two parts:
– Mobile Country Code (MCC), consisting of three decimal digits.
– Mobile Network Code (MNC), consisting of two or three decimal digits.
When the SUPI type is a Network Specific Identifier, the Home Network Identifier consists of a string of characters with a variable length representing a domain name. Ex. [abc@xyz.com](mailto:abc@xyz.com)

**Routing Indicator:** consisting of 1 to 4 decimal digits assigned by the home network operator and provisioned in the USIM.

**Routing Indicator:** consisting of 1 to 4 decimal digits assigned by the home network operator and provisioned in the USIM.

**Protection Scheme Identifier:** consisting in a value in the range of 0 to 15 and represented in 4 bits.

- null-scheme     0x0;
- Profile <A>     0x1;
- Profile <B>     0x2.

**Home Network Public Key Identifier:** consisting in a value in the range 0 to 255. It represents a public key provisioned by the HPLMN and it is used to identify the key used for SUPI protection. In case of null-scheme being used, this data field shall be set to the value 0;

**Scheme Output:** consisting of a string of characters with a variable length or hexadecimal digits, dependent on the used protection scheme.

- **Null Scheme** – For null scheme no encryption happens and scheme output field is replaced by MSIN(value after taking out MCC and MNC from IMSI) value of IMSI as it is.

![img](.\pic\so-null.jpg)

- Elliptic Curve Integrated Encryption Scheme(ECIES) Profile A

   – In this case scheme out put is further divided in two parts:

  1. ECC ephemeral public key 64 bits, freshly generated using the provisioned ECIES input parameters.
  2. Ciphered Text, is of variable length 

![img](.\pic\so-a.jpg)

- Elliptic Curve Integrated Encryption Scheme(ECIES) Profile B

   

  – In this case scheme out put is further divided in two parts

  1. ECC ephemeral public key 66 bits, freshly generated using the provisioned ECIES input parameters.
  2. Ciphered Text, is of variable length

![img](.\pic\so-b.jpg)

**Note:** Detailed into **Elliptic Curve Integrated Encryption Scheme(ECIES)** will be discussed in another Blog.

## 参考文献

33501-f50-5G安全架构和程序
