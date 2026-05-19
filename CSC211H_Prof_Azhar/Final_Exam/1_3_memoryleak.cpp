/*
Memory leak occurs when dynamic memory is allocated but not properly released.
*/

int main()
{
    int *ptr = new int; // memory leak if forget to delete the point

    delete ptr;
    ptr = nullptr;

    // for dynamic array
    int *ptr = new int[10];

    delete[] ptr;
    ptr = nullptr;
}