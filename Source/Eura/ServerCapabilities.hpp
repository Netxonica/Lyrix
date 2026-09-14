// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_server_capabilities
#define lyrix_header_guard_eura_server_capabilities
#include "Eura/HoverOptions.hpp"
#include "Eura/RenameOptions.hpp"
#include "Eura/CodeLensOptions.hpp"
#include "Eura/ReferenceOptions.hpp"
#include "Eura/WorkspaceOptions.hpp"
#include "Eura/CompletionOptions.hpp"
#include "Eura/DefinitionOptions.hpp"
#include "Eura/CodeActionOptions.hpp"
#include "Eura/DocumentLinkOptions.hpp"
#include "Eura/PositionEncodingKind.hpp"
#include "Eura/SignatureHelpOptions.hpp"
#include "Eura/DocumentSymbolOptions.hpp"
#include "Eura/ExecuteCommandOptions.hpp"
#include "Eura/WorkspaceSymbolOptions.hpp"
#include "Eura/TextDocumentSyncOptions.hpp"
#include "Eura/InlineCompletionOptions.hpp"
#include "Eura/DocumentHighlightOptions.hpp"
#include "Eura/DocumentFormattingOptions.hpp"
#include "Eura/MonikerRegistrationOptions.hpp"
#include "Eura/InlayHintRegistrationOptions.hpp"
#include "Eura/DiagnosticRegistrationOptions.hpp"
#include "Eura/DocumentRangeFormattingOptions.hpp"
#include "Eura/DeclarationRegistrationOptions.hpp"
#include "Eura/InlineValueRegistrationOptions.hpp"
#include "Eura/DocumentOnTypeFormattingOptions.hpp"
#include "Eura/FoldingRangeRegistrationOptions.hpp"
#include "Eura/DocumentColorRegistrationOptions.hpp"
#include "Eura/CallHierarchyRegistrationOptions.hpp"
#include "Eura/TypeHierarchyRegistrationOptions.hpp"
#include "Eura/TypeDefinitionRegistrationOptions.hpp"
#include "Eura/ImplementationRegistrationOptions.hpp"
#include "Eura/SelectionRangeRegistrationOptions.hpp"
#include "Eura/SemanticTokensRegistrationOptions.hpp"
#include "Eura/LinkedEditingRangeRegistrationOptions.hpp"
#include "Eura/NotebookDocumentSyncRegistrationOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] ServerCapabilities final
    {
        std::optional<PositionEncodingKind> positionEncoding;

        std::optional<std::variant<TextDocumentSyncOptions, TextDocumentSyncKind>> textDocumentSync
        ;

        std::optional<std::variant<NotebookDocumentSyncOptions,
        NotebookDocumentSyncRegistrationOptions>> notebookDocumentSync;

        std::optional<CompletionOptions> completionProvider;

        std::optional<std::variant<bool, HoverOptions>> hoverProvider;

        std::optional<SignatureHelpOptions> signatureHelpProvider;

        std::optional<std::variant<bool, DeclarationOptions, DeclarationRegistrationOptions>>
        declarationProvider;

        std::optional<std::variant<bool, DefinitionOptions>> definitionProvider;

        std::optional<std::variant<bool, TypeDefinitionOptions, TypeDefinitionRegistrationOptions>>
        typeDefinitionProvider;

        std::optional<std::variant<bool, ImplementationOptions, ImplementationRegistrationOptions>>
        implementationProvider;

        std::optional<std::variant<bool, ReferenceOptions>> referenceProvider;

        std::optional<std::variant<bool, DocumentHighlightOptions>> documentHighlightProvider;

        std::optional<std::variant<bool, DocumentSymbolOptions>> documentSymbolProvider;

        std::optional<std::variant<bool, CodeActionOptions>> codeActionProvider;

        std::optional<CodeLensOptions> codeLensProvider;

        std::optional<DocumentLinkOptions> documentLinkProvider;

        std::optional<std::variant<bool, DocumentColorOptions, DocumentColorRegistrationOptions>>
        colorProvider;

        std::optional<std::variant<bool, DocumentFormattingOptions>> documentFormattingProvider;

        std::optional<std::variant<bool, DocumentRangeFormattingOptions>>
        documentRangeFormattingProvider;

        std::optional<DocumentOnTypeFormattingOptions> documentOnTypeFormattingProvider;

        std::optional<std::variant<bool, RenameOptions>> renameProvider;

        std::optional<std::variant<bool, FoldingRangeOptions, FoldingRangeRegistrationOptions>>
        foldingRangeProvider;

        std::optional<ExecuteCommandOptions> executeCommandProvider;

        std::optional<std::variant<bool, SelectionRangeOptions, SelectionRangeRegistrationOptions>>
        selectionRangeProvider;

        std::optional<std::variant<bool, LinkedEditingRangeOptions,
        LinkedEditingRangeRegistrationOptions>> linkedEditingRangeProvider;

        std::optional<std::variant<bool, CallHierarchyOptions, CallHierarchyRegistrationOptions>>
        callHierarchyProvider;

        std::optional<std::variant<SemanticTokensOptions, SemanticTokensRegistrationOptions>>
        semanticTokensProvider;

        std::optional<std::variant<bool, MonikerOptions, MonikerRegistrationOptions>>
        monikerProvider;

        std::optional<std::variant<bool, TypeHierarchyOptions, TypeHierarchyRegistrationOptions>>
        typeHierarchyProvider;

        std::optional<std::variant<bool, InlineValueOptions, InlineValueRegistrationOptions>>
        inlineValueProvider;

        std::optional<std::variant<bool, InlayHintOptions, InlayHintRegistrationOptions>>
        inlayHintProvider;

        std::optional<std::variant<DiagnosticOptions, DiagnosticRegistrationOptions>>
        diagnosticProvider;

        std::optional<std::variant<bool, WorkspaceSymbolOptions>> workspaceSymbolProvider;

        std::optional<std::variant<bool, InlineCompletionOptions>> inlineCompletionProvider;

        std::optional<WorkspaceOptions> workspace;

        std::optional<nlohmann::json> experimental;
    };

    auto from_json(const nlohmann::json& object, ServerCapabilities& server_capabilities) noexcept
    -> void;

    auto to_json(nlohmann::json& object, const ServerCapabilities& server_capabilities) noexcept ->
    void;
}

#endif
#endif