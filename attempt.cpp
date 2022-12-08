#include <forward_list>
#include <iostream>
using namespace std;
/* Project task: Implementation of Heaps using linked lists. We'll use minHeap.
                 -> Insert an element in the heap (new elements)
                 -> Delete an element in the heap (existing elements)
*/
//function prototypes
void insert_element();
void delete_element();
//Global variables
forward_list<int> list1; 
int insert_new;
int delete_new;
char userinput;
char uinput;
// Additional note: Forward list --> a singly linked list with forward traversal only. 
int main () {

    // Assign list values using assign() function 
    list1.assign({10, 15, 19, 20, 26, 27, 31, 33, 35});
    // display the forward list 
    cout << "The current list of the elements include: ";
    for (int& a : list1)
        cout << a << " ";
    cout << endl;
    
    //prompt user whether want to insert element
    cout << "Insert an element into the minHeap ? ";
    cin >> userinput;

    do {

       // insert new element (userinput)
       if (userinput == 'y' || userinput == 'Y') {
           insert_element(); 
           break;
       } else if(userinput == 'n' || userinput == 'N') {
           delete_element();
           break;
       } else {
            cout << "Invalid input detected!" << endl;
       }

    }while(userinput != 'y' || userinput != 'Y' || userinput != 'n' || userinput != 'N');

    return 0;
}
// Insert an element at the end by userinput
void insert_element() {
    
    // find the iterator to the last element by incrementing .before_begin N times
    auto before_end = list1.before_begin();
    for (auto& _ : list1)
    ++ before_end;
    cout << "Insert a numerical element into heap: ";
    cin >> insert_new;
    list1.insert_after(before_end, insert_new);
    //check if insert_new is appropriate value or requires bubble-sort
    if(insert_new < 35) {
        list1.sort();
        cout << "Heap after insertion of new element: ";
        // output of the forward list after sort
        for (auto it = list1.begin(); it != list1.end(); ++it)
            cout << ' ' << *it;
            cout << endl;
    } else {
         // output of forward list (no bubble-sort needed)
        cout << "Heap after insertion of new element: ";
        for (int& c : list1)
           cout << c << " ";
        cout << endl;
    }

    delete_element();
}
// delete an existing element 
void delete_element() {
    
   cout << "Delete an element from the minHeap ? ";
   cin >> uinput;
   // switch case statement for validation and process
   switch(uinput) {
       case 'y': {  // delete existing element (userinput)
                cout << "Insert an existing heap value for deletion: ";
                cin >> delete_new;
                list1.remove(delete_new);
                // check if delete_new is appropriate value or requires bubble-down
               if(delete_new >= insert_new) {
               //output of forward list (no bubble-down needed)
               cout << "Heap after deletion of last element: ";
               for (int& d : list1)
                   cout << d << " ";
               cout << endl;
              } else {
                //output of forward list after bubble-down
                auto prev = list1.before_begin();
                for (auto it = list1.begin(); it != list1.end(); ++it) {
                    if(*it== delete_new) { // instead of delete_new, can also use any known position 
                      list1.erase_after(prev);
                      break;
                    }
                    prev=it;
                }
                list1.sort();
                cout << "Heap after deletion of existing element: ";
                for (int& e : list1)
                    cout << e << " ";
                cout << endl;
            } 
        } break;
        case 'n': {
            cout << "Only insertion and deletion is applicable for the program! Thank you. ";
        } break;
        default: {
            cout << "Invalid input detected!" << endl;
        }
   } cout << endl;
   return;
}
// The End
