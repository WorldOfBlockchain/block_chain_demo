#include "../hash/SHA_256.h"

class block{
public:
    block(string PreBlockHash, string transactions);
    string get_PreBlockHash();
    string get_BlockHash();
private:
    string PreBlockHash;
    string BlockHash;
    string transactions;
};
