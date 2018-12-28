#include "customlist.h"

template <typename list_type>
CustomList<list_type>::CustomList()
{
    size = 0;
}
template <typename list_type>
void CustomList<list_type>::push_back(list_type data)
{

    if (size != 0){
        last->next = new node;
        last->next->prev = last;
        last = last->next;
        last->data = data;
    }
    else if (size == 0){
        first = new node;
        first->data = data;
        last = first;
    }
    size++;
}

template <typename list_type>
void CustomList<list_type>::push_forward(list_type data)
{

    if (size != 0){
        first->prev = new node;
        first->prev->next = first;
        first = first->prev;
        first->data = data;
    }
    else if (size == 0){
        first = new node;
        first->data = data;
        last = first;
    }
    size++;
}
template <typename list_type>
void CustomList<list_type>::pop_back()
{
    last = last->prev;
    delete [] last->next;
    last->next = nullptr;
    size--;
}
template <typename list_type>
void CustomList<list_type>::pop_forward()
{
    first = first->next;
    delete [] first->prev;
    first->prev = nullptr;
    size--;
}
template <typename list_type>
typename CustomList<list_type>::node* CustomList<list_type>::find(size_t n)
{
    node* finder = first;
    for (size_t i = 1; i < n; i++){
        finder = finder->next;
    }
    return finder;
}

template <typename list_type> void CustomList<list_type>::swap(size_t initial, size_t target)
{
    int temp_data;

    node* initial_nd = find(initial);
    node* target_nd = find(target);
    temp_data = target_nd->data;
    target_nd->data = initial_nd->data;
    initial_nd->data = temp_data;
}

template <typename list_type> void CustomList<list_type>::sort()
{
    node* sorter = first;
    for (size_t i = 1; i <= size; i++){
        if (sorter->next == nullptr)
            break;
        if(sorter->data > sorter->next->data){
            swap(i,i+1);
            i = 0;
        }
    }
}

template <typename list_type> void CustomList<list_type>::show()
{
    node* buff = first;

    for (size_t i = 0; i < size; i++){
        std::cout << buff->data << std::endl;
        buff = buff->next;
    }
    std::cout << find(1)->data << " - first" << std::endl;
    std::cout << std::endl;
}

template <typename list_type> size_t CustomList<list_type>::getSize(){
    return size;
}

template class CustomList<int>;
