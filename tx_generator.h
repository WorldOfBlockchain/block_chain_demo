#include <iostream>
#include <vector>
#include <random>
#include <functional> //for std::function
#include <algorithm>  //for std::generate_n
#include <string>
#include <ctime>

using namespace std;

string random_string( size_t length, function<char(void)> rand_char );

vector<string> transaction_generator(int n);