/* isupper example */
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

#define MAX 100000

int main ()
{
    int i=0;
    string str;
    char c, a;
    char d[MAX];
    cin>>str;
    while (str[i])
    {
        c=str[i];
        i++;
        if (isupper(str[i])){
            cout << "str  \n " << str[i] << "\n" << endl;
            d[i] = str[i];
            cout << "d \n " << d[i] << endl;
        }
    }

    for(int i=0;i<sizeof(d)/sizeof(d[0]);i++){
        if(d[i] == d[i+1])

    }

  return 0;
}
