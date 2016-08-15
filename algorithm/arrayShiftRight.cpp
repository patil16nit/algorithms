#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int* rotateFront(int *arr, int start1, int end) {
    int len = end+1;
    int shift = (end-start1+1)%len;
    int count = 0;
    for (int start=0; count<=(end-start1); start++) {
        int curr = start;
        int prev = arr[start];
        do {
            int next = (curr+shift)%len;
            int temp = arr[next];
            arr[next] = prev;
            prev = temp;
            curr = next;
            count++;
            //cout<<"arr[" << next<<"]"<<arr[next]<<endl;
        } while(start != curr);
        
    }
    return arr;
}


int* rotateBack (int *arr, int start1, int end, int len) {
    int shift = (end-start1+1)%len;
    int count = 0;
    for (int start=start1; start<= end; start++) {
        int curr = start;
        int prev = arr[start];
        //cout<< "[####]Entering inside do while"<<endl;
        do {
            //cout<<"[Debug] start do while "<<endl;
            int next;
            if ((curr+end-start1+1) < len) {
                //cout<<"### curr+end-start1+1 ->"<<curr+end-start1+1<<endl;
                next = (curr+end-start1+1)%len;
                //cout<<"### next ->"<<next<<endl; 
            } else  {
                //cout<<"Curr ->"<<curr<<endl;
                int requiredShift = len-(end - start1 +1);
                int performShift = len-1-curr;
                
                next = requiredShift-performShift-1;
                //cout<<"ELSE #### next ->"<<next<<endl;
            }
            int temp = arr[next];
            arr[next] = prev;
            prev = temp;
            curr = next;
            count++;
            //cout<<"Count -> "<<count<<endl;
            //cout<<"arr[" << next<<"]"<<arr[next]<<endl;
        } while(start != curr);
        
    }
    return arr;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    cin>>n>>m;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int fn, start, end;
    int *a = arr;
    int len = sizeof(arr)/sizeof(arr[0]);
    for (int j=0; j<m; j++) {
        cin>>fn>>start>>end;
        if (fn == 1) {
            a = rotateFront(a, start-1, end-1);
        } else {
            a = rotateBack(a, start-1, end-1, len);
        }
    }
    
    cout<<abs(a[0]-a[len-1])<<endl;
    
    for (int i=0; i<len; i++) {
        cout<< a[i]<< " ";
    }
    
    return 0;
}
