// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ReferenceParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ReferenceParams& reference_params) noexcept ->
    void
    {
        from_json(object, static_cast<TextDocumentPositionParams&>(reference_params));
        from_json(object, static_cast<WorkDoneProgressParams&>(reference_params));
        from_json(object, static_cast<PartialResultParams&>(reference_params));
        reference_params.context = object.at("context").get<ReferenceContext>();
    }

    auto to_json(nlohmann::json& object, const ReferenceParams& reference_params) noexcept -> void
    {
        to_json(object, static_cast<const TextDocumentPositionParams&>(reference_params));
        to_json(object, static_cast<const WorkDoneProgressParams&>(reference_params));
        to_json(object, static_cast<const PartialResultParams&>(reference_params));
        object["context"] = reference_params.context;
    }
}

#endif