// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CodeLens.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CodeLens& code_lens) noexcept -> void
    {
        code_lens.range = object.at("range").get<Range>();
        if(object.contains("command"))
            code_lens.command = object.at("command").get<Command>();
        if(object.contains("data"))
            code_lens.data = object.at("data");
    }

    auto to_json(nlohmann::json& object, const CodeLens& code_lens) noexcept -> void
    {
        object["range"] = code_lens.range;
        if(code_lens.command.has_value())
            object["command"] = *code_lens.command;
        if(code_lens.data.has_value())
            object["data"] = *code_lens.data;
    }
}

#endif