#include "Ship.h"
#include "CargoShip.h"
#include "CruiseShip.h"

#include <memory> // for std::unique_ptr, std::make_unique
#include <vector> // for std::vector

int main()
{
    // ===================================================================
    // VERSION A: STACK ARRAY OF POINTERS TO HEAP OBJECTS
    // ===================================================================
    // Declaration: Ship *ptrA[3]
    //   Read right-to-left from the name:
    //     "ptrA is an array of 3 pointers to Ship"
    //   The ARRAY itself lives on the STACK (no `new` for the array).
    //   The Ship objects the pointers point to live on the HEAP.
    //
    // Memory picture:
    //
    //   STACK                              HEAP
    //   ┌──────────────┐
    //   │ ptrA[0] ●────┼──────────────► [ Ship       ]
    //   │ ptrA[1] ●────┼──────────────► [ CruiseShip ]
    //   │ ptrA[2] ●────┼──────────────► [ CargoShip  ]
    //   └──────────────┘
    //
    // Cleanup rule: only delete what you `new`'d.
    //   3 `new`s for the Ships  →  3 `delete`s.
    //   0 `new` for the array   →  0 `delete` for the array.
    // -------------------------------------------------------------------

    cout << "===== VERSION A: stack array of pointers =====" << endl;

    Ship *ptrA[3] = {
        new Ship("Delphinus", "1990"),             // heap-allocated Ship
        new CruiseShip("Titanic", "1880", 200),    // heap-allocated CruiseShip
        new CargoShip("Tokyo Maru", "1998", 20000) // heap-allocated CargoShip
    };

    cout << "Our Fleet Info" << endl;

    // Polymorphic loop — virtual print() dispatches to the actual
    // derived class's print() based on each object's real type.
    for (int i = 0; i < 3; i++)
    {
        ptrA[i]->print();
    }

    // Cleanup: free each Ship that was new'd.
    // Relies on Ship having a virtual destructor so that the correct
    // derived destructor runs (CruiseShip's for ptrA[1], etc.).
    for (int i = 0; i < 3; i++)
    {
        delete ptrA[i];
    }

    // NOTE: No `delete ptrA;` — the array is on the stack.
    // NOTE: No `ptrA = nullptr;` — array names aren't assignable.

    // ===================================================================
    // VERSION B: HEAP ARRAY OF POINTERS TO HEAP OBJECTS
    // ===================================================================
    // Declaration: Ship **ptrB = new Ship*[3]
    //   Read right-to-left from the name:
    //     "ptrB is a pointer to a pointer to Ship"
    //   The single pointer `ptrB` lives on the STACK.
    //   `new Ship*[3]` allocates an array of 3 Ship* on the HEAP,
    //   and ptrB points to the first element of that array.
    //   The Ship objects themselves are also on the HEAP.
    //
    // Memory picture:
    //
    //   STACK          HEAP
    //   ┌──────┐      ┌──────────────┐
    //   │ ptrB ●─────►│ ptrB[0] ●────┼──────────────► [ Ship       ]
    //   └──────┘      │ ptrB[1] ●────┼──────────────► [ CruiseShip ]
    //                 │ ptrB[2] ●────┼──────────────► [ CargoShip  ]
    //                 └──────────────┘
    //
    // Cleanup rule: only delete what you `new`'d.
    //   3 `new`s for the Ships          →  3 `delete`s.
    //   1 `new[]` for the pointer array →  1 `delete[]`.
    // -------------------------------------------------------------------

    cout << "\n===== VERSION B: heap array of pointers =====" << endl;

    // Allocate the array of 3 Ship pointers on the heap.
    // The 3 slots exist now but hold garbage until we assign to them.
    Ship **ptrB = new Ship *[3];

    // Make each pointer point to its own heap-allocated Ship object.
    ptrB[0] = new Ship("Delphinus", "1990");
    ptrB[1] = new CruiseShip("Titanic", "1880", 200);
    ptrB[2] = new CargoShip("Tokyo Maru", "1998", 20000);

    cout << "Our Fleet Info" << endl;

    // The access syntax is identical to Version A.
    for (int i = 0; i < 3; i++)
    {
        ptrB[i]->print();
    }

    // Cleanup in TWO stages, in this order:

    // Stage 1: delete each Ship object the pointers point to.
    // Must happen BEFORE deleting the array, or we'd lose the
    // pointers and leak every Ship.
    for (int i = 0; i < 3; i++)
    {
        delete ptrB[i];
    }

    // Stage 2: delete the array of pointers itself.
    // Use `delete[]` (array form) because we allocated with `new[]`.
    delete[] ptrB;

    // Optional but good practice — ptrB is a real pointer variable
    // (unlike ptrA which was an array name), so this is legal here.
    ptrB = nullptr;

    // ===================================================================
    // VERSION C: MODERN C++ — std::vector OF std::unique_ptr
    // ===================================================================
    // This is the modern equivalent. No raw `new`, no manual `delete`,
    // no leaks possible. The vector manages the array storage; each
    // unique_ptr owns its Ship and deletes it automatically when the
    // unique_ptr is destroyed (which happens when the vector is
    // destroyed at end of scope).
    //
    // Memory picture is the same as Version B — the vector's internal
    // buffer lives on the heap, each unique_ptr inside it points to a
    // heap-allocated Ship — but cleanup is fully automatic.
    // -------------------------------------------------------------------

    cout << "\n===== VERSION C: vector of unique_ptr (modern C++) =====" << endl;

    std::vector<std::unique_ptr<Ship>> fleet;
    fleet.push_back(std::make_unique<Ship>("Delphinus", "1990"));
    fleet.push_back(std::make_unique<CruiseShip>("Titanic", "1880", 200));
    fleet.push_back(std::make_unique<CargoShip>("Tokyo Maru", "1998", 20000));

    cout << "Our Fleet Info" << endl;

    // Range-based for loop. Each `ship` is a reference to a unique_ptr<Ship>.
    // We use `->` on the unique_ptr to call print() on the underlying Ship.
    // Virtual dispatch works exactly as before.
    for (const auto &ship : fleet)
    {
        ship->print();
    }

    // No cleanup code needed!
    // When `fleet` goes out of scope at the end of main(), its destructor
    // runs, which destroys every unique_ptr inside it, which in turn
    // deletes every Ship. Done — zero risk of forgetting a delete.

    return 0;
}