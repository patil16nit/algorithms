#include <iostream>
#include <string>

using namespace std;
int max(int num1, int num2) {
    return num1 > num2 ? num1 : num2;
}

int longestCommonSubstring(string s1, string s2) {
    int len1 = s1.length(); 
    int len2 = s2.length();

    int c[len1+1][len2+1];
    for (int i=0; i <= len1; i++) {
        c[0][i] = 0;
    }
    for (int i=0; i <= len2; i++) {
        c[i][0] = 0;
    }
 
   // loop throght strings
   for (int i = 1; i <= len2; i++) {
       for(int j = 1; j <= len1; j++) {
           
           if( int(s1[j-1]) == int(s2[i-1])) {
               c[i][j] = c[i-1][j-1] + 1;
           } else {
               c[i][j] = max(c[i-1][j], c[i][j-1]);
           }
       }
   }
   return c[len2][len1];
}


int main() {
    string str1;
    string str2;
    cout<<endl<<"Enter strings "<<endl;
    cin>>str1;
    cin>>str2;
    cout<<longestCommonSubstring(str1,str2)<<endl;
    return 0;
}
