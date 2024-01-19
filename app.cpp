#include "oatpp/web/server/HttpConnectionHandler.hpp"

#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

using namespace oatpp::web::server;
using namespace oatpp::network;

void run()
{

    /* Create Router for HTTP requests routing */
    auto router = HttpRouter::createShared();

    /* Create HTTP connection handler with router */
    auto connectionHandler = HttpConnectionHandler::createShared(router);

    /* Create TCP connection provider */
    auto connectionProvider = tcp::server::ConnectionProvider::createShared(
        {
            "localhost", 
            8000, 
            Address::IP_4
        }
    );

    /* Create server which takes provided TCP connections and passes them to HTTP connection handler */
    Server server(connectionProvider, connectionHandler);

    /* Print info about server port */
    OATPP_LOGI("MyApp", "Server running on port %s", connectionProvider->getProperty("port").getData());

    /* Run server */
    server.run();
}

int main()
{

    /* Init oatpp Environment */
    oatpp::base::Environment::init();

    /* Run App */
    run();

    /* Destroy oatpp Environment */
    oatpp::base::Environment::destroy();

    return 0;
}
