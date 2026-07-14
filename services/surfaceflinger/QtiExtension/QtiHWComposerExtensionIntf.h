/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */
#pragma once

#include "../DisplayHardware/HWC2.h"
#include "../DisplayHardware/HWComposer.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconversion"
#pragma clang diagnostic ignored "-Wextra"

#include "../DisplayHardware/ComposerHal.h"

#ifdef QTI_LSR_ENABLED
#include <android/gui/CompositionLayerType.h>
#include <android/gui/DisplayDeviceConfig.h>
#include <android/gui/Frustum.h>
#include <android/gui/LayerVisibilityType.h>
#include <android/gui/Orientation.h>
#include <android/gui/PlaneEquation.h>
#include <android/gui/Pose.h>
#include <android/gui/Position.h>
#include <android/gui/RenderLayerReferenceSpaceType.h>
#endif

#include <ui/DisplayId.h>
#include "QtiComposerHalExtensionIntf.h"

#pragma clang diagnostic pop

namespace android {


namespace impl {
class HWComposer;
} // namespace impl

namespace Hwc2 {
class Composer;
}

namespace HWC2::impl {
class Layer;
}

namespace surfaceflingerextension {

class QtiHWComposerExtensionIntf {
public:
    virtual ~QtiHWComposerExtensionIntf() {}

    virtual std::optional<hal::HWDisplayId> qtiFromVirtualDisplayId(HalVirtualDisplayId) const = 0;
    virtual status_t qtiSetDisplayElapseTime(HalDisplayId displayId, uint64_t timeStamp) = 0;
    virtual status_t qtiSetLayerType(HWC2::Layer* layer, uint32_t type) = 0;
    virtual status_t qtiTryDrawMethod(HalDisplayId displayId,
                                      uint32_t drawMethod) = 0;
    virtual status_t qtiSetClientTarget_3_1(HalDisplayId displayId, int32_t slot,
                                            const sp<Fence>& acquireFence,
                                            uint32_t dataspace) = 0;
    virtual status_t qtiSetLayerFlag(HWC2::Layer* layer,
                                     uint32_t layerFlag) = 0;
#ifdef QTI_LSR_ENABLED
    virtual status_t qtiSetCompositionLayerType(HWC2::Layer* layer,
                                                gui::CompositionLayerType compositionLayerType) = 0;
    virtual status_t qtiSetLayerVisibilityType(HWC2::Layer* layer,
                                               gui::LayerVisibilityType layerVisibilityType) = 0;
    virtual status_t qtiSetReferenceSpaceType(
            HWC2::Layer* layer, gui::RenderLayerReferenceSpaceType referenceSpaceType) = 0;
    virtual status_t qtiSetFrustum(HWC2::Layer* layer, gui::Frustum frustum) = 0;
    virtual status_t qtiSetPose(HWC2::Layer* layer, gui::Pose pose) = 0;
    virtual status_t qtiSetPlaneEquation(HWC2::Layer* layer, gui::PlaneEquation planeEquation) = 0;
    virtual status_t qtiSetQuadSize(HWC2::Layer* layer, float quadWidth, float quadHeight) = 0;
    virtual status_t qtiSetDisplayConfig(HalDisplayId displayId,
                                         const gui::DisplayDeviceConfig& displayDeviceConfig) = 0;
#endif
};

QtiHWComposerExtensionIntf* qtiCreateHWComposerExtension(android::impl::HWComposer& hwc,
                                                         Hwc2::Composer* composerHal);

class QtiHWComposerExtension : public QtiHWComposerExtensionIntf {
public:
    QtiHWComposerExtension(android::impl::HWComposer& hwc);
    QtiHWComposerExtension(android::impl::HWComposer& hwc, Hwc2::Composer* composerHal);
    ~QtiHWComposerExtension() = default;

    std::optional<hal::HWDisplayId> qtiFromVirtualDisplayId(HalVirtualDisplayId) const override;
    status_t qtiSetDisplayElapseTime(HalDisplayId displayId, uint64_t timeStamp) override;
    status_t qtiSetLayerType(HWC2::Layer* layer, uint32_t type) override;
#ifdef QTI_LSR_ENABLED
    status_t qtiSetCompositionLayerType(HWC2::Layer* layer,
                                        gui::CompositionLayerType compositionLayerType) override;
    status_t qtiSetLayerVisibilityType(HWC2::Layer* layer,
                                       gui::LayerVisibilityType layerVisibilityType) override;
    status_t qtiSetReferenceSpaceType(
            HWC2::Layer* layer, gui::RenderLayerReferenceSpaceType referenceSpaceType) override;
    status_t qtiSetFrustum(HWC2::Layer* layer, gui::Frustum frustum) override;
    status_t qtiSetPose(HWC2::Layer* layer, gui::Pose pose) override;
    status_t qtiSetPlaneEquation(HWC2::Layer* layer, gui::PlaneEquation planeEquation) override;
    status_t qtiSetQuadSize(HWC2::Layer* layer, float quadWidth, float quadHeight) override;
#endif
    status_t qtiSetLayerFlag(HWC2::Layer* layer, uint32_t layerFlag) override;
    status_t qtiSetClientTarget_3_1(HalDisplayId displayId, int32_t slot,
                                    const sp<Fence>& acquireFence,
                                    uint32_t dataspace) override;
    status_t qtiTryDrawMethod(HalDisplayId displayId,
                              uint32_t drawMethod) override;
#ifdef QTI_LSR_ENABLED
    status_t qtiSetDisplayConfig(HalDisplayId displayId,
                                 const gui::DisplayDeviceConfig& displayDeviceConfig) override;
#endif

private:
    android::impl::HWComposer& mQtiHWComposer;
    QtiComposerHalExtension* mQtiComposerHalExtn = nullptr;
};

} // namespace surfaceflingerextension
} // namespace android
