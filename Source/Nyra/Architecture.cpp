// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/Architecture.hpp"

namespace Nyra
{
    [[nodiscard]] auto Stringify(const Architecture architecture) noexcept -> std::string_view
    {
        switch(architecture)
        {
            using enum Architecture;
            case Arm64:
                return "arm64";
            case Amd64:
                return "amd64";
            case Riscv64:
                return "riscv64";
        }
    }
}

#endif