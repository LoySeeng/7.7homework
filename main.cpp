#include <iostream>
#include <exception>
#include "IA.h"

using namespace std;

int main() {

    try {

        IntegerArray array(9);

        for (int i{ 0 }; i < 9; ++i)
            array[i] = i + 1;

        array.changeL(8);

        array.addbefore(20, 5);

        array.remove(3);

        for (int i = 0; i < array.getLength(); ++i)
            cout << array[i] << ' ';
    }
    catch (exception& e)
    {
        cout << e.what();
    }
        return 0;
    }