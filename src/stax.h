#ifndef STAX_HPP
#define STAX_HPP

#include <iostream>
#include <map>
#include <string>


namespace stax
{
    // Application data
    struct Domain
    {
        int age = 0;
        std::string name;
        std::string registrar;
    };

    // Node
    struct Node
    {
        Node *prev;
        Domain data;
        Node *next;
    };

    // Type aliases for pointers
    using NodePtr = Node *;
    using DomainPtr = Domain *;
    class Stax
    {
    public:
        // constructor
        Stax() : head(nullptr){};

        void printList();
        void removeNode(const NodePtr node);
        void insertAtBeginning(NodePtr node);
        Node createNode(const Domain &domainObject);
        Domain loadData(const std::map<std::string, std::string> &data);

#ifdef UNIT_TEST
        friend class staxTest;
#endif
    private:
        NodePtr head;
    };
}

#endif // !STAX_HPP
