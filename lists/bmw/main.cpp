#include <iostream>

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
public:
  linked_list()
  {
    tail = nullptr;
    head = nullptr;
  }
  ~linked_list(){
    /* Free al the nodes */
  }
  /* Inserts the value x in it's corresponding place in the list */
  bool insert(const T& x);
  /* Returns the value of the node at index n */
  T get(size_t n);
  /* Removes the node at index n */
  bool remove(T n);
  /* Prints the list in the specified order */
  void print(void);
  /* Returns the number of nodes contained in the list */
  size_t size(void);
  /* Pass the reference to the sorting algorithm */
  bool set_sortingAlgo(void (*fnc)(bool) ); // TODO
};

/*---------------Class Declaration --------------------[END]*/


/*[BEGIN]---------------Class implementation --------------------*/


/* Default sorting algorithm */


template <typename T>
bool linked_list<T>::insert(const T& x) {
  node<T> *new_node = new node<T>();
  new_node->datum = x;
  new_node->next = nullptr;
  /* Find where in the list this node must be inserted */



  if(nullptr == this->tail)
  {
    /* This is the first element of the list */
    this->tail = new_node;
  }
  else
  {
    this->head = new_node;
  }
  return true;
}

template <typename T>
T linked_list<T>::get(size_t n)
{
  return 0;
};

template <typename T>
bool linked_list<T>::remove(T n)
{

}

template <typename T>
void linked_list<T>::print()
{

}

template <typename T>
size_t linked_list<T>::size()
{
  return 2;
}
/*---------------Class implementation --------------------[END]*/

/*  */
int main() {
  std::cout << "Hello, World!" << std::endl;

  linked_list<int> int_list;

  int_list.insert(5);

  return 0;
}