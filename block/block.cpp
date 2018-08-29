#include "block.h"

block::block(string PreBlockHash, string transactions):PreBlockHash(PreBlockHash), transactions(transactions){
    const char *tmp = (PreBlockHash + transactions).c_str();
    this->BlockHash = SHA_256((char*)tmp);
}

string block::get_PreBlockHash(){
    return PreBlockHash;
}

string block::get_BlockHash(){
    return BlockHash;
}