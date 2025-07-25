#include "header.h"

template<typename T>  
class LinkedList;

template<typename T>  
class LinkedList
{
    
private:
   T data;
   LinkedList* next;
   
public:
    LinkedList(T value) : data(value),next(nullptr){}


//------------------------------------------------------------------------------------------------


    //setter and getter for data
    void setData(T value) {
        data = value;
    }

//------------------------------------------------------------------------------------------------


    T getData() const {
        return data;
    }

//------------------------------------------------------------------------------------------------
    

    //setter and getter for next
    void setNext(LinkedList* nextNode) {
        next = nextNode;
    }

//------------------------------------------------------------------------------------------------


    LinkedList* getNext() const {
        return next;
    }
    
//------------------------------------------------------------------------------------------------


    void PrintAllNode()
    {
        LinkedList<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

//------------------------------------------------------------------------------------------------


    void Reverse()
    {   
        LinkedList<T>* prev = nullptr;
        LinkedList<T>* current = head;
        while (current != nullptr)
        {
            LinkedList<T>* nextNode = current->next; // Store next node
            current->next = prev;
            prev = current; // Move prev to current
            current = nextNode; // Move to next node
        }
        head = prev; // Update head to the new first node 
    }
    
//------------------------------------------------------------------------------------------------


    void AddToFront(T value)
    {
        LinkedList<T>* newNode = new LinkedList<T>(value);
        newNode->next = head; // Point new node to the current head
        head = newNode; // Update head to the new node
    }

//------------------------------------------------------------------------------------------------


    void AddToEnd(T value)
    {
        LinkedList<T>* newNode = new LinkedList<T>(value);
        if (head == nullptr) {
            head = newNode; // If the list is empty, set head to new node
            return;
        }
        LinkedList<T>* current = head;

        // Traverse to the end of the list
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode; // Link the new node at the end
    }
  
//------------------------------------------------------------------------------------------------
    

    void DeleteNode(int position)
    {
        
        if (head == nullptr) {
            return; // List is empty, nothing to delete
        }

        LinkedList<T>* prev = nullptr;
        LinkedList<T>* current = head;
        
        for (int i = 1; current != nullptr && i < position; i++) {
            prev = current; // Keep track of the previous node
            current = current->next; // Move to the next node
        }
        
        prev->next = current->next; // Link the previous node to the next node
        head = prev; // Update head to the previous node
        delete current; // Delete the current node
        
    }

//------------------------------------------------------------------------------------------------


    bool Search(T value)
    {
        LinkedList<T>* current = head;
        while (current != nullptr)
        {
            if (current->data == value) {
                return true; // Value found
            }
            current = current->next; // Move to the next node
        }
        
    }

//------------------------------------------------------------------------------------------------

    //Check is in cycle
    bool IsCycle()
    {
        LinkedList<T>* fast = head;
        LinkedList<T>* slow = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next; // Move fast pointer two steps
            slow = slow->next; // Move slow pointer one step
            if (fast == slow) {
                return true; // Cycle detected
            }
        }
        return false; // No cycle detected
    }
    

};


//------------------------------------------------------------------------------------------------

template<typename T>
class Stack
{
private:
    LinkedList<T>* top; // Pointer to the top of the stack
public:
    stack() : top(nullptr) {} // Constructor initializes the stack to empty
    ~stack() {
        while (top != nullptr) {
            pop(); // Pop all elements to free memory
        }
    }

//------------------------------------------------------------------------------------------------


    void push(T value)
    {
        LinkedList<T>* newNode = new LinkedList<T>(value);
        if (top == nullptr)
        {
            cout << "Stack is empty, adding first element: " << value << endl;
            top = newNode;
        }
        else
        {
            cout << "Pushing element onto stack: " << value << endl;
            newNode->next = top; // Link the new node to the previous top
            top = newNode; // Update top to the new node
        }
        
    }

//------------------------------------------------------------------------------------------------


    void pop()
    {
        if(top == nullptr)
        {
            cout << "Top is empty need add element";
            return;
        }
        LinkedList<T>* temp = top;
        top = top->next;
        delete temp; 
    }

//------------------------------------------------------------------------------------------------


    int getSize()
    {
        int size = 0;
        LinkedList<T>* temp = top;
        while(temp != nullptr)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }
    
};


int main() {


//------------------------------------------------------------------------------------------------

    //Creating LinkedList
    LinkedList<int>* node1 = new LinkedList<int>(10);
    LinkedList<int>* node2 = new LinkedList<int>(20);
    LinkedList<int>* node3 = new LinkedList<int>(30);
    node1->setNext(node2);
    node2->setNext(node3);
    node1->PrintAllNode();

//------------------------------------------------------------------------------------------------


    // Add to front
    node1->AddToFront( 5);
    node1->PrintAllNode();

//------------------------------------------------------------------------------------------------
    
    // Add to end
    node1->AddToEnd(40);
    node1->PrintAllNode();

//------------------------------------------------------------------------------------------------

    // Delete a node at position 2
    node1->DeleteNode(2);
    node1->PrintAllNode();

//------------------------------------------------------------------------------------------------

    // Reverse the linked list
    node1->Reverse();
    node1->PrintAllNode();

//------------------------------------------------------------------------------------------------

    // Search for values
    std::cout << "Search 20: " << (node1->Search(20) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 30: " << (node1->Search(30) ? "Found" : "Not Found") << std::endl;

//------------------------------------------------------------------------------------------------

    // Create a cycle for testing
    std::cout << "Is Cycle: " << (node1->IsCycle() ? "Yes" : "No") << std::endl;
    

    return 0;
}