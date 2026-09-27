// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ShowDocumentResult.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ShowDocumentResult& show_document_result) noexcept
    -> void
    {
        show_document_result.success = object.at("success").get<bool>();
    }

    auto to_json(nlohmann::json& object, const ShowDocumentResult& show_document_result) noexcept
    -> void
    {
        object["success"] = show_document_result.success;
    }
}

#endif