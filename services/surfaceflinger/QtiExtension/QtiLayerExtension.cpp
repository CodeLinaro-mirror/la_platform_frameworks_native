/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */

#ifdef QTI_LSR_ENABLED
#include <cutils/properties.h>
#include <log/log.h>

#include "QtiExtensionContext.h"
#include "QtiLayerExtension.h"
using android::surfaceflingerextension::QtiExtensionContext;

namespace android::layerextension {

bool QtiLayerExtension::isCompositionLayerTypeChanged(
        const gui::CompositionLayerType& compositionLayerType) {
    if (mQtiCompositionLayerType == compositionLayerType) {
        return false;
    }

    mQtiCompositionLayerType = compositionLayerType;
    return true;
}

bool QtiLayerExtension::isLayerVisibilityTypeChanged(
        const gui::LayerVisibilityType& layerVisibilityType) {
    if (mQtiLayerVisibilityType == layerVisibilityType) {
        return false;
    }

    mQtiLayerVisibilityType = layerVisibilityType;
    return true;
}

bool QtiLayerExtension::isReferenceSpaceTypeChanged(
        const gui::RenderLayerReferenceSpaceType& referenceSpaceType) {
    if (mQtiReferenceSpaceType == referenceSpaceType) {
        return false;
    }

    mQtiReferenceSpaceType = referenceSpaceType;
    return true;
}

bool QtiLayerExtension::isFrustumChanged(const gui::Frustum& frustum) {
    if (mQtiFrustum == frustum) {
        return false;
    }

    mQtiFrustum = frustum;
    return true;
}

bool QtiLayerExtension::isPoseChanged(const gui::Pose& pose) {
    if (mQtiPose == pose) {
        return false;
    }

    mQtiPose = pose;
    return true;
}

bool QtiLayerExtension::isPlaneEquationChanged(const gui::PlaneEquation& planeEquation) {
    if (mQtiPlaneEquation == planeEquation) {
        return false;
    }

    mQtiPlaneEquation = planeEquation;
    return true;
}

bool QtiLayerExtension::isQuadSizeChanged(const float& quadWidth, const float& quadHeight) {
    if ((mQtiQuadWidth == quadWidth) && (mQtiQuadHeight == quadHeight)) {
        return false;
    }

    mQtiQuadWidth = quadWidth;
    mQtiQuadHeight = quadHeight;
    return true;
}
} // namespace android::layerextension
#endif
