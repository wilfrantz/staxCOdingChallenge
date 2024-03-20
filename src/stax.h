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
        Stax(){};


        void addData();
        void removeNode();
        void removeNode(const NodePtr node);
        void addNode(const Node &domainData);
        void printDomain(const Domain &domain); // Corrected parameter declaration
        Domain loadData(int &age, std::string &name, std::string &registrar);

    private:
        NodePtr head;
    };
}

#endif // !STAX_HPP
