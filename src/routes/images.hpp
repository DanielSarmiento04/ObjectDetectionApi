#ifndef IMAGES_HPP
#define IMAGES_HPP

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"


#include "iostream"
#include <string>

#include OATPP_CODEGEN_BEGIN(ApiController) //<-- Begin Codegen


class IamgeAnalyzeRoute : public oatpp::web::server::api::ApiController
{

private:
    const oatpp::data::mapping::type::String m_root = "/images";

public:
    /*
    * Constructor with object mapper.
    */
    IamgeAnalyzeRoute(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)
    ) : oatpp::web::server::api::ApiController(objectMapper){}

public:

    ENDPOINT_INFO(root) {
        info->summary = "Base API images endpoint";
    }
    ENDPOINT("GET", m_root, root) {

        return createResponse(Status::CODE_200, "images");
    }

};

#include OATPP_CODEGEN_END(ApiController) //<-- End Codegen

#endif /* AppComponent_hpp */