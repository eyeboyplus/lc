#include "./../lc.h"

string serialize(TreeNode *root) {
    ostringstream out;
    serialize(root, out);
    return out.str();
}

TreeNode* deserialize(string data) {
    istringstream in(data);
    return deserialize(in);
}

void serialize(TreeNode *root, ostringstream &out) {
    if(root) {
        out << root->val << ' ';
        serialize(root->left, out);
        serialize(root->right, out);
    } else {
        out << "# ";
    }
}

TreeNode* deserialize(istringstream &in) {
    string val;
    in >> val;
    if(val == "#")
        return nullptr;
    TreeNode *root = new TreeNode(stoi(val));
    root->left = deserialize(in);
    root->right = deserialize(in);
    return root;
}

int main(int argc, char **argv) {
    
    std::cout << "done.";
    return 0;
}