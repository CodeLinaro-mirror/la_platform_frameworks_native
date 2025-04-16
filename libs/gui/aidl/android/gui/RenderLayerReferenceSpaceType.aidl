/**
 * Copyright (c) 2025, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Changes from Qualcomm Technologies, Inc. are provided under the following license:
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */

package android.gui;

/**
 * App layer lock type
 */
@Backing(type="int")
enum RenderLayerReferenceSpaceType {
    RENDER_LAYER_REFERENCE_SPACE_NONE = 0,
    RENDER_LAYER_REFERENCE_SPACE_WORLD = 1,
    RENDER_LAYER_REFERENCE_SPACE_HEAD = 2,
    RENDER_LAYER_REFERENCE_SPACE_SPHERE = 3
}