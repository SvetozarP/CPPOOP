#include <iostream>
#include <algorithm>
#include <cstddef>

#include "SmartArray.h"

int main()
{
    SmartArray<int> arr(5);
    arr[2] = 42;

    arr.print();

    SmartArray<int> arrB(6);
    arrB[3] = 12;
    SmartArray<int> arrC = arrB;

    arrB.print();
    arrB = arr;
    arrB.print();
    arr.print();

    //  SmartArray<int> arrC(5);
    //  arrC.resize(10);
    //  arrC.resize(2);

    //  for(auto & a : arr) {
    //      std::cout << a << ' ' << std::flush;
    //      a++;
    //  }
    // std::cout << std::endl;

    return 0;
}
