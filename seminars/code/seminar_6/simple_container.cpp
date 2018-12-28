#include "simple_container.h"
#include <iostream>

using std::cout;
using std::endl;

//constructor
simple_container::simple_container()
{
    m_size = 0;
    m_capacity = 2;
    m_data = 0;
}

//constructor
simple_container::simple_container(int size, double value)
{
    m_capacity = 2;
    while (m_capacity < size)
    {
        m_capacity *= 2;
    }
    m_data = new double[m_capacity];
    for (int i = 0; i<size; i++)
        m_data[i] = value;
    m_size = size;
}

//copy constructor
simple_container::simple_container(const simple_container &container)
{
    m_size = container.m_size;
    m_capacity = container.m_capacity;
    m_data = new double[m_capacity];
    for (int i = 0; i<container.m_size; i++)
        m_data[i] = container.m_data[i];
}

//destructor
simple_container::~simple_container()
{
    if (m_data)     //mdata != 0
        delete[] m_data;
    m_data = 0;
}

void simple_container::showAll()
{
    cout << "Data: ";
    for (int i = 0; i<m_size;i++)
        cout << m_data[i] << " ";
    cout << endl << "Size: " << m_size << endl << "Capacity: " << m_capacity << endl;

}

int simple_container::size()
{
    return m_size;
}

int simple_container::capacity()
{
    return m_capacity;
}

double simple_container::get(int index)
{
    if (index>=0 && index<m_size)
        return m_data[index];
    else
    {
        std::cerr << "Wrong index " << index << endl;
        return 0;
    }
}

void simple_container::set(int index, double value)
{
    if (index>=0 && index<m_size)
        m_data[index] = value;
    else
        std::cerr << "Wrong index " << index << endl;

}

void simple_container::add(double value)
{
    if (m_size == m_capacity)
        reallocate();
    else m_data[m_size + 1] = value;
}

void simple_container::reallocate()
{
    int new_capacity = m_capacity * 2;
    double* new_data = new double[new_capacity];

    for (int i = 0; i < m_capacity; i++)
        new_data[i] = m_data[i];
    delete [] m_data;
    m_capacity = new_capacity;
    m_data = new_data;
}

void simple_container::erase()
{
    m_size = 0;
    m_capacity = 2;
    delete [] m_data;
    m_data = 0;
}

void simple_container::reset(int size, double value)
{
    int new_capacity = 2;
    while (new_capacity < size)
    {
        new_capacity *= 2;
    }
    double* new_data = new double[new_capacity];

    for (int i = 0; i < size; i++)
        new_data[i] = value;
    delete [] m_data;
    m_data = new_data;
    m_size = size;
    m_capacity = new_capacity;
}

void simple_container::resize(int size)
{
    int new_capacity = 2;
    while (new_capacity < size)
    {
        new_capacity *= 2;
    }
    double* new_data = new double[new_capacity];
    for (int i = 0; i < size; i++)
        new_data[i] = m_data[i];
    delete [] m_data;
    m_data = new_data;
    m_size = size;
    m_capacity = new_capacity;
}

// операторы
simple_container& simple_container::operator = (const simple_container &container)
{
   if (this != &container)
   {
       if (m_data)          //проверка размера
           delete [] m_data;
       m_size = container.m_size;
       m_capacity = container.m_capacity;
       m_data = new double[m_capacity];
       for (int i = 0; i<container.m_size; i++)
           m_data[i] = container.m_data[i];
       return *this;
   }
}

simple_container& simple_container::operator + (const simple_container &container)
{
   if (this != &container)
   {
       if (m_data)          //проверка размера
           delete [] m_data;
       m_size = container.m_size;
       m_capacity = container.m_capacity;
       m_data = new double[m_capacity];
       for (int i = 0; i<container.m_size; i++)
           m_data[i] = container.m_data[i];
   }
}
