/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */

// #define LOG_NDEBUG 0
#include "QtiAidlComposerHalExtension.h"
#include "QtiHWComposerExtensionIntf.h"
#include "QtiHidlComposerHalExtension.h"
#include "QtiLayerExtension.h"
#include "utils/Errors.h"

#define LOG_DISPLAY_ERROR(displayId, msg) \
    ALOGE("%s failed for display %s: %s", __FUNCTION__, to_string(displayId).c_str(), msg)

namespace android::surfaceflingerextension {

QtiHWComposerExtensionIntf* qtiCreateHWComposerExtension(android::impl::HWComposer& hwc,
                                                         Hwc2::Composer* composerHal) {
    return new QtiHWComposerExtension(hwc, composerHal);
}

QtiHWComposerExtension::QtiHWComposerExtension(android::impl::HWComposer& hwc)
      : mQtiHWComposer(hwc) {}

QtiHWComposerExtension::QtiHWComposerExtension(android::impl::HWComposer& hwc,
                                               Hwc2::Composer* composerHal)
      : mQtiHWComposer(hwc) {
    if (Hwc2::AidlComposer::namesAnAidlComposerService("default")) {
        mQtiComposerHalExtn =
                static_cast<QtiComposerHalExtension*>(new QtiAidlComposerHalExtension(composerHal));
    } else {
        mQtiComposerHalExtn =
                static_cast<QtiComposerHalExtension*>(new QtiHidlComposerHalExtension(composerHal));
        new QtiHidlComposerHalExtension(composerHal);
    }
}

std::optional<hal::HWDisplayId> QtiHWComposerExtension::qtiFromVirtualDisplayId(
        HalVirtualDisplayId displayId) const {
    if (const auto it = mQtiHWComposer.mDisplayData.find(displayId);
        it != mQtiHWComposer.mDisplayData.end()) {
        ALOGV("Virtual display id %d", static_cast<uint32_t>((it->second.hwcDisplay->getId())));
        return it->second.hwcDisplay->getId();
    }
    return {};
}

status_t QtiHWComposerExtension::qtiSetDisplayElapseTime(HalDisplayId displayId,
                                                         uint64_t timeStamp) {
    if (!mQtiComposerHalExtn) {
        return NO_ERROR;
    }

    if (mQtiHWComposer.mDisplayData.empty()) {
        ALOGV("HWComposer's displayData is empty");
        return BAD_VALUE;
    }

    if (mQtiHWComposer.mDisplayData.count(displayId) == 0) {
        LOG_DISPLAY_ERROR(displayId, "Invalid display");
        return UNKNOWN_ERROR;
    }

    const auto& displayData = mQtiHWComposer.mDisplayData[displayId];
    auto halHWDisplayId = displayData.hwcDisplay->getId();
    auto error = mQtiComposerHalExtn->qtiSetDisplayElapseTime(halHWDisplayId, timeStamp);
    if (error != Error::NONE) {
        return BAD_VALUE;
    }

    return NO_ERROR;
}

status_t QtiHWComposerExtension::qtiSetLayerType(HWC2::Layer* layer, uint32_t type) {
    if (!mQtiComposerHalExtn) {
        return NO_ERROR;
    }

    if (layer == nullptr) {
        return BAD_VALUE;
    }

    HWC2::impl::Layer* implLayer = static_cast<HWC2::impl::Layer*>(layer);
    auto intError = mQtiComposerHalExtn->qtiSetLayerType(implLayer->qtiGetDisplayId(),
                                                         implLayer->getId(), type);
    Error error = static_cast<Error>(intError);
    if (error != Error::NONE) {
        ALOGW("Failed to send SET_LAYER_TYPE command to HWC");
        return BAD_VALUE;
    }

    return NO_ERROR;
}

status_t QtiHWComposerExtension::qtiSetCompositionLayerType(
        HWC2::Layer* layer, gui::CompositionLayerType compositionLayerType) {
    if (!mQtiComposerHalExtn) {
        return NO_ERROR;
    }

    if (layer == nullptr) {
        return BAD_VALUE;
    }

    HWC2::impl::Layer* implLayer = static_cast<HWC2::impl::Layer*>(layer);
    bool typeChanged = implLayer->GetLayerExt().isCompositionLayerTypeChanged(compositionLayerType);
    if (!typeChanged) {
        return NO_ERROR;
    }

    auto intError = mQtiComposerHalExtn->qtiSetCompositionLayerType(implLayer->qtiGetDisplayId(),
                                                                    implLayer->getId(),
                                                                    compositionLayerType);
    Error error = static_cast<Error>(intError);
    if (error != Error::NONE) {
        ALOGW("Failed to send SET_LAYER_COMPOSITION_TYPE command to HWC");
        return BAD_VALUE;
    }

    return NO_ERROR;
}

status_t QtiHWComposerExtension::qtiSetLayerVisibilityType(
        HWC2::Layer* layer, gui::LayerVisibilityType layerVisibilityType) {
    if (!mQtiComposerHalExtn) {
        return NO_ERROR;
    }

    if (layer == nullptr) {
        return BAD_VALUE;
    }

    HWC2::impl::Layer* implLayer = static_cast<HWC2::impl::Layer*>(layer);
    bool typeChanged = implLayer->GetLayerExt().isLayerVisibilityTypeChanged(layerVisibilityType);
    if (!typeChanged) {
        return NO_ERROR;
    }

    auto intError =
            mQtiComposerHalExtn->qtiSetLayerVisibilityType(implLayer->qtiGetDisplayId(),
                                                           implLayer->getId(), layerVisibilityType);
    Error error = static_cast<Error>(intError);
    if (error != Error::NONE) {
        ALOGW("Failed to send Set Layer Visibility Type command to HWC");
        return BAD_VALUE;
    }

    return NO_ERROR;
}

status_t QtiHWComposerExtension::qtiSetReferenceSpaceType(
        HWC2::Layer* layer, gui::RenderLayerReferenceSpaceType referenceSpaceType) {
    if (!mQtiComposerHalExtn) {
        return NO_ERROR;
    }

    if (layer == nullptr) {
        return BAD_VALUE;
    }

    HWC2::impl::Layer* implLayer = static_cast<HWC2::impl::Layer*>(layer);
    bool typeChanged = implLayer->GetLayerExt().isReferenceSpaceTypeChanged(referenceSpaceType);
    if (!typeChanged) {
        return NO_ERROR;
    }

    auto intError =
            mQtiComposerHalExtn->qtiSetReferenceSpaceType(implLayer->qtiGetDisplayId(),
                                                          implLayer->getId(), referenceSpaceType);
    Error error = static_cast<Error>(intError);
    if (error != Error::NONE) {
        ALOGW("Failed to send Set ReferenceSpace Type command to HWC");
        return BAD_VALUE;
    }

    return NO_ERROR;
}

status_t QtiHWComposerExtension::qtiSetFrustum(HWC2::Layer* layer, gui::Frustum frustum) {
    if (!mQtiComposerHalExtn) {
        return NO_ERROR;
    }

    if (layer == nullptr) {
        return BAD_VALUE;
    }

    HWC2::impl::Layer* implLayer = static_cast<HWC2::impl::Layer*>(layer);
    bool frustumChanged = implLayer->GetLayerExt().isFrustumChanged(frustum);
    if (!frustumChanged) {
        return NO_ERROR;
    }

    auto intError = mQtiComposerHalExtn->qtiSetFrustum(implLayer->qtiGetDisplayId(),
                                                       implLayer->getId(), frustum);
    Error error = static_cast<Error>(intError);
    if (error != Error::NONE) {
        ALOGW("Failed to send Set Frustum command to HWC");
        return BAD_VALUE;
    }

    return NO_ERROR;
}

status_t QtiHWComposerExtension::qtiSetPose(HWC2::Layer* layer, gui::Pose pose) {
    if (!mQtiComposerHalExtn) {
        return NO_ERROR;
    }

    if (layer == nullptr) {
        return BAD_VALUE;
    }

    HWC2::impl::Layer* implLayer = static_cast<HWC2::impl::Layer*>(layer);
    bool poseChanged = implLayer->GetLayerExt().isPoseChanged(pose);
    if (!poseChanged) {
        return NO_ERROR;
    }

    auto intError =
            mQtiComposerHalExtn->qtiSetPose(implLayer->qtiGetDisplayId(), implLayer->getId(), pose);
    Error error = static_cast<Error>(intError);
    if (error != Error::NONE) {
        ALOGW("Failed to send Set Pose command to HWC");
        return BAD_VALUE;
    }

    return NO_ERROR;
}

status_t QtiHWComposerExtension::qtiSetPlaneEquation(HWC2::Layer* layer,
                                                     gui::PlaneEquation planeEquation) {
    if (!mQtiComposerHalExtn) {
        return NO_ERROR;
    }

    if (layer == nullptr) {
        return BAD_VALUE;
    }

    HWC2::impl::Layer* implLayer = static_cast<HWC2::impl::Layer*>(layer);
    bool planeEquationChanged = implLayer->GetLayerExt().isPlaneEquationChanged(planeEquation);
    if (!planeEquationChanged) {
        return NO_ERROR;
    }

    auto intError = mQtiComposerHalExtn->qtiSetPlaneEquation(implLayer->qtiGetDisplayId(),
                                                             implLayer->getId(), planeEquation);
    Error error = static_cast<Error>(intError);
    if (error != Error::NONE) {
        ALOGW("Failed to send SET_PLANE_EQUATION command to HWC");
        return BAD_VALUE;
    }

    return NO_ERROR;
}

status_t QtiHWComposerExtension::qtiSetQuadSize(HWC2::Layer* layer, float quadWidth,
                                                float quadHeight) {
    if (!mQtiComposerHalExtn) {
        return NO_ERROR;
    }

    if (layer == nullptr) {
        return BAD_VALUE;
    }

    HWC2::impl::Layer* implLayer = static_cast<HWC2::impl::Layer*>(layer);
    bool quadSizeChanged = implLayer->GetLayerExt().isQuadSizeChanged(quadWidth, quadHeight);
    if (!quadSizeChanged) {
        return NO_ERROR;
    }

    auto intError = mQtiComposerHalExtn->qtiSetQuadSize(implLayer->qtiGetDisplayId(),
                                                        implLayer->getId(), quadWidth, quadHeight);
    Error error = static_cast<Error>(intError);
    if (error != Error::NONE) {
        ALOGW("Failed to send SET_QUAD_SIZE command to HWC");
        return BAD_VALUE;
    }

    return NO_ERROR;
}

status_t QtiHWComposerExtension::qtiSetLayerFlag(HWC2::Layer* layer, uint32_t flags) {
    if (!mQtiComposerHalExtn) {
        return NO_ERROR;
    }
    if (layer == nullptr) {
        return BAD_VALUE;
    }

    HWC2::impl::Layer* implLayer = static_cast<HWC2::impl::Layer*>(layer);
    auto intError = mQtiComposerHalExtn->qtiSetLayerFlag(implLayer->qtiGetDisplayId(),
                                                         implLayer->getId(), flags);
    Error error = static_cast<Error>(intError);
    if (error != Error::NONE) {
        return BAD_VALUE;
    }

    return NO_ERROR;
}

status_t QtiHWComposerExtension::qtiSetClientTarget_3_1(HalDisplayId displayId, int32_t slot,
                                                        const sp<Fence>& acquireFence,
                                                        uint32_t dataspace) {
    if (!mQtiComposerHalExtn) {
        return NO_ERROR;
    }

    if (mQtiHWComposer.mDisplayData.empty()) {
        ALOGV("HWComposer's displayData is empty");
        return BAD_VALUE;
    }

    if (mQtiHWComposer.mDisplayData.count(displayId) == 0) {
        LOG_DISPLAY_ERROR(displayId, "Invalid display");
        return UNKNOWN_ERROR;
    }

    const auto& displayData = mQtiHWComposer.mDisplayData[displayId];
    auto halHWDisplayId = displayData.hwcDisplay->getId();
    int32_t fenceFd = acquireFence->dup();
    auto error =
            mQtiComposerHalExtn->qtiSetClientTarget_3_1(halHWDisplayId, slot, fenceFd, dataspace);
    if (error != Error::NONE) {
        return BAD_VALUE;
    }
    return NO_ERROR;
}

status_t QtiHWComposerExtension::qtiTryDrawMethod(HalDisplayId displayId, uint32_t drawMethod) {
    if (!mQtiComposerHalExtn) {
        return NO_ERROR;
    }

    if (mQtiHWComposer.mDisplayData.empty()) {
        ALOGV("HWComposer's displayData is empty");
        return BAD_VALUE;
    }

    if (mQtiHWComposer.mDisplayData.count(displayId) == 0) {
        LOG_DISPLAY_ERROR(displayId, "Invalid display");
        return UNKNOWN_ERROR;
    }

    const auto& displayData = mQtiHWComposer.mDisplayData[displayId];
    auto halHWDisplayId = displayData.hwcDisplay->getId();
    auto error = mQtiComposerHalExtn->qtiTryDrawMethod(halHWDisplayId, drawMethod);
    if (error != Error::NONE) {
        return BAD_VALUE;
    }

    return NO_ERROR;
}

status_t QtiHWComposerExtension::qtiSetDisplayConfig(
        HalDisplayId displayId, const gui::DisplayDeviceConfig& displayDeviceConfig) {
    if (!mQtiComposerHalExtn) {
        return NO_ERROR;
    }

    if (mQtiHWComposer.mDisplayData.empty()) {
        ALOGV("HWComposer's displayData is empty");
        return BAD_VALUE;
    }

    if (mQtiHWComposer.mDisplayData.count(displayId) == 0) {
        LOG_DISPLAY_ERROR(displayId, "Invalid display");
        return UNKNOWN_ERROR;
    }

    const auto& displayData = mQtiHWComposer.mDisplayData[displayId];
    auto halHWDisplayId = displayData.hwcDisplay->getId();
    auto error = mQtiComposerHalExtn->qtiSetDisplayConfig(halHWDisplayId, displayDeviceConfig);
    if (error != Error::NONE) {
        return BAD_VALUE;
    }

    return NO_ERROR;
}

} // namespace android::surfaceflingerextension
