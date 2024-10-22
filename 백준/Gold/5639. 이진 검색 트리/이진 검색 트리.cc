#include <iostream>
// #define endl '\n'
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    explicit Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

// 트리에 새로운 노드를 삽입하는 함수
Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

// 후위 순회 (post-order traversal) 함수
void post_order(Node* root) {
    if (root == nullptr) return;
    post_order(root->left);
    post_order(root->right);
    cout << root->value << endl;
}

// 트리의 모든 노드를 삭제하는 함수
void delete_tree(Node* root) {
    if (root == nullptr) return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Node* root = nullptr;
    int value;
    while (cin >> value) {
        root = insert(root, value);
    }
    
    // 후위 순회 출력
    post_order(root);

    // 메모리 해제
    delete_tree(root);

    return 0;
}