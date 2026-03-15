/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */
#pragma once

#include "../DisplayHardware/HidlComposerHal.h"
#include "QtiComposerHalExtensionIntf.h"

#include <vendor/qti/hardware/display/composer/3.1/IQtiComposer.h>
#include <vendor/qti/hardware/display/composer/3.1/IQtiComposerClient.h>
#include <cstdint>

namespace android {

using vendor::qti::hardware::display::composer::V3_1::IQtiComposer;
using vendor::qti::hardware::display::composer::V3_1::IQtiComposerClient;

namespace types = hardware::graphics::common;
namespace V2_1 = hardware::graphics::composer::V2_1;

using V2_1::Display;
using V2_1_Layer = V2_1::Layer;

namespace Hwc2 {
class HidlComposer;
}

namespace surfaceflingerextension {

class QtiHidlComposerHalExtension : public QtiComposerHalExtension {
public:
    QtiHidlComposerHalExtension(Hwc2::Composer* composerHal);

    V2_1::Error qtiSetDisplayElapseTime(Display display, uint64_t timeStamp) override;
    V2_1::Error qtiSetLayerType(Display display, V2_1_Layer layer, uint32_t type) override;
#ifdef QTI_LSR_ENABLED
    V2_1::Error qtiSetCompositionLayerType(
            Display display, V2_1_Layer layer,
            gui::CompositionLayerType compositionLayerType) override {
        return Error::NONE;
    }
    V2_1::Error qtiSetLayerVisibilityType(Display display, V2_1_Layer layer,
                                          gui::LayerVisibilityType layerVisibilityType) override {
        return Error::NONE;
    }
    V2_1::Error qtiSetReferenceSpaceType(
            Display display, V2_1_Layer layer,
            gui::RenderLayerReferenceSpaceType referenceSpaceType) override {
        return Error::NONE;
    }
    V2_1::Error qtiSetFrustum(Display display, V2_1_Layer layer, gui::Frustum frustum) override {
        return Error::NONE;
    }
    V2_1::Error qtiSetPose(Display display, V2_1_Layer layer, gui::Pose pose) override {
        return Error::NONE;
    }
    V2_1::Error qtiSetPlaneEquation(Display display, V2_1_Layer layer,
                                    gui::PlaneEquation planeEquation) override {
        return Error::NONE;
    }
    V2_1::Error qtiSetQuadSize(Display display, V2_1_Layer layer, float quadWidth,
                               float quadHeight) override {
        return Error::NONE;
    }
    V2_1::Error qtiSetDisplayConfig(Display display,
                                    const gui::DisplayDeviceConfig& displayDeviceConfig) {
        return Error::NONE;
    }
#endif
    V2_1::Error qtiSetLayerFlag(Display display, V2_1_Layer layer,
                          uint32_t layerFlag) override;
    V2_1::Error qtiSetClientTarget_3_1(Display display, int32_t slot, int acquireFence,
                                 uint32_t dataspace) override;
    V2_1::Error qtiTryDrawMethod(Display display, uint32_t drawMethod) override;

private:
    Hwc2::HidlComposer* mQtiHidlComposer = nullptr;
    sp<IQtiComposerClient> mClient_3_1;
};

} // namespace surfaceflingerextension
} // namespace android
