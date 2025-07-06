/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */
#pragma once

#include <android/gui/CompositionLayerType.h>
#include <android/gui/DisplayDeviceConfig.h>
#include <android/gui/Frustum.h>
#include <android/gui/LayerVisibilityType.h>
#include <android/gui/Orientation.h>
#include <android/gui/PlaneEquation.h>
#include <android/gui/Pose.h>
#include <android/gui/Position.h>
#include <android/gui/RenderLayerReferenceSpaceType.h>
#include <android/hardware/graphics/composer/2.4/IComposerClient.h>

namespace android {

namespace V2_1 = hardware::graphics::composer::V2_1;

using V2_1::Display;
using V2_1::Error;
using V2_1_Layer = V2_1::Layer;

namespace Hwc2 {
class Composer;
} // namespace Hwc2

namespace surfaceflingerextension {

class QtiComposerHalExtension {
public:
    virtual ~QtiComposerHalExtension(){};

    virtual Error qtiSetDisplayElapseTime(Display display, uint64_t timeStamp) = 0;
    virtual Error qtiSetLayerType(Display display, V2_1_Layer layer, uint32_t type) = 0;
    virtual Error qtiTryDrawMethod(Display display, uint32_t drawMethod) = 0;
    virtual Error qtiSetClientTarget_3_1(Display display, int32_t slot, int acquireFence,
                                         uint32_t dataspace) = 0;
    virtual Error qtiSetLayerFlag(Display display, V2_1_Layer layer,
                                  uint32_t layerFlag) = 0;
    virtual Error qtiSetCompositionLayerType(Display display, V2_1_Layer layer,
                                             gui::CompositionLayerType compositionLayerType) = 0;
    virtual Error qtiSetLayerVisibilityType(Display display, V2_1_Layer layer,
                                            gui::LayerVisibilityType layerVisibilityType) = 0;
    virtual Error qtiSetReferenceSpaceType(
            Display display, V2_1_Layer layer,
            gui::RenderLayerReferenceSpaceType referenceSpaceType) = 0;
    virtual Error qtiSetFrustum(Display display, V2_1_Layer layer, gui::Frustum frustum) = 0;
    virtual Error qtiSetPose(Display display, V2_1_Layer layer, gui::Pose pose) = 0;
    virtual Error qtiSetPlaneEquation(Display display, V2_1_Layer layer,
                                      gui::PlaneEquation planeEquation) = 0;
    virtual Error qtiSetQuadSize(Display display, V2_1_Layer layer, float quadWidth,
                                 float quadHeight) = 0;
    virtual Error qtiSetDisplayConfig(Display display,
                                      const gui::DisplayDeviceConfig& displayDeviceConfig) = 0;
};

} // namespace surfaceflingerextension
} // namespace android
