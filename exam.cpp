#include<bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    int number;
    TreeNode *left;
    TreeNode *right;
    TreeNode *father;
    //初始化
    void initial(int _val,int _number,TreeNode *_left,TreeNode *_right,TreeNode *_father)
    {
        val = _val;
        number = _number;
        left = _left;
        right = _right;
        father = _father;
    }
};
//遍历二叉树，返回所有节点的和
int traversal(TreeNode *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    int left = traversal(root->left);
    int right = traversal(root->right);
    int mid = left + right + root->val;
    return mid;
}
int main()
{
    ifstream in("test.txt");
    int num;
    in >> num;
    vector<int>points(num);
    for(int i = 0;i < points.size();i++)
    {
        in >> points[i];
    }
    //搭建二叉树
    vector<TreeNode*>Tree;
    for(int i = 0;i < num;i++)
    {
        TreeNode* tmp = new TreeNode();
        Tree.push_back(tmp);
    }
    vector<int>isinitial(num,0);//判断是否初始化
    int father;
    int son;
    while(in >> father && in >> son)
    {
        //初始化
        if(isinitial[father] == 0)
        {
            Tree[father]->initial(points[father],father,nullptr,nullptr,nullptr);
            isinitial[father] = 1;
        }
        if(isinitial[son] == 0)
        {
            Tree[son]->initial(points[son],son,nullptr,nullptr,nullptr);
            isinitial[son] = 1;
        }
        //父亲找儿子
        if(Tree[father]->left == nullptr)
        {
            Tree[father]->left = Tree[son];
        }
        else
        {
            Tree[father]->right = Tree[son]; 
        }
        //儿子找父亲
        Tree[son]->father = Tree[father];
    }
    //寻找根节点
    TreeNode* root = Tree[0];
    while(root->father != nullptr)
    {
        root = root->father;
    }
    //计算差值最大的结果
    int res = INT_MIN;
    int index;
    int sum = traversal(root);
    for(int i = 0;i < num;i++)
    {
        if(sum - 2*traversal(Tree[i]) > res)
        {
            res = sum - 2*traversal(Tree[i]);
            index = i;//最终编号
        }
    }
    cout << index << endl;
    return 0;
}