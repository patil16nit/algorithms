#include <iostream>
using namespace std;
 
int gcd(int a, int b) {
	if (b==0) return a;
	else return gcd(a,a%b);
} 
 
void leftRotate( int a[], int d, int n) {
	int gc=gcd(d,n);
	for (int i=n-1; i>=n-gc-1; i--) {
		int temp=a[i];
		int term= (i+gc)%n;
		cout<< "Terminate "<< term<<endl;
		int j=i;
		while(1) {
			int k=j-d;
			if (k==term) break;
			break;
			a[j]=a[k];
			j=k;
		}
		a[term]=temp;
	}
}
 
void printArr(int a[], int size) {
	for (int i=0; i<=size; i++) {
		cout<< a[i] <<" ";
	}
}

 
int main() {
	// your code goes here
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
   	leftRotate(arr, 2, 7);
    printArr(arr, sizeof(arr)/sizeof(arr[0]));
	return 0;
}
