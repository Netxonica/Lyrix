// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_workspace_edit
#define lyrix_header_guard_eura_workspace_edit
#include "Eura/CreateFile.hpp"
#include "Eura/RenameFile.hpp"
#include "Eura/DeleteFile.hpp"
#include "Eura/ChangeAnnotation.hpp"
#include "Eura/TextDocumentEdit.hpp"

namespace Eura
{
    struct [[nodiscard]] WorkspaceEdit final
    {
        std::optional<std::unordered_map<DocumentUri, std::vector<TextEdit>>> changes;

        std::optional<std::vector<std::variant<TextDocumentEdit, CreateFile, RenameFile, DeleteFile
        >>> documentChanges;

        std::optional<std::unordered_map<ChangeAnnotationIdentifier, ChangeAnnotation>>
        changeAnnotations;
    };

    auto from_json(const nlohmann::json& object, WorkspaceEdit& workspace_edit) noexcept -> void;

    auto to_json(nlohmann::json& object, const WorkspaceEdit& workspace_edit) noexcept -> void;
}

#endif
#endif