// Greedy Approach: Implementation of Huffman Code

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

// Node representation for the Huffman Tree
struct HuffmanNode {
    char data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char character, int frequency) {
        data = character;
        freq = frequency;
        left = nullptr;
        right = nullptr;
    }
};

// Comparator for the Min-Priority Queue
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq; // Lowest frequency gets highest priority
    }
};

// Recursive function to traverse the tree and generate codes
void generateCodes(HuffmanNode* root, const std::string& code, 
                   std::unordered_map<char, std::string>& huffmanCodes) {
    if (!root) return;

    // Found a leaf node (contains a character)
    if (!root->left && !root->right) {
        huffmanCodes[root->data] = code;
        return;
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

// Function to clean up allocated tree nodes
void freeTree(HuffmanNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

// Main function to build Huffman Tree and display codes
void buildHuffmanTree(const std::string& text) {
    if (text.empty()) return;

    // Step 1: Count frequency of each character
    std::unordered_map<char, int> freqMap;
    for (char ch : text) {
        freqMap[ch]++;
    }

    // Step 2: Push all leaf nodes into a min-heap
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Compare> minHeap;
    for (auto pair : freqMap) {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    // Special edge case: Only one unique character
    if (minHeap.size() == 1) {
        HuffmanNode* singleNode = minHeap.top();
        std::cout << singleNode->data << ": 0\n";
        delete singleNode;
        return;
    }

    // Step 3: Iterate until heap size becomes 1 (Greedy combination)
    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();

        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        // Internal nodes are assigned a dummy character like '$'
        HuffmanNode* top = new HuffmanNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    HuffmanNode* root = minHeap.top();

    // Step 4: Traverse the tree to generate codes
    std::unordered_map<char, std::string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    std::cout << "Huffman Codes:\n";
    std::cout << "--------------\n";
    for (auto pair : huffmanCodes) {
        std::cout << "'" << pair.first << "' : " << pair.second << "\n";
    }

    // Display encoded string
    std::cout << "\nEncoded String:\n";
    for (char ch : text) {
        std::cout << huffmanCodes[ch];
    }
    std::cout << "\n";

    // Clean up memory
    freeTree(root);
}

int main() {
    std::string text = "HelloWorld";
    std::cout << "Original Text: " << text << "\n\n";

    buildHuffmanTree(text);

    return 0;
}