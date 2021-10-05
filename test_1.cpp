#include<bits/stdc++.h>
using namespace std;
class doc
{
public:
    int num;//出现顺序
    int count;//次数
    string s;//识别
    string hang;
    string c_name;//完整文件名
    string name;//文件名
    //初始化
    void initial(int _num,int _count,string &_hang,string &_name,string &_c_name,string &_s)
    {
        num = _num;
        count = _count;
        hang = _hang;
        name = _name;
        c_name = _c_name;
        s = _s;
    }
    //增加计数
    void add()
    {
        count++;
    }
};
bool cmp(const doc d1,const doc d2)
{
    if(d1.count == d2.count)
    {
        return d1.num < d2.num;
    }
    else
    {
        return d1.count > d2.count;
    }
}
int main()
{
    ifstream infile("A.txt");
    vector<string>vec;
    vector<string>number;
    string str;
    string num;
    while(infile >> str)
    {
        infile >> num;
        vec.push_back(str);
        number.push_back(num);
    }
    vector<doc>ans;
    int doc_index = 0;
    set<string>myset;
    for(int i = 0;i < vec.size();i++)
    {
        string tmp = vec[i];
        int index = 0;
        for(int j = 0;j < tmp.size();j++)
        {
            if(tmp[j] == '\\')
            {
                index = j + 1;
            }
        }
        string name = tmp.substr(index);
        string s = name + number[i];
        if(tmp.size() - index <= 16)
        {
            vec[i] = tmp.substr(index);
        }
        else
        {
            while(tmp.size() - index > 16)
            {
                index++;
            }
            vec[i] = tmp.substr(index);
        }
        if(myset.find(s) == myset.end())
        {
            myset.insert(s);
            doc d;
            ans.push_back(d);
            ans[doc_index].initial(i,1,number[i],vec[i],name,s);
            doc_index++;
        }
        else
        {
            for(int k = 0;k < doc_index;k++)
            {
                if(ans[k].s == s)
                {
                    ans[k].add();
                    break;
                }
            }
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    int ans_num = ans.size();
    if(ans_num > 8)
    {
        ans_num = 8;
    }
    for(int i = 0;i < ans_num;i++)
    {
        cout << ans[i].name << " " << ans[i].hang << " " << ans[i].count << endl;
    }
    return 0;
}