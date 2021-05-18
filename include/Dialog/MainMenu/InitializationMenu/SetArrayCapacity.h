#ifndef __SET_ARRAY_CAPACITY_H__
#define __SET_ARRAY_CAPACITY_H__

#include <iostream>

void SetArrayCapacity(DataBox& data) {
    std::cout << "SetArrayCapacity()\n";
    int capacity;
    capacity = get_variant(5); // 5 max enough
    data.numOfStrings = capacity;
    data.strings = new MyString[capacity];
    // Блокируем этот пункт, разблокируем пункт заполнения
    menu_entry_block_list["SetArrayCapacity"] = true;
    menu_entry_block_list["FillArray"] = false;
    pause();
}

#endif // __SET_ARRAY_CAPACITY_H__
