#include <iostream>
#include "No.h"
using namespace std;

No::No()
{

}
float No::consultaInfo()
{
    return info;
}
No* No::consultaProx()
{
    return prox;
}
void No::atribInfo(float val)
{
    info = val;
}
void No::atribProx(No *p)
{
    prox = p;
}
No::~No()
{

}
