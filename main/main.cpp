# include "../block/block.h"

int main(){
    
    string Genesis_Tx = "Hi, I am genesis block";
    string GenesisBlockPreBlockHash = "0";
    block GenesisBlock(GenesisBlockPreBlockHash, Genesis_Tx);
    cout << GenesisBlock.get_BlockHash() << endl;

    return 0;
}