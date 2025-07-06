/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */
#pragma once

#include <android/hardware/graphics/composer3/ComposerClientWriter.h>
using ::aidl::android::hardware::graphics::composer3::ComposerClientWriter;

#ifndef QTI_COMPOSER3_EXTENSIONS
#define QtiAidlCommandWriter ComposerClientWriter
#else
#include <aidl/vendor/qti/hardware/display/composer3/IQtiComposer3Client.h>
#include <android/gui/CompositionLayerType.h>
#include <android/gui/Frustum.h>
#include <android/gui/LayerVisibilityType.h>
#include <android/gui/Orientation.h>
#include <android/gui/PlaneEquation.h>
#include <android/gui/Pose.h>
#include <android/gui/Position.h>
#include <android/gui/RenderLayerReferenceSpaceType.h>
#if 0 // TODO: enable compilation once intf change finalized
#include <aidl/vendor/qti/hardware/display/composer3/QtiLayerCommand.h>
#endif

using aidl::vendor::qti::hardware::display::composer3::IQtiComposer3Client;
using aidl::vendor::qti::hardware::display::composer3::QtiDisplayCommand;
using aidl::vendor::qti::hardware::display::composer3::QtiDrawMethod;
using aidl::vendor::qti::hardware::display::composer3::QtiLayerCommand;
using aidl::vendor::qti::hardware::display::composer3::QtiLayerFlags;
using aidl::vendor::qti::hardware::display::composer3::QtiLayerType;
#if 0
using aidl::vendor::qti::hardware::display::composer3::QtiCompositionLayerType;
using aidl::vendor::qti::hardware::display::composer3::QtiLayerVisibilityType;
using aidl::vendor::qti::hardware::display::composer3::QtiRenderLayerReferenceSpaceType;
#endif

namespace android::Hwc2 {

class QtiAidlCommandWriter : public ComposerClientWriter {
public:
    explicit QtiAidlCommandWriter(int64_t display)
          : ComposerClientWriter(display), mDisplay(display) {
        qtiReset();
    }
    ~QtiAidlCommandWriter() override { qtiReset(); }

    QtiAidlCommandWriter(QtiAidlCommandWriter&&) = default;
    QtiAidlCommandWriter(const QtiAidlCommandWriter&) = delete;
    QtiAidlCommandWriter& operator=(const QtiAidlCommandWriter&) = delete;

    void qtiSetLayerType(int64_t display, int64_t layer, uint32_t type) {
        auto qtiLayerCommand = qtiGetLayerCommand(display, layer);
        if (qtiLayerCommand) {
            qtiLayerCommand->qtiLayerType = static_cast<QtiLayerType>(type);
        }
    }

    void qtiSetCompositionLayerType(int64_t display, int64_t layer,
                                    gui::CompositionLayerType compositionLayerType) {
#if 0
        auto qtiLayerCommand = qtiGetLayerCommand(display, layer);
        if (qtiLayerCommand) {
            qtiLayerCommand->qtiCompositionLayerType.emplace();
            qtiLayerCommand->qtiCompositionLayerType->compositionLayerType =
                    static_cast<QtiCompositionLayerType>(compositionLayerType);
        }
#endif
    }

    void qtiSetLayerVisibilityType(int64_t display, int64_t layer,
                                   gui::LayerVisibilityType layerVisibilityType) {
#if 0
        auto qtiLayerCommand = qtiGetLayerCommand(display, layer);
        if (qtiLayerCommand) {
            qtiLayerCommand->qtiLayerVisibilityType.emplace();
            qtiLayerCommand->qtiLayerVisibilityType->layerVisibilityType =
                    static_cast<QtiLayerVisibilityType>(layerVisibilityType);
        }
#endif
    }

    void qtiSetReferenceSpaceType(int64_t display, int64_t layer,
                                  gui::RenderLayerReferenceSpaceType referenceSpaceType) {
#if 0
        auto qtiLayerCommand = qtiGetLayerCommand(display, layer);
        if (qtiLayerCommand) {
            qtiLayerCommand->qtiRenderLayerReferenceSpaceType.emplace();
            qtiLayerCommand->qtiRenderLayerReferenceSpaceType->renderLayerReferenceSpaceType =
                    static_cast<QtiRenderLayerReferenceSpaceType>(referenceSpaceType);
        }
#endif
    }

    void qtiSetFrustum(int64_t display, int64_t layer, gui::Frustum frustum) {
#if 0
        auto qtiLayerCommand = qtiGetLayerCommand(display, layer);
        if (qtiLayerCommand) {
            qtiLayerCommand->qtiLayerFrustum.emplace();
            qtiLayerCommand->qtiLayerFrustum->angleLeft = frustum.angleLeft;
            qtiLayerCommand->qtiLayerFrustum->angleRight = frustum.angleRight;
            qtiLayerCommand->qtiLayerFrustum->angleUp = frustum.angleUp;
            qtiLayerCommand->qtiLayerFrustum->angleDown = frustum.angleDown;
        }
#endif
    }

    void qtiSetPose(int64_t display, int64_t layer, gui::Pose pose) {
#if 0
        auto qtiLayerCommand = qtiGetLayerCommand(display, layer);
        if (qtiLayerCommand) {
            qtiLayerCommand->qtiLayerPose.emplace();
            auto& pos = qtiLayerCommand->qtiLayerPose->pos;
            pos.x = pose.pos.x;
            pos.y = pose.pos.y;
            pos.z = pose.pos.z;
            auto& orientation = qtiLayerCommand->qtiLayerPose->orientation;
            orientation.x = pose.orientation.x;
            orientation.y = pose.orientation.y;
            orientation.z = pose.orientation.z;
            orientation.w = pose.orientation.w;
        }
#endif
    }

