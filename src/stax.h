#ifndef STAX_HPP
#define STAX_HPP

#include <list>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <iostream>
#include <algorithm>
#include <filesystem>
#include <curl/curl.h>
#include <cstdlib>
#include <thread>
#include <functional>
#include <atomic>
#include <condition_variable>
#include <mutex>
#include <chrono>
#include <any>

#include <iostream>
#include <string>
#include <map>
#include <random>

namespace stax
{
    struct Domain
    {
        int age = 0;
        std::string name;
        std::string registrar;
    };

    struct Node
    {
        Node *prev;
        Domain data;
        Node *next;
    };

    typedef Node *NodePtr;
    typedef Domain *DomainPtr;
    class Stax
    {
    public:
        Stax() : head(nullptr){};

        void printList();
        void removeNode(const NodePtr node);
        Node createNode(const Domain &domainObject);
        Domain loadData(const std::map<std::string, std::string> &data);

        inline void insertAtEnd(NodePtr node)
        {
            if (head != nullptr)
                head->prev = node;
        }

        // Function to insert a new node at the end of the list
        inline void insertAtBeginning(NodePtr node)
        {
            node->next = nullptr;
            if (head == nullptr)
            {
                node->prev = nullptr;
                head = node;
                return;
            }

            NodePtr last = head;
            while (last->next != nullptr)
            {
                last = last->next;
            }

            last->next = head;
            node->prev = last;
        }

    private:
        NodePtr head;
    };
}

#endif // !STAX_HPP
