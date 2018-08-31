#include "block.h"

BlockHeader::BlockHeader(string PreBlockHash, string MerkleRoot)
:PreBlockHash(PreBlockHash), MerkleRoot(MerkleRoot){
    const char *tmp = (PreBlockHash + MerkleRoot).c_str();
    this->BlockHash = Double_SHA256((char *)tmp);
}

string BlockHeader::get_PreBlockHash(){
    return PreBlockHash;
}

string BlockHeader::get_BlockHash(){
    return BlockHash;
}