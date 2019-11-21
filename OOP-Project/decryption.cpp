#include<iostream>
#include<string.h>
#include<fstream>
#include<cstdio>
using namespace std;
int main()
{
    ofstream fout;
    ifstream fin;
    fin.open("Rohan.txt");
    fout.open("decryptedmessage.txt");
    char table[36][36];
    int i=0;
    char key[10],prokey[50],ch[50],chdecry[50],temp;
    cout<<"Enter the key to decrypt\n";
    cin>>key;
    int length=strlen(key);
    for(i=0;i<(length)/2;i++)
    {
        temp=key[i];
        key[i]=key[(length)-i-1];
        key[(length)-i-1]=temp;
    }
    int j=0,k;
    i=0;
    while(!fin.eof())
    {
        if(j==36)
        {
            i++;
            j=0;
        }
        fin>>table[i][j];
        j++;
    }
    fin.close();
    fin.open("encryptedmessage.txt");
    while(fin>>ch)
    {
        for(i=0;i<strlen(ch);i++)
        {
            prokey[i]=key[i];
            if(i>=strlen(key))
                prokey[i]=key[i%strlen(key)];
        }
        prokey[i]='\0';
        for(k=0;k<strlen(prokey);k++)
        {
            for(i=0;i<36;i++)
            {
                if(table[i][0]==prokey[k])
                {
                    for(j=0;j<36;j++)
                    {
                        if(table[i][j]==ch[k])
                            chdecry[k]=table[0][j];
                    }
                }
            }
        }
        chdecry[k]='\0';
        fout<<chdecry<<" ";
    }
    fin.close();
    fout.close();
    return 0;
}
