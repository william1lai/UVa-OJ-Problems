#include <iostream>
#include <cctype>

using namespace std;

struct Node
{
	int num;
	Node* up;
	Node* left;
	Node* right;
};

void skipWhiteSpace()
{
	char c;
	while (cin.get(c))
	{
		if (c != '\n' && c != ' ')
			break;
	}
	cin.putback(c);
}

Node* parseTree()
{
	bool hasRoot = false;
	Node* root = new Node();
	Node* cur = root;
	int level = 0;
	bool left = true;
	char c;

	skipWhiteSpace();
	cin.get(c); //'('
	level++;
	skipWhiteSpace();	
	char pika = cin.peek();
	if (pika != '-' && !isdigit(pika))
	{
		cin.get(c);
		return NULL;
	}
	int val;
	cin >> val;
	root->num = val;
	skipWhiteSpace();

	while (cin.get(c))
	{
		if (c == '(')
		{
			skipWhiteSpace();
			level++;
			char cc = cin.peek();
			if (isdigit(cc) || cc == '-')
			{
				bool neg = (cc == '-');
				if (neg)
					cin.get(c);
				int num;
				cin >> num;
				if (neg)
					num = -num;

				if (left)
				{
					cur->left = new Node();
					cur->left->num = num;
					cur->left->up = cur;
					cur = cur->left;
				}
				else
				{
					cur->right = new Node();
					cur->right->num = num;
					cur->right->up = cur;
					cur = cur->right;
				}
				left = true;
			}
			else //')'
			{
				cin.get(c);
				level--;
				if (level == 0)
					return root;
				skipWhiteSpace();

				//if (!left)
					//cur = cur->up;

				char ccc = cin.peek();
				if (ccc == '(')
				{
					left = false;
				}
			}
		}
		else if (c == ')')
		{
			level--;
			if (level == 0)
				return root;
			cur = cur->up;
		}
		skipWhiteSpace();
	}
}

bool subsetSum(Node* root, int sum)
{
	if (root->left == NULL && root->right == NULL)
		return sum == root->num;

	bool lhs = false;
	bool rhs = false;
	if (root->left != NULL)
	{
		lhs = subsetSum(root->left, sum - root->num);
	}
	if (root->right != NULL)
	{
		rhs = subsetSum(root->right, sum - root->num);
	}

	return (lhs || rhs);
}

int main()
{
	int n;
	while (cin >> n)
	{
		Node* head = parseTree();
		if (head && subsetSum(head, n))
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}
