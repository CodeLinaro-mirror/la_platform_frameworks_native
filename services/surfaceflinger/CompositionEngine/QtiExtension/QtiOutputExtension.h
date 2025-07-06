/* Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */
#pragma once

#include <android/gui/CompositionLayerType.h>
#include <android/gui/Frustum.h>
#include <android/gui/LayerVisibilityType.h>
#include <android/gui/Orientation.h>
#include <android/gui/PlaneEquation.h>
#include <android/gui/Pose.h>
#include <android/gui/Position.h>
#include <android/gui/RenderLayerReferenceSpaceType.h>
#include "DisplayHardware/HWC2.h"
#include "compositionengine/impl/Output.h"

using android::compositionengine::impl::Output;

namespace android::compositionengineextension {

class QtiOutputExtension {
public:
    QtiOutputExtension() = default;
    ~QtiOutputExtension() = default;

    static bool qtiIsProtectedContent(const Output* output);
    static bool qtiHasSecureDisplay(const Output* output);
    static bool qtiHasSecureOrProtectedContent(const Output* output);
    static void qtiWriteLayerFlagToHWC(HWC2::Layer* layer, const Output* output);
    static void qtiSetLayerAsMask(DisplayIdVariant id, uint64_t layerId);
    static void qtiSetLayerType(HWC2::Layer* layerId, uint32_t type, const char* debugName);
    static bool qtiUseSpecFence(void);
    static void qtiGetVisibleLayerInfo(const Output* output);
    static void qtiSetCompositionLayerType(HWC2::Layer* layer,
                                           gui::CompositionLayerType compositionLayerType,
                                           const char* debugName);
    static void qtiSetLayerVisibilityType(HWC2::Layer* layer,
                                          gui::LayerVisibilityType layerVisibilityType,
                                          const char* debugName);
    static void qtiSetReferenceSpaceType(HWC2::Layer* layer,
                                         gui::RenderLayerReferenceSpaceType referenceSpaceType,
                                         const char* debugName);
    static void qtiSetFrustum(HWC2::Layer* layer, gui::Frustum frustum, const char* debugName);
    static void qtiSetPose(HWC2::Layer* layer, gui::Pose pose, const char* debugName);
    static void qtiSetPlaneEquation(HWC2::Layer* layer, gui::PlaneEquation planeEquation,
                                    const char* debugName);
    static void qtiSetQuadSize(HWC2::Layer* layer, float quadWidth, float quadHeight,
                               const char* debugName);
};

} // namespace android::compositionengineextension
