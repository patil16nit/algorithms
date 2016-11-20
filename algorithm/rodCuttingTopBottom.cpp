#include <iostream>
#include <map>

using namespace std;

int max(int a, int b) {
    return a>b?a:b;
}

int rodCuttingTopBottomPatch(int cut, map<int, int> mp, int r[]) {
    if (r[cut]>=0) {
        return r[cut];
    }
    if (cut== 0) {
        return 0;
    } else {
        int q = -1;
    
        for (int i=1; i<= cut; i++) {
            q = max(q, mp[i] + rodCuttingTopBottomPatch(cut-i, mp, r));
        }
        r[cut]=q;
        return q;
    }
}

int rodCuttingTopBottom(int cut, map<int, int> mp) {
    int r[cut];
    for(int i=0; i<=cut;i++) {
        r[i]=-1;
    }
    return rodCuttingTopBottomPatch(cut, mp, r);
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
    cout<<endl<<"Maximum profile by cutting : "<< rodCuttingTopBottom(cut, priceMap);
    return 0;
}
