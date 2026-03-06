/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */
#define LOG_NDEBUG 0
#include "QtiAidlComposerHalExtension.h"
#include <aidl/vendor/qti/hardware/display/composer3/QtiLayerCommand.h>

using aidl::vendor::qti::hardware::display::composer3::QtiDisplayDeviceConfig;
using aidl::vendor::qti::hardware::display::composer3::QtiDisplayProjectionMatrix;
using aidl::vendor::qti::hardware::display::composer3::QtiLayerOrientation;

namespace android::surfaceflingerextension {

QtiAidlComposerHalExtension::QtiAidlComposerHalExtension(Hwc2::Composer* composerHal) {
    if (!composerHal) {
        ALOGW("Passed an invalid pointer to composer hal");
        return;
    }

    mQtiAidlComposer = static_cast<Hwc2::AidlComposer*>(composerHal);
    ALOGV("Successfully created QtiAidlComposerHalExtension %p", mQtiAidlComposer);
}

Error QtiAidlComposerHalExtension::qtiSetDisplayElapseTime(Display display, uint64_t timeStamp) {
    Error error = Error::NONE;
#ifdef QTI_COMPOSER3_EXTENSIONS
    mQtiAidlComposer->mMutex.lock_shared();
    if (mQtiAidlComposer->getWriter(display)) {
        mQtiAidlComposer->getWriter(display)->get().qtiSetDisplayElapseTime(static_cast<int64_t>(
                                                                                    display),
                                                                            timeStamp);
    } else {
        error = Error::BAD_DISPLAY;
        ALOGI("%s: Attempted to set display elapsed time for disconnected display %" PRId64,
              __func__, display);
    }
    mQtiAidlComposer->mMutex.unlock_shared();
#endif
    return error;
}

Error QtiAidlComposerHalExtension::qtiSetLayerType(Display display, V2_1_Layer layer,
                                                   uint32_t type) {
    Error error = Error::NONE;
#ifdef QTI_COMPOSER3_EXTENSIONS
    mQtiAidlComposer->mMutex.lock_shared();
    if (mQtiAidlComposer->getWriter(display)) {
        mQtiAidlComposer->getWriter(display)->get().qtiSetLayerType(static_cast<int64_t>(display),
                                                                    static_cast<int64_t>(layer),
                                                                    type);
    } else {
        error = Error::BAD_DISPLAY;
        ALOGI("%s: Attempted to set layer type for disconnected display %" PRId64, __func__,
              display);
    }
    mQtiAidlComposer->mMutex.unlock_shared();
#endif
    return error;
}

Error QtiAidlComposerHalExtension::qtiSetCompositionLayerType(
        Display display, V2_1_Layer layer, gui::CompositionLayerType compositionLayerType) {
#ifdef QTI_COMPOSER3_EXTENSIONS
    mQtiAidlComposer->mMutex.lock_shared();
    mQtiAidlComposer->getWriter(display)->get().qtiSetCompositionLayerType(static_cast<int64_t>(
                                                                                   display),
                                                                           static_cast<int64_t>(
                                                                                   layer),
                                                                           compositionLayerType);
    mQtiAidlComposer->mMutex.unlock_shared();
#endif
    return Error::NONE;
}

Error QtiAidlComposerHalExtension::qtiSetLayerVisibilityType(
        Display display, V2_1_Layer layer, gui::LayerVisibilityType layerVisibilityType) {
#ifdef QTI_COMPOSER3_EXTENSIONS
    mQtiAidlComposer->mMutex.lock_shared();
    mQtiAidlComposer->getWriter(display)->get().qtiSetLayerVisibilityType(static_cast<int64_t>(
                                                                                  display),
                                                                          static_cast<int64_t>(
                                                                                  layer),
                                                                          layerVisibilityType);
    mQtiAidlComposer->mMutex.unlock_shared();
#endif
    return Error::NONE;
}

Error QtiAidlComposerHalExtension::qtiSetReferenceSpaceType(
        Display display, V2_1_Layer layer, gui::RenderLayerReferenceSpaceType referenceSpaceType) {
#ifdef QTI_COMPOSER3_EXTENSIONS
    mQtiAidlComposer->mMutex.lock_shared();
    mQtiAidlComposer->getWriter(display)->get().qtiSetReferenceSpaceType(static_cast<int64_t>(
                                                                                 display),
                                                                         static_cast<int64_t>(
                                                                                 layer),
                                                                         referenceSpaceType);
    mQtiAidlComposer->mMutex.unlock_shared();
#endif
    return Error::NONE;
}

Error QtiAidlComposerHalExtension::qtiSetFrustum(Display display, V2_1_Layer layer,
                                                 gui::Frustum frustum) {
#ifdef QTI_COMPOSER3_EXTENSIONS
    mQtiAidlComposer->mMutex.lock_shared();
    mQtiAidlComposer->getWriter(display)->get().qtiSetFrustum(static_cast<int64_t>(display),
                                                              static_cast<int64_t>(layer), frustum);
    mQtiAidlComposer->mMutex.unlock_shared();
#endif
    return Error::NONE;
}

Error QtiAidlComposerHalExtension::qtiSetPose(Display display, V2_1_Layer layer, gui::Pose pose) {
#ifdef QTI_COMPOSER3_EXTENSIONS
    mQtiAidlComposer->mMutex.lock_shared();
    mQtiAidlComposer->getWriter(display)->get().qtiSetPose(static_cast<int64_t>(display),
                                                           static_cast<int64_t>(layer), pose);
    mQtiAidlComposer->mMutex.unlock_shared();
#endif
    return Error::NONE;
}

Error QtiAidlComposerHalExtension::qtiSetPlaneEquation(Display display, V2_1_Layer layer,
                                                       gui::PlaneEquation planeEquation) {
#ifdef QTI_COMPOSER3_EXTENSIONS
    mQtiAidlComposer->mMutex.lock_shared();
    mQtiAidlComposer->getWriter(display)->get().qtiSetPlaneEquation(static_cast<int64_t>(display),
                                                                    static_cast<int64_t>(layer),
                                                                    planeEquation);
    mQtiAidlComposer->mMutex.unlock_shared();
#endif
    return Error::NONE;
}

Error QtiAidlComposerHalExtension::qtiSetQuadSize(Display display, V2_1_Layer layer,
                                                  float quadWidth, float quadHeight) {
#ifdef QTI_COMPOSER3_EXTENSIONS
    mQtiAidlComposer->mMutex.lock_shared();
    mQtiAidlComposer->getWriter(display)->get().qtiSetQuadSize(static_cast<int64_t>(display),
                                                               static_cast<int64_t>(layer),
                                                               quadWidth, quadHeight);
    mQtiAidlComposer->mMutex.unlock_shared();
#endif
    return Error::NONE;
}

Error QtiAidlComposerHalExtension::qtiSetLayerFlag(Display display, V2_1_Layer layer,
                                                   uint32_t flags) {
    Error error = Error::NONE;
#ifdef QTI_COMPOSER3_EXTENSIONS
    mQtiAidlComposer->mMutex.lock_shared();
    if (mQtiAidlComposer->getWriter(display)) {
        mQtiAidlComposer->getWriter(display)->get().qtiSetLayerFlag(static_cast<int64_t>(display),
                                                                    static_cast<int64_t>(layer),
                                                                    static_cast<QtiLayerFlags>(
                                                                            flags));

    } else {
        error = Error::BAD_DISPLAY;
        ALOGI("%s: Attempted to set layer flag for disconnected display %" PRId64, __func__,
              display);
    }
    mQtiAidlComposer->mMutex.unlock_shared();
#endif
    return error;
}

Error QtiAidlComposerHalExtension::qtiSetClientTarget_3_1(Display display, int32_t slot,
                                                          int acquireFence,
                                                          uint32_t dataspace) {
    Error error = Error::NONE;
#ifdef QTI_COMPOSER3_EXTENSIONS
    mQtiAidlComposer->mMutex.lock_shared();
    if (mQtiAidlComposer->getWriter(display)) {
        mQtiAidlComposer->getWriter(display)->get().qtiSetClientTarget_3_1(static_cast<int64_t>(
                                                                                   display),
                                                                           static_cast<uint32_t>(
                                                                                   slot),
                                                                           acquireFence, dataspace);
    } else {
        error = Error::BAD_DISPLAY;
        ALOGI("%s: Attempted to set client target for disconnected display %" PRId64, __func__,
              display);
    }
    mQtiAidlComposer->mMutex.unlock_shared();
#endif
    return error;
}

Error QtiAidlComposerHalExtension::qtiTryDrawMethod(Display display,
                                                    uint32_t drawMethod) {
    Error ret = Error::NONE;
#ifdef QTI_COMPOSER3_EXTENSIONS
    mQtiAidlComposer->mMutex.lock_shared();
    if (mQtiAidlComposer->qtiComposer3Client) {
        auto status = mQtiAidlComposer->qtiComposer3Client
                              ->qtiTryDrawMethod(static_cast<int64_t>(display),
                                                 static_cast<QtiDrawMethod>(drawMethod));
        if (!status.isOk()) {
            ALOGE("tryDrawMethod failed %s", status.getDescription().c_str());
            ret = static_cast<Error>(status.getServiceSpecificError());
        }
    }
    mQtiAidlComposer->mMutex.unlock_shared();
#endif
    return ret;
}

Error QtiAidlComposerHalExtension::qtiSetDisplayConfig(
        Display display, const gui::DisplayDeviceConfig& displayDeviceConfig) {
    Error ret = Error::NONE;
#ifdef QTI_COMPOSER3_EXTENSIONS
    mQtiAidlComposer->mMutex.lock_shared();
    if (mQtiAidlComposer->qtiComposer3Client) {
        QtiDisplayDeviceConfig qtiDisplayDeviceConfig;
        for (size_t i = 0; i < qtiDisplayDeviceConfig.rotation.size(); i++) {
            auto& qtiRotation = qtiDisplayDeviceConfig.rotation[i];
            auto& rotation = displayDeviceConfig.rotation[i];
            qtiRotation.x = rotation.x;
            qtiRotation.y = rotation.y;
            qtiRotation.z = rotation.z;
            qtiRotation.w = rotation.w;
            qtiDisplayDeviceConfig.projectionMatrix[i].prjMatrix =
                    displayDeviceConfig.projectionMatrix[i].prjMatrix;
        }
        qtiDisplayDeviceConfig.gamma = displayDeviceConfig.gamma;
        qtiDisplayDeviceConfig.calibrationFileStr = displayDeviceConfig.calibrationFileStr;

        auto status = mQtiAidlComposer->qtiComposer3Client
                              ->qtiSetDisplayDeviceConfig(static_cast<int64_t>(display),
                                                          qtiDisplayDeviceConfig);
        if (!status.isOk()) {
            ALOGE("qtiDisplayDeviceConfig failed %s", status.getDescription().c_str());
            ret = static_cast<Error>(status.getServiceSpecificError());
        }
    }
    mQtiAidlComposer->mMutex.unlock_shared();
#endif
    return ret;
}

} // namespace android::surfaceflingerextension
