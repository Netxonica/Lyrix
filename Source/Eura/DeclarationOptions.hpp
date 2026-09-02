// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_declaration_options
#define lyrix_header_guard_eura_declaration_options
#include "Eura/WorkDoneProgressOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] DeclarationOptions final : WorkDoneProgressOptions{};

    auto from_json(const nlohmann::json& object, DeclarationOptions& declaration_options) noexcept
    -> void;

    auto to_json(nlohmann::json& object, const DeclarationOptions& declaration_options) noexcept ->
    void;
}

#endif
#endif