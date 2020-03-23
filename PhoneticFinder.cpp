//
// Created by avichai on 3/22/20.
//

#include <iostream>
#include <stdexcept>

#include "PhoneticFinder.hpp"
using namespace std;


namespace phonetic {
   /* string find(string text, string s) {
        for (int i = 0; i < text.length(); i++) {
            int j = 0;
            while (text[i] != ' '||j == s.length()) {
                if (j != s.length()) {
                    if (s[j] == text[i]) {
                        j++;
                        i++;
                    }
                    else if (((s[j] == 't' && text[i] == 'd') || (s[j] == 'd' && text[i] == 't'))) {
                        j++;
                        i++;
                    }
                    else {
                        j = 0;
                        i = space2(text, i);
                    }
                }
                else{
                    int indexHelp=i-s.length();
                    string ans="";
                    for(int k=indexHelp,j=0;j<s.length();k++,j++) {

                        ans = ans + text[k];
                    }
                    return ans;

                }

            }
        }
            }
    int space2(string text, int index) {
        for (int i = index; i < text.length(); i++) {
            if (text[i] == ' ') return i;

        }
        return -1;
    }




        */

////////////////////////////////////////////////////////////////////////////////////
        bool equal(string a,string b){
            for(int i=0; i<a.length(); i++){
                if(a[i]!=b[i])
                    return false;

            }
            return true;
        }

