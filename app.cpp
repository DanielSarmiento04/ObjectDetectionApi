#include "iostream"

// RestApi Framework
#include "oatpp/network/Server.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/core/macro/codegen.hpp"
// json 
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"


// including a important namespaces
using namespace oatpp;
using namespace oatpp::network;
using namespace oatpp::web::server;
using namespace oatpp::data::mapping;
using namespace std;

/* Begin DTO code-generation */
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Message Data-Transfer-Object
 */
class MessageDto : public DTO {

    DTO_INIT(MessageDto, DTO /* Extends */)

    DTO_FIELD(Int32, statusCode);   // Status code field
    DTO_FIELD(String, message);     // Message field

};

/* End DTO code-generation */
#include OATPP_CODEGEN_END(DTO)

/**
 * Custom Request Handler
 */
class Handler : public HttpRequestHandler
{
private:
    shared_ptr<ObjectMapper> m_objectMapper;
public:
    /**
     * Constructor with object mapper.
     * @param objectMapper - object mapper used to serialize objects.
     */
    Handler(const shared_ptr<ObjectMapper>& objectMapper)
        : m_objectMapper(objectMapper)
    {}
    /**
     * Handle incoming request and return outgoing response.
     */
    shared_ptr<OutgoingResponse> handle(const shared_ptr<IncomingRequest> &request) override
    {
        auto message = MessageDto::createShared();
        
        message->statusCode = 1024;
        message->message = "Hello DTO!";
        
        return ResponseFactory::createResponse(
            Status::CODE_200,
            message,
            m_objectMapper
        );
    }
};

void run()
{
    /* Create json object mapper */
    auto objectMapper = parser::json::mapping::ObjectMapper::createShared();

    /* Create Router for HTTP requests routing */
    auto router = HttpRouter::createShared();

    // Route GET - "/hello" requests to Handler
    router -> route("GET", "/hello", std::make_shared<Handler>(objectMapper));


    // Create HTTP connection handler with router 
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
    OATPP_LOGI(
        "MyApp",
        "Server running on run on port %s \n",
        connectionProvider->getProperty("port").getData()    
    );

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
