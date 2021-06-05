/*~*~*
   Stack template
 
 Written by: Shun Furuya
 IDE: Xcode
*~*/

#ifndef STACK_ADT
#define STACK_ADT

template <class T>
class Stack
{
private:
    // Structure for the stack nodes
    struct StackNode
    {
      T value;          // Value in the node
      StackNode *next;  // Pointer to next node
    };

    StackNode *top;     // Pointer to the stack top
    int length;

public:
    Stack(){ top = NULL; length = 0;}// Constructor
    ~Stack();// Destructor

    // Stack operations:
    // push()
    bool push(T);
    // pop()
    T pop();
    // peek()
    T peek(){ return top->value;};
    // isEmpty()
    bool isEmpty(){
        if(length == 0)
           return true;
        else
           return false;
    };
    // getLength()
    int getLength(){ return length;};
};


/*~*~*
  Member function push inserts the argument onto
  the stack.
*~**/
template <class T>
bool Stack<T>::push(T item){
    StackNode *newNode;
    
    newNode = new StackNode;
    
    if(!newNode)
        return false;
    
    newNode->value = item;
    newNode->next = top;
    top = newNode;
    length++;
    
    //cout << " Push:" << item << endl;
    
    return true;
}


/*~*~*
  Member function pop deletes the value at the top
  of the stack and returns it.
  Assume stack is not empty.
*~**/
template <class T>
T Stack<T>::pop(){
//    T temp = top->value;
//    top = top->next;
//    --length;
//    return temp;
    StackNode *temp; // Temporary pointer

    T item = top->value;
    temp = top->next;
    delete top; //<==== missing
    top = temp;
    length--;

    return item;
}


//Destructor
template <class T>
Stack<T>::~Stack(){
    StackNode *currNode;
    
    while (top != NULL)
    {
       currNode = top;
       top = top->next;
       delete currNode;
    }
    //cout << "delete" << endl;
}


#endif
