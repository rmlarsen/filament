/*
 * Copyright (C) 2015 The Android Open Source Project
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

#ifndef TNT_FILABRIDGE_SIBGENERATOR_H
#define TNT_FILABRIDGE_SIBGENERATOR_H

#include "private/filament/Variant.h"

#include <stdint.h>
#include <stddef.h>
#include "private/filament/EngineEnums.h"

namespace filament {

class SamplerInterfaceBlock;

class SibGenerator {
public:
    static SamplerInterfaceBlock const& getPerViewSib(Variant variant) noexcept;
    static SamplerInterfaceBlock const& getPerRenderableSib(Variant variant) noexcept;
    static SamplerInterfaceBlock const* getSib(filament::DescriptorSetBindingPoints bindingPoint, Variant variant) noexcept;
    // When adding a sampler block here, make sure to also update
    //      FMaterial::getSurfaceProgramSlow and FMaterial::getPostProcessProgramSlow if needed
};

} // namespace filament

#endif // TNT_FILABRIDGE_SIBGENERATOR_H
