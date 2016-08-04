/*
 *  author: Martin Durcek
 *  email: nitramdurcek@gmail.com
*/

//Convert this program to C++
//change to C++ io
//change to one line comments
//change defines of constants to const
//change array to vector<>
//inline any short function

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
const double N = 40;


int main()
{
    int accum = 0;
    //using vector instead of array
    vector<int> data(N);

    //filling vector with values + variable declaration inside of for loop
    for(int i = 0; i < N; ++i){
        data[i] = i;
    }

    //no need for inline function, C++ offers accumulate feature
    accum = accumulate(data.begin(), data.end(), 0);
    cout << "Sum is " << accum << endl;

    //return SUCCESS
    return 0;
}
