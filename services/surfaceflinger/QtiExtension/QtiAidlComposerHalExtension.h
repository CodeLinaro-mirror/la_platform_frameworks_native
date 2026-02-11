/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */
#pragma once

#include "../DisplayHardware/AidlComposerHal.h"
#include "QtiComposerHalExtensionIntf.h"

namespace android {

#ifdef QTI_COMPOSER3_EXTENSIONS
using aidl::vendor::qti::hardware::display::composer3::IQtiComposer3Client;
using aidl::vendor::qti::hardware::display::composer3::QtiDisplayCommand;
using aidl::vendor::qti::hardware::display::composer3::QtiDrawMethod;
using aidl::vendor::qti::hardware::display::composer3::QtiLayerCommand;
using aidl::vendor::qti::hardware::display::composer3::QtiLayerFlags;
using aidl::vendor::qti::hardware::display::composer3::QtiLayerType;
#endif

namespace Hwc2 {
class AidlComposer;
}

namespace surfaceflingerextension {

class QtiAidlComposerHalExtension : public QtiComposerHalExtension {
public:
    QtiAidlComposerHalExtension(Hwc2::Composer* composerHal);

    Error qtiSetDisplayElapseTime(Display display, uint64_t timeStamp) override;
    Error qtiSetLayerType(Display display, V2_1_Layer layer, uint32_t type) override;
    Error qtiTryDrawMethod(Display display, uint32_t drawMethod) override;
    Error qtiSetClientTarget_3_1(Display display, int32_t slot, int acquireFence,
                                 uint32_t dataspace) override;
    Error qtiSetLayerFlag(Display display, V2_1_Layer layer,
                          uint32_t layerFlag) override;
#ifdef QTI_LSR_ENABLED
    Error qtiSetCompositionLayerType(Display display, V2_1_Layer layer,
                                     gui::CompositionLayerType compositionLayerType) override;
    Error qtiSetLayerVisibilityType(Display display, V2_1_Layer layer,
                                    gui::LayerVisibilityType layerVisibilityType) override;
    Error qtiSetReferenceSpaceType(Display display, V2_1_Layer layer,
                                   gui::RenderLayerReferenceSpaceType referenceSpaceType) override;
    Error qtiSetFrustum(Display display, V2_1_Layer layer, gui::Frustum frustum) override;
    Error qtiSetPose(Display display, V2_1_Layer layer, gui::Pose pose) override;
    Error qtiSetPlaneEquation(Display display, V2_1_Layer layer,
                              gui::PlaneEquation planeEquation) override;
    Error qtiSetQuadSize(Display display, V2_1_Layer layer, float quadWidth,
                         float quadHeight) override;
    Error qtiSetDisplayConfig(Display display,
                              const gui::DisplayDeviceConfig& displayDeviceConfig) override;
#endif

private:
    Hwc2::AidlComposer* mQtiAidlComposer = nullptr;
};

} // namespace surfaceflingerextension
} // namespace android
