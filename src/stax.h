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
    class Stax
    {
    public:
        Stax(){};

        struct Domain
        {
            int age;
            std::string name;
            std::string registrar; // Corrected member variable name
        };

        void addNode();
        void addData();
        void removeNode();
        void printDomain(const Domain &domain); // Corrected parameter declaration

    private:

        struct Node
        {
            Node *prev;
            Domain data;
            Node *next;
        };
    };
}

#endif // !STAX_HPP

