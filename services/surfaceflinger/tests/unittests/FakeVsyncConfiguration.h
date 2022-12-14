/*
 * Copyright 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <gmock/gmock.h>

#include "Scheduler/VsyncConfiguration.h"

namespace android::scheduler {

struct FakePhaseOffsets : VsyncConfiguration {
    static constexpr nsecs_t FAKE_PHASE_OFFSET_NS = 0;
    static constexpr auto FAKE_DURATION_OFFSET_NS = std::chrono::nanoseconds(0);

    VsyncConfigSet getConfigsForRefreshRate(Fps) const override { return getCurrentConfigs(); }

    VsyncConfigSet getCurrentConfigs() const override {
        return {{FAKE_PHASE_OFFSET_NS, FAKE_PHASE_OFFSET_NS, FAKE_DURATION_OFFSET_NS,
                 FAKE_DURATION_OFFSET_NS},
                {FAKE_PHASE_OFFSET_NS, FAKE_PHASE_OFFSET_NS, FAKE_DURATION_OFFSET_NS,
                 FAKE_DURATION_OFFSET_NS},
                {FAKE_PHASE_OFFSET_NS, FAKE_PHASE_OFFSET_NS, FAKE_DURATION_OFFSET_NS,
                 FAKE_DURATION_OFFSET_NS},
                FAKE_DURATION_OFFSET_NS};
    }

    void reset() override {}
    void setRefreshRateFps(Fps) override {}
    void dump(std::string&) const override {}
    void UpdateSfOffsets(std::unordered_map<float, int64_t>*) override {}
    void UpdateWorkDurations(std::unordered_map<float, pair<int64_t, int64_t>>*) override {}
};

} // namespace android::scheduler