        string find(string text, string s) {
            int index=0;
            string help="";
            string help1="";
            string help2="";
            string ans="";
            string temp="";
            for (int i = 0; i < text.length(); i++) {
                if(text[i]==' ')
                    index=i;
            }

            for (int i = 0; i < text.length(); i++) {
                if(text[i]!=' ') {
                    help=help+text[i];
                }
                if(text[i]==' ') {
                    temp=help;
                    for(int k=0; k<help.length(); k++) {
                        if(help[k]<97)
                            help1=help1+(char)(help[k]+32);
                        else
                            help1=help1+help[k];
                    }
                    for (int k1 = 0; k1 < s.length(); k1++) {
                        if(s[k1]<97)
                            help2=help2+(char)(s[k1]+32);
                        else
                            help2=help2+s[k1];

                    }
                    s=help2;
                    help=help1;
                    help1="";
                    help2="";
                    for (int x = 0; x < help.length(); x++) {

                        if(x<s.length()) {
                            if((s[x]==help[x]+32)||(s[x]+32==help[x]))
                                ans=ans+help[x];
                            if((s[x]=='t' && help[x]=='d')||(s[x]=='d' && help[x]=='t'))
                                ans=ans+help[x];
                            if((s[x]=='b'&&(help[x]=='f'||help[x]=='p'))||(s[x]=='f'&&(help[x]=='b'||help[x]=='p'))||(s[x]=='p'&&(help[x]=='b'||help[x]=='f')))
                                ans=ans+help[x];
                            if((s[x]=='c'&&(help[x]=='k'||help[x]=='q'))||(s[x]=='k'&&(help[x]=='c'||help[x]=='q'))||(s[x]=='q'&&(help[x]=='c'||help[x]=='k')))
                                ans=ans+help[x];
                            if((s[x]=='w' && help[x]=='v')||(s[x]=='v' && help[x]=='w'))
                                ans=ans+help[x];
                            if((s[x]=='u' && help[x]=='o')||(s[x]=='o' && help[x]=='u'))
                                ans=ans+help[x];
                            if((s[x]=='z' && help[x]=='s')||(s[x]=='s' && help[x]=='z'))
                                ans=ans+help[x];
                            if((s[x]=='y' && help[x]=='i')||(s[x]=='i' && help[x]=='y'))
                                ans=ans+help[x];
                            if((s[x]=='j' && help[x]=='g')||(s[x]=='g' && help[x]=='j'))
                                ans=ans+help[x];
                            if(s[x]==help[x])
                                ans=ans+help[x];
                            if(equal(help,ans))
                                return temp;

                        }
                    }


                    if(!equal(help,ans))
                        ans="";
                    help="";
                }
            }

            if(index>0){
                help="";
                for(int t=index+1; t<text.length(); t++) {
                    help=help+text[t];

                }
                temp=help;
                for(int k=0; k<help.length(); k++) {
                    if(help[k]<97)
                        help1=help1+(char)(help[k]+32);
                    else
                        help1=help1+help[k];
                }
                for (int k1 = 0; k1 < s.length(); k1++) {
                    if(s[k1]<97)
                        help2=help2+(char)(s[k1]+32);
                    else
                        help2=help2+s[k1];

                }
                s=help2;
                help=help1;
                help1="";
                help2="";

                for (int x = 0; x < help.length(); x++) {

                    if(x<s.length()) {
                        if((s[x]==help[x]+32)||(s[x]+32==help[x]))
                            ans=ans+help[x];
                        if((s[x]=='t' && help[x]=='d')||(s[x]=='d' && help[x]=='t'))
                            ans=ans+help[x];
                        if((s[x]=='b'&&(help[x]=='f'||help[x]=='p'))||(s[x]=='f'&&(help[x]=='b'||help[x]=='p'))||(s[x]=='p'&&(help[x]=='b'||help[x]=='f')))
                            ans=ans+help[x];
                        if((s[x]=='c'&&(help[x]=='k'||help[x]=='q'))||(s[x]=='k'&&(help[x]=='c'||help[x]=='q'))||(s[x]=='q'&&(help[x]=='c'||help[x]=='k')))
                            ans=ans+help[x];
                        if((s[x]=='w' && help[x]=='v')||(s[x]=='v' && help[x]=='w'))
                            ans=ans+help[x];
                        if((s[x]=='u' && help[x]=='o')||(s[x]=='o' && help[x]=='u'))
                            ans=ans+help[x];
                        if((s[x]=='z' && help[x]=='s')||(s[x]=='s' && help[x]=='z'))
                            ans=ans+help[x];
                        if((s[x]=='y' && help[x]=='i')||(s[x]=='i' && help[x]=='y'))
                            ans=ans+help[x];
                        if((s[x]=='j' && help[x]=='g')||(s[x]=='g' && help[x]=='j'))
                            ans=ans+help[x];
                        if(s[x]==help[x])
                            ans=ans+help[x];
                        if(equal(help,ans))
                            return temp;

                    }
                }


            }
            if(index==0){
                help="";
                for(int t=0; t<text.length(); t++) {
                    help=help+text[t];

                }
                temp=help;
                for(int k=0; k<help.length(); k++) {
                    if(help[k]<97)
                        help1=help1+(char)(help[k]+32);
                    else
                        help1=help1+help[k];
                }
                for (int k1 = 0; k1 < s.length(); k1++) {
                    if(s[k1]<97)
                        help2=help2+(char)(s[k1]+32);
                    else
                        help2=help2+s[k1];

                }
                s=help2;
                help=help1;
                help1="";
                help2="";

                for (int x = 0; x < help.length(); x++) {

                    if(x<s.length()) {
                        if((s[x]==help[x]+32)||(s[x]+32==help[x]))
                            ans=ans+help[x];
                        if((s[x]=='t' && help[x]=='d')||(s[x]=='d' && help[x]=='t'))
                            ans=ans+help[x];
                        if((s[x]=='b'&&(help[x]=='f'||help[x]=='p'))||(s[x]=='f'&&(help[x]=='b'||help[x]=='p'))||(s[x]=='p'&&(help[x]=='b'||help[x]=='f')))
                            ans=ans+help[x];
                        if((s[x]=='c'&&(help[x]=='k'||help[x]=='q'))||(s[x]=='k'&&(help[x]=='c'||help[x]=='q'))||(s[x]=='q'&&(help[x]=='c'||help[x]=='k')))
                            ans=ans+help[x];
                        if((s[x]=='w' && help[x]=='v')||(s[x]=='v' && help[x]=='w'))
                            ans=ans+help[x];
                        if((s[x]=='u' && help[x]=='o')||(s[x]=='o' && help[x]=='u'))
                            ans=ans+help[x];
                        if((s[x]=='z' && help[x]=='s')||(s[x]=='s' && help[x]=='z'))
                            ans=ans+help[x];
                        if((s[x]=='y' && help[x]=='i')||(s[x]=='i' && help[x]=='y'))
                            ans=ans+help[x];
                        if((s[x]=='j' && help[x]=='g')||(s[x]=='g' && help[x]=='j'))
                            ans=ans+help[x];
                        if(s[x]==help[x])
                            ans=ans+help[x];
                        if(equal(help,ans))
                            return temp;

                    }
                }
            }

            return temp;
		return temp;
        }
}