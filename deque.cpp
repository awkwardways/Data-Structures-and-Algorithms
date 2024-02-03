#include<iostream>

using namespace std;

class deque
{
private:
    struct node
    {
        int val;
        node* next, *prev;
    };
    int size;
    node *front, *back;
public:
    deque()
    {
        size = 0;
        front = nullptr;
        back = front;
    }
    ~deque()
    {
        node* aux = front;
        while(aux != nullptr)
        {
            front = front->next;
            cout << "Deleting " << aux->val << "\n";
            delete aux;
            aux = front;
        }
    }
    void push_back(int x);
    void push_front(int x);
    int showFront();
    int showBack();
    bool empty();
    int showSize();
    void popBack();
    void popFront();
};

void deque::push_back(int x)
{
    if(!size)
    {
        front = new node;
        front->val = x; 
        front->next = nullptr;
        back = front;
        size++;
        return;
    }
    node* aux = new node;
    aux->val = x;
    aux->next = nullptr;
    aux->prev = back;
    back->next = aux;
    back = aux;
    size++;
    return;
}

void deque::push_front(int x)
{
    if(!size)
    {
        front = new node;
        front->val = x;
        front->next = nullptr;
        back = front;
        size++;
        return;        
    }
    node* aux = new node;
    aux->val = x;
    aux->prev = nullptr;
    aux->next = front;
    front->prev = aux;
    front = aux;
    size++;
    return;
}

int deque::showFront(){return(front->val);}

int deque::showBack(){return(back->val);}

bool deque::empty(){return size;}

int deque::showSize(){return size;}

void deque::popBack()
{
    node* aux = back;
    back = back->prev;
    delete aux;
    back->next = nullptr;
}

void deque::popFront()
{
    node* aux = front;
    front = front->next;
    delete aux;
    front->prev = nullptr;
}

int main()
{
    int sel, x;
    deque q;
    while(true)
    {
        cout << "1. Push to front\n2. Push to back\n3. Show front\n4. Show back\n5. Show queue fill state\n6. Pop back\n7. Pop front\n8. Exit";
        cin >> sel;
        switch(sel)
        {
            case 1:
                cin >> x;
                q.push_front(x);
            break;

            case 2:
                cin >> x;
                q.push_back(x);
            break;

            case 3:
                cout << q.showFront() << "\n";
            break;

            case 4:
                cout << q.showBack() << "\n";
            break;

            case 5:
                cout << q.showSize() << "\n";
            break;

            case 6:
                q.popBack();
            break;

            case 7:
                q.popFront();
            break;

            case 8:
                return 0;
            break;
        }
    }
    return 0;
}