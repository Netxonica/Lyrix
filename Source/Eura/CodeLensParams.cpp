// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CodeLensParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CodeLensParams& code_lens_params) noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressParams&>(code_lens_params));
        from_json(object, static_cast<PartialResultParams&>(code_lens_params));
        code_lens_params.textDocument = object.at("textDocument").get<TextDocumentIdentifier>();
    }

    auto to_json(nlohmann::json& object, const CodeLensParams& code_lens_params) noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressParams&>(code_lens_params));
        to_json(object, static_cast<const PartialResultParams&>(code_lens_params));
        object["textDocument"] = code_lens_params.textDocument;
    }
}

#endif