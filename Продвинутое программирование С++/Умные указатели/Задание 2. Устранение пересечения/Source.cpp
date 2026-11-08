#include <iostream>
#include <vector>
#include <memory>

class node
{
    int m_value;
public:
    std::weak_ptr<node> parent; //shared_ptr заменен на weak_ptr
    node(int value) : m_value{ value } {};
    ~node() { std::cout << "destructor called\n"; }
};

int main()
{
    {
        auto node1 = std::make_shared<node>(1);
        auto node2 = std::make_shared<node>(2);
        node1->parent = node2;
        node2->parent = node1;
    }

    return 0;
}