// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Server.hpp"
#include "Eura/Json.hpp"
#include "Eura/WorkspaceEdit.hpp"
#include <print>

namespace Eura
{
    auto Listen() noexcept -> void
    {
        Json::Strings strings;
        const std::string content = "{\"changes\":{\"ohwow.lyrix\":[{\"range\":{\"start\":{\"line\":42,\"character\":7},\"end\":{\"line\":50,\"character\":10}},\"newText\":\"huh...\"}]},\"documentChanges\":[{\"textDocument\":{\"uri\":\"ohwtf.cpp\",\"version\":null},\"edits\":[{\"range\":{\"start\":{\"line\":678,\"character\":3},\"end\":{\"line\":74756,\"character\":2}},\"newText\":\"what the actual fuck is this\"}]}],\"changeAnnotations\":{\"annotation 1\":{\"label\":\"invincible\",\"needsConfirmation\":false}}}";
        Json::Root root = Json::Deserialize(content, strings);
        WorkspaceEdit message;
        Deserialize(root, message);
        Json::Root response;
        Serialize(response, message);
        std::println("{}", Json::Serialize(response));
    }
}

#endif