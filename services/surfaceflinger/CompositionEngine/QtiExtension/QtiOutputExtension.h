/* Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */
#pragma once

#include "DisplayHardware/HWC2.h"
#include "compositionengine/impl/Output.h"

using android::compositionengine::impl::Output;

namespace android::compositionengineextension {

class QtiOutputExtension {
public:
    QtiOutputExtension() = default;
    ~QtiOutputExtension() = default;

    static void qtiInit();
    static bool qtiIsProtectedContent(const Output* output);
    static bool qtiHasSecureDisplay(const Output* output);
    static bool qtiHasSecureOrProtectedContent(const Output* output);
    static void qtiWriteLayerFlagToHWC(HWC2::Layer* layer, const Output* output);
    static void qtiSetLayerAsMask(DisplayId id, uint64_t layerId);
    static void qtiSetLayerType(HWC2::Layer* layerId, uint32_t type, const char* debugName);
    static bool qtiUseSpecFence(void);
    static void qtiGetVisibleLayerInfo(const Output* output);

private:
    static bool secure_gpu_comp_;
};

} // namespace android::compositionengineextension
