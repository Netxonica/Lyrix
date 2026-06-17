// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/Version.hpp"
#include <print>
#include "Nyra/Host.hpp"
#include "Lumina/Style.hpp"

namespace Nyra
{
    auto Version() noexcept -> void
    {
        const std::optional<Host> host = Hostify();
        if(host.has_value())
        {
            constexpr std::string_view tabs = "    ";
            std::println(stdout, "\n{}{}{}VERSION:{}\n{}{}Architecture: {}{}{}\n{}System:   {}{}{}"
            , Lumina::Style::Bold, Lumina::Style::Italic, Lumina::Style::Data, Lumina::Style::
            Normal, tabs, Lumina::Style::Path, Lumina::Style::Token, Stringify(host->architecture()
            ), Lumina::Style::Path, tabs, Lumina::Style::Token, tabs, Stringify(host->system()));
        }
    }
}

#endif