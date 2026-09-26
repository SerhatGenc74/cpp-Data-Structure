#include "header.h"

template <typename T>
class LinkedList;

template <typename T>
struct Node
{
    T data;
    Node *next;
    Node(T val) : data(val), next(nullptr) {}
};
template <typename T>
class LinkedList
{

private:
    Node<T> *head;
    size_t size;

public:
    LinkedList() : head(nullptr) {}

    LinkedList(T value) : head(new Node<T>(value)), size(1) {}

    //------------------------------------------------------------------------------------------------

    // setter and getter for data
    void setData(T value)
    {
        head->data = value;
    }

    //------------------------------------------------------------------------------------------------

    T getData() const
    {
        return head->data;
    }

    size_t getSize() const
    {
        return size;
    }


    //------------------------------------------------------------------------------------------------

    void PrintAllNode()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    //------------------------------------------------------------------------------------------------

    void Reverse()
    {
        Node<T> *prev = nullptr;
        Node<T> *current = head;
        while (current != nullptr)
        {
            Node<T> *nextNode = current->next; // Store next node
            current->next = prev;
            prev = current;     // Move prev to current
            current = nextNode; // Move to next node
        }
        head = prev; // Update head to the new first node
    }

    //------------------------------------------------------------------------------------------------

    void AddToFront(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head; // Point new node to the current head
        head = newNode;       // Update head to the new node
    }

    //------------------------------------------------------------------------------------------------

    void AddToEnd(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (head == nullptr)
        {
            head = newNode; // If the list is empty, set head to new node
            return;
        }
        Node<T> *current = head;

        // Traverse to the end of the list
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode; // Link the new node at the end
    }

    //------------------------------------------------------------------------------------------------

    void DeleteNode(int position)
    {
        Node<T> *head = this;
        if (head == nullptr)
        {
            return; // List is empty, nothing to delete
        }

        Node<T> *prev = nullptr;
        Node<T> *current = head;

        for (int i = 1; current != nullptr && i < position; i++)
        {
            prev = current;          // Keep track of the previous node
            current = current->next; // Move to the next node
        }

        prev->next = current->next; // Link the previous node to the next node
        head = prev;                // Update head to the previous node
        delete current;             // Delete the current node
    }

    //------------------------------------------------------------------------------------------------

    bool Search(T value)
    {
        Node<T> *head = this;
        Node<T> *current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                return true; // Value found
            }
            current = current->next; // Move to the next node
        }
        return false; // Value not found
    }

    //------------------------------------------------------------------------------------------------

    // Check is in cycle
    bool IsCycle()
    {
        Node<T> *head = this;
        Node<T> *fast = head;
        Node<T> *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next; // Move fast pointer two steps
            slow = slow->next;       // Move slow pointer one step
            if (fast == slow)
            {
                return true; // Cycle detected
            }
        }
        return false; // No cycle detected
    }
};

//------------------------------------------------------------------------------------------------

//LIFO Last In First Out
template <typename T>
class Stack
{
private:
    Node<T> *top; // Pointer to the top of the stack
public:
    Stack() : top(nullptr) {} // Add constructor to initialize top

    ~Stack()
    {
        while (top != nullptr)
        {
            pop(); // Pop all elements to free memory
        }
    }

    //------------------------------------------------------------------------------------------------

    void push(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = top; // Link the new node to the current top
        top = newNode;         // Update top to the new node
    }

    //------------------------------------------------------------------------------------------------

    void pop()
    {
        if(top == nullptr) // Check if the stack is empty
        {
            cout << "Stack is empty, cannot pop." << endl;
            return;
        }
        else
        {
            Node<T> *temp = top; // Store the current top node
            top = top->next;       // Update top to the next node
            delete temp;               // Delete the old top node
        }
    }

    //------------------------------------------------------------------------------------------------

    T peek()
    {
        if (top == nullptr) // checck if the stack is empty
        {
            cout << "Stack is empty, cannot peek." << endl;
            return T(); // Return default value of T
        }
        else
        {
            return top->data; // Return the data of the top node
        }
    }

    bool isEmpty()
    {
        return top == nullptr;
    }


    bool isFull()
    {
        return false; // Stack is never full in this implementation
    }

    int getSize()
    {
        int size = 0;
        Node<T> *temp = top;
        while (temp != nullptr)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }
};

//------------------------------------------------------------------------------------------------

// FIFO First In First Out
template <typename T>
class Queue
{
    public:

    Queue() : front(nullptr), rear(nullptr), size(0) {}
    
    void Enqueue(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (rear == nullptr) // If the queue is empty
        {
            rear = front = newNode; // Both front and rear point to the new node
        }
        else
        {
            rear->next = newNode; // Link the new node at the end of the queue
            rear = newNode;        // Update rear to the new node
        }
    }
    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty, cannot dequeue." << endl;
            return;
        }
        else
        {
            Node<T> *temp = front; // Store the current front node
            front = front->next;    // Update front to the next node
            if (isEmpty())   // If the queue is now empty
            {
                rear = nullptr; // Update rear to nullptr as well
            }
            delete temp; // Delete the old front node
        }
    }
    bool isEmpty()
    {
        return front == nullptr;
    }
    Node<T> *getFront()
    {
        return front;
    }
    Node<T> *getRear()
    {
        return rear;
    }
    void display()
    {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue:  ";
        Node<T> *current = front;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }


    private:
    Node<T> *front; // Pointer to the front of the queue
    Node<T> *rear;  // Pointer to the rear of the queue
    size_t size;          // Size of the queue
};


int main()
{

    //------------------------------------------------------------------------------------------------

    // Creating LinkedList
    LinkedList<int> *list = new LinkedList<int>(10);
    list->AddToEnd(20);
    list->AddToEnd(30);
    list->PrintAllNode();

    //------------------------------------------------------------------------------------------------

    // Add to front
    list->AddToFront(5);
    list->PrintAllNode();

    //------------------------------------------------------------------------------------------------

    // Add to end
    list->AddToEnd(40);
    list->PrintAllNode();

    //------------------------------------------------------------------------------------------------

    // Delete a node at position 2
    list->DeleteNode(2);
    list->PrintAllNode();

    //------------------------------------------------------------------------------------------------

    // Reverse the linked list
    list->Reverse();
    list->PrintAllNode();

    //------------------------------------------------------------------------------------------------

    // Search for values
    std::cout << "Search 20: " << (list->Search(20) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 30: " << (list->Search(30) ? "Found" : "Not Found") << std::endl;

    //------------------------------------------------------------------------------------------------

    // Create a cycle for testing
    std::cout << "Is Cycle: " << (list->IsCycle() ? "Yes" : "No") << std::endl;

    return 0;
}