#include "merkle.h"



// makes sure n is 2^h, note that this isn't exactly how bitcoin deals with merkle tree
tx_tree_info full_tree_num(int n){
    tx_tree_info tree_info;
    for(int i = 1; i < 31; i++){
        if (n == 0){
            tree_info.tx_num = 1, tree_info.h = 0;
            return tree_info;
        }
        else if(n == (1 << i) ){
            tree_info.tx_num = n, tree_info.h = i;
            return tree_info;
        }
        else if( (n > (1 << i)) && ( n < (1 << (i + 1) )) ){
            tree_info.tx_num = (1 << (i + 1) ), tree_info.h = i + 1;
            return tree_info;
        }
    }
    tree_info.tx_num = (1 << 30), tree_info.h = 30;
    return tree_info;
}

string  ComputeMerkleRoot(vector<string> tx_hashes, tx_tree_info tree_info){
    vector<string> merkle_tree;
    merkle_tree.resize(1 << tree_info.h);
    // bottom of merkle tree is SHA256(SHA256(Tx hash))
    for(int i = (1 << tree_info.h) - 1, j = 0; i < (1 << (tree_info.h + 1)) - 1; i++, j++){
        merkle_tree[i] = Double_SHA256((char *)tx_hashes[j].c_str());
    }
    int height = tree_info.h - 1;
    for(int i = height; i >= 0; i--){
        for(int j = (1 << height) - 1; j < (1 << (height + 1)) - 1; j++){
            merkle_tree[j] = Double_SHA256((char *)(merkle_tree[j*2 + 1] + merkle_tree[j*2 + 2]).c_str());
        }
    }
    return merkle_tree[0];
}