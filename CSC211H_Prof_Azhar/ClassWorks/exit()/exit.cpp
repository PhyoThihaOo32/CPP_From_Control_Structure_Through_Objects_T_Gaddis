/*

Terminate calling process
Terminates the process normally, performing the regular cleanup for terminating programs.

Normal program termination performs the following (in the same order):
Objects associated with the current thread with thread storage duration are destroyed (C++11 only).
Objects with static storage duration are destroyed (C++) and functions registered with atexit are called.
All C streams (open with functions in <cstdio>) are closed (and flushed, if buffered), and all files created with tmpfile are removed.
Control is returned to the host environment.

Note that objects with automatic storage are not destroyed by calling exit (C++).

If status is zero or EXIT_SUCCESS, a successful termination status is returned to the host environment.
If status is EXIT_FAILURE, an unsuccessful termination status is returned to the host environment.
Otherwise, the status returned depends on the system and library implementation.


1) What is exit()?
-------------------
exit() is a function that immediately terminates the entire program
and returns a status code to the operating system.

Declared in:
    #include <cstdlib>

Syntax:
    exit(status_code);

Example:
    exit(0);   // successful termination
    exit(1);   // error termination


2) What Happens When exit() Is Called?
--------------------------------------
When exit() executes:

- Program stops immediately
- Remaining code in the function does NOT run
- Control returns to the operating system
- Status code is sent to the OS
- Output buffers are flushed
- Global and static objects are destroyed

BUT IMPORTANT:

Local automatic variables are NOT destroyed.
Stack unwinding does NOT occur.


3) Local Automatic Variables
----------------------------
These are normal variables created inside a function.

Example:

    int main() {
        std::string name = "Phyo";
        exit(0);
    }

Because exit() does NOT unwind the stack:
- The destructor of "name" will NOT run.
- RAII cleanup will NOT happen properly.


4) return vs exit()
--------------------

Using return in main:

    int main() {
        Test t;
        return 0;
    }

- Stack unwinds
- Destructor of t runs
- Clean termination

Using exit():

    int main() {
        Test t;
        exit(0);
    }

- Immediate termination
- Stack does NOT unwind
- Destructor of t does NOT run


5) Why This Matters (RAII)
--------------------------
Modern C++ relies on RAII (Resource Acquisition Is Initialization).

RAII means:
- Objects manage resources
- Destructors clean up resources automatically

Examples:
- File streams
- Smart pointers
- Mutex locks
- Database connections
- Network sockets

exit() bypasses scope cleanup and may cause:
- Memory leaks
- Resource leaks
- File corruption
- Deadlocks


6) EXIT_SUCCESS vs EXIT_FAILURE
-------------------------------
Defined in <cstdlib>:

    EXIT_SUCCESS   // usually 0
    EXIT_FAILURE   // usually non-zero (often 1)

Use EXIT_SUCCESS when:
- Program completed normally
- No errors occurred

Use EXIT_FAILURE when:
- Fatal error occurred
- Program cannot continue safely


7) What Gets Destroyed with exit()?
-----------------------------------

Object Type            Destructor Called?
------------------------------------------
Local automatic        NO
Static/global          YES
Heap objects           NO (unless manually deleted first)


8) Best Practice
----------------
Prefer:

    return EXIT_SUCCESS;
    return EXIT_FAILURE;

Instead of calling exit() directly,
unless you truly need immediate program termination.


=========================================================
SUMMARY
=========================================================

exit():
- Immediately terminates program
- Skips stack unwinding
- Does NOT destroy local automatic objects
- Can break RAII
- Should be used carefully in C++

Use return when possible.
Use exit() only for fatal, unrecoverable errors.
=========================================================
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{

    FILE *pFile;
    pFile = fopen("myfile.txt", "r");
    if (pFile == NULL)
    {
        cout << "Error opening file." << endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}