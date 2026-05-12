/*
Robot Unit Test:

This main() tests the Robot class by:
- Initializing and printing position/orientation
- Moving in all four directions and checking boundaries
- Testing turnCW() and turnAntiCW()
- Verifying zig() and zag() behavior
- Traversing the entire 10x10 grid while counting moves

Purpose: validate movement logic, edge detection,
direction changes, and full-grid traversal.
*/

#include <iostream>
#include "robot.h"

using namespace std;

int main()
{

    Robot robo;

    robo.init();
    robo.print();
    robo.setOrientation(NORTH);
    robo.print();

    // test forward
    cout << "TEST FORWARD.\n\n";
    cout << "Moving NORTH>>>>>>>>" << endl;
    while (robo.forward())
    {
        robo.print();
        // test northEnd
        if (robo.northEnd())
        {
            cout << "---At North End---" << endl;
        }
    }

    robo.setOrientation(EAST);
    cout << "Moving EAST>>>>>>>>" << endl;
    while (robo.forward())
    {
        robo.print();
        // test eastEnd
        if (robo.eastEnd())
        {
            cout << "---At East End---" << endl;
        }
    }

    robo.setOrientation(SOUTH);
    cout << "Moving SOUTH>>>>>>>>" << endl;
    while (robo.forward())
    {
        robo.print();
        // test south end
        if (robo.southEnd())
        {
            cout << "---At South End---" << endl;
        }
    }
    robo.setOrientation(WEST);
    cout << "Moving WEST>>>>>>>>" << endl;
    while (robo.forward())
    {
        robo.print();
        // test west end
        if (robo.westEnd())
        {
            cout << "---At West End---" << endl;
        }
    }

    // test turnCW
    cout << "TEST TURNCW\n\n";
    for (int i = 0; i < 5; i++)
    {
        robo.turnCW();
        robo.print();
    }

    // test turnAnitCW
    cout << "TEST ANTICW\n\n";
    for (int i = 0; i < 5; i++)
    {
        robo.turnAntiCW();
        robo.print();
    }

    // test zig
    cout << "\n\nTEST ZIG." << endl;
    robo.init();
    robo.setOrientation(EAST);
    robo.print();
    while (robo.forward())
    {
        robo.print();
        // if (robo.eastEnd())
        // {
        //     robo.zig();
        //     robo.print();
        // }
    }
    robo.zig();
    cout << "TEST ZAG." << endl;
    while (robo.forward())
    {
        robo.print();
    }
    robo.zag();
    robo.print();

    // test all cells
    // tesing E - W transversal
    cout << "\n\nTesting E - W Transversal.\n\n";
    cout << "\n\nFINAL TEST ROBOT MOVE ALL CELLS." << endl;
    robo.init();
    robo.print();
    int cellCount = 1;

    while (cellCount <= 100)
    {
        while (robo.forward())
        {
            robo.print();
            cellCount++;
        }
        cout << "\nTotal Cell Count: " << cellCount << endl;
        cout << "\nZAG - TURN NORTH - FORWARD - TURN WEST." << endl;
        robo.zag();
        robo.print();
        cellCount++;
        while (robo.forward())
        {
            robo.print();
            cellCount++;
        }

        cout << "\nTotal Cell Count: " << cellCount << endl;
        cout << "\nZIG - TURN NORTH - FORWARD - TURN EAST." << endl;
        robo.zig();
        robo.print();
        cellCount++;
    };

    // testing N-S transveral
    cout << "\n\nTesting N - S Transversal.\n\n";
    cellCount = 1;
    robo.init();
    robo.setOrientation(NORTH);
    robo.print();
    while (cellCount <= 100)
    {
        while (robo.forward())
        {
            robo.print();
            cellCount++;
        }
        cout << "\nTotal Cell Count: " << cellCount << endl;
        cout << "\nZAG - TURN EAST - FORWARD - TURN SOUTH." << endl;
        robo.zag();
        robo.print();
        cellCount++;
        while (robo.forward())
        {
            robo.print();
            cellCount++;
        }

        cout << "\nTotal Cell Count: " << cellCount << endl;
        cout << "\nZAG - TURN EAST - FORWARD - TURN NORTH." << endl;
        robo.zig();
        robo.print();
        cellCount++;
    };

    return 0;
}