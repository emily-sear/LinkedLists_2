
#include "LinkedList.hpp"
#include <iostream> 
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv)
{
    LinkedList* ll = new LinkedList();
    
    ll->addEnd(4);
    ll->addEnd(6);
    ll->addEnd(8);
    ll->addEnd(2);
    ll->addFront(3);
    ll->removeFront();
    ll->display();

    return 0;
}