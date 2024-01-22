#ifndef BASE_HPP
#define BASE_HPP

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"
#include "models/base_dto.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<-- Begin Codegen

class BaseRoute : public oatpp::web::server::api::ApiController
{
public:
    /*
    * Constructor with object mapper.
    */
    BaseRoute(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)
    ) : oatpp::web::server::api::ApiController(objectMapper){}

public:

    ENDPOINT_INFO(root) {
        info->summary = "Base API endpoint";
    }
    ENDPOINT("GET", "/", root) {
        auto dto = BaseModel::createShared();
        dto->statusCode = 200;
        dto->message = "Hello World from the base route";
        return createDtoResponse(Status::CODE_200, dto);
    }

};

#include OATPP_CODEGEN_END(ApiController) //<-- End Codegen

#endif /* AppComponent_hpp */