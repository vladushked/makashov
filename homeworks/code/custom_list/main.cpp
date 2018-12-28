#include <iostream>
#include "customlist.h"

using namespace std;

int main()
{

    CustomList<int> list;
    //create nodes
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_forward(5);
    list.show();
    //delete nodes
    list.pop_back();
    list.pop_forward();
    list.show();
    //swap
    list.swap(1,2);
    list.show();
    //sort
    list.sort();
    list.show();

    return 0;
}
