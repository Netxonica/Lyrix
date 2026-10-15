// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/Process.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    return Nyra::create_process("Lyrix", std::vector<std::string>{"version"}).has_value();
}

int main()
{
    return not lyrix_test();
}

#endif