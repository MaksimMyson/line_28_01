#include <iostream>
#include "smart_pointer.h"

using namespace std;

int main() {
    // Тестування UniquePtr
    UniquePtr<int> uniquePtr(new int(42));
    cout << "UniquePtr value: " << *uniquePtr << endl;

    // Тестування SharedPtr
    SharedPtr<int> sharedPtr1(new int(42));
    SharedPtr<int> sharedPtr2 = sharedPtr1;

    cout << "SharedPtr value: " << *sharedPtr1 << endl;
    cout << "SharedPtr use count: " << sharedPtr1.useCount() << endl;

    return 0;
}
