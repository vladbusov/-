template <class T>
class Stack {
public:
    Stack() = default;
    ~Stack() { free(); }
 
    Stack( const Stack<T>& other ) = delete;
    Stack( Stack<T>&& other ) { *this = std::forward<Stack>( other ); }
 
    Stack<T>& operator=( const Stack<T>& other ) = delete;
    Stack<T>& operator=( Stack<T>&& other );
 
    bool IsEmpty() const { return head == 0; }
 
    void Push( const T& value );
    void Pop();
    const T& Top() const;
 
private:
    struct Node {
        T Data;
        Node* Next = 0;
 
        Node( const T& data ) : Data( data ) {}
    };
 
    Node* head = 0;
 
    void free();
};
 
template <class T>
Stack<T>& Stack<T>::operator=( Stack<T>&& other )
{
    free();
    head = other.head;
    other.head = 0;
 
    return *this;
}
 
template <class T>
void Stack<T>::free()
{
    while( !IsEmpty() ) {
        Pop();
    }
}
 
template <class T>
void Stack<T>::Push( const T& data )
{
    Node* newNode = new Node( data );
    newNode->Next = head;
    head = newNode;
}
 
template <class T>
void Stack<T>::Pop()
{
    assert( !IsEmpty() );
 
    Node* nodeToDelete = head;
    head = head->Next;
 
    delete nodeToDelete;
}
 
template <class T>
const T& Stack<T>::Top() const
{
    assert( !IsEmpty() );
    return head->Data;
}