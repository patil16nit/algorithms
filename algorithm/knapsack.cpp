#include <iostream>
using namespace std;

int max(int a, int b) { return (a > b)? a : b; }
int knapSack(int W, int wt[], int val[], int n) {
	int i, w;
	int K[n+1][W+1];

	// Build table K[][] in bottom up manner
	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i==0 || w==0)
				K[i][w] = 0;
			else if (wt[i-1] <= w) {
				int sum = val[i-1];
				while (sum < w) {
					sum += max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
					//K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
				}
				K[i][w] = sum;
			}else
				K[i][w] = K[i-1][w];
		}
	}
cout<< K[n][W];
	for (int i=0; i<=n; i++) {
	    for (int j=0; j<=W; j++) {
		cout<<K[i][j]<< " ";	
	    }
	    cout<<endl;
	}
}
int main() {
	int val[] = {3, 4, 4, 4, 8};//{1,6,9};//{2, 3, 5};
	int wt[] = {3, 4, 4, 4, 8};//{1,6,9};//{1,6,9};//{50, 100, 140};
	int W = 12;
	int n = sizeof(val)/sizeof(val[0]);
	cout<< knapSack(W, wt, val, n);
	return 0;
}
