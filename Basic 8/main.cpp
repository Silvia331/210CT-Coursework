/* PSEUDOCODE

REMOVE-VOCALS(s)
    if strlen(s)>0
        if strchr("aeiou",s[0])
            strcpy(s,s+1)
            REMOVE-VOCALS(s)
        else
            REMOVE-VOCALS(s+1)
*/

#include <iostream>
#include <cstring>
using namespace std;

void remove_vocals(char s[101])
{if(strlen(s)>0)
    if(strchr("aeiou",s[0]))
        { strcpy(s,s+1);
          remove_vocals(s);
        }
        else
        remove_vocals(s+1);
}

int main()
{char s[101];

cout<<"Input string: ";
cin.get(s,101);

remove_vocals(s);

cout<<endl<<"String without vocals: "<<s;
    return 0;
}
