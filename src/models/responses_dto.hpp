#ifndef responses_dto_hpp
#define responses_dto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include "inference_dto.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  Data Transfer Object. Object containing fields only.
 *  Used in API for serialization/deserialization and validation
 */
class ResponseModel : public oatpp::DTO
{

    DTO_INIT(ResponseModel, DTO)

    DTO_FIELD(List<Object<InferenceModel>>, inferences);
};

#include OATPP_CODEGEN_END(DTO)

#endif /* DTOs_hpp */
