#include <iostream>
#include <vector>


typedef unsigned long long int uint64;

struct Node {
    int data;
    Node* next;
};

int main()
{
    using namespace std; //이제 std 안쓸께요.
    Node* head = new Node(); //새 노드 만들기
    head->data = 100;
    head->next = new Node();
    head->next->data = 200;
    head->next->next = new Node();
    head->next->next->data = 300;
    head->next->next->next = 0;

    Node* current = head;

    while (current != 0)
    {
        cout << current->data << endl;
        current = current->next;
    }   

    return 0;
}