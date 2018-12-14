#include <bits/stdc++.h>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define type char
using namespace std;
typedef long long ll;
typedef pair<string, string> pss;
typedef pair<int, int> pii;

const int maxn = 1005;

struct TreeNode {
    type data;
    TreeNode *left, *right;
};

// 给定前序中序求后序
TreeNode* buildPreIn(string pre, string in) {
    TreeNode *root = NULL;
    if(pre.length() > 0) {
        root = new TreeNode;
        root -> data = pre[0];
        int index = in.find(pre[0]);
        root -> left = buildTree(pre.substr(1, index), in.substr(0, index));
        root -> right = buildTree(pre.substr(index+1), in.substr(index+1));
    }
    return root;
}

// 给定中序后序求前序
TreeNode* buildInPost(string in, string post) {
    TreeNode *root = NULL;
    if(post.length() > 0) {
        root = new TreeNode;
        root -> data = post.back();
        int index = in.find(post.back());
        root -> left = buildInPost(in.substr(0, index), post.substr(0, index));
        root -> right = buildInPost(in.substr(index+1), post.substr(index, post.length()-index-1));
    }
    return root;
}

void preTraverse(TreeNode *root) {
    if(root != NULL) {
        cout << root->data;
        preTraverse(root -> left);
        preTraverse(root -> right);
    }
}

void inTraverse(TreeNode *root) {
    if(root != NULL) {
        inTraverse(root -> left);
        cout << root->data;
        inTraverse(root -> right);
    }
}

void postTraverse(TreeNode *root) {
    if(root != NULL) {
        postTraverse(root -> left);
        postTraverse(root -> right);
        cout << root->data;
    }
}

int main() {
    string pre, in;
    while(cin >> pre >> in) {
        TreeNode *root = buildPreIn(pre, in);
        // cout << "前序: "; preTraverse(root); cout << endl;
        // cout << "中序: "; inTraverse(root); cout << endl;
        // cout << "后序: "; postTraverse(root); cout << endl;
        postTraverse(root);
        cout << endl;
    }
    return 0;
}