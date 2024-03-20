
#include "stax.h"

struct Node;
namespace stax
{
    /** Add nodes to the list
     *
     */
    void Stax::addNode(const Node &domainData)
    {
        std::map<std::string, std::string> domainData{
            {"age", "19"},
            {"name", "dede.dev"},
            {"registrar", "Godaddy LLC"}};

        Domain domain = loadData();
    }

    /** Remove nodes to the list
     *
     */
    void Stax::removeNode(const NodePtr node)
    {
        if (!node)
        {
            std::cerr << "Error: Node pointer is nullptr." << std::endl;
            return;
        }

        // Adjust prev node's next pointer
        if (node->prev)
        {
            node->prev->next = node->next;
        }

        // Adjust next node's prev pointer
        if (node->next)
        {
            node->next->prev = node->prev;
        }

        // If node is head, update head pointer
        if (head == node)
        {
            head = node->next;
        }

        // Delete the node
        delete node;
    }

    /** @brief Load data to the application data
     * \param: domain's age, name and registrar info
     * \return: Domain object.
     */

    Domain loadData(std::map<std::string, std::map<std::string, std::string>> &dataMap)
    {
        Domain domainData;

        for (const auto &outer : dataMap)
        {
            std::string entry = outer.first;
            for (const auto &inner : outer.second)
            {
                // NOTE: Validate age input, set a default value is !> 0 or NAN
                if (inner.first == "age")
                    domainData.age = std::stoi(inner.second) >= 0 ? std::stoi(inner.second) : 0;
                else if (inner.first == "name")
                    domainData.name = inner.second;
                else if (inner.first == "registrar")
                    domainData.registrar = inner.second;
            }
        }

        return domainData;
    }

    Node Stax::createNode(const Domain &domainObject)
    {
        NodePtr node = new Node;

        node->data = domainObject;

        return *node;
    }

    /** Print domain data to stdout
     *
     */
    void Stax::printDomain(const Domain &domain)
    {
        std::cout << "Domain: " << domain.name << "\n"
                  << "Age: " << domain.age << "\n"
                  << "Registrar: " << domain.registrar << std::endl;
    }
}