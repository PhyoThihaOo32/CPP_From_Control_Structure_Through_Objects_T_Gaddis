
// Ordinary variable:
// - Created automatically
// - Stored on the stack usually
// - Accessed directly by name
// - Automatically destroyed when it goes out of scope
// - No need to use delete

// Stack:
// - Used for local variables
// - Memory is managed automatically
// - Fast
// - Variable is destroyed when it goes out of scope
// - Usually smaller than heap

// Dynamic variable:
// - Created manually using new
// - Stored on the heap
// - Accessed through a pointer
// - Stays in memory until deleted
// - Must be deleted manually using delete

// Heap:
// - Used for dynamic memory
// - Created using new
// - Must be deleted manually using delete
// - More flexible
// - Usually larger than stack
// - Can cause memory leak if not deleted

int main()
{
    int x = 10;         // oridinary variable -> stored in stack
    int *ptr = new int; // dynamic variable -> stored in heap
    delete ptr;
    ptr = nullptr;
}
