# Word Frequency Counter Using Binary Search Tree (BST)

 1. Problem Statement

Counting the frequency of words in a paragraph manually is time-consuming, especially when the paragraph contains many words or repeated words. This project aims to develop a C++ program that counts the occurrences of each word using a Binary Search Tree (BST). The program processes the input paragraph, removes punctuation, converts words to lowercase, and displays each unique word along with its frequency in alphabetical order.

2. Aim

To develop a C++ program that counts the frequency of words in a paragraph using a Binary Search Tree.

3. Objectives

- To accept a paragraph as input from the user.
- To extract individual words from the paragraph.
- To remove punctuation and non-alphanumeric characters.
- To convert words to lowercase for consistent counting.
- To store words and their frequencies using a Binary Search Tree.
- To display unique words and their frequencies in alphabetical order.

4. Theory

A Binary Search Tree (BST) is a hierarchical data structure in which each node contains data and pointers to its left and right child nodes. In this project, each node stores a word, its frequency, and pointers to its left and right children.

When a word is inserted into the BST, it is compared with the word stored in the current node. If the word already exists, its frequency is incremented. If the word is alphabetically smaller, it is inserted into the left subtree; otherwise, it is inserted into the right subtree.

The program uses the 'iostream' library for input and output, the `string` library for handling text, the `sstream` library for extracting words, and the `cctype` library for character checking and lowercase conversion.

The program uses recursion for insertion and in-order traversal. In-order traversal visits the left subtree, the current node, and then the right subtree. This ensures that the words are displayed in alphabetical order.

 5. Algorithm

1. Start the program.
2. Create a Binary Search Tree with an empty root.
3. Accept a paragraph from the user.
4. Extract individual words using a string stream.
5. Remove punctuation and non-alphanumeric characters from each word.
6. Convert each word to lowercase.
7. Insert the cleaned word into the BST.
8. If the word already exists, increment its frequency.
9. If the word is smaller than the current node's word, move to the left subtree.
10. Otherwise, move to the right subtree.
11. Repeat the process until all words are processed.
12. Perform an in-order traversal of the BST.
13. Display each word and its frequency.
14. Stop the program.

6. Flowchart

Start  
↓  
Input Paragraph  
↓  
Extract Individual Word  
↓  
Remove Punctuation and Convert to Lowercase  
↓  
Check Whether the Word Is Empty  
↓  
Insert Word into Binary Search Tree  
↓  
Check Whether the Word Already Exists  
↓  
Increment Frequency if the Word Exists; Otherwise, Insert a New Node  
↓  
Process Remaining Words  
↓  
Perform In-order Traversal  
↓  
Display Words and Their Frequencies  
↓  
Stop

7. Conclusion

The Word Frequency Counter using a Binary Search Tree was implemented successfully in C++. The program counts the occurrences of unique words in a paragraph, ignores differences in letter case, removes punctuation, and displays the results in alphabetical order. This project demonstrates the practical application of binary search trees, recursion, string processing, and tree traversal in solving a text-processing problem.