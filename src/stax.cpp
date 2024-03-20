
#include "stax.h"


struct Node;
namespace stax
{
    /** Add nodes to the list
     *
     */
    void Stax::addNode(const Node &domainData) {}

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
    Domain loadData(int &age, std::string &name, std::string &registrar)
    {
        Domain domainData;

        // Validate age input
        if (age >= 0)
        {
            domainData.age = age;
        }
        else
        {
            // NOTE Handle invalid age input, set to a default value or throw an exception
            std::cerr << "Invalid age input: " << age << ". Setting age to 0." << std::endl;
            domainData.age = 0;
        }

        domainData.name = name;
        domainData.registrar = registrar;

        return domainData;
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