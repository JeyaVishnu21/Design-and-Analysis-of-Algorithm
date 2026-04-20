// Implementing the Huffman Coding using the Greedy Technique
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>

using namespace std;

// Node structure compatible with older C++ standards
struct Node {
    char data;
    float freq;
    Node *left, *right;

    Node(char d, float f) {
        data = d;
        freq = f;
        left = NULL;
        right = NULL;
    }
};

// Comparator for the Min-Heap
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Print current nodes in the heap
void printCurrentNodes(priority_queue<Node*, vector<Node*>, Compare> pq) {
    cout << "Nodes: ";
    while (!pq.empty()) {
        Node* curr = pq.top();
        pq.pop();
        if (curr->data == '$')
            cout << "(" << fixed << setprecision(2) << curr->freq << ") ";
        else
            cout << "(" << curr->data << ":" << fixed << setprecision(2) << curr->freq << ") ";
    }
    cout << endl;
}

// Recursive function to print codes
void printCodes(Node* root, string code) {
    if (!root) return;

    if (!root->left && !root->right) {
        cout << root->data << ": " << code << endl;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
} 
int main() {
    int n;
    cout << "Enter number of characters: ";
    if (!(cin >> n)) return 0;

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < n; i++) {
        char ch;
        float freq;
        cout << "Enter character and frequency: ";
        cin >> ch >> freq;
        pq.push(new Node(ch, freq));
    }

    cout << "\nBuilding \n";

    while (pq.size() > 1) {
        printCurrentNodes(pq);

        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        // Create internal node
        Node *newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    if (!pq.empty()) {
        Node* root = pq.top();
        cout << "\nEncoding:\n";
        printCodes(root, "");
    }

    return 0;
}