    void qtiSetPlaneEquation(int64_t display, int64_t layer, gui::PlaneEquation planeEquation) {
#if 0
        auto qtiLayerCommand = qtiGetLayerCommand(display, layer);
        if (qtiLayerCommand) {
            qtiLayerCommand->qtiLayerPlaneEquation.emplace();
            qtiLayerCommand->qtiLayerPlaneEquation->a = planeEquation.a;
            qtiLayerCommand->qtiLayerPlaneEquation->b = planeEquation.b;
            qtiLayerCommand->qtiLayerPlaneEquation->c = planeEquation.c;
            qtiLayerCommand->qtiLayerPlaneEquation->d = planeEquation.d;
        }
#endif
    }

    void qtiSetQuadSize(int64_t display, int64_t layer, float quadWidth, float quadHeight) {
#if 0
        auto qtiLayerCommand = qtiGetLayerCommand(display, layer);
        if (qtiLayerCommand) {
            qtiLayerCommand->qtiLayerQuadSize.emplace();
            qtiLayerCommand->qtiLayerQuadSize->width = quadWidth;
            qtiLayerCommand->qtiLayerQuadSize->height = quadHeight;
        }
#endif
    }

    void qtiSetDisplayElapseTime(int64_t display, uint64_t time) {
        auto qtiDisplayCommand = qtiGetDisplayCommand(display);
        if (qtiDisplayCommand) {
            qtiDisplayCommand->time = static_cast<int64_t>(time);
        }
    }

    void qtiSetClientTarget_3_1(int64_t display, uint32_t slot, int acquireFence,
                                uint32_t dataspace) {
        auto qtiDisplayCommand = qtiGetDisplayCommand(display);
        ClientTarget clientTargetCommand;
        clientTargetCommand.buffer = qtiGetBuffer(slot, nullptr, acquireFence);
        clientTargetCommand.dataspace =
                static_cast<aidl::android::hardware::graphics::common::Dataspace>(dataspace);
        if (qtiDisplayCommand) {
            qtiDisplayCommand->clientTarget_3_1.emplace(std::move(clientTargetCommand));
        }
    }

    void qtiSetLayerFlag(int64_t display, int64_t layer, QtiLayerFlags flags) {
        auto qtiLayerCommand = qtiGetLayerCommand(display, layer);
        if (qtiLayerCommand) {
            qtiLayerCommand->qtiLayerFlags = flags;
        }
    }

    void qtiReset() {
        mQtiDisplayCommand.reset();
        mQtiLayerCommand.reset();
        mQtiCommands.clear();
    }

    const std::vector<QtiDisplayCommand>& getPendingQtiCommands() {
        qtiFlushLayerCommand();
        qtiFlushDisplayCommand();
        return mQtiCommands;
    }

private:
    std::optional<QtiDisplayCommand> mQtiDisplayCommand;
    std::optional<QtiLayerCommand> mQtiLayerCommand;
    std::vector<QtiDisplayCommand> mQtiCommands;
    const int64_t mDisplay;

    void qtiFlushLayerCommand() {
        if (mQtiLayerCommand.has_value()) {
            mQtiDisplayCommand->qtiLayers.emplace_back(std::move(*mQtiLayerCommand));
            mQtiLayerCommand.reset();
        }
    }

    void qtiFlushDisplayCommand() {
        if (mQtiDisplayCommand.has_value()) {
            mQtiCommands.emplace_back(std::move(*mQtiDisplayCommand));
            mQtiDisplayCommand.reset();
        }
    }

    Buffer qtiGetBuffer(uint32_t slot, const native_handle_t* bufferHandle, int fence) {
        Buffer bufferCommand;
        bufferCommand.slot = static_cast<int32_t>(slot);
        if (bufferHandle) bufferCommand.handle.emplace(::android::dupToAidl(bufferHandle));
        if (fence > 0) bufferCommand.fence = ::ndk::ScopedFileDescriptor(fence);
        return bufferCommand;
    }

    QtiDisplayCommand* qtiGetDisplayCommand(int64_t display) {
        if (!mQtiDisplayCommand.has_value() ||
            (mQtiDisplayCommand.has_value() && mQtiDisplayCommand->display != display)) {
            if (display != mDisplay) {
                ALOGW("Incorrect display id, skipping QTI command");
                return nullptr;
            }
            qtiFlushLayerCommand();
            qtiFlushDisplayCommand();
            mQtiDisplayCommand.emplace();
            mQtiDisplayCommand->display = display;
        }
        return &(*mQtiDisplayCommand);
    }

    QtiLayerCommand* qtiGetLayerCommand(int64_t display, int64_t layer) {
        auto qtiDisplayCommand = qtiGetDisplayCommand(display);
        if (!qtiDisplayCommand) return nullptr;

        if (!mQtiLayerCommand.has_value() ||
            (mQtiLayerCommand.has_value() && mQtiLayerCommand->layer != layer)) {
            qtiFlushLayerCommand();
            mQtiLayerCommand.emplace();
            mQtiLayerCommand->layer = layer;
        }
        return &(*mQtiLayerCommand);
    }
};
} // namespace android::Hwc2
#endif
