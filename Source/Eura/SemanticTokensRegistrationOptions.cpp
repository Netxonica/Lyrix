// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SemanticTokensRegistrationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SemanticTokensRegistrationOptions&
    semantic_tokens_registration_options) noexcept -> void
    {
        from_json(object, static_cast<TextDocumentRegistrationOptions&>(
        semantic_tokens_registration_options));
        from_json(object, static_cast<SemanticTokensOptions&>(semantic_tokens_registration_options)
        );
        from_json(object, static_cast<StaticRegistrationOptions&>(
        semantic_tokens_registration_options));
    }

    auto to_json(nlohmann::json& object, const SemanticTokensRegistrationOptions&
    semantic_tokens_registration_options) noexcept -> void
    {
        to_json(object, static_cast<const TextDocumentRegistrationOptions&>(
        semantic_tokens_registration_options));
        to_json(object, static_cast<const SemanticTokensOptions&>(
        semantic_tokens_registration_options));
        to_json(object, static_cast<const StaticRegistrationOptions&>(
        semantic_tokens_registration_options));
    }
}

#endif