// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/Help.hpp"
#include <print>
#include <cstdio>
#include "Lumina/Style.hpp"

namespace Nyra
{
    auto Help() noexcept -> void
    {
        constexpr const std::string_view tabs = "    ", dtabs = "        ";
        std::println(stderr,
        "\n{}{}Usage:{} Lyrix{}{}{} [COMMAND]\n\n{}COMMAND:{}\n{}{}help {}{}{}- {}This exact same "
        "help message\n{}{}version  {}{}{}- {}Prints information about the running Lyrix compiler "
        "instance\n{}{}lsp  {}{}{}- {}Initializes the LSP server (meant to be run by an LSP client"
        ")\n{}{}create  {}{}{}{}NAME {}{}- {}Creates a new Lyrix project with the specified {}{}{}"
        "NAME{}\n{}{}compile {}{}{}{}NAME {}{}- {}Compiles an existing Lyrix project with the "
        "specified {}{}{}NAME\n\n{}NAME{}{}{}:\n{}{}An identifier that satisfies the following "
        "regular expression: {}{}{}^[A-Za-z_][A-Za-z0-9_]*${}\n", Lumina::Style::Bold, Lumina::
        Style::Path, Lumina::Style::Data, Lumina::Style::Bold, Lumina::Style::Normal, Lumina::Style
        ::Bold, Lumina::Style::Path, Lumina::Style::Normal, tabs, Lumina::Style::Data, dtabs,
        Lumina::Style::Normal, Lumina::Style::Path, Lumina::Style::Normal, tabs, Lumina::Style::
        Data, tabs, Lumina::Style::Normal, Lumina::Style::Path, Lumina::Style::Normal, tabs, Lumina
        ::Style::Data, dtabs, Lumina::Style::Normal, Lumina::Style::Path, Lumina::Style::Normal,
        tabs, Lumina::Style::Data, Lumina::Style::Normal, Lumina::Style::Path, Lumina::Style::Bold,
        Lumina::Style::Italic, Lumina::Style::Normal, Lumina::Style::Path, Lumina::Style::Normal,
        Lumina::Style::Path, Lumina::Style::Bold, Lumina::Style::Italic, Lumina::Style::Normal,
        tabs, Lumina::Style::Data, Lumina::Style::Normal, Lumina::Style::Path, Lumina::Style::Bold,
        Lumina::Style::Italic, Lumina::Style::Normal, Lumina::Style::Path, Lumina::Style::Normal,
        Lumina::Style::Path, Lumina::Style::Bold, Lumina::Style::Italic, tabs, Lumina::Style::
        Normal, Lumina::Style::Path, Lumina::Style::Bold, Lumina::Style::Normal, dtabs, Lumina::
        Style::Data, Lumina::Style::Bold, Lumina::Style::Italic, Lumina::Style::Normal);
    }
}

#endif