#include<bits/stdc++.h>

using namespace std;

int* lpsfn(string patter) {
    int sz = patter.size();
    int *lps = new int [sz + 1];
    memset(lps, 0, sz*sizeof(lps[0]));

    int index = 0, i = 0;

    for(i = 1; i < sz; )
    {
        if(patter[i] == patter[index]) {
            lps[i] = index + 1;
            i++;
            index++;
        }
        else {
            if (index != 0) index = lps[index - 1];
            else
               lps[i++] = 0;
        }
    }

    return lps;
}


void kmp(string text, string pattern) {
    int *lps = lpsfn(pattern);
    int p = pattern.size();
    int index = 0, cnt = 0;
    for(int i = 0; i < text.size();) {
       if(text[i] == pattern[index]) {
          i++;
          index++;
          cnt++;
       }
       else {
          if(index != 0)index = lps[index - 1];
          else
             i++;
       }
       if(p == cnt)
       {
          cout << "pattern match" << endl;
          break;
       }
    }
}

int main() {
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    kmp(text, pattern);

    return 0;
}
