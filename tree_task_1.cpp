// Дано дерево. Удалить четные элементы
#include <iostream>

using namespace std;

struct tree
{
	int inf;
	tree* left;
	tree* right;
	tree* parent;
};

tree* node(int x) { //создание узла
	tree* n = new tree;
	n->inf = x;
	n->parent = NULL;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void inorder(tree* tr) { //симметричный обход дерева
	if (tr) {
		inorder(tr->left);
		cout << tr->inf;
		inorder(tr->right);
	}
}
int main() {
}