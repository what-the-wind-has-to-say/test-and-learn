#include<bits/stdc++.h>
using namespace std;

void get_host(string &startUrl,string &host)
{
    int pos;
    if(startUrl.find("/",7) == startUrl.npos)
    {
        pos = startUrl.size();
    }
    else
    {
        pos = startUrl.find("/",7);
    }
    host = startUrl.substr(7,pos - 7);
}
int main()
{
    string str = "http://news.yahoo.com";
    string host;
    get_host(str,host);
    cout << host << endl;
    return 0;
}