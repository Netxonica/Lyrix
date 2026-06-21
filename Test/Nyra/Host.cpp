// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/Host.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::optional<Nyra::Host> host = Nyra::Hostify();
    if(not host.has_value())
        return false;
    if(host->architecture() not_eq Nyra::Architecture::
    #ifdef lyrix_darwin
    Arm64
    #elifdef lyrix_windows
    Amd64
    #else
    Amd64
    #endif
    )
        return false;
    return host->system() == Nyra::System::
    #ifdef lyrix_darwin
    Darwin
    #elifdef lyrix_windows
    Windows
    #else
    Linux
    #endif
    ;
}

int main()
{
    return not lyrix_test();
}

#endif