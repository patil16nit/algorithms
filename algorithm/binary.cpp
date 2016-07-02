#include<iostream>
using namespace std;
int binSearch(int arr[], int l, int r , int x) {
    if (r>l) {
        int mid = l + (r-l)/2;
        if (arr[mid]==x) return mid;
        if (arr[mid]>x) return binSearch(arr,mid-1,r,x);
        return  binSearch(arr,l,mid+1,x);
    } else {
        return -1;
    }
}

int main(void) {
    int arr[]={4,3,54,78,34,10,2,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<binSearch(arr,0,n-1,34)<<endl;
    cout<<n/2<<endl;
    cout<<6/2<<endl;
    return 0;
}
