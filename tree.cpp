#include <iostream>

using namespace std;


struct node{
	int value;
	node *left;
	node *right;
};

class btree{
public:
    //Construction
	btree();
	//Destruction
	~btree();

	void insertNode(int key);
	node *searchNode(int key);
	void destroy_tree();
	void inorder_print();
	void postorder_print();
	void preorder_print();

private:
	void destroy_tree(node *leaf);
	void insertNode(int key, node *leaf);
	node *searchNode(int key, node *leaf);
	void inorder_print(node *leaf);
	void postorder_print(node *leaf);
	void preorder_print(node *leaf);

	node *root;
};


btree::btree(){
	root = NULL;
}

btree::~btree(){
	destroy_tree();
}

void btree::destroy_tree(node *leaf){
	if(leaf != NULL){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::insertNode(int key, node *leaf){

	if(key < leaf->value){
		if(leaf->left != NULL){
			insertNode(key, leaf->left);
		}else{
			leaf->left = new node;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}else if(key >= leaf->value){
		if(leaf->right != NULL){
			insertNode(key, leaf->right);
		}else{
			leaf->right = new node;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}

}

void btree::insertNode(int key){
	if(root != NULL){
		insertNode(key, root);
	}else{
		root = new node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

node *btree::searchNode(int key, node *leaf){
	if(leaf != NULL){
		if(key == leaf->value){
			return leaf;
		}
		if(key < leaf->value){
			return searchNode(key, leaf->left);
		}else{
			return searchNode(key, leaf->right);
		}
	}else{
		return NULL;
	}
}

node *btree::searchNode(int key){
	return searchNode(key, root);
}

void btree::destroy_tree(){
	destroy_tree(root);
}

void btree::inorder_print(){
	inorder_print(root);
	cout << "\n";
}

void btree::inorder_print(node *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		cout << leaf->value << ",";
		inorder_print(leaf->right);
	}
}

void btree::postorder_print(){
	postorder_print(root);
	cout << "\n";
}

void btree::postorder_print(node *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		inorder_print(leaf->right);
		cout << leaf->value << ",";
	}
}

void btree::preorder_print(){
	preorder_print(root);
	cout << "\n";
}

void btree::preorder_print(node *leaf){
	if(leaf != NULL){
		cout << leaf->value << ",";
		inorder_print(leaf->left);
		inorder_print(leaf->right);
	}
}

int main(){

	//btree tree;
	btree *tree = new btree();

	int node,nodeValue;
	cout<<"Enter the number of nodes : ";
	cin>>node;

	while(node>0){
        cin>>nodeValue;
        tree->insertNode(nodeValue);
        node--;
	}
    // root - left - right
	tree->preorder_print();
	// left - root - right
	tree->inorder_print();
	// left - right - root
	tree->postorder_print();

	delete tree;

}
