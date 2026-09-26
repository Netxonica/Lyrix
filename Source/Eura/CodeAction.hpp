// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_code_action
#define lyrix_header_guard_eura_code_action
#include "Eura/Command.hpp"
#include "Eura/Diagnostic.hpp"
#include "Eura/WorkspaceEdit.hpp"
#include "Eura/CodeActionTag.hpp"
#include "Eura/CodeActionKind.hpp"
#include "Eura/CodeActionDisabled.hpp"

namespace Eura
{
    struct [[nodiscard]] CodeAction final
    {
        std::string title;

        std::optional<CodeActionKind> kind;

        std::optional<std::vector<Diagnostic>> diagnostics;

        std::optional<bool> isPreferred;

        std::optional<CodeActionDisabled> disabled;

        std::optional<WorkspaceEdit> edit;

        std::optional<Command> command;

        std::optional<nlohmann::json> data;

        std::optional<std::vector<CodeActionTag>> tags;
    };

    auto from_json(const nlohmann::json& object, CodeAction& code_action) noexcept -> void;

    auto to_json(nlohmann::json& object, const CodeAction& code_action) noexcept -> void;
}

#endif
#endif