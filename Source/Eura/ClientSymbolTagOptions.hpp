// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_client_symbol_tag_options
#define lyrix_header_guard_eura_client_symbol_tag_options
#include "Eura/Json.hpp"
#include "Eura/SymbolTag.hpp"

namespace Eura
{
    struct [[nodiscard]] ClientSymbolTagOptions final
    {
        std::vector<SymbolTag> valueSet;
    };

    auto from_json(const nlohmann::json& object, ClientSymbolTagOptions& client_symbol_tag_options)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const ClientSymbolTagOptions& client_symbol_tag_options)
    noexcept -> void;
}

#endif
#endif