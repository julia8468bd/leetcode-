#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;
vector<int> result;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		TreeNode* root = nullptr;
		root = build_tree(root, nums, 0, nums.size() - 1);
		return root;
	}

	TreeNode* build_tree(TreeNode* root, vector<int>& nums, int l, int r) {
		if (l > r) {
			return NULL;	//若左位置>右位置，回傳NULL
		}
		int m = (l + r + 1) / 2;	//紀錄中間位置
		root = new TreeNode(0);
		root->val = nums[m];
		
		root->left = build_tree(root->left, nums, l, m - 1);	//遞迴左子樹(最右~中間-1)
		root->right = build_tree(root->right, nums, m + 1, r);  //遞迴右子樹(中間+1~最左)
		
		return root;
	}

	void Levelorder(TreeNode* root) {		//為了用Levelorder印出樹
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {				// 若queue不為空，有node還未走訪
			TreeNode *current = q.front();  // 取出先進入queue的node
			q.pop();						
			if (current->left != NULL) {	// 若左有資料, 進queue
				q.push(current->left);
			}

			if (current->right != NULL) {	// 若右有資料, 進queue
				q.push(current->right);
			}

			result.push_back(current->val);
		}
	}
};

int main() {
	Solution s;
	vector<int> nums = { -10, -3, 0, 5, 9};
	//s.sortedArrayToBST(nums);
	s.Levelorder(s.sortedArrayToBST(nums));

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
	cout << endl;
	system("pause");
}

