// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ReferenceContext.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ReferenceContext& reference_context) noexcept ->
    void
    {
        reference_context.includeDeclaration = object.at("includeDeclaration").get<bool>();
    }

    auto to_json(nlohmann::json& object, const ReferenceContext& reference_context) noexcept ->
    void
    {
        object["includeDeclaration"] = reference_context.includeDeclaration;
    }
}

#endif