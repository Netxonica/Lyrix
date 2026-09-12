// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_definition_options
#define lyrix_header_guard_eura_definition_options
#include "Eura/WorkDoneProgressOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] DefinitionOptions final : WorkDoneProgressOptions{};

    auto from_json(const nlohmann::json& object, DefinitionOptions& definition_options) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const DefinitionOptions& definition_options) noexcept ->
    void;
}

#endif
#endif