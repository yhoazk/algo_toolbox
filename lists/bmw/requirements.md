##########################################################################
##### Brief
##########################################################################

##########################################################################
##### TASK
##########################################################################

This small exercise is about implementing a self-sorting list in C++. A
list is seen as a container that supports insertion and removal of
elements from anywhere in the container during runtime. You can decide
which C++ dialect you want to use for the implementation.

##########################################################################
##### REQUIREMENTS
##########################################################################

- The type of the objects stored within a list shall be fixed at creation
  time of the list object.
- Different lists shall be able to store different types of objects,
  whereas the object type of one particular list is fixed to one type.
- The sorting algorithm for a certain list shall be fixed at creation time
  of the object.
- It shall be possible to use different sorting algorithms for different
  lists.
- Elements shall be automatically sorted upon insert.
- Basic list functions like insert(..), get(..), remove(..), print() and
  size() are required. No restrictions on how this should work internally.
- It can be assumed, that every type provides stream operators for 
  printing.
- a real implementation is required, wrappers for other list 
  implementations are not allowed.
 
example list setup: 
????? myList(?????);
myList.insert(5);
myList.insert(6);
myList.insert(7);
myList.insert(4);
myList.insert(42);
myList.insert(1);
myList.insert(-5);
myList.print();  

example output of descending ordering:
>> 42, 7, 6, 5, 4, 1, -5