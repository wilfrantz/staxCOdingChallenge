#include "stax.h"

using namespace stax;

int main()
{

    Stax stax;
    std::map<std::string, std::map<std::string, std::string>> domainData{
        {"domain1", {{"age", "19"}, {"name", "dede.dev"}, {"registrar", "Godaddy LLC"}}},
        {"domain2", {{"age", "19"}, {"name", "dede.dev"}, {"registrar", "Godaddy LLC"}}}};

    const Domain data = stax.loadData(domainData);
    Node node = stax.createNode(data);

    return (EXIT_SUCCESS);
}
