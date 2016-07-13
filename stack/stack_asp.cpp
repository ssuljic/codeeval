template <typename T>
class Stack {
    struct Node {
        T element;
        Node* next;
        Node* previous;
    };
    Node* first;
    Node* last;
    int count;
public:
    Stack() : count(0), first(0), last(0) {}

    ~Stack() {
        clear();
    }

    Stack(const Stack &s) {
        if(s.count == 0) throw "Empty stack";
        count = s.count;
        first = new Node;
        first->element = s.first->element;
        first->previous = 0;
        Node* p = first;
        Node* k = s.first;
        int i = 1;
        for(;;) {
            p->next = new Node;
            p->next->previous = p;
            p=p->next;
            k=k->next;
            p->element=k->element;
            if(k->next==0) {
            p->next=0;
            last=p;
            break;
            }
        }
    }

    Stack &operator =(const Stack &s) {
        if(s.count==0) throw "Stek je prazan!";
        clear();
        count = s.count;
        first = new Node;
        first->element = s.first->element;
        first->previous = 0;
        Node* p = first;
        Node* k = s.first;
        int i(1);
        for(;;) {
            p->next = new Node;
            p->next->previous = p;
            p = p->next;
            k = k->next;
            p->element = k->element;
            if(k->next == 0) {
                p->next = 0;
                last = p;
                break;
            }
        }
        return *this;
    }

    void clear() {
        Node *p(first);
        while(p != 0) {
            p = p->next;
            delete first;
            first = p;
        }
        first = 0;
        last = 0;
        count = 0;
    }

    void push(const T &el) {
        if(count == 0) {
            first = new Node;
            first->next = 0;
            first->previous = 0;
            last = first;
            first->element = el;

        } else {
            last->next = new Node;
            Node *p(last);
            last = last->next;
            last->next = 0;
            last->previous = p;
            last->element = el;
        }
        count++;
    }

    T pop() {
        if(count == 0) throw "Empty stack";
        else if(count == 1) {
            T ret(last->element);
            delete last;
            first = 0;
            last = 0;
            count = 0;
            return ret;
        } else {
            T ret(last->element);
            last = last->previous;
            delete last->next;
            last->next = 0;
            count--;
            return ret;
        }
    }

    T& head() {
        if(count == 0) throw "Empty stack";
        return last->element;
    }

    int size() const {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }
};