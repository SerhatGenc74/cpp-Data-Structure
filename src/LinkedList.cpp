#include "header.h"

template<typename T>  
class LinkedList;



int main() {
    LinkedList<int>* node1 = new LinkedList<int>(10);
    LinkedList<int>* node2 = new LinkedList<int>(20);
    LinkedList<int>* node3 = new LinkedList<int>(30);
    node1->next = node2;
    node2->next = node3;
    
    node1->PrintAllNode(node1);

    return 0;
}   


template<typename T>  
class LinkedList
{

public:
   T data;
   LinkedList* next;
   

    LinkedList(T value) : data(value),next(nullptr){}

    void PrintAllNode(LinkedList<T>* head)
    {
        LinkedList<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

};

