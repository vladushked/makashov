#include <iostream>
#include <simple_container.h>

using namespace std;

int main(int argc, char *argv[])
{

    simple_container test(5,3.14);
    test.showAll();
    test.set(3,567);
    cout << test.size() << test.get(3);
    test.reset(15,7);
    test.showAll();
    test.resize(7);
    test.showAll();
}
