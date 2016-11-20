#include <iostream>
#include <map>

using namespace std;

int max(int a, int b) {
    return a>b?a:b;
}

int maxCutProfit(int cut, map<int, int> mp) {
    if (cut== 0) {
        return 0;
    }
    int q = -1;
    
    for (int i=1; i<= cut; i++) {
        q = max(q, mp[i]+maxCutProfit(cut-i, mp));
    }
    return q;
}



int main() {
    int cut;
    cout<<endl<<"Enter the number of cuts :"<<endl;
    cin>>cut;
    map<int, int> priceMap;
    int cutLength, price;
    for (int i=0; i<10; i++) {
        cout<<"Enter cut length and price : "<<endl;
        cin>>cutLength>>price;
        priceMap[cutLength]=price;
    }
    cout<<endl<<"Maximum profile by cutting : "<< maxCutProfit(cut, priceMap);
    return 0;
}
