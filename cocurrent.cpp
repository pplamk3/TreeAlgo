#include <iostream>
#include <thread>
using namespace std;

struct Node{
	int data;
	int age;
	int height;
	Node* left;
	Node* right;
};
int heightt(Node *N){  
	if (N == NULL)  
		return 0;  
	return N->height;  
} 

int max(int a, int b){  
	if(a > b) return a;
	else return b;
} 

int getBalance(Node *N){  
	if (N == NULL)  return 0;  
	return heightt(N->left) - heightt(N->right);  
}

Node* findheight(Node* root){
	if(root != NULL){
		root->height = 1 + max(heightt(root->left), heightt(root->right));
		findheight(root->left);
		findheight(root->right);
	}	
	return root;
}

Node *rightRotate(Node *root){  
	Node *nodel = root->left;  
	Node *T2 = nodel->right;  
	nodel->right = root;  
	root->left = T2;  
	return nodel;  
}  
  
Node *leftRotate(Node *root){  
	Node *noder = root->right;  
	Node *T2 = noder->left;
	noder->left = root;  
	root->right = T2;  
	return noder;  
}

Node* insert(Node* root, int data, int age){
	if(root == NULL){
		Node* newNode = new Node;
		newNode->data = data;
		newNode->age = age;
		newNode->left = newNode->right = NULL;
		root = newNode;
		newNode = NULL;
	}
	else if (data < root->data){
		root->left = insert(root->left, data, age);
	}	
	else if (data > root->data){
		root->right = insert(root->right, data, age);
	}
	findheight(root);
	int balance = getBalance(root);
	// check if the absolute balance factor > 1; if yes, rebalace
	// Left Left Case  
	if (balance > 1 && data < root->left->data)  
		return rightRotate(root);  
  
	// Right Right Case  
	if (balance < -1 && data > root->right->data)  
		return leftRotate(root);  
  
	// Left Right Case  
	if (balance > 1 && data > root->left->data){  
        	root->left = leftRotate(root->left);  
        	return rightRotate(root);
    	}  
  
    	// Right Left Case  
    	if (balance < -1 && data < root->right->data){  
		root->right = rightRotate(root->right);  
		return leftRotate(root);  
	}  
	findheight(root);
	return root;  
}

Node* FindMin(Node* root){
	if(root->left != NULL){
		root = root->left;
		return FindMin(root);
	}
	else{
		return root;
	}
}

Node* remove(struct Node *root, int data){
	if (root == NULL){
		return root;
	}
	else if(data < root->data){
		root->left = remove(root->left, data);
	}
	else if(data > root->data){
                root->right = remove(root->right, data);
        }
	else{
		if(root->left == NULL && root->right == NULL){
			delete root;
			root = NULL;
		}
		else if (root->left == NULL){
			Node *temp = root;
			root = root -> right;
			temp = NULL;
		}
		else if (root->right == NULL){
                        Node *temp = root;
                        root = root -> left;
                        temp = NULL;
                }
		else{
			Node* temp = FindMin(root->right);
			root->data = temp->data;
			root->age = temp->age;
			root->right = remove(root->right, temp->data);
		}
	}
	findheight(root);
	int balance = getBalance(root);
	// check if the absolute balance factor > 1; if yes, rebalace
	// Left Left Case  
	if (balance > 1 && data < root->left->data)  
		return rightRotate(root);  
  
	// Right Right Case  
	if (balance < -1 && data > root->right->data)  
		return leftRotate(root);  
  
	// Left Right Case  
	if (balance > 1 && data > root->left->data){  
        	root->left = leftRotate(root->left);  
        	return rightRotate(root);
    	}
  
    	// Right Left Case  
    	if (balance < -1 && data < root->right->data){  
		root->right = rightRotate(root->right);  
		return leftRotate(root);  
	}  
	findheight(root);
	return root; 
}

void search(Node* root, int data){
	if (root == NULL){
		cout << "Not found\n";
	}
	else if (root->data == data){
		cout << "Found, age = " << root->age << endl;
	}
	else if (data < root->data){
		return search(root->left, data);
	}
	else{
		return search(root-> right, data);
	}
}

