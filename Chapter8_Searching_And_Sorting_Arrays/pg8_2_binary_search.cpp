/*
This program demonstrate the binary search algorithm, and perform binary search on integer array.
*/

#include <iostream>

using namespace std;

int binarySearch(const int[], int, int);

const int SIZE = 100;

int main()
{

    int emp_id[SIZE] = {
        1001, 1003, 1005, 1008, 1012, 1014, 1016, 1019, 1023, 1025,
        1027, 1030, 1034, 1037, 1039, 1041, 1043, 1046, 1049, 1052,
        1055, 1058, 1060, 1063, 1065, 1068, 1070, 1073, 1075, 1077,
        1080, 1082, 1084, 1087, 1090, 1092, 1095, 1097, 1099, 1101,
        1104, 1106, 1108, 1111, 1113, 1115, 1117, 1119, 1122, 1125,
        1127, 1129, 1132, 1134, 1136, 1138, 1141, 1143, 1146, 1148,
        1150, 1152, 1154, 1157, 1160, 1162, 1164, 1167, 1170, 1173,
        1175, 1177, 1180, 1182, 1184, 1186, 1189, 1191, 1193, 1195,
        1197, 1200, 1202, 1204, 1207, 1209, 1211, 1213, 1215, 1218,
        1220, 1222, 1225, 1228, 1230, 1233, 1235, 1237, 1239, 1241};

    int search_id,
        result;

    // get the searching id number from the user
    cout << "Enter the 4 digit employee number that you are looking for [1001_1241] :";
    cin >> search_id;

    result = binarySearch(emp_id, SIZE, search_id);

    if (result == -1)
    {
        cout << "Not in the list" << endl;
    }
    else
    {
        cout << "The employee id is at the index " << result << endl;
    }

    return 0;
}

int binarySearch(const int array[], int num_elements, int value)
{
    int firstIndex = 0,
        lastIndex = num_elements - 1,
        middleIndex,
        position = -1;
    bool isFound = false;

    while (!isFound && firstIndex <= lastIndex)
    {
        middleIndex = (firstIndex + lastIndex) / 2;
        if (array[middleIndex] == value)
        {
            isFound = true;
            position = middleIndex;
        }
        else if (array[middleIndex] > value)
        { // the search value is in the lower half
            lastIndex = middleIndex - 1;
        }
        else
        { // the search value is in the higher half
            firstIndex = middleIndex + 1;
        }
    }

    return position;
}