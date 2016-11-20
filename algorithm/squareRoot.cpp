#include <iostream>

using namespace std;

float absolute(float num) {
    if (num < 0) {
        num = -num;
    }
    return num;
}

float square_rt(int num) {
    float guess = 1;
    while ( absolute(guess*guess - num) >= 0.0001 ) {
        guess = (guess + (num/guess))/2;
    }
    return guess;
}

int main() {
    int number;
    cout<<endl<<"Enter the number ro find square root :"<<endl;
    cin>>number;
    float output = square_rt(number);
    cout<<"Square root of "<<number <<" => "<<output<<endl;
    return 0; 
}