void preOrder(Node *root, int data){
	if(root != NULL){
		cout << "Node: " << root->data << "; subtree = ";  
		if (root->left == NULL)cout << "L: " << "NULL";
		else cout << "L: " << root->left->data;
		cout << ", ";
		if (root->right == NULL)cout << "R: " << "NULL";
		else cout << "R: " << root->right->data;
		cout << "; threadsearch" << endl;
		if(root->data == data) cout << "\nFound Node: " << root->data << ", age: " << root->age << "\n\n";
		preOrder(root->left, data);
		preOrder(root->right, data);
	}
}  

void manager(Node *root, int data){
	if(root != NULL){
		cout << "Node: " << root->data << "; subtree = ";
		if (root->left == NULL)cout << "L: " << "NULL";
		else cout << "L: " << root->left->data;
		cout << ", ";
		if (root->right == NULL)cout << "R: " << "NULL";
		else cout << "R: " << root->right->data;
		cout << endl;
		if(root->data == data) cout << "\nFound Node: " << root->data << ", age: " << root->age << "\n\n";
		if(root->left != NULL){
			preOrder(root->left, data); 
		}
		manager(root->right, data);
	}
}

void sub(Node *root, int data){
	if (root == NULL){
		cout << "Not found\n";
	}
	else if (root->data == data){
		if (root->left == NULL)cout << "NULL";
		else cout << root->left->data;
		cout << " <-> ";
		if (root->right == NULL)cout << "NULL";
		else cout << root->right->data;
		cout << endl;
	}
	else if (data < root->data){
		return sub(root->left, data);
	}
	else{
		return sub(root-> right, data);
	}
}

int main(){
	Node* root = NULL;
	// initialise the tree
	root = insert(root, 8, 25); // first level
	root = insert(root, 3, 10); // second level
	root = insert(root, 10, 11);
	root = insert(root, 1, 20); // third level
	root = insert(root, 6, 31);
	root = insert(root, 14, 28);
	root = insert(root, 4, 17); // fourth level
	root = insert(root, 7, 17);
	root = insert(root, 13, 9);

	cout << "Enter your command: \ninsert\n";
	cout << "Enter number to be inserted\n"; // insert node
	cout << "2 49\n";
	root = insert(root, 2, 49);
	cout << "Enter your command: \ninsert\n";
	cout << "Enter number to be inserted\n";
	cout << "0 33\n";
	root = insert(root, 0, 33); 
	cout << "Enter your command: \nremove\n";
	cout << "Enter number to be removed\n"; // remove node
	cout << "7\n";
	remove(root, 7);
	cout << "Enter your command: \npreorder\npreorder traversal:\n";
	manager(root, 6); // Q1
	cout << "Enter your command: \nexit\n";
	cout << "Program finished \n";
}


// optional choice for running the program manually, replace the above main() function by the following main() function
/*
int main(){
	Node* root = NULL;
	// initialise the tree
	root = insert(root, 8, 25); // first level
	root = insert(root, 3, 10); // second level
	root = insert(root, 10, 11);
	root = insert(root, 1, 20); // third level
	root = insert(root, 6, 31);
	root = insert(root, 14, 28);
	root = insert(root, 4, 17); // fourth level
	root = insert(root, 7, 17);
	root = insert(root, 13, 9);
	
	while(true){
		cout << "Enter your command: \n";
		string s;
		int d, a;
		cin >> s;
		if (s == "i"){ // type command "i" to insert node
			cout << "Enter id to be inserted: \n";
			cin >> d >> a; // insert node, input the id(root->data) and age(root->age)
			root = insert(root, d, a);
		}
		else if (s == "s"){ // type command "s" to search node
			cout << "Enter id to be searched: \n";
			cin >> d; // input the node being searched
			search(root, d);
		}
		else if (s == "r"){ // type command "r" to remove node
			cout << "Enter id to be removed: \n";
			cin >> d; // input the node being removed
			remove(root, d);
		}
		else if (s == "e"){ // type command "e" to exit program
			cout << "Program finished \n";
			break;
		}
		else if (s == "p"){ // type command "p" to print tree
			cout << "Enter id to be searched: \n";
			cin >> d;
			cout << "preorder traversal:\n";
			manager(root, d);
		}
		else{
			continue;
		}
	}
}
*/
