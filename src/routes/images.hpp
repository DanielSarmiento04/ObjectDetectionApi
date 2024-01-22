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
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/TemporaryFileProvider.hpp"

// OpenCV dependencies
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>    // Basic OpenCV structures (cv::Mat)
#include <opencv2/videoio.hpp> // Video write

// DTO'S
#include "models/base_dto.hpp"

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
        info->summary = "Base API images endpoint.";
    }
    ENDPOINT("GET", m_root, images_root) {

        return createResponse(Status::CODE_200, "images");
    }


    ENDPOINT_INFO(analyze_image) {
        info->summary = "Endpoint to upload file.";
    }
    ENDPOINT("POST", m_root, analyze_image,
            REQUEST(std::shared_ptr<IncomingRequest>, request) // configure the request management
    ) 
    {

        /* create multipart object */
        multipart::PartList multipart(request->getHeaders());

        /* create multipart reader */
        multipart::Reader multipartReader(&multipart);

        /* setup reader to stream parts to a temporary files by default */
        multipartReader.setDefaultPartReader(multipart::createTemporaryFilePartReader("/tmp" /* /tmp directory */));

        /* upload multipart data */
        request->transferBody(&multipartReader);

        /* get part by name */
        auto image_file = multipart.getNamedPart("image"); 

        // /* Assert part is not null */
        if(image_file == nullptr){
            auto error_message = BaseModel::createShared();
            error_message->message = "Input stream file as image name not found.";
            error_message->statusCode = 500;
            return createDtoResponse(Status::CODE_500, error_message);
        }
        OATPP_LOGD("part", "name=%s, location=%s", image_file->getName()->c_str(), image_file->getPayload()->getLocation()->c_str())


        cv::Mat image = cv::imread(image_file->getPayload()->getLocation()->c_str(), cv::IMREAD_COLOR);

        cv::imwrite("./image.jpg", image);
        // /* list all parts and locations to corresponding temporary files */
        // auto parts = multipart.getAllParts();
        // for(auto& p : parts) {
        //     OATPP_LOGD("part", "name=%s, location=%s", p->getName()->c_str(), p->getPayload()->getLocation()->c_str())
        // }

        // /* Prepare multipart container. */
        // auto multipart = std::make_shared<multipart::PartList>(request->getHeaders());

        // /* Read multipart body */
        // multipart::Reader multipartReader(multipart.get());

        // /* Configure to stream part with name "part1" to file */
        // multipartReader.setPartReader("image", multipart::createInMemoryPartReader(256 /* max-data-size */));


        // /* Read multipart body */
        // request->transferBody(&multipartReader);

        // /* Print value of "part1" */
        // auto image_file = multipart->getNamedPart("image");

        // /* Assert part is not null */

        // OATPP_LOGD("Multipart", "part1='%s'", image_file->getInMemoryData()->c_str());



        return createResponse(Status::CODE_200, "post images");
    }

};

#include OATPP_CODEGEN_END(ApiController) //<-- End Codegen

#endif /*   */