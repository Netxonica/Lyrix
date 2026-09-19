// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_definition_params
#define lyrix_header_guard_eura_definition_params
#include "Eura/PartialResultParams.hpp"
#include "Eura/WorkDoneProgressParams.hpp"
#include "Eura/TextDocumentPositionParams.hpp"

namespace Eura
{
    struct [[nodiscard]] DefinitionParams final : TextDocumentPositionParams,
    WorkDoneProgressParams, PartialResultParams{};

    auto from_json(const nlohmann::json& object, DefinitionParams& definition_params) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const DefinitionParams& definition_params) noexcept ->
    void;
}

#endif
#endif