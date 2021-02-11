#include "map.hpp"
#include <map>
#include <iostream>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

template<class U, class V>
void print(map<U, V> mp)
{
    for (typename map<U, V>::iterator it = mp.begin() ; it != mp.end() ; it++)
    {
        std::cout << "key: " << it->first;
        // std::cout << " val: " << it->second;
        std::cout << std::endl;
    }
    std::cout << "---" << std::endl;
    
}

// useful because template arguments dont have to be specified: they are deduced from the function argument
// (class template argument deduction is not available untin c++17, so when using std::pair, template arguments have to be provided explicitely)
template<class U, class V>
std::pair<U,V> make_pairs(U u, V v)
{
    return std::pair<U, V>(u, v);
}

int main()
{
    // insert
    map<int, char> map3;
    std::pair<map<int, char>::iterator, bool> p;
    map<int, char>::iterator it3;
    map3.insert(make_pairs(10, 'a'));
    map3.insert(make_pairs(5, 'a'));
    map3.insert(make_pairs(8, 'x'));
    map3.insert(make_pairs(15, 'a'));
    map3.insert(make_pairs(7, 'a'));
    // insert return value
    p = map3.insert(make_pairs(1, 'a'));
    std::cout << p.second << std::endl;
    p = map3.insert(make_pairs(1, 'a'));
    std::cout << p.second << std::endl;
    std::cout << "---" << std::endl;
    it3 = p.first;
    std::cout << it3->first << std::endl;
    std::cout << (++it3)->first << std::endl;
    std::cout << (++it3)->first << std::endl;
    std::cout << (++it3)->first << std::endl;
    std::cout << (++it3)->first << std::endl;
    std::cout << (++it3)->first << std::endl;

    // erase
    map<int, char> map5(map3);
    print(map5);
    map5.erase(8); // one child
    print(map5);
    map5.erase(5); // two child
    print(map5);
    map5.erase(15); // no child
    print(map5);
    map5.erase(10); // root
    print(map5);
    map5.erase(1); // root
    print(map5);
    map5.erase(7); // root
    print(map5);

    // iterator ++ & --
    map<int, char>::iterator it2 = map3.begin();
    map3.erase(10); // root node is erased -> doesnt alter it2
    print(map3);
    std::cout << it2->first << std::endl;
    std::cout << (++it2)->first << std::endl;
    std::cout << (++it2)->first << std::endl;
    std::cout << (++it2)->first << std::endl;
    std::cout << (it2++)->first << std::endl;
    std::cout << (it2)->first << std::endl;
    std::cout << "---" << std::endl;
    std::cout << (it2)->first << std::endl;
    std::cout << (--it2)->first << std::endl;
    std::cout << (--it2)->first << std::endl;
    std::cout << (--it2)->first << std::endl;
    std::cout << (it2--)->first << std::endl;
    std::cout << (it2)->first << std::endl;
    std::cout << "---" << std::endl;

    // iterator comparison
    std::cout << (it2 == map3.begin()) << std::endl;
    std::cout << (++it2 == map3.begin()) << std::endl;
    std::cout << (++it2 != map3.begin()) << std::endl;
    std::cout << "---" << std::endl;

    // construct const_iterator from iterator
    map<int, char>::const_iterator it4(it2);
    
    std::cout << (++it4)->first << std::endl;
    std::cout << (--it4)->first << std::endl;
    std::cout << "---" << std::endl;

    // operator =
    map<int, char> map4;
    map4.insert(make_pairs(100, 'a'));
    map4 = map3;
    print(map4);

    // // reverse iterator
    map<int, char>::reverse_iterator it5 = map4.rbegin();
    while(it5 != map4.rend())
    {
        std::cout << it5->first << std::endl;
        it5++;
    }
    
    // clear and iterator constructor
    map<int, char> map6(map3.begin(), map3.end());
    print(map6);
    map6.clear();
    print(map6);




}