// 17. Implement Huffman Code

// Algorithm
// 1. Start.
// 2. Read the characters and their frequencies.
// 3. Create a leaf node for each character.
// 4. Insert all nodes into a Min Priority Queue.
// 5. Remove the two nodes with the smallest frequencies.
// 6. Create a new internal node with their combined frequency.
// 7. Insert the new node back into the priority queue.
// 8. Repeat until only one node remains.
// 9. Generate codes by traversing the Huffman tree: left as 0 and right as 1.
// 10. Display the Huffman codes.
// 11. Stop.

// T.C : O(n log n) ; S.C : O(n)


#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct Compare
{
    bool operator()(Node* a, Node* b)
    {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->ch << " : "
             << (code.empty() ? "0" : code) << endl;
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main()
{
    int n, freq[100];
    char ch[100];

    cout << "Enter number of characters: ";
    cin >> n;

    priority_queue<Node*, vector<Node*>, Compare> pq;

    cout << "Enter character and frequency:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> ch[i] >> freq[i];
        pq.push(new Node(ch[i], freq[i]));
    }

    while (pq.size() > 1)
    {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$',
                                left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    cout << "\nHuffman Codes:\n";
    printCodes(pq.top(), "");

    return 0;
}
