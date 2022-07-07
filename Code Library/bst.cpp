
class node {
public:
	int val;
	node *left;
	node *right;
	node() {
		val = 0;
		left = right = NULL;
	}
	node(int val) {
		this->val = val;
		left = right = NULL;
	}
	node(int val, node *left, node *right) {
		this->val = val;
		this->left = left;
		this->right = right;
	}
};

void Insert(int val, node *root)
{
	if (root->val > val)
	{
		if (root->left != NULL)
			Insert(val, root->left);
		else
		{
			node *newNode = new node(val);
			root->left = newNode;
		}
	}
	else
	{
		if (root->right != NULL)
			Insert(val, root->right);
		else
		{
			node *newNode = new node(val);
			root->right = newNode;
		}
	}
	return;
}

void Print(node *root)
{
	if (root == NULL)
		return;
	Print(root->left);
	cout << root->val << " -> ";
	Print(root->right);
}

void Search(int val, node *root)
{
	if (root == NULL)
		return;
	if (root->val == val)
	{
		cout << val << " found !\n";
		return;
	}
	else if (root->val > val)
		Search(root->left);
	else
		Search(root->right);
	return;
}

node* SearchNode(int val, node *root)
{
	if (root == NULL)
		return NULL;
	if (root->val == val)
		return root;
	else if (root->val > val)
		Search(root->left);
	else
		Search(root->right);
}

void Delete(int val, node *root)
{

}