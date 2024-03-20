#include "stax.h"

using namespace stax;

int main()
{

    Stax stax;
    std::map<std::string, std::map<std::string, std::string>> domainData{
        {"Entry 1", {{"age", "19"}, {"name", "dede.dev"}, {"registrar", "GoDaddy LLC"}}},
        {"Entry 2", {{"age", "8"}, {"name", "facebook.com"}, {"registrar", "nameCheap LLC"}}},
        {"Entry 3", {{"age", "3"}, {"name", "staxpayments.com"}, {"registrar", "GoDaddy LLC"}}},
        {"Entry 4", {{"age", "13"}, {"name", "payment.com"}, {"registrar", "101domain GRS Limited"}}},
        {"Entry 5", {{"age", "60"}, {"name", "pay.com"}, {"registrar", "SafeNames Ltd."}}}};

    const Domain data = stax.loadData(domainData);
    Node node = stax.createNode(data);
    stax.insertAtBeginning(&node);
    stax.printList();

    return (EXIT_SUCCESS);
    }
