#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// Define a structure for a tree node
struct TreeNode {
    string symbol;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string symbol, TreeNode* left = nullptr, TreeNode* right = nullptr)
        : symbol(symbol), left(left), right(right) {}
};

// Function to create a new tree node
TreeNode* createNode(string symbol) {
    return new TreeNode(symbol);
}

// Function to print the parse tree in a pre-order traversal
void printParseTree(TreeNode* root) {
    if (root != nullptr) {
        cout << root->symbol << " ";
        printParseTree(root->left);
        printParseTree(root->right);
    }
}

// Function to check if a symbol is terminal (modify based on your grammar)
bool isTerminal(string symbol) {
    // Consider symbols starting with lowercase letters as terminals
    return islower(symbol[0]);
}

// Function to get the index of a non-terminal symbol in the parsing table (modify if needed)
int getNonTerminalIndex(string symbol) {
    // Implement logic to map non-terminal symbols to their indices
    // (e.g., use a hash table or a switch statement)
    // ...
    return -1; // Placeholder for proper implementation
}

// Function to get the index of a terminal symbol in the parsing table (modify if needed)
int getTerminalIndex(string symbol) {
    // Implement logic to map terminal symbols to their indices
    // (e.g., use a hash table or a switch statement for special symbols)
    return (symbol == "$") ? 0 : symbol[0] - 'a' + 1; // Assuming terminals are lowercase letters
}

int main() {
    // Parsing table (replace with your actual table)
    vector<vector<string>> parsingTable = {
        {"FT", "E+T", "", "", "", ""},
        {"FT", "", "T*F", "", "", ""},
        {"id", "", "", "", "", ""}
    };

    string input = "id+id*id";
    stack<string> stack;
    stack.push("$");
    stack.push("E");

    TreeNode* root = createNode("E");
    TreeNode* current = root;

    int i = 0;

    while (!stack.empty()) {
        string top = stack.top();
        stack.pop();

        if (top == "$" && input[i] == '$') {
            cout << "Parsing successful!" << endl;
            printParseTree(root);
            break;
        }

        if (isTerminal(top)) {
            if (top[0] == input[i]) {
                i++;
                current->left = createNode(top);
                current = current->left;
            } else {
                cout << "Parsing error!" << endl;
                break;
            }
        } else {
            int nonTerminalIndex = getNonTerminalIndex(top);
            int terminalIndex = getTerminalIndex(input[i]);

            if (nonTerminalIndex < 0 || terminalIndex < 0 || nonTerminalIndex >= parsingTable.size() || terminalIndex >= parsingTable[nonTerminalIndex].size()) {
                cout << "Error: Invalid parsing table indices." << endl;
                break;
            }

            string production = parsingTable[nonTerminalIndex][terminalIndex];

            for (int j = production.length() - 1; j >= 0; j--) {
                if (production[j] != ' ') {
                    stack.push(string(1, production[j]));
                }
            }

            current->left = createNode(top);
            current = current->left;
        }
    }

    return 0;
}