// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CodeLensOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CodeLensOptions& code_lens_options) noexcept ->
    void
    {
        from_json(object, static_cast<WorkDoneProgressOptions&>(code_lens_options));
        if(object.contains("resolveProvider"))
            code_lens_options.resolveProvider = object.at("resolveProvider").get<bool>();
    }

    auto to_json(nlohmann::json& object, const CodeLensOptions& code_lens_options) noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressOptions&>(code_lens_options));
        if(code_lens_options.resolveProvider.has_value())
            object["resolveProvider"] = *code_lens_options.resolveProvider;
    }
}

#endif