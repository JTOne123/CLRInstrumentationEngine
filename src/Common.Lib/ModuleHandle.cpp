// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "stdafx.h"
#include "ModuleHandle.h"

namespace CommonLib
{
    CModuleHandle::CModuleHandle(const HMODULE hModule) noexcept
        : m_hModule(hModule)
    {
    }

    CModuleHandle::~CModuleHandle()
    {
        Reset();
    }

    const HMODULE CModuleHandle::GetHandle() const
    {
        return m_hModule;
    }

    CModuleHandle::operator const HMODULE() const
    {
        return GetHandle();
    }

    void CModuleHandle::Reset(const HMODULE hModule)
    {
        if (nullptr != m_hModule)
        {
            ::FreeLibrary(m_hModule);
        }

        m_hModule = hModule;
    }
}