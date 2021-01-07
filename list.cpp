#include "list.hpp"

t_list *ft_lst_new(const int &val)
{
    t_list *elem = new t_list;
    elem->content = val;
    elem->next = NULL;
    elem->prev = NULL;
    return elem;
}

void ft::list::delete_node(t_list *node)
{
    if (node == NULL)
        return;

    if (node->prev)
        node->prev->next = node->next;
    else // if we are deleting the first element of the list, we need to update this->lst
        this->lst = node->next;

    if (node->next)
        node->next->prev = node->prev;
    
    delete node;
    if (this->num == 1) // if there will be no more element left on the list, set this->lst to NULL
        this->lst = NULL;
    this->num--;
}

void ft::list::swap_nodes(t_list *a, t_list *b)
{
    t_list *tmp;

    // std::cout << "swap " << a->content << " " << b->content << std::endl << std::endl;
    if (a->prev)
        a->prev->next = b;
    else
        this->lst = b; // if a was the first element, we need to update this->lst 
    
    if (b->next)
        b->next->prev = a;
    
    tmp = a->prev;
    // std::cout << "tmp->prev " << tmp << std::endl;
    a->prev = b;
    a->next = b->next;
    
    b->next = a;
    b->prev = tmp;
    // std::cout << "tmp->prev " << tmp << std::endl;

}

t_list *ft::list::get_last_node()
{
    t_list *tmp(this->lst);
    if (tmp == NULL)
        return NULL;
    while (tmp->next)
        tmp = tmp->next;
    return tmp;
}

t_list *ft::list::get_last_node() const
{
    t_list *tmp(this->lst);
    if (tmp == NULL)
        return NULL;
    while (tmp->next)
        tmp = tmp->next;
    return tmp;
}

// constructors & destructors

ft::list::list(): lst(NULL), num(0)
{
}

ft::list::list(size_type n, const int val): num(0)
{
    for (size_type i = 0; i < n; i++)
    {
        this->push_back(val);
    }
}

ft::list::list(const list& x): num(0)
{
    t_list *tmp;
    tmp = x.lst;
    for (size_type i = 0; i < x.num; i++)
    {
        this->push_back(tmp->content); // num is incremented at each call
        tmp = tmp->next;
    }
}

ft::list& ft::list::operator=(const list& x)
{
    this->clear();
    
    t_list *tmp;
    tmp = x.lst;
    for (size_type i = 0; i < x.num; i++)
    {
        this->push_back(tmp->content); // num is incremented at each call
        tmp = tmp->next;
    }
    return *this;
}

ft::list::~list()
{
    t_list *tmp;
    t_list *del;
    tmp = this->lst;
    for (size_type i = 0; i < this->num; i++)
    {
        del = tmp;
        tmp = del->next;
        delete del;
    }
}


//capacity

ft::list::size_type ft::list::size() const
{
    return this->num;
}

bool ft::list::empty() const
{
    if (this->num == 0)
        return true;
    else
        return false;
}


// element access
// Calling these functions (front & back) on an empty container causes undefined behavior (cplusplus.com)

int &ft::list::front()
{
    return this->lst->content;
}

const int &ft::list::front() const
{
    return this->lst->content;
}

int &ft::list::back()
{
    return this->get_last_node()->content;
}

const int &ft::list::back() const
{
    return this->get_last_node()->content;
}


// modifiers

void ft::list::push_back(const int &val)
{
    if (this->empty())
    {
        this->lst = ft_lst_new(val);
        this->num = 1;
        return ;
    }
    // add elem at the end
    t_list *last(this->get_last_node());
    t_list *new_elem(ft_lst_new(val));
    last->next = new_elem;
    // set last elem->prev
    new_elem->prev = last;
    this->num++;
}

void ft::list::pop_back()
{
    // t_list *tmp(this->lst);
    // t_list *old(NULL);
    // while (tmp->next)
    // {
    //     old = tmp;
    //     tmp = tmp->next;
    // }
    // delete tmp;
    // if (old)
    //     old->next = NULL;
    // this->num--;
    // if (this->num == 0)
    //     this->lst = NULL;
    // t_list *tmp(this->lst);
    // while (tmp->next)
    //     tmp = tmp->next;
    this->delete_node(this->get_last_node());
}

void ft::list::push_front (const value_type& val)
{
    if (this->empty())
    {
        this->lst = ft_lst_new(val);
        this->num = 1;
        return ;
    }
    t_list *tmp(this->lst);
    this->lst = ft_lst_new(val);
    this->lst->next = tmp;
    tmp->prev = this->lst;
    this->num++;
}

void ft::list::pop_front()
{
    // if (this->num == 1)
    // {
    //     this->num--;
    //     delete this->lst;
    //     this->lst = NULL;
    //     return ;
    // }
    // t_list *tmp(this->lst->next);
    // delete this->lst;
    // this->lst = tmp;
    // this->lst->prev = NULL;
    // this->num--;
    this->delete_node(this->lst);
}

void ft::list::clear()
{
    t_list *tmp;
    t_list *del;
    tmp = this->lst;
    for (size_type i = 0; i < this->num; i++)
    {
        del = tmp;
        tmp = del->next;
        delete del;
    }
    this->num = 0;
    this->lst = NULL;
}


void ft::list::assign(size_type n, const value_type& val)
{
    // delete old list
    this->clear();
    // assign new list
    for (size_type i = 0; i < n; i++)
        this->push_back(val);
}

void ft::list::swap (list& x)
{
    list tmp;
    tmp = *this;
    *this = x;
    x = tmp;
}
    
void ft::list::resize (size_type n, value_type val)
{
    if (n > this->num)
    {
        while (this->num != n)
            this->push_back(val);
    }
    else
    {
        while (this->num != n)
            this->pop_back();
    }
}


// operations

void ft::list::remove(const value_type& val)
{
    t_list *tmp(this->lst);
    t_list *old(NULL);
    while (tmp)
    {
        old = tmp;
        tmp = tmp->next;
        if (old->content == val)
            this->delete_node(old);
    }
}

void ft::list::unique()
{
    t_list *tmp(this->lst);
    while (tmp->next)
    {
        if (tmp->content == tmp->next->content)
        {
            this->delete_node(tmp->next);
            tmp = this->lst;
        }
        else
            tmp = tmp->next;
    }
}

void ft::list::sort()
{
    t_list *tmp(this->lst);
    while (tmp->next)
    {
        // this->displaylist();
        // std::cout << "1st elem " << this->lst->prev << std::endl;
        if (tmp->content > tmp->next->content)
        {
            this->swap_nodes(tmp, tmp->next);
            tmp = this->lst;
        }
        else
            tmp = tmp->next;
    }
}

//debug

void ft::list::displaylist()
{
    t_list *tmp;
    tmp = this->lst;
    while (tmp)
    {
        std::cout << tmp->content << std::endl;
        tmp = tmp->next;
    }
    std::cout << "---" << std::endl;
}

void ft::list::displaylist_reverse()
{
    t_list *tmp;
    tmp = this->lst;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    while (tmp)
    {
        std::cout << tmp->content << std::endl;
        tmp = tmp->prev;
    }
    std::cout << "---" << std::endl;
}