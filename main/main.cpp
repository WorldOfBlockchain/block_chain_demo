#include <iostream>
#include <vector>
#include "../block/block.h"
#include "../tx_generator.h"
#include "../merkle/merkle.h"

using namespace std;

int main(){
    
    string Genesis_MerkleRoot = "4a5e1e4baab89f3a32518a88c31bc87f618f76673e2cc77ab2127b7afdeda33b";
    string GenesisBlockPreBlockHash = "0";
    BlockHeader GenesisBlock(GenesisBlockPreBlockHash, Genesis_MerkleRoot);
    cout << GenesisBlock.get_BlockHash() << endl;

    tx_tree_info tree_info = full_tree_num(16);
    BlockHeader block_1(GenesisBlock.get_BlockHash(), ComputeMerkleRoot(transaction_generator(tree_info.tx_num), tree_info));
    return 0;
}