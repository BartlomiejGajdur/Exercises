#include <iostream>
#include <memory>
using namespace std;

class Node
{
public:
    Node(const int v) :
        next(nullptr),
        value(v)
    {}


    std::unique_ptr<Node> next;
    int value;
};

class List
{
public:
    List();
    void add(std::unique_ptr<Node> node);
    Node* get(const int value);
   

private:
    std::unique_ptr<Node> first;
};

List::List() :
    first(nullptr)
{}

void List::add(std::unique_ptr<Node> node)
{
    if(!first)
    {
        first = std::move(node);
    }
    else
    {
        Node* current = first.get();
        while(current->next)
        {
            current = current->next.get();
        }
        current->next = std::move(node);
    }
   
}

Node* List::get(const int value)
{
    if(!first)
    {
        cout << "List is empty!" << endl;
        return nullptr;
    }
    else
    {
        Node* current = first.get();
        do
        {
            if(current->value == value)
            {
                cout << "Found value " << current->value << endl;
                return current;
            }
            else
            {
                cout << "Going through " << current->value << endl;
                current = current->next.get();
            }
        } while(current);
        cout << "Not found: value " << value << endl;
        return nullptr;
    }
}

int main()
{
    List lista;
    std::unique_ptr<Node> node4 = make_unique<Node>(4);
    std::unique_ptr<Node> node7 = make_unique<Node>(7);

    lista.add(std::move(node4));
    lista.add(std::make_unique<Node>(4));
    lista.add(std::move(node7));
    lista.add(std::make_unique<Node>(4));
    auto node = lista.get(7);

    if (node)
        cout << node->value << '\n';



    return 0;
}
