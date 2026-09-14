// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentContentOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TextDocumentContentOptions&
    text_document_content_options) noexcept -> void
    {
        const nlohmann::json& schemes = object.at("schemes");
        for(const nlohmann::json& scheme : schemes)
            text_document_content_options.schemes.emplace_back(scheme.get<std::string>());
    }

    auto to_json(nlohmann::json& object, const TextDocumentContentOptions&
    text_document_content_options) noexcept -> void
    {
        nlohmann::json schemes = nlohmann::json::array();
        for(const std::string& scheme : text_document_content_options.schemes)
            schemes.emplace_back(scheme);
        object["schemes"] = schemes;
    }
}

#endif