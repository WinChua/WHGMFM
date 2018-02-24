#ifndef SHOW_ARRAY_H
#define SHOW_ARRAY_H
#include<iostream>
template<typename T>
void show_container(T data, int size) {
    for(int i=0; i<size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
    return;
}
#endif // SHOW_ARRAY_H
