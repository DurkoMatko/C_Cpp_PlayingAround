#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool answer=false;
    string highLow;
    int lowerBound=0;
    int upperBound=100;
    cout << "Is your number" << (lowerBound+upperBound)/2 << "?" <<endl;
    cin >> answer;
    while (!answer){
        cout << "Higher or lower? h/l" <<endl;
        cin >> highLow;
        if(highLow=="h"){
            lowerBound = (lowerBound+upperBound)/2;
        }
        else{
            upperBound = (lowerBound+upperBound)/2;
        }
        cout << "Is your number" << (lowerBound+upperBound)/2 << "?" <<endl;
        cin >> answer;
    }

    cout << "Yay...ur number was " << (lowerBound+upperBound)/2 <<endl;
    return 0;
}
