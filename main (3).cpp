#include <iostream>

template <typename T>

class Linked_List
{
public:

struct Node
{
  T data;
  Node* next;
  Node(const T& value) : data(value), next(nullptr) {}
  };

  Node* head;
    // Constructor
  Linked_List() : head(nullptr) {}

    // Destructor
    ~Linked_List()
    {
      clear();
    }

    // Copy constructor
  Linked_List(const Linked_List& other) : head(nullptr)
    {
      Node* current = other.head;
      while (current)
      {
        insert(current->data);
        current = current->next;
      }
    }

    // Assignment operator
  Linked_List& operator=(const Linked_List& other)
    {
      if (this != &other)
      {
        clear();
        Node* current = other.head;
        while (current)
        {
          insert(current->data);
          current = current->next;
        }
      }

      return *this;
    }

    // Check if the Linked_List is empty
  bool empty() const
    {
      return head == nullptr;
    }

    // Traverse and print the Linked_List
    void traverse() const
    {
      Node* current = head;
      while (current)
      {
        std::cout << current->data << " ";
        current = current->next;
      }

      std::cout << std::endl;
    }

    // Insert an element at the beginning of the Linked_List
    void insert(const T& item)
    {
      Node* newNode = new Node(item);
      newNode->next = head;
      head = newNode;
    }

    // Delete the first occurrence of an element in the Linked_List
    void remove(const T& item)
    {
      Node* current = head;
      Node* prev = nullptr;

      while (current)
      {
        if (current->data == item)
        {
          if (prev)
          {
            prev->next = current->next;
          }
          else
          {
            head = current->next;
          }

        delete current;
        return;
        }
        prev = current;
        current = current->next;
      }
    }

    // Search the Linked_List for a given item
    Node* search(const T& item) const
    {
      Node* current = head;
      while (current)
      {
        if (current->data == item)
        {
          return current;
        }
          current = current->next;
      }

      return nullptr;
    }

    // Clear the Linked_List and free memory
    void clear()
    {
      Node* current = head;
      while (current)
      {
        Node* temp = current;
        current = current->next;
        delete temp;
      }

      head = nullptr;
    }
};

int main()
{
  Linked_List<int> myLinked_List;
  myLinked_List.insert(10);
  myLinked_List.insert(20);
  myLinked_List.insert(30);
  myLinked_List.insert(40);
  myLinked_List.insert(50);
  myLinked_List.insert(60);
  myLinked_List.insert(70);

  std::cout << "Linked_List: ";
  myLinked_List.traverse();  // Print the Linked_List: 30 20 10

  Linked_List<int> copiedLinked_List = myLinked_List;   // Copy constructor

  std::cout << "\nLinked_List after copy: ";
  copiedLinked_List.traverse();

  std::cout << "\nCopied Linked_List after Remove one Element (20 Removed): ";
  copiedLinked_List.remove(20);
  copiedLinked_List.traverse();  // Output: 30 10

  Linked_List<int> anotherLinked_List;
  anotherLinked_List = myLinked_List;  // Assignment operator

  std::cout << "\nLinked_List after insertion (80 added): ";
  anotherLinked_List.insert(80);
  anotherLinked_List.traverse();  // Output: 40 30 20 10

  Linked_List<int>::Node* node = myLinked_List.search(20);
  if (node)
  {
    std::cout << "\nYour searched element: " << node->data << std::endl;
  }
  else
  {
    std::cout << "\nNot found." << std::endl;
  }

  system("pause>0");
}
