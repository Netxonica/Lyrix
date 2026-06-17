// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/Architecture.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    return Nyra::Stringify(Nyra::Architecture::Arm64) == "arm64" and Nyra::Stringify(Nyra::
    Architecture::Amd64) == "amd64" and Nyra::Stringify(Nyra::Architecture::Riscv64) == "riscv64";
}

int main()
{
    return not lyrix_test();
}

#endif