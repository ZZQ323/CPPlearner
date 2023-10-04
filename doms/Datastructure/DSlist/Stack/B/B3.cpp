#include <iostream>
#include <stdexcept>
#include <list>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d = 0) : data(d), next(nullptr) {}
    Node(const Node& var) : data(var.data), next(nullptr) {}
};

std::list<int> sl;

struct Ciclist{

    struct Iterator{
        Node* head;
        Node* last_one;
        Node* current;

        Iterator(Node* node,Node*hd,Node* le=nullptr) 
        : current(node),head(hd),last_one(le){;}

        int& operator*() {
            return current->data;
        }
        
        Iterator operator++(int) {
            Iterator temp(*this);
            last_one=current;
            current = current->next;
            if( current==head ){
                last_one=current;
                current = current->next;
            }
            return temp;
        }

        Iterator& operator++() {
            last_one=current;
            current = current->next;
            if( current==head ){
                last_one=current;
                current = current->next;
            }
            return *this;
        }
        
        Iterator& operator+(int id) {
            while(id--){
                last_one=current;
                current = current->next;
                if( current==head ){
                    last_one=current;
                    current = current->next;
                }
            }
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

        bool operator==(const Iterator& other) const {
            return current == other.current;
        }
    };

    Node* head;
    Node* rear;
    int len;

    Ciclist();
    ~Ciclist();
    
    Iterator begin();
    Iterator end();

    void push_back(int d);
    void del(Iterator pre);
    Node& operator[](int id);
    Iterator find(Node var);
    
};

Ciclist::Ciclist() 
: head(new Node()), len(0), rear(nullptr) {}

Ciclist::~Ciclist() {
    Node* pre = nullptr;
    Node* now = head;

    if( len==0 )
        head->next=rear=nullptr;
    while (now != head) {
        pre = now;
        now = now->next;
        delete pre;
    }
}

void Ciclist::push_back(int d) {
    if (rear == nullptr) {
        rear = head->next = new Node(d);
    } else {
        rear = rear->next = new Node(d);
    }
    rear->next = head;
    ++len;
}

void Ciclist::del(Iterator var) {
    Node* pre = var.last_one;
    if( pre==nullptr || len==1){
        delete var.current;
        head->next=rear=nullptr;
    }else{
        Node* now = var.current;
        pre->next = now->next;
        delete now;
    }
    --len;
}

Node& Ciclist::operator[](int id) {
    if (id < 0 || id >= len) {
        throw runtime_error("operator[" + to_string(id) + "] outline");
    }

    Node* now = head->next;
    while (id > 0) {
        now = now->next;
        --id;
    }

    return *now;
}

Ciclist::Iterator Ciclist::find(Node var) {
    Node* now = head;
    while (now->next != head && now->next->data != var.data) {
        now = now->next;
    }
    return {now,head};
}

Ciclist::Iterator Ciclist::begin() {
    return Iterator(head->next,head);
}

Ciclist::Iterator Ciclist::end() {
    return Iterator(head,rear);
}


int main(int argc, char** argv)
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k, s;
        scanf("%d%d%d", &n, &k, &s);

        Ciclist var;
        for (int i = 1; i <= n; ++i)
            var.push_back(i);

        

        cout << '\n';
    }

    return 0;
}


