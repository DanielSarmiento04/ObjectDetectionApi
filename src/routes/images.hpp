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

// Custom extensions
#include "ia/inference.h"

// DTO'S
#include "models/base_dto.hpp"
#include "models/inference_dto.hpp"
#include "models/responses_dto.hpp"

// native dependencies
#include "iostream"
#include <string>

#include OATPP_CODEGEN_BEGIN(ApiController) //<-- Begin Codegen

namespace multipart = oatpp::web::mime::multipart; 

class ImageAnalyzeRoute : public oatpp::web::server::api::ApiController
{

private:
    const oatpp::String m_root = "/images";
    const std::string project_path = "/Users/josedanielsarmientoblanco/Desktop/hobby/api_image_manipulation/";
    Inference inference;

public:
    /*
    * Constructor with object mapper.
    */
    ImageAnalyzeRoute(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)
    ) : oatpp::web::server::api::ApiController(objectMapper) , inference(project_path + "yolov8n.onnx", cv::Size(640, 640)){}

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

        std::vector<Detection> results = inference.process(image);

        int detections = results.size();
        OATPP_LOGD("Image router ", "detections=%d", detections);

        List<Object<InferenceModel>> list_result = List<Object<InferenceModel>>::createShared();

        for (int i = 0; i < detections; i++)
        {
            auto result = InferenceModel::createShared();
            result->className = results[i].className;
            result->confidence = results[i].confidence;
            result->class_id = results[i].class_id;
            
            auto bbox = results[i].box;
            result->x = bbox.x;
            result->y = bbox.y;
            result->width = bbox.width;
            result->height = bbox.height;

         
            list_result->push_back(result);
        }

        auto response = ResponseModel::createShared();
        response->inferences=list_result;

        return createDtoResponse(Status::CODE_200, response);
    }

};

#include OATPP_CODEGEN_END(ApiController) //<-- End Codegen

#endif /*   */