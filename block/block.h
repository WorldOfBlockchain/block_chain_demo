#ifndef BLOCK_H
#define BLOCK_H
#include "../hash/SHA_256.h"

class BlockHeader{
public:
    BlockHeader(string PreBlockHash, string MerkleRoot);
    string get_PreBlockHash();
    string get_BlockHash();
private:
    string PreBlockHash;
    string BlockHash;
    string MerkleRoot;
};


#endif