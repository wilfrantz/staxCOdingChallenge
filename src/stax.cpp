
#include "stax.h"

struct Node;
namespace stax
{

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

    Domain Stax::loadData(const std::map<std::string, std::string> &dataMap)
    {
        Domain domainData;

        for (const auto &data : dataMap)
        {
            // NOTE: Validate age input, set a default value is !> 0 or NAN
            if (data.first == "age")
                domainData.age = std::stoi(data.second) >= 0 ? std::stoi(data.second) : 0;
            else if (data.first == "name")
                domainData.name = data.second;
            else if (data.first == "registrar")
                domainData.registrar = data.second;

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
    void Stax::printList()
    {
        NodePtr current = head;
        while (current != nullptr)
        {
            // Retrieve domain data from the current node
            Domain domain = current->data;

            // Print domain information
            std::cout << "Domain: " << domain.name << std::endl;
            std::cout << "Age: " << domain.age << std::endl;
            std::cout << "Registrar: " << domain.registrar << std::endl;

            // Move to the next node
            current = current->next;
        }
        std::cout << std::endl;
    }
}