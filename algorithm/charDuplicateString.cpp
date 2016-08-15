#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void printDuplicate( string const &in) {
  map <int, int> chars;
  for (unsigned int i=0; i< in.length(); i++ ) {
    int charConst = static_cast<int>(in[i]);

      if (!chars[charConst] ) {
        //cout<<"Value exists" << chars[charConst]<< endl;
        chars[charConst] = 1;
        //cout<<"Settinh 0 to "<<in[i]<<endl;
      } else {
        chars[charConst] += 1;
        if (chars[charConst]  == 2) {
          cout<< in[i];
        }
      }
  //cout<<chars[charConst]<<endl; 

    //cout<< in[i] << static_cast<int>(in[i]) << endl;
  }
}

void printString( string const &t) {
   for ( unsigned int i= 0; i<t.length(); i++) {
     cout<<t[i];
   }
}


void removeDup( string const &s) {
  int len = s.length();
  vector<int> newStr;
  for (unsigned int i=0; i< len; i++) {
    int charConst = static_cast<int>(s[i]);
    if (newStr.empty()) {
      newStr.push_back(charConst);
    } else if ( newStr.back() == charConst) {
      newStr.pop_back();
    } else {
      newStr.push_back(charConst);
    }
  }

  if (newStr.size() == 0) {
    cout<<"Empty String"<<endl;
  } else {
    for (vector<int>::const_iterator i = newStr.begin(); i != newStr.end(); i++) {
      cout << (char)*i << ' ';
    } 
  }
}


int main() {
   string str;
   cout<<"Enter String:"<<endl;
   getline(cin, str);
   //printDuplicate(str);
   //printString(str);

   removeDup(str);
   return 0;
}
