#include <iostream>
#include "DLList.h"

int main() {
    DLList test;
    test.PushBack("OPOP");
    test.PushBack("OPOP");
    test.PushBack("OPOP");
    test.PushBack("OPOP");
    test.PopBack();
    test.PopBack();
    test.PopBack();
    test.PrintList();
    return 0;
}
