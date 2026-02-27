#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to get length of list
int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find intersection point
Node* findIntersection(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    Node* ptr1 = head1;
    Node* ptr2 = head2;

    // Move pointer of longer list ahead
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < len2 - len1; i++)
            ptr2 = ptr2->next;
    }

    // Traverse both together
    while (ptr1 && ptr2) {
        if (ptr1 == ptr2)
            return ptr1;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return nullptr;
}

int main() {
    int n, m;

    cin >> n;
    Node* head1 = nullptr;
    Node* tail1 = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* newNode = new Node(x);

        if (!head1) {
            head1 = tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    cin >> m;
    Node* head2 = nullptr;
    Node* tail2 = nullptr;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        Node* newNode = new Node(x);

        if (!head2) {
            head2 = tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    Node* intersection = findIntersection(head1, head2);

    if (intersection)
        cout << intersection->data;
    else
        cout << "No Intersection";

    return 0;
}