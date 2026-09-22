// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_document_symbol
#define lyrix_header_guard_eura_document_symbol
#include "Eura/Range.hpp"
#include "Eura/SymbolTag.hpp"
#include "Eura/SymbolKind.hpp"

namespace Eura
{
    struct [[nodiscard]] DocumentSymbol final
    {
        std::string name;

        std::optional<std::string> detail;

        SymbolKind kind;

        std::optional<std::vector<SymbolTag>> tags;

        Range range, selectionRange;

        std::optional<std::vector<DocumentSymbol>> children;
    };

    auto from_json(const nlohmann::json& object, DocumentSymbol& document_symbol) noexcept -> void;

    auto to_json(nlohmann::json& object, const DocumentSymbol& document_symbol) noexcept -> void;
}

#endif
#endif