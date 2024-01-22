#ifndef IMAGES_HPP
#define IMAGES_HPP

// Base oat pp dependencies
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

// multipart dependencies
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"


// native dependencies
#include "iostream"
#include <string>

#include OATPP_CODEGEN_BEGIN(ApiController) //<-- Begin Codegen

namespace multipart = oatpp::web::mime::multipart; 

class ImageAnalyzeRoute : public oatpp::web::server::api::ApiController
{

private:
    const oatpp::String m_root = "/images";

public:
    /*
    * Constructor with object mapper.
    */
    ImageAnalyzeRoute(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)
    ) : oatpp::web::server::api::ApiController(objectMapper){}

public:

    ENDPOINT_INFO(images_root) {
        info->summary = "Base API images endpoint";
    }
    ENDPOINT("GET", m_root, images_root) {

        return createResponse(Status::CODE_200, "images");
    }


    ENDPOINT_INFO(analyze_image) {
        info->summary = "Endpoint to upload file ";
    }
    ENDPOINT("POST", m_root, analyze_image,
            REQUEST(std::shared_ptr<IncomingRequest>, request) // configure the request management
        ) 
    {
        /* Prepare multipart container. */
        auto multipart = std::make_shared<multipart::PartList>(request->getHeaders());

        /* Read multipart body */
        multipart::Reader multipartReader(multipart.get());

        /* Configure to stream part with name "part1" to file */
        multipartReader.setPartReader("part1", multipart::createFilePartReader("./part1"));

        /* Read multipart body */
        request->transferBody(&multipartReader);

        /* Print value of "part1" */
        auto part1 = multipart->getNamedPart("part1");
        /* Assert part is not null */
        // OATPP_ASSERT_HTTP(part1, Status::CODE_400, "part1 is null");

        return createResponse(Status::CODE_200, "post images");
    }

};

#include OATPP_CODEGEN_END(ApiController) //<-- End Codegen

#endif /*   */