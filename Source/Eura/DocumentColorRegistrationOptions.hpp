// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_document_color_registration_options
#define lyrix_header_guard_eura_document_color_registration_options
#include "Eura/DocumentColorOptions.hpp"
#include "Eura/StaticRegistrationOptions.hpp"
#include "Eura/TextDocumentRegistrationOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] DocumentColorRegistrationOptions final : TextDocumentRegistrationOptions,
    StaticRegistrationOptions, DocumentColorOptions{};

    auto from_json(const nlohmann::json& object, DocumentColorRegistrationOptions&
    document_color_registration_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const DocumentColorRegistrationOptions&
    document_color_registration_options) noexcept -> void;
}

#endif
#endif