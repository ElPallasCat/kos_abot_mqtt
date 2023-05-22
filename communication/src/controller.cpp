#include <cstring>
#include <exception>
#include <iostream>
#include <memory>

#include <kos_net.h>

/* Files required for transport initialization. */
#include <coresrv/nk/transport-kos.h>
#include <coresrv/sl/sl_api.h>


#include <forte/NavigationCommand.idl.h>

#include <assert.h>

#include "subscriber.h"


subscriber_confg getSubscriberConfig() {

    subscriber_confg connectionConfig;

	connectionConfig.host = "10.21.155.22";
	connectionConfig.mqttUser = "mYser";
	connectionConfig.mqttPassword = "#hidden";
	connectionConfig.subTopic = "control";
	connectionConfig.port = 1883;

    return connectionConfig;
} 


int main(void)
{
    std::cout << "[CommunicationController] Waiting for network" << std::endl;
    if (!wait_for_network())
    {
        std::cerr << "[CommunicationController]  Error: Wait for network failed!"
                  << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "[CommunicationController] Initing navigation connection" << std::endl;

    NkKosTransport transportNav;
    struct forte_NavigationCommand_proxy proxyNav;
    Handle handleNav = ServiceLocatorConnect("navigation_connection");
    assert(handleNav != INVALID_HANDLE);

    /* Initialize IPC transport for interaction with the server entity. */
    NkKosTransport_Init(&transportNav, handleNav, NK_NULL, 0);

    nk_iid_t riidNav = ServiceLocatorGetRiid(handleNav, "forte.Forte.setNavigationCommand");
    assert(riidNav != INVALID_RIID);

    forte_NavigationCommand_proxy_init(&proxyNav, &transportNav.base, riid);

    NavigationMessageSender sender(&transportNav, &proxyNav);
    MessageValidator validator;

    mosqpp::lib_init();
    std::cout << "[CommunicationController]  Creating subscriber" << std::endl;
    auto sub = std::make_unique<Subscriber>(connectionConfig, &validator, &sender);
    if (sub)
    {
        sub->loop_forever();
    }
    mosqpp::lib_cleanup();
    
    return EXIT_SUCCESS;
}
