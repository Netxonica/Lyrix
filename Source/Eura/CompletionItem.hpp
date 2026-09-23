// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_completion_item
#define lyrix_header_guard_eura_completion_item
#include "Eura/Command.hpp"
#include "Eura/TextEdit.hpp"
#include "Eura/MarkupContent.hpp"
#include "Eura/InsertTextMode.hpp"
#include "Eura/InsertTextFormat.hpp"
#include "Eura/InsertReplaceEdit.hpp"
#include "Eura/CompletionItemTag.hpp"
#include "Eura/CompletionItemKind.hpp"
#include "Eura/CompletionItemLabelDetails.hpp"

namespace Eura
{
    struct [[nodiscard]] CompletionItem final
    {
        std::string label;

        std::optional<CompletionItemLabelDetails> labelDetails;

        std::optional<CompletionItemKind> kind;

        std::optional<std::vector<CompletionItemTag>> tags;

        std::optional<std::string> detail;

        std::optional<std::variant<std::string, MarkupContent>> documentation;

        std::optional<bool> preselect;

        std::optional<std::string> sortText, filterText, insertText;

        std::optional<InsertTextFormat> insertTextFormat;

        std::optional<InsertTextMode> insertTextMode;

        std::optional<std::variant<TextEdit, InsertReplaceEdit>> textEdit;

        std::optional<std::string> textEditText;

        std::optional<std::vector<TextEdit>> additionalTextEdits;

        std::optional<std::vector<std::string>> commitCharacters;

        std::optional<Command> command;

        std::optional<nlohmann::json> data;
    };

    auto from_json(const nlohmann::json& object, CompletionItem& completion_item) noexcept -> void;

    auto to_json(nlohmann::json& object, const CompletionItem& completion_item) noexcept -> void;
}

#endif
#endif