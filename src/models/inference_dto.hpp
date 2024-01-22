#ifndef inference_dto_hpp
#define inference_dto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
   *  Data Transfer Object. Object containing fields only.
   *  Used in API for serialization/deserialization and validation
*/
class InferenceModel : public oatpp::DTO {
    
    DTO_INIT(InferenceModel, DTO)
    
    DTO_FIELD(Int32, class_id);
    DTO_FIELD(String, className);
    DTO_FIELD(Float32, confidence);
    // DTO_FIELD(Vector<Int32>, bbox);
  
};

#include OATPP_CODEGEN_END(DTO)

#endif /* DTOs_hpp */
