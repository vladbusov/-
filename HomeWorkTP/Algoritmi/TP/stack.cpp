
template <class T>
class Stack{
public:
    Stack() = default;
    ~Stack();

    Stack(const Stack& other ) = delete;
    Stack(Stack&& other);

    Stack& operator=(const Stack& other) = delete;
    Stack& operator=(Stack&& other){*this = other;}

    bool IsEmpty() {return head == 0}

    void push(const T& value);
    void pop();
    const T& top() const;
private:
    struct Node{
        T Data;
        Node* Next;
    
        Node*( const T& data): Data(data){}
    }
    Node<T> head;

};

template<class T>
void Stack::Push(const T& data){
    Node* newNode = new Node(data);
    newNode->Next = head;
    head = newNode;
}

template<class T>
void Stack::pop(){
    assert(!IsEmpty());

    Node* nodeToDelete = head;
    head = head->Next;

    delete nodeToDelete
}

template <class T>
Sctack::Stack(Stack&& other){
    head = other.head; 
    other.head = 0;
}

template <class Y>
Stack& stack::operator=(Stack&& other){
    free();
    head = other.head;
    other.head = 0;
}

template <class T>
const T& Stack::top() const{
    assert(!IsEmpty());
    return head->data;
}
Stack::~Stack(){

}