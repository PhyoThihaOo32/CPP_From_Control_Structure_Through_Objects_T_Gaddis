/*
=========================================================
SMART POINTERS IN C++
=========================================================

Definition:
- Smart pointers are objects that manage dynamic memory automatically.
- They help prevent memory leaks by deleting memory when it is no longer needed.

Header:
    #include <memory>

---------------------------------------------------------

Why use smart pointers?

- Avoid manual use of new and delete
- Prevent memory leaks
- Ensure exception safety
- Automatically free memory when object goes out of scope

---------------------------------------------------------

Types of Smart Pointers
=========================================================

1) unique_ptr

- Exclusive ownership (only ONE pointer owns the object)
- Cannot be copied
- Can be moved

Example:
    unique_ptr<int> p = make_unique<int>(10);

Key Points:
- When p goes out of scope → memory is deleted automatically
- Ownership cannot be shared

---------------------------------------------------------

2) shared_ptr

- Shared ownership (multiple pointers can point to same object)
- Uses reference counting

Example:
    shared_ptr<int> p1 = make_shared<int>(10);
    shared_ptr<int> p2 = p1;

Key Points:
- Memory is deleted when last shared_ptr is destroyed
- Reference count keeps track of owners

---------------------------------------------------------

3) weak_ptr

- Non-owning pointer
- Used with shared_ptr to avoid circular references

Example:
    weak_ptr<int> wp = p1;

Key Points:
- Does NOT increase reference count
- Must be converted using lock() to access object

---------------------------------------------------------

Important Concepts
=========================================================

Ownership:
- unique_ptr → single owner
- shared_ptr → multiple owners
- weak_ptr → observer (no ownership)

---------------------------------------------------------

Memory Management:

Traditional pointer:
    int* p = new int(10);
    delete p;   // must remember

Smart pointer:
    unique_ptr<int> p = make_unique<int>(10);
    // automatically deleted

---------------------------------------------------------

Advantages:

✔ Automatic memory cleanup
✔ Prevent memory leaks
✔ Safer than raw pointers
✔ Clear ownership semantics

---------------------------------------------------------

Disadvantages:

Slight overhead (especially shared_ptr)
Must understand ownership rules

---------------------------------------------------------

Exam One-Liner:

Smart pointers are objects that automatically manage dynamic memory
by ensuring proper deletion, improving safety and preventing memory leaks.

=========================================================
*/

#include <iostream>
#include <memory>

using namespace std;

int main()
{

    unique_ptr<int> ptr(new int);

    *ptr = 99;

    cout << *ptr << endl;

    return 0;
}