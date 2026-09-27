// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_show_document_result
#define lyrix_header_guard_eura_show_document_result
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] ShowDocumentResult final
    {
        bool success;
    };

    auto from_json(const nlohmann::json& object, ShowDocumentResult& show_document_result) noexcept
    -> void;

    auto to_json(nlohmann::json& object, const ShowDocumentResult& show_document_result) noexcept
    -> void;
}

#endif
#endif