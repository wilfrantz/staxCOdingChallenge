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
        int age;
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
    class Stax
    {
    public:
        Stax() : head(nullptr){};

        void addData();
        void removeNode();
        void removeNode(const NodePtr node);
        void addNode(const Node &domainData);
        void printDomain(const Domain &domain); 
        Node createNode(const Domain &domainObject);

        inline void insertAtEnd(NodePtr node)
        {
            if (head != nullptr)
                head->prev = node;
        }

        // Function to insert a new node at the end of the list
        inline void insertAtBeginning(NodePtr node)
        {
            node->next == nullptr;
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

        Domain loadData(std::map<std::string, std::map<std::string, std::string>> &data);

    private:
        NodePtr head;
    };
}

#endif // !STAX_HPP
