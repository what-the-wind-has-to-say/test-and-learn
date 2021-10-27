#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class spy
{
    public:
    spy* father;
    int id;
    int country;//红为0，蓝为1
    spy(int _id,int _country,spy *_father = nullptr):id(_id),country(_country),father(_father){};
};
void trans(int &path,int &country,spy *cur,int m)
{
    spy* tmp = cur;
    while(tmp->father != nullptr)
    {
        path++;
        tmp = tmp->father;
        if(path > m)
        {
            break;
        }
    }
    if(tmp->id != 1)
    {
        country = 2;
    }
    else
    {
        country = tmp->country;
    }
}
int main() {
    int count;
    cin >> count;
    while(count--)
    {
        int red_count;
        int blue_count;
        int T;
        cin >> red_count >> blue_count;
        cin >> T;
        string str;
        vector<spy*>red_spys;
        for(int i = 0;i < red_count;i++)
        {
            //创建红树
            spy *spy_r = new spy(i + 1,0);
            red_spys.push_back(spy_r);
        }
        for(int i = 1;i < red_count;i++)
        {
            //构建上级关系
            cin >> str;
            int father_id = str[1] - '0';
            red_spys[i]->father = red_spys[father_id - 1];
        }
        vector<spy*>blue_spys;
        for(int i = 0;i < blue_count;i++)
        {
            //创建蓝树
            spy *spy_b = new spy(i + 1,1);
            blue_spys.push_back(spy_b);
        }
        for(int i = 1;i < blue_count;i++)
        {
            //构建上级关系
            cin >> str;
            int father_id = str[1] - '0';
            blue_spys[i]->father = blue_spys[father_id - 1];
        }
   
        while(T--)
        {
            char c;//事件
            cin >> c;
            string e1;
            string e2;
            cin >> e1 >> e2;
            if(c == 'w')
            {
                //传递情报
                int n1 = e1[1] - '0';
                int path1 = 0;
                int country1 = -1;
                int n2 = e2[1] - '0';
                int path2 = 0;
                int country2 = -1;
                if(e1[0] == 'R')
                {
                    //红国传递第一份情报
                    trans(path1,country1,red_spys[n1 - 1],red_count + blue_count);
                }
                else if(e1[0] == 'B')
                {
                    //蓝国传递第一份情报
                    trans(path1,country1,blue_spys[n1 - 1],red_count + blue_count);                    
                }
                if(e2[0] == 'R')
                {
                    //红国传递第二份情报
                    trans(path2,country2,red_spys[n2 - 1],red_count + blue_count);
                }
                else if(e2[0] == 'B')
                {
                    //蓝国传递第二份情报
                    trans(path2,country2,blue_spys[n2 - 1],red_count + blue_count);                    
                }
                //判断逻辑
                if(country1 == 2 && country2 == 2)
                {
                    cout << "NONE" << endl;
                }
                else
                {
                    if(country1 == 2)
                    {
                        if(country2 == 0)
                        {
                            cout << "RED " << path2 << endl;
                        }
                        else
                        {
                            cout << "BLUE " << path2 << endl;
                        }
                    }
                    else if(country2 == 2)
                    {
                        if(country1 == 0)
                        {
                            cout << "RED " << path1 << endl;
                        }
                        else
                        {
                            cout << "BLUE " << path1 << endl;
                        }
                    }
                    else
                    {
                        if(path1 == path2)
                        {
                            if(country1 != country2)
                            {
                                cout << "TIE " << path1 << endl;
                            }
                            else if(country1 == 0)
                            {
                                cout << "RED " << path1 << endl;
                            }
                            else
                            {
                                cout << "BLUE " << path1 << endl;
                            }
                        }
                        else if(path1 < path2)
                        {
                            if(country1 == 0)
                            {
                                cout << "RED " << path1 << endl;
                            }
                            else
                            {
                                cout << "BLUE " << path1 << endl;
                            }
                        }
                        else
                        {
                            if(country2 == 0)
                            {
                                cout << "RED " << path2 << endl;
                            }
                            else
                            {
                                cout << "BLUE " << path2 << endl;
                            }
                        }
                    }
                }
            }

            if(c == 'c')
            {
                int i1 = e1[1] - '0';//子
                int i2 = e2[1] - '0';//新的爸爸

                if(e1[0] == 'R' && e2[0] == 'R')
                {
                    red_spys[i1 - 1]->father = red_spys[i2 - 1];

                }
                if(e1[0] == 'R' && e2[0] == 'B')
                {
                    red_spys[i1 - 1]->father = blue_spys[i2 - 1];

                }
                if(e1[0] == 'B' && e2[0] == 'R')
                {
                    blue_spys[i1 - 1]->father = red_spys[i2 - 1];

                }
                if(e1[0] == 'B' && e2[0] == 'B')
                {
                    blue_spys[i1 - 1]->father = blue_spys[i2 - 1];

                }
            }

        }

    }
}