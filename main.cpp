#include "map.hpp"
#include <map>
#include <iostream>

using namespace ft;

int main()
{
    map_node<int, char> *root;
    root = new map_node<int, char>(8, 'c');
    insert<int, char>(root, 4, 'b');
    insert<int, char>(root, 12, 'd');
    insert<int, char>(root, 11, 'd');
    insert<int, char>(root, 13, 'd');
    insert<int, char>(root, 2, 'd');
    insert<int, char>(root, 6, 'd');
    insert<int, char>(root, 10, 'd');
    insert<int, char>(root, 9, 'd');
    
    map_node<int, char> *tmp;

    // search
    tmp = search(root, 2);
    if (tmp)
        std::cout << tmp->value.first << std::endl; 
    tmp = search(root, 10);
    if (tmp)
        std::cout << tmp->value.first << std::endl; 
    tmp = search(root, 15);
    if (tmp)
        std::cout << tmp->value.first << std::endl; 
    std::cout << "---" << std::endl;

    // search max
    tmp = search_max(root);
    std::cout << tmp->value.first << std::endl;
    tmp = search_max_parent(root);
    std::cout << tmp->value.first << std::endl;
    std::cout << "---" << std::endl;

    // delete
    print_in_order(root);
    std::cout << "---" << std::endl;
    delete_map_node(root, 12);
    print_in_order(root);
    std::cout << "---" << std::endl;
    delete_map_node(root, 4);
    print_in_order(root);
    std::cout << "---" << std::endl;
    delete_map_node(root, 6);
    print_in_order(root);
    std::cout << "---" << std::endl;
    delete_map_node(root, 2);
    print_in_order(root);
    std::cout << "---" << std::endl;
    delete_map_node(root, 8);
    print_in_order(root);
    std::cout << "---" << std::endl;
    std::cout << "---" << std::endl;
    // delete_map_node(root, 9);
    // delete_map_node(root, 10);
    // delete_map_node(root, 13);
    // delete_map_node(root, 11);
    delete_postfix(root);

    std::map<char, int> first;
    first['b'] = 20;
    first['c'] = 30;
    first['a'] = 10;
    
    // iterator constructor
    ft::map<char, int> second(first.begin(), first.end());
    second.print();
    
    // erase
    second.erase('b');
    second.erase('c');
    std::cout << "---" << std::endl;
    second.print();
    std::cout << "---" << std::endl;
    second.erase('a'); // not working
    second.print();
    std::cout << "---" << std::endl;
    
    // clear
    ft::map<char, int> map1(first.begin(), first.end());
    map1.clear();

    // begin
    ft::map<char, int> map2(first.begin(), first.end());
    std::cout << map2.begin()->first << std::endl;


}