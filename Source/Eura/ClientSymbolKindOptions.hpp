// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_client_symbol_kind_options
#define lyrix_header_guard_eura_client_symbol_kind_options
#include "Eura/Json.hpp"
#include "Eura/SymbolKind.hpp"

namespace Eura
{
    struct [[nodiscard]] ClientSymbolKindOptions final
    {
        std::optional<std::vector<SymbolKind>> valueSet;
    };

    auto from_json(const nlohmann::json& object, ClientSymbolKindOptions&
    client_symbol_kind_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const ClientSymbolKindOptions& client_symbol_kind_options)
    noexcept -> void;
}

#endif
#endif