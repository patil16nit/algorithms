#include <iostream>
#include <stack>

using namespace std;

// https://www.careercup.com/question?id=5717797377146880

int main () {
    stack<int> num;
    int arraySize,data, sum=0;
    cout<<"Enter array size: ";
    cin>>arraySize;
    for (int i=0; i< arraySize; i++) {
        cin >> data;
        if (data > 0) {
            num.push(data);
        } else {
            while (data <0) {
                int top = num.top();
                num.pop();
                data += top;
            }
        }
    }

    int size =num.size();
    for (int i=0; i<size; i++) {
        cout << num.top() << " ";
        num.pop();
    }
    return 0;
}
