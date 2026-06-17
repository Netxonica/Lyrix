// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/Host.hpp"
#include <memory>
#ifdef lyxin_windows
#include <windows.h>
#else
#include <sys/utsname.h>
#endif
#include "Nyra/Error.hpp"

namespace Nyra
{
    Host::Host(const Architecture architecture, const System system) noexcept : m_arch(architecture
    ), m_sys(system){}

    [[nodiscard]] auto Host::architecture() const noexcept -> Architecture
    {
        return m_arch;
    }

    [[nodiscard]] auto Host::system() const noexcept -> System
    {
        return m_sys;
    }

    [[nodiscard]] auto Hostify() noexcept -> std::optional<Host>
    {
        #ifdef lynix_windows
        SYSTEM_INFO info;
        GetNativeSystemInfo(&info);
        Architecture arch = Architecture::Amd64;
        switch(info.wProcessorArchitecture)
        {
            default:
                std::make_unique<Error>(13uz)->Report();
                return std::nullopt;
            case PROCESSOR_ARCHITECTURE_AMD64:
            break;
            case PROCESSOR_ARCHITECTURE_ARM64:
                arch = Architecture::Arm64;
        }
        return Host(arch, System::Windows);
        #else
        utsname info;
        if(uname(&info) not_eq 0)
        {
            std::make_unique<Error>(12uz)->Report();
            return std::nullopt;
        }
        const std::string_view machine = info.machine, sysname = info.sysname;
        Architecture arch = Architecture::Amd64;
        if(machine == "aarch64" or machine == "arm64")
            arch = Architecture::Arm64;
        else if(machine == "riscv64")
            arch = Architecture::Riscv64;
        else if(machine not_eq "x86_64" and machine not_eq "amd64" and machine not_eq "x64")
        {
            std::make_unique<Error>(13uz)->Report();
            return std::nullopt;
        }
        System sys = System::Darwin;
        if(sysname == "Linux")
            sys = System::Linux;
        else if(sysname not_eq "Darwin")
        {
            std::make_unique<Error>(14uz)->Report();
            return std::nullopt;
        }
        return Host(arch, sys);
        #endif
    }
}

#endif