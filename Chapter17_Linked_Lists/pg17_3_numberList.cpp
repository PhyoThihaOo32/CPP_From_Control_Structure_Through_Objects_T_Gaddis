#include "NumberList.h"

int main()
{

    NumberList List;

    List.appendNode(2.5);
    List.appendNode(3.5);
    List.appendNode(4.5);

    List.displayNodeList();

    List.insertNode(3.4);

    List.displayNodeList();

    return 0;
}
