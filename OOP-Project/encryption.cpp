#include<iostream>
#include<string.h>
#include<fstream>
#include<cstdio>
using namespace std;
int main()
{
    ofstream fout;
    ifstream fin;
    fout.open("Rohan.txt");
    fin.open("message.txt");
    int i,j,k;
    char table[36][36],key[10],prokey[50],temp,ch[50],chencry[50],alpha[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};
    cout<<"Enter the key to encrypt\n";
    cin>>key;
    int length=strlen(key);
    for(i=0;i<(length/2);i++)
    {
        temp=key[i];
        key[i]=key[(length)-i-1];
        key[(length)-i-1]=temp;
    }
    for(i=0;i<36;i++)
    {
        for(j=0;j<36;j++)
        {
            table[i][j]=alpha[i+j];
            if(i+j>=36)
                table[i][j]=alpha[(i+j)-36];
        }
    }
    for(i=0;i<36;i++)
    {
        for(j=0;j<36;j++)
        {
            fout<<table[i][j];
        }fout<<endl;
    }
    fout.close();
    fout.open("encryptedmessage.txt");
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
                        if(table[0][j]==ch[k])
                            chencry[k]=table[i][j];
                    }
                }
            }
        }
        chencry[k]='\0';
        fout<<chencry<<" ";
    }
    fin.close();
    fout.close();
    return 0;
}
