#ifndef SIMPLE_CONTAINER_H
#define SIMPLE_CONTAINER_H


class simple_container

{

public:

    simple_container();                         //constructor
    simple_container(int size, double value);   //constructor
    simple_container(const simple_container &container);    //copy constructor

    ~simple_container();                        //destructor

    void showAll();                             //shows all elements in container
    int size();                                 //shows the size of container
    int capacity();
    double get(int index);                               //shows the value of index element in container
    void set(int index, double value);          //sets the value of index element
    void add(double value);                     //add value to container, increases the size of container
    void erase();                               //erases all data from container
    void reset(int size, double value);         //change the container size on size and replace elements by value
    void resize(int size);                      //change the size of the container

    simple_container& operator = (const simple_container &container); //operator =
    simple_container& operator + (const simple_container &container); //operator +
    simple_container& operator - (const simple_container &container); //operator -

private:

    void reallocate();

    double* m_data;
    int m_size;
    int m_capacity;


};

#endif // SIMPLE_CONTAINER_H
