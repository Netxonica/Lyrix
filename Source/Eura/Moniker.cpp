// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Moniker.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, Moniker& moniker) noexcept -> void
    {
        moniker.scheme = object.at("scheme").get<std::string>();
        moniker.identifier = object.at("identifier").get<std::string>();
        moniker.unique = object.at("unique").get<UniquenessLevel>();
        if(object.contains("kind"))
            moniker.kind = object.at("kind").get<MonikerKind>();
    }

    auto to_json(nlohmann::json& object, const Moniker& moniker) noexcept -> void
    {
        object["scheme"] = moniker.scheme;
        object["identifier"] = moniker.identifier;
        object["unique"] = moniker.unique;
        if(moniker.kind.has_value())
            object["kind"] = *moniker.kind;
    }
}

#endif