#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class person
{
public:
    person();
    person(int age,string name);

    int age() const {return m_age;}
    string name() const {return m_name;}
    void greetings() const;

protected:
    int m_age;
    string m_name;
};

class student : public person
{
public:
    student()

protected:
};

#endif // PERSON_H
