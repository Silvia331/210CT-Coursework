/* PSEUDOCODE
 REVERSE-WORDS(s,inv)
    if strlen(s)>0
        if strchr(s,' ')
            REVERSE-WORDS(strchr(s,' ')+1,inv)
            strncat(inv,s,strlen(inv))
            strcat(inv," ")
        else
            strcpy(inv,s)
            strcat(inv," ")
*/

#include <iostream>
#include <cstring>
using namespace std;

void reverse_words(char s[101],char inv[101])
{if(strlen(s)>0)
    if(strchr(s,' '))
        {reverse_words(strchr(s,' ')+1,inv);
         strncat(inv,s,strlen(s)-strlen(inv));
         strcat(inv," ");
        }
    else
         {strcpy(inv,s);
          strcat(inv," ");}
}

int main()
{char s[101],inv[101];
cout<<"Input sentence: ";
cin.get(s,101);
cout<<endl<<"Reversed sentence: ";
reverse_words(s,inv);
cout<<inv;
}
