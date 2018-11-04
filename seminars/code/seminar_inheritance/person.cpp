#include "person.h"
#include <iostream>

person::person()
{
    m_name = "anonymus";
    m_age = -1;
}

person::person(int age, string name)
{
    m_name = name;
    m_age = age;
}

void person::greetings() const
{
    std::cout << "Hello guys, my name is - " << m_name << endl;
}
