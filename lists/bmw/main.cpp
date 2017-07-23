#include <iostream>
#include <string>
/*[BEGIN]---------------Class Declaration --------------------*/


template <typename T>
struct node
{
  T datum;
  node<T> *next; // remember to init next to null
};


template <typename T>
class linked_list
{
  node<T> *tail;
  node<T> *head;
  /* Given a value X returns the pointer of the list where the next element
   * must be placed */
  node<T> *get_InsertPtr(const T& x);
  /* default sorting algorithm*/
  static bool downSort(const T& x, const T& y){ return (x>=y);}
  static bool primitiveEqual(const T& x, const T& y){ return (x==y);}
  bool (*compare)(const T& x, const T& y);
  bool (*equal)(const T& x, const T& y);
public:
  linked_list()
  {
    tail = nullptr;
    head = nullptr;
    compare = &downSort;
    equal = &primitiveEqual;
  }

  linked_list(bool (*sort)(const T& x, const T& y), bool (*equ)(const T& x, const T& y))
  {
    tail = nullptr;
    head = nullptr;
    compare = sort;
    equal = equ;
  }

  ~linked_list()
  {
    /* Free al the nodes */
    node<T> *tmp_node;
    while(nullptr != this->tail )
    {
      tmp_node = this->tail;
      this->tail = this->tail->next;
      delete tmp_node;
    }
  }
  /* Inserts the value x in it's corresponding place in the list */
  bool insert(const T& x);
  /* Returns the value of the node at index n */
  T get(size_t n);
  /* Removes the first occurence of x found in the list */
  bool remove(T x);
  /* Prints the list in the specified order */
  void print(void);
  /* Returns the number of nodes contained in the list */
  size_t size(void);
  /* Pass the reference to the sorting algorithm */
  /* The function must return true if equal or in the desired order or false if the order is inverse */
  bool set_sortingAlgo(bool (*fnc)(const T& x, const T& y) );
  bool set_equal(bool (*fnc)(const T& x, const T& y));
};

/*---------------Class Declaration --------------------[END]*/


/*[BEGIN]---------------Class implementation --------------------*/


/* Default sorting algorithm for primitive types */



template <typename T>
bool linked_list<T>::insert(const T& x) {
  node<T> *new_node = new node<T>();
  node<T> *insert_location;
  new_node->datum = x;
  new_node->next = nullptr;
  /* Find where in the list this node must be inserted by using the generic sorting algorithm */
  insert_location = linked_list::get_InsertPtr(x);

  if(nullptr == this->tail)
  {
    /* Empty list */
    this->tail = new_node;
    this->head = new_node;
  }
  else if(insert_location == this->tail)
  {
    new_node->next = this->tail;
    this->tail = new_node;
  }
  else if(insert_location == this->head)
  {
    this->head->next = new_node;
    this->head = new_node;
  }
  else
  {
    new_node->next = insert_location->next;
    insert_location->next = new_node;
  }
  return true;
}

template <typename T>
T linked_list<T>::get(size_t n)
{
  T x = T();
  node<T>* current_node = this->tail;
  while(n--)
  {
    current_node = current_node->next;
  }
  return current_node->datum;
};

template <typename T>
bool linked_list<T>::remove(T x)
{
  node<T>* current_node = this->tail;
  node<T>* past_node;
  node<T>* tmp_node;

  if(current_node == nullptr){ return false; }
  bool found = false;
  bool ret_val = false;

  while (found != true ) {
    if(this->equal(x, current_node->datum))
    {
      /* item found */
      if(current_node == this->tail)
      {
          tmp_node = this->tail;
          this->tail = this->tail->next;
      }
      else if(current_node == this->head)
      {
        tmp_node = this->head;
        past_node->next = nullptr;
        this->head = past_node;
      }
      else
      {
        tmp_node = current_node;
        past_node->next = current_node->next;

      }
      delete tmp_node;
      found = true;
    }
    past_node = current_node;
    current_node = current_node->next;
  }
  return ret_val;
}

template <typename T>
void linked_list<T>::print()
{
  node<T>* current_node = this->tail;
  if(current_node == nullptr){ return; }
  while(true)
  {
    std::cout << current_node->datum;
    if(nullptr != current_node->next)
    {
      std::cout << ", ";
    }
    else
    {
      break;
    }
    current_node = current_node->next;
  }
  std::cout << std::endl;

}

template <typename T>
size_t linked_list<T>::size()
{
  /* For the moment it's assumed that there will be no loops in the list  */
  size_t i = 0;
  node<T> *current = this->tail;
  if(nullptr == this->tail) { return 0;}
  while(current != this->head)
  {
    current = current->next;
    i++;
  }
  return ++i; /* Increment to take head into the count */
}

template <typename T>
node<T>* linked_list<T>::get_InsertPtr(const T& x)
{
  node<T> *current_node = this->tail;
  node<T> *past_node = this->tail;
  if(this->tail != nullptr)
  {
    while ( (current_node->next != nullptr) && (!this->compare(x, current_node->datum)) ) {
      past_node = current_node;
      current_node = current_node->next;
    }
  }
  if(current_node == this->head){ past_node = this->head;}
  return past_node;
}
template <typename T>
bool linked_list<T>::set_sortingAlgo(bool (*fnc)(const T& x, const T& y) )
{
  if(nullptr != fnc)
  {
    this->compare = fnc;
  }
}
/*---------------Class implementation --------------------[END]*/


class test{
  int a;
};



bool up(const char& x, const char& y){ return (x<=y);}
bool upstring (const std::string& x, const std::string& y){ return (x.compare(y) == 0);}
/*  */
int main() {
  std::cout << "Hello, World!" << std::endl;

  linked_list<int> myList;
  myList.insert(5);
  myList.insert(6);
  myList.insert(7);
  myList.insert(4);
  myList.insert(42);
  myList.insert(1);
  myList.insert(-5);
  std::cout << "Size of list: " << myList.size() << std::endl;
  myList.print();
  std::cout << "Remove item tail" << std::endl;
  myList.remove(42);
  myList.print();
  std::cout << "Remove item head" << std::endl;
  myList.remove(-5);
  myList.print();
  std::cout << "Remove item from the middle" << std::endl;
  myList.remove(5);
  myList.print();

  std::cout << "Get item from the tail: " << myList.get(0) << std::endl;
  std::cout << "Get item from the head: "  << myList.get(myList.size()-1) << std::endl;
  std::cout << "Get item from the middle: " <<  myList.get(myList.size()/2) << std::endl;
  myList.print();

  /******************** second test *******************/

  linked_list<char> myCharList;
  myCharList.set_sortingAlgo(&up);
  myCharList.insert('a');
  myCharList.print();
  myCharList.insert('b');
  myCharList.print();
  myCharList.insert('c');
  myCharList.print();
  myCharList.insert('t');
  myCharList.print();
  myCharList.insert('r');
  myCharList.print();
  myCharList.insert('2');
  myCharList.print();
  myCharList.insert('2');
  myCharList.print();
  myCharList.insert('2');
  myCharList.print();
  myCharList.insert('z');
  myCharList.print();
  myCharList.insert('3');
  myCharList.print();

  myCharList.remove('3');
  myCharList.print();

  myCharList.remove('c');
  myCharList.print();

  linked_list<std::string> myStringList(upstring, upstring);
  myStringList.insert("A");
  myStringList.insert("ABC");
  myStringList.insert("A1BC");
  myStringList.insert("A1BC");
  myStringList.insert("ArBC");
  myStringList.insert("AeBC");
  myStringList.insert("AzBC");
  myStringList.insert("zABC");
  myStringList.insert("xxx");

  myStringList.print();
  return 0;
}