// Copyright 2023 The Dawn & Tint Authors
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived from
//    this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef SRC_DAWN_NATIVE_D3D_PHYSICALDEVICED3D_H_
#define SRC_DAWN_NATIVE_D3D_PHYSICALDEVICED3D_H_

#include "dawn/native/PhysicalDevice.h"
#include "partition_alloc/pointers/raw_ptr.h"

#include "dawn/native/d3d/d3d_platform.h"

namespace dawn::native::d3d {

class Backend;

class PhysicalDevice : public PhysicalDeviceBase {
  public:
    PhysicalDevice(Backend* backend,
                   ComPtr<IDXGIAdapter3> hardwareAdapter,
                   wgpu::BackendType backendType);
    ~PhysicalDevice() override;

    IDXGIAdapter3* GetHardwareAdapter() const;
    Backend* GetBackend() const;

    ResultOrError<PhysicalDeviceSurfaceCapabilities> GetSurfaceCapabilities(
        InstanceBase* instance,
        const Surface* surface) const override;

  protected:
    MaybeError InitializeImpl() override;

  private:
    ComPtr<IDXGIAdapter3> mHardwareAdapter;
    raw_ptr<Backend> mBackend;
};

}  // namespace dawn::native::d3d

#endif  // SRC_DAWN_NATIVE_D3D_PHYSICALDEVICED3D_H_
