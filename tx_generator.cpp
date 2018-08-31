#include "tx_generator.h"

/*string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    string str(length,0);
    generate_n( str.begin(), length, randchar );
    return str;
}*/

typedef std::vector<char> char_array;

char_array charset()
{
    //Change this to suit
    return char_array({'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f',});
};

string random_string( size_t length, function<char(void)> rand_char )
{
    string str(length,0);
    generate_n( str.begin(), length, rand_char );
    return str;
}

vector<string> transaction_generator(int n){
    vector<string> hashes;
    //0) create the character set.
    //   yes, you can use an array here, 
    //   but a function is cleaner and more flexible
    const auto ch_set = charset();

    //1) create a non-deterministic random number generator      
    std::default_random_engine rng(std::random_device{}());

    //2) create a random number "shaper" that will give
    //   us uniformly distributed indices into the character set
    std::uniform_int_distribution<> dist(0, ch_set.size()-1);

    //3) create a function that ties them together, to get:
    //   a non-deterministic uniform distribution from the 
    //   character set of your choice.
    auto randchar = [ ch_set,&dist,&rng ](){return ch_set[ dist(rng) ];};
    for(int i = 0; i < n; i++){
        hashes.push_back("0100000001" + random_string(64, randchar) + "000000008b" + random_string(278, randchar) + "ffffffff" + random_string(92, randchar));
    }
    return hashes;
}
/*
int main(){
    transaction_generator(16);
    return 0;
}
*/