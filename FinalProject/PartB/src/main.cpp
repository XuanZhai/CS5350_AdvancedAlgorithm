#include <iostream>
#include "SLVO.h"




int main() {



    SLVO newSLVO;
    newSLVO.ReadFile("Complete.txt");
    newSLVO.Coloring();
    newSLVO.PrintResult();

    return 0;
}
