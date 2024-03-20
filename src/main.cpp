#include "stax.h"

using namespace stax;

int main()
{

    Stax list;
    Node node;
    Domain data;

    std::map<std::string, std::map<std::string, std::string>> entryMap{
        {"Entry 1", {{"age", "19"}, {"name", "dede.dev"}, {"registrar", "GoDaddy LLC"}}},
        {"Entry 2", {{"age", "8"}, {"name", "facebook.com"}, {"registrar", "nameCheap LLC"}}},
        {"Entry 3", {{"age", "3"}, {"name", "staxpayments.com"}, {"registrar", "GoDaddy LLC"}}},
        {"Entry 4", {{"age", "-13"}, {"name", "payment.com"}, {"registrar", "101domain GRS Limited"}}},
        {"Entry 5", {{"age", "60"}, {"name", "pay.com"}, {"registrar", "SafeNames Ltd."}}}};

    for (const auto &entry : entryMap)
    {
        std::cout << "Processing " << entry.first << std::endl;
        const std::map<std::string, std::string> &domainData = entry.second;
        data = list.loadData(domainData);
        node = list.createNode(data);
        list.insertAtBeginning(&node);

    }

    list.printList();

    // debug
    // std::cout << data.name << data.age << data.registrar << std::endl;

    return (EXIT_SUCCESS);
}
