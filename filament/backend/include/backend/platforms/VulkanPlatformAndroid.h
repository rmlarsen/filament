/*
 * Copyright (C) 2025 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef TNT_FILAMENT_BACKEND_PLATFORMS_VULKAN_PLATFORM_ANDROID_H
#define TNT_FILAMENT_BACKEND_PLATFORMS_VULKAN_PLATFORM_ANDROID_H

#include <backend/DriverEnums.h>
#include <backend/platforms/VulkanPlatform.h>

#include <android/hardware_buffer.h>

namespace filament::backend {

class VulkanPlatformAndroid : public VulkanPlatform {
public:
    ExternalImageHandle UTILS_PUBLIC createExternalImage(AHardwareBuffer const* buffer,
            bool sRGB) noexcept;

    struct UTILS_PUBLIC ExternalImageDescAndroid {
        uint32_t width;      // Texture width
        uint32_t height;     // Texture height
        TextureFormat format;// Texture format
        TextureUsage usage;  // Texture usage flags
    };

    ExternalImageDescAndroid UTILS_PUBLIC getExternalImageDesc(
            ExternalImageHandleRef externalImage) const noexcept;

    virtual ExternalImageMetadata extractExternalImageMetadata(
            ExternalImageHandleRef image) const override;

    virtual ImageData createVkImageFromExternal(ExternalImageHandleRef image) const override;

protected:
    virtual ExtensionSet getSwapchainInstanceExtensions() const override;

    using SurfaceBundle = VulkanPlatform::SurfaceBundle;
    virtual SurfaceBundle createVkSurfaceKHR(void* nativeWindow, VkInstance instance,
            uint64_t flags) const noexcept override;

private:
    struct ExternalImageVulkanAndroid : public Platform::ExternalImage {
        AHardwareBuffer* aHardwareBuffer = nullptr;
        bool sRGB = false;

    protected:
        ~ExternalImageVulkanAndroid() override;
    };
};

}// namespace filament::backend

#endif// TNT_FILAMENT_BACKEND_PLATFORMS_VULKAN_PLATFORM_ANDROID_H
