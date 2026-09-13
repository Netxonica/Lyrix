// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_inline_value_registration_options
#define lyrix_header_guard_eura_inline_value_registration_options
#include "Eura/InlineValueOptions.hpp"
#include "Eura/StaticRegistrationOptions.hpp"
#include "Eura/TextDocumentRegistrationOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] InlineValueRegistrationOptions final : InlineValueOptions,
    TextDocumentRegistrationOptions, StaticRegistrationOptions{};

    auto from_json(const nlohmann::json& object, InlineValueRegistrationOptions&
    inline_value_registration_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const InlineValueRegistrationOptions&
    inline_value_registration_options) noexcept -> void;
}

#endif
#endif