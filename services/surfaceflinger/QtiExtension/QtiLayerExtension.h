/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */

#pragma once

#ifdef QTI_LSR_ENABLED
#include <android/gui/CompositionLayerType.h>
#include <android/gui/Frustum.h>
#include <android/gui/LayerVisibilityType.h>
#include <android/gui/Orientation.h>
#include <android/gui/PlaneEquation.h>
#include <android/gui/Pose.h>
#include <android/gui/Position.h>
#include <android/gui/RenderLayerReferenceSpaceType.h>
#include "DisplayHardware/HWC2.h"

namespace android {

namespace HWC2 {
class Layer;
} // namespace HWC2

namespace layerextension {

class QtiLayerExtension {
public:
    QtiLayerExtension() {}
    ~QtiLayerExtension() = default;

    bool isCompositionLayerTypeChanged(const gui::CompositionLayerType& compositionLayerType);
    bool isLayerVisibilityTypeChanged(const gui::LayerVisibilityType& layerVisibilityType);
    bool isReferenceSpaceTypeChanged(const gui::RenderLayerReferenceSpaceType& referenceSpaceType);
    bool isFrustumChanged(const gui::Frustum& frustum);
    bool isPoseChanged(const gui::Pose& pose);
    bool isPlaneEquationChanged(const gui::PlaneEquation& planeEquation);
    bool isQuadSizeChanged(const float& quadWidth, const float& quadHeight);

private:
    gui::CompositionLayerType mQtiCompositionLayerType =
            gui::CompositionLayerType::COMPOSITION_LAYER_NONE;
    gui::RenderLayerReferenceSpaceType mQtiReferenceSpaceType =
            gui::RenderLayerReferenceSpaceType::RENDER_LAYER_REFERENCE_SPACE_NONE;
    gui::LayerVisibilityType mQtiLayerVisibilityType =
            gui::LayerVisibilityType::LAYER_VISIBILITY_NONE;
    gui::Frustum mQtiFrustum = gui::Frustum();
    gui::Pose mQtiPose = gui::Pose();
    gui::PlaneEquation mQtiPlaneEquation = gui::PlaneEquation();
    float mQtiQuadWidth{0.f};
    float mQtiQuadHeight{0.f};
};

} // namespace layerextension
} // namespace android
#endif
