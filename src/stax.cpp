
#include "stax.h"

namespace stax
{
    /** Add nodes to the list
     *
     */
    void Stax::addNode() {}

    /** Remove nodes to the list
     *
     */
    void Stax::removeNode() {}

    void Stax::printDomain(const Domain &domain)
    {
        std::cout << "Domain: " << domain.name << "\n"
                  << "Age: " << domain.age << "\n"
                  << "Registrar: " << domain.registrar << std::endl;
    }
}