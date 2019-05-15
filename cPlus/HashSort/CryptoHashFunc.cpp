#include "CriptoHashFunction.hpp"
#include <string>
#include <CommonCrypto/CommonDigest.h>

using namespace std;

string CriptoHashFunction::hash(int list[], int length) {
    unsigned char digest[CC_MD5_DIGEST_LENGTH];
    
    CC_MD5_CTX context;
    CC_MD5_Init(&context);
    CC_MD5_Update(&context, list, (CC_LONG) length);
    CC_MD5_Final(digest, &context);
    
    string hash = "";
    char buf[32];
    for(int i=0; i < 16; i++){
        sprintf(buf, "%02x", digest[i]);
        hash.append( buf );
    }

	return hash;
}
