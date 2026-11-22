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