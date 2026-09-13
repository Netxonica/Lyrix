// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_document_on_type_formatting_options
#define lyrix_header_guard_eura_document_on_type_formatting_options
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] DocumentOnTypeFormattingOptions final
    {
        std::string firstTriggerCharacter;

        std::optional<std::vector<std::string>> moreTriggerCharacter;
    };

    auto from_json(const nlohmann::json& object, DocumentOnTypeFormattingOptions&
    document_on_type_formatting_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const DocumentOnTypeFormattingOptions&
    document_on_type_formatting_options) noexcept -> void;
}

#endif
#endif