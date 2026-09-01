// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_document_client_capabilities
#define lyrix_header_guard_eura_text_document_client_capabilities
#include "Eura/HoverClientCapabilities.hpp"
#include "Eura/RenameClientCapabilities.hpp"
#include "Eura/MonikerClientCapabilities.hpp"
#include "Eura/CodeLensClientCapabilities.hpp"
#include "Eura/ReferenceClientCapabilities.hpp"
#include "Eura/InlayHintClientCapabilities.hpp"
#include "Eura/CompletionClientCapabilities.hpp"
#include "Eura/DefinitionClientCapabilities.hpp"
#include "Eura/CodeActionClientCapabilities.hpp"
#include "Eura/DiagnosticClientCapabilities.hpp"
#include "Eura/DeclarationClientCapabilities.hpp"
#include "Eura/InlineValueClientCapabilities.hpp"
#include "Eura/DocumentLinkClientCapabilities.hpp"
#include "Eura/FoldingRangeClientCapabilities.hpp"
#include "Eura/SignatureHelpClientCapabilities.hpp"
#include "Eura/DocumentColorClientCapabilities.hpp"
#include "Eura/CallHierarchyClientCapabilities.hpp"
#include "Eura/TypeHierarchyClientCapabilities.hpp"
#include "Eura/TypeDefinitionClientCapabilities.hpp"
#include "Eura/ImplementationClientCapabilities.hpp"
#include "Eura/DocumentSymbolClientCapabilities.hpp"
#include "Eura/SelectionRangeClientCapabilities.hpp"
#include "Eura/SemanticTokensClientCapabilities.hpp"
#include "Eura/TextDocumentSyncClientCapabilities.hpp"
#include "Eura/InlineCompletionClientCapabilities.hpp"
#include "Eura/DocumentHighlightClientCapabilities.hpp"
#include "Eura/TextDocumentFilterClientCapabilities.hpp"
#include "Eura/DocumentFormattingClientCapabilities.hpp"
#include "Eura/PublishDiagnosticsClientCapabilities.hpp"
#include "Eura/LinkedEditingRangeClientCapabilities.hpp"
#include "Eura/DocumentRangeFormattingClientCapabilities.hpp"
#include "Eura/DocumentOnTypeFormattingClientCapabilities.hpp"

namespace Eura
{
    struct [[nodiscard]] TextDocumentClientCapabilities final
    {
        std::optional<TextDocumentSyncClientCapabilities> synchronization;

        std::optional<TextDocumentFilterClientCapabilities> filters;

        std::optional<CompletionClientCapabilities> completion;

        std::optional<HoverClientCapabilities> hover;

        std::optional<SignatureHelpClientCapabilities> signatureHelp;

        std::optional<DeclarationClientCapabilities> declaration;

        std::optional<DefinitionClientCapabilities> definition;

        std::optional<TypeDefinitionClientCapabilities> typeDefinition;

        std::optional<ImplementationClientCapabilities> implementation;

        std::optional<ReferenceClientCapabilities> references;

        std::optional<DocumentHighlightClientCapabilities> documentHighlight;

        std::optional<DocumentSymbolClientCapabilities> documentSymbol;

        std::optional<CodeActionClientCapabilities> codeAction;

        std::optional<CodeLensClientCapabilities> codeLens;

        std::optional<DocumentLinkClientCapabilities> documentLink;

        std::optional<DocumentColorClientCapabilities> colorProvider;

        std::optional<DocumentFormattingClientCapabilities> formatting;

        std::optional<DocumentRangeFormattingClientCapabilities> rangeFormatting;

        std::optional<DocumentOnTypeFormattingClientCapabilities> onTypeFormatting;

        std::optional<RenameClientCapabilities> rename;

        std::optional<PublishDiagnosticsClientCapabilities> publishDiagnostics;

        std::optional<FoldingRangeClientCapabilities> foldingRange;

        std::optional<SelectionRangeClientCapabilities> selectionRange;

        std::optional<LinkedEditingRangeClientCapabilities> linkedEditingRange;

        std::optional<CallHierarchyClientCapabilities> callHierarchy;

        std::optional<SemanticTokensClientCapabilities> semanticTokens;

        std::optional<MonikerClientCapabilities> moniker;

        std::optional<TypeHierarchyClientCapabilities> typeHierarchy;

        std::optional<InlineValueClientCapabilities> inlineValue;

        std::optional<InlayHintClientCapabilities> inlayHint;

        std::optional<DiagnosticClientCapabilities> diagnostic;

        std::optional<InlineCompletionClientCapabilities> inlineCompletion;
    };

    auto from_json(const nlohmann::json& object, TextDocumentClientCapabilities&
    text_document_client_capabilities) noexcept -> void;

    auto to_json(nlohmann::json& object, const TextDocumentClientCapabilities&
    text_document_client_capabilities) noexcept -> void;
}

#endif
#endif