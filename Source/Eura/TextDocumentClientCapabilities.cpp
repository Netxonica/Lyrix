// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TextDocumentClientCapabilities&
    text_document_client_capabilities) noexcept -> void
    {
        if(object.contains("synchronization"))
            text_document_client_capabilities.synchronization = object.at("synchronization").get<
            TextDocumentSyncClientCapabilities>();
        if(object.contains("filters"))
            text_document_client_capabilities.filters = object.at("filters").get<
            TextDocumentFilterClientCapabilities>();
        if(object.contains("completion"))
            text_document_client_capabilities.completion = object.at("completion").get<
            CompletionClientCapabilities>();
        if(object.contains("hover"))
            text_document_client_capabilities.hover = object.at("hover").get<
            HoverClientCapabilities>();
        if(object.contains("signatureHelp"))
            text_document_client_capabilities.signatureHelp = object.at("signatureHelp").get<
            SignatureHelpClientCapabilities>();
        if(object.contains("declaration"))
            text_document_client_capabilities.declaration = object.at("declaration").get<
            DeclarationClientCapabilities>();
        if(object.contains("definition"))
            text_document_client_capabilities.definition = object.at("definition").get<
            DefinitionClientCapabilities>();
        if(object.contains("typeDefinition"))
            text_document_client_capabilities.typeDefinition = object.at("typeDefinition").get<
            TypeDefinitionClientCapabilities>();
        if(object.contains("implementation"))
            text_document_client_capabilities.implementation = object.at("implementation").get<
            ImplementationClientCapabilities>();
        if(object.contains("references"))
            text_document_client_capabilities.references = object.at("references").get<
            ReferenceClientCapabilities>();
        if(object.contains("documentHighlight"))
            text_document_client_capabilities.documentHighlight = object.at("documentHighlight").
            get<DocumentHighlightClientCapabilities>();
        if(object.contains("documentSymbol"))
            text_document_client_capabilities.documentSymbol = object.at("documentSymbol").get<
            DocumentSymbolClientCapabilities>();
        if(object.contains("codeAction"))
            text_document_client_capabilities.codeAction = object.at("codeAction").get<
            CodeActionClientCapabilities>();
        if(object.contains("codeLens"))
            text_document_client_capabilities.codeLens = object.at("codeLens").get<
            CodeLensClientCapabilities>();
        if(object.contains("documentLink"))
            text_document_client_capabilities.documentLink = object.at("documentLink").get<
            DocumentLinkClientCapabilities>();
        if(object.contains("colorProvider"))
            text_document_client_capabilities.colorProvider = object.at("colorProvider").get<
            DocumentColorClientCapabilities>();
        if(object.contains("formatting"))
            text_document_client_capabilities.formatting = object.at("formatting").get<
            DocumentFormattingClientCapabilities>();
        if(object.contains("rangeFormatting"))
            text_document_client_capabilities.rangeFormatting = object.at("rangeFormatting").get<
            DocumentRangeFormattingClientCapabilities>();
        if(object.contains("onTypeFormatting"))
            text_document_client_capabilities.onTypeFormatting = object.at("onTypeFormatting").get<
            DocumentOnTypeFormattingClientCapabilities>();
        if(object.contains("rename"))
            text_document_client_capabilities.rename = object.at("rename").get<
            RenameClientCapabilities>();
        if(object.contains("publishDiagnostics"))
            text_document_client_capabilities.publishDiagnostics = object.at("publishDiagnostics").
            get<PublishDiagnosticsClientCapabilities>();
        if(object.contains("foldingRange"))
            text_document_client_capabilities.foldingRange = object.at("foldingRange").get<
            FoldingRangeClientCapabilities>();
        if(object.contains("selectionRange"))
            text_document_client_capabilities.selectionRange = object.at("selectionRange").get<
            SelectionRangeClientCapabilities>();
        if(object.contains("linkedEditingRange"))
            text_document_client_capabilities.linkedEditingRange = object.at("linkedEditingRange").
            get<LinkedEditingRangeClientCapabilities>();
        if(object.contains("callHierarchy"))
            text_document_client_capabilities.callHierarchy = object.at("callHierarchy").get<
            CallHierarchyClientCapabilities>();
        if(object.contains("semanticTokens"))
            text_document_client_capabilities.semanticTokens = object.at("semanticTokens").get<
            SemanticTokensClientCapabilities>();
        if(object.contains("moniker"))
            text_document_client_capabilities.moniker = object.at("moniker").get<
            MonikerClientCapabilities>();
        if(object.contains("typeHierarchy"))
            text_document_client_capabilities.typeHierarchy = object.at("typeHierarchy").get<
            TypeHierarchyClientCapabilities>();
        if(object.contains("inlineValue"))
            text_document_client_capabilities.inlineValue = object.at("inlineValue").get<
            InlineValueClientCapabilities>();
        if(object.contains("inlayHint"))
            text_document_client_capabilities.inlayHint = object.at("inlayHint").get<
            InlayHintClientCapabilities>();
        if(object.contains("diagnostic"))
            text_document_client_capabilities.diagnostic = object.at("diagnostic").get<
            DiagnosticClientCapabilities>();
        if(object.contains("inlineCompletion"))
            text_document_client_capabilities.inlineCompletion = object.at("inlineCompletion").get<
            InlineCompletionClientCapabilities>();
    }

    auto to_json(nlohmann::json& object, const TextDocumentClientCapabilities&
    text_document_client_capabilities) noexcept -> void
    {
        if(text_document_client_capabilities.synchronization.has_value())
            object["synchronization"] = *text_document_client_capabilities.synchronization;
        if(text_document_client_capabilities.filters.has_value())
            object["filters"] = *text_document_client_capabilities.filters;
        if(text_document_client_capabilities.completion.has_value())
            object["completion"] = *text_document_client_capabilities.completion;
        if(text_document_client_capabilities.hover.has_value())
            object["hover"] = *text_document_client_capabilities.hover;
        if(text_document_client_capabilities.signatureHelp.has_value())
            object["signatureHelp"] = *text_document_client_capabilities.signatureHelp;
        if(text_document_client_capabilities.declaration.has_value())
            object["declaration"] = *text_document_client_capabilities.declaration;
        if(text_document_client_capabilities.definition.has_value())
            object["definition"] = *text_document_client_capabilities.definition;
        if(text_document_client_capabilities.typeDefinition.has_value())
            object["typeDefinition"] = *text_document_client_capabilities.typeDefinition;
        if(text_document_client_capabilities.implementation.has_value())
            object["implementation"] = *text_document_client_capabilities.implementation;
        if(text_document_client_capabilities.references.has_value())
            object["references"] = *text_document_client_capabilities.references;
        if(text_document_client_capabilities.documentHighlight.has_value())
            object["documentHighlight"] = *text_document_client_capabilities.documentHighlight;
        if(text_document_client_capabilities.documentSymbol.has_value())
            object["documentSymbol"] = *text_document_client_capabilities.documentSymbol;
        if(text_document_client_capabilities.codeAction.has_value())
            object["codeAction"] = *text_document_client_capabilities.codeAction;
        if(text_document_client_capabilities.codeLens.has_value())
            object["codeLens"] = *text_document_client_capabilities.codeLens;
        if(text_document_client_capabilities.documentLink.has_value())
            object["documentLink"] = *text_document_client_capabilities.documentLink;
        if(text_document_client_capabilities.colorProvider.has_value())
            object["colorProvider"] = *text_document_client_capabilities.colorProvider;
        if(text_document_client_capabilities.formatting.has_value())
            object["formatting"] = *text_document_client_capabilities.formatting;
        if(text_document_client_capabilities.rangeFormatting.has_value())
            object["rangeFormatting"] = *text_document_client_capabilities.rangeFormatting;
        if(text_document_client_capabilities.onTypeFormatting.has_value())
            object["onTypeFormatting"] = *text_document_client_capabilities.onTypeFormatting;
        if(text_document_client_capabilities.rename.has_value())
            object["rename"] = *text_document_client_capabilities.rename;
        if(text_document_client_capabilities.publishDiagnostics.has_value())
            object["publishDiagnostics"] = *text_document_client_capabilities.publishDiagnostics;
        if(text_document_client_capabilities.foldingRange.has_value())
            object["foldingRange"] = *text_document_client_capabilities.foldingRange;
        if(text_document_client_capabilities.selectionRange.has_value())
            object["selectionRange"] = *text_document_client_capabilities.selectionRange;
        if(text_document_client_capabilities.linkedEditingRange.has_value())
            object["linkedEditingRange"] = *text_document_client_capabilities.linkedEditingRange;
        if(text_document_client_capabilities.callHierarchy.has_value())
            object["callHierarchy"] = *text_document_client_capabilities.callHierarchy;
        if(text_document_client_capabilities.semanticTokens.has_value())
            object["semanticTokens"] = *text_document_client_capabilities.semanticTokens;
        if(text_document_client_capabilities.moniker.has_value())
            object["moniker"] = *text_document_client_capabilities.moniker;
        if(text_document_client_capabilities.typeHierarchy.has_value())
            object["typeHierarchy"] = *text_document_client_capabilities.typeHierarchy;
        if(text_document_client_capabilities.inlineValue.has_value())
            object["inlineValue"] = *text_document_client_capabilities.inlineValue;
        if(text_document_client_capabilities.inlayHint.has_value())
            object["inlayHint"] = *text_document_client_capabilities.inlayHint;
        if(text_document_client_capabilities.diagnostic.has_value())
            object["diagnostic"] = *text_document_client_capabilities.diagnostic;
        if(text_document_client_capabilities.inlineCompletion.has_value())
            object["inlineCompletion"] = *text_document_client_capabilities.inlineCompletion;
    }
}

#endif