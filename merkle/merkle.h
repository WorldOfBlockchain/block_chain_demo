#ifndef MERKLE_H
#define MERKLE_H
#include <vector>
#include <string>
#include "../hash/SHA_256.h"

using namespace std;

typedef struct{
    int tx_num;
    int h;
} tx_tree_info;

tx_tree_info full_tree_num(int n);

string  ComputeMerkleRoot(vector<string> tx_hashes, tx_tree_info tree_info);

#endif