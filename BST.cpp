#include <iostream>
using namespace std;

struct Node{
	int data;
	int age;
	int height;
	Node* left;
	Node* right;
};

Node* insert(Node* root, int data, int age, int height){
	if(root == NULL){ // if can't search the input id, construct a new node
		Node* newNode = new Node;
		newNode->data = data;
		newNode->age = age;
		newNode->height = height;
		newNode->left = newNode->right = NULL;
		root = newNode;
		newNode = NULL;
	}
	else if (data < root->data){ // if input id less than current searched id, shift to the left subtree
		root->left = insert(root->left, data, age, height+1);
	}	
	else if (data > root->data){ // if input id larger than current searched id, shift to the right subtree

		root->right = insert(root->right, data, age, height+1);
	}
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

Node* findheight(Node* root, int h){
	if(root != NULL){
		root->height = h;
		findheight(root->left, h+1);
		findheight(root->right, h+1);
	}	
	return root;
}

Node* remove(struct Node *root, int data){
	if (root == NULL){
		return root;
	}
	else if(data < root->data){ // if input id less than current searched id, shift to the left subtree
		root->left = remove(root->left, data);
	}
	else if(data > root->data){ // if input id larger than current searched id, shift to the right subtree
                root->right = remove(root->right, data);
        }
	else{
		if(root->left == NULL && root->right == NULL){ // if no subtree
			delete root;
			root = NULL; 
		}
		else if (root->left == NULL){ // if contains right subtree
			Node *temp = root;
			root = root -> right; // replace the deleted node with the right subtree
			temp = NULL;
		}
		else if (root->right == NULL){ // if contains left subtree
                        Node *temp = root;
                        root = root -> left; // replace the deleted node with the left subtree
                        temp = NULL;
                }
		else{ // if contains both left and right subtree
			Node* temp = FindMin(root->right); // find the smallest id in the right subtree for replacing the deleted node
			root->data = temp->data;
			root->age = temp->age;
			root->right = remove(root->right, temp->data);
		}
	}
	findheight(root, 0);
	return root;
}

void search(Node* root, int data){
	if (root == NULL){ // if id doesn't exists, return not found
		cout << "Not found\n";
	}
	else if (root->data == data){ // if id found, print the corresponding age
		cout << "Found, age = " << root->age << endl;
	}
	else if (data < root->data){ // if input id less than current searched id, search the left subtree
		return search(root->left, data);
	}
	else{ // if input id larger than current searched id, search the right subtree
		return search(root-> right, data);
	}
}

void printree(Node *root)  {  
	if(root != NULL){
		cout << root->data << " ";  
		printree(root->left);
		printree(root->right);
	}
}  

int main(){
	Node* root = NULL;
	// initialise the tree
	root = insert(root, 8, 25, 0); // first level
	root = insert(root, 3, 10, 0); // second level
	root = insert(root, 10, 11, 0);
	root = insert(root, 1, 20, 0); // third level
	root = insert(root, 6, 31, 0);
	root = insert(root, 14, 28, 0);
	root = insert(root, 4, 17, 0); // fourth level
	root = insert(root, 7, 17, 0);
	root = insert(root, 13, 9, 0);
	
	cout << "Enter your command: \nprint\nprint tree:\n";
	printree(root); // check the initialised tree
	cout << endl;
	cout << "Enter your command: \ninsert\n";
	cout << "Enter number to be inserted\n"; // insert node
	cout << "2 49\n";
	root = insert(root, 2, 49, 0); // Q1, Q2
	cout << "Enter your command: \ninsert\n";
	cout << "Enter number to be inserted\n";
	cout << "0 33\n";
	root = insert(root, 0, 33, 0); // Q1, Q2
	cout << "Enter your command: \nremove\n";
	cout << "Enter number to be removed\n"; // remove node
	cout << "7\n";
	remove(root, 7); // Q1, Q3
	cout << "Enter your command: \nsearch\n";
	cout << "Enter number to be searched\n"; // search node and print age
	cout << "13\n";
	search(root, 13); // Q1, Q4
	cout << "Enter your command: \nprint\nprint tree:\n";
	printree(root); // check the tree before quitting 
	cout << endl;
	cout << "Enter your command: \nexit\n";
	cout << "Program finished \n";
}


// optional choice for running the program manually, replace the above main() function by the following main() function
/*
int main(){
	Node* root = NULL;
	// initialise the tree
	root = insert(root, 8, 25, 0); // first level
	root = insert(root, 3, 10, 0); // second level
	root = insert(root, 10, 11, 0);
	root = insert(root, 1, 20, 0); // third level
	root = insert(root, 6, 31, 0);
	root = insert(root, 14, 28, 0);
	root = insert(root, 4, 17, 0); // fourth level
	root = insert(root, 7, 17, 0);
	root = insert(root, 13, 9, 0);
	
	while(true){
		cout << "Enter your command: \n";
		string s;
		int d, a;
		cin >> s;
		if (s == "i"){ // type command "i" to insert node
			cout << "Enter number to be inserted: \n";
			cin >> d >> a; // insert node, input the id(root->data) and age(root->age)
			root = insert(root, d, a, 0);
		}
		else if (s == "s"){ // type command "s" to search node
			cout << "Enter number to be searched: \n";
			cin >> d; // input the node being searched
			search(root, d);
		}
		else if (s == "r"){ // type command "r" to remove node
			cout << "Enter number to be removed: \n";
			cin >> d; // input the node being removed
			remove(root, d);
		}
		else if (s == "e"){ // type command "e" to exit program
			cout << "Program finished \n";
			break;
		}
		else{
			continue;
		}
	}
}
*/
