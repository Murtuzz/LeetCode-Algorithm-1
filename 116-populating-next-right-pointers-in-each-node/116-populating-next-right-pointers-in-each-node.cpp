/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
     
        if (!root) {
            return root;
        }
        queue <Node*> q;
        q.push(root);
        int power = 0;
        int count = 0;
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            count++;
            if (pow (2, power) != count ) {
                temp->next = q.front();
            } else {
                power++;
                count = 0;
                temp->next = nullptr;
            }
            
            if (temp->left) {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return root;
    }
};