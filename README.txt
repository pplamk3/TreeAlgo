Task 1 BST
The first program 1.cpp include a few basic function for building a BST, including insert(), remove() and search(). 

First, the program initialise the BST given in the question by using insert function. The insert sequence is according to the level of the node. First insert 8 (level 0), then 3 and 10 (level 1), 1, 6 and 14 (level 2) and lastly 4, 7 and 13 (level 3). For the next insert id, eg. 2, is inserted base on the BST. 2 is less than 8 and 3 so it goes to the left subtree and it's larger than 1 so it goes to the right subtree of the node with id 1. Similar mechanism for the next inserted number 0, it goes to the left subtree of node 1.

For the remove function, it includes a few cases. If there's no subtree for the node, then it can be deleted without extra operation. If there's one subtree for the node, then connect the previous node to the next node and delete the target node. If there's two subtree, find the node with minimum id in the right subtree and replace it to the target node and delete the target node. Node 7 got no subtree so it is deleted and set to null.

For the search function, it simply tells the program to traverse the whole tree and print the age stored in the target node.

Run the program on C++ compiler can shows the operations of the program. The program will run automatically. Under linux environment, input the following command to run the first program:
g++ 1.cpp -o 1
./1

//==================================================

Task 2 AVL
The program 2.cpp rebalance the unbalanced BST. It considers 4 cases, left left, right right, left right and right left case.

Q1
for all nodes with absolute balance factor > 1, then the tree is unbalance.
(a) is unbalance. 
The balance factor of node 8
= height of the left subtree - height of the right subtree
= 3 - 1 = 2 > 1

(b) is balance. All nodes have absolute balance factor < 1.

(c) is unbalance
The balance factor of node 9
= height of the left subtree - height of the right subtree
= 0 - 2 = -2 < -1

Q2
After executing all the questions in task 1, the tree becomes:
        8
       / \
      3  10
     / \   \
    1   6  14
   / \  /   /
  0  2  4  13
Obviously, the tree is not balance as node 10 have a balance factor of -2 < -1.

Q3
The tree is unbalance and it belongs to the Right-Left case. Take node 10 for the rotate operation. To make the tree balance, right rotation is first taken on node 14, so node 14 became the right subtree of node 13. Then take left rotation on node 10 and it becomes the left subtree of node 13. The balanced tree will look:
         8
       /   \
      3    13
     / \   / \
    1   6 10 14
   / \  /
  0  2  4

The rebalance function is inserted inside the insert and remove function. The program will check and balance the tree automatically after each insertion and removal. So there's no need for external operation or command to balance the tree.

Run the program on C++ compiler can shows the operations of the program. The program will run automatically. Under linux environment, input the following command to run the second program:
g++ 2.cpp -o 2
./2

//==================================================

Task 3 Concurrent Search
The program 3.cpp includes the preorder traversal function to print the tree, show the subtree of each node and search for the target node stated in the question. The program will print the preorder traversal list. Once the targeted node is found, the found message will pop up and the program continue to print the list of node identities.

After performing Q1-Q3 of task 1. The program perform the preorder traversal. It first call the manager function and search for the right subtree in each node. If left subtree of the node is found, then the manager function calls the preorder function to search for the entire left subtree. The two functions execute concurrently and present the multithreading to the entire tree. The operation recur until the entire tree is traversed. 

The program take preorder traversal on the AVL tree so as to increase the performance and efficiency. The tree is balanced and the multithread searching is more effective.

Run the program on C++ compiler can shows the operations of the program. The program will run automatically. Under linux environment, input the following command to run the third program:
g++ 3.cpp -o 3
./3

A manually control main function is attached at the bottom of each program, instructions are stated next to the function. Thanks for your attention.
