#include <stdio.h>
#include "Son.h"
#include <iostream>

using namespace std;

int sub1::min_unit_finder()
{
    Unit* last = get_last();
    Unit* min = last;
    int size_f = size;
    while (size_f > 1)
    {
        if ((min->value) > (last->prev->value))
        {
            min = last->prev;
        }
        last = last->prev;
        size_f--;
    }
    return min->value;
}

int sub2::min_unit_finder()
{
    Unit* last = get_last();
    Unit* min = last;
    int size_f = size;
    while (size_f > 1)
    {
        if ((min->value) > (last->prev->value))
        {
            min = last->prev;
        }
        last = last->prev;
        size_f--;
    }
    return min->value;
}

int sub2::pop()
{
    return Queue::pop();
}

void sub2::push(int Value)
{
    return Queue::push(Value);
}

void sub2::out()
{
    return Queue::out();
}

void sub2::copy(sub2& ob)
{
    return Queue::copy(ob);
}

void sub2::merger(sub2& ob1, sub2& ob2)
{
    return Queue::merger(ob1, ob2);
}

bool sub2::check()
{
    return Queue::check();
}

int sub3::min_unit_finder()
{
    Unit* last = get_last();
    Unit* min = last;
    int size_f = size;
    while (size_f > 1)
    {
        if ((min->value) > (last->prev->value))
        {
            min = last->prev;
        }
        last = last->prev;
        size_f--;
    }
    return min->value;
}

int sub3::pop()
{
    return Queue::pop();
}

void sub3::push(int Value)
{
    return Queue::push(Value);
}

void sub3::out()
{
    return Queue::out();
}

void sub3::copy(sub3& ob)
{
    return Queue::copy(ob);
}

void sub3::merger(sub3& ob1, sub3& ob2)
{
    return Queue::merger(ob1, ob2);
}

bool sub3::check()
{
    return Queue::check();
}