from tinyec import registry 
import secrets 
curve = registry.get_curve('brainpoolP256r1') 
def compress_point(point): 
    return hex(point.x) + hex(point.y % 2)[2:] 
def ecc_calc_encryption_keys(pubKey): 
    ciphertextPrivKey = secrets.randbelow(curve.field.n) 
    ciphertextPubKey = ciphertextPrivKey * curve.g 
    sharedECCKey = pubKey * ciphertextPrivKey 
    return (sharedECCKey, ciphertextPubKey) 
def ecc_calc_decryption_key(privKey, ciphertextPubKey): 
    sharedECCKey = ciphertextPubKey * privKey 
    return sharedECCKey 
privKey = secrets.randbelow(curve.field.n) 
pubKey = privKey * curve.g 
print("private key:", hex(privKey)) 
print("public key:", compress_point(pubKey)) 
(encryptKey, ciphertextPubKey) = ecc_calc_encryption_keys(pubKey) 
print("ciphertext pubKey:", compress_point(ciphertextPubKey)) 
print("encryption key:", compress_point(encryptKey)) 
decryptKey = ecc_calc_decryption_key(privKey, ciphertextPubKey) 
print("decryption key:", compress_point(decryptKey)) 
