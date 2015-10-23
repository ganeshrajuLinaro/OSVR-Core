/** @file
    @brief Header

    @date 2015

    @author
    Sensics, Inc.
    <http://sensics.com/osvr>
*/

// Copyright 2015 Sensics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef INCLUDED_FlexibleKalmanFilter_h_GUID_3A3B8A14_6DFC_4A81_97CA_189834AC4B61
#define INCLUDED_FlexibleKalmanFilter_h_GUID_3A3B8A14_6DFC_4A81_97CA_189834AC4B61

// Internal Includes
#include "FlexibleKalmanBase.h"

// Library/third-party includes
// - none

// Standard includes
// - none

namespace osvr {
namespace kalman {
#if 0
    template <typename FilterType> using StateType = typename FilterType::State;
    template <typename FilterType>
    using ProcessModelType = typename FilterType::ProcessModel;
    template <typename StateType, typename ProcessModelType>
    class KalmanPrediction {
      public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

        StateSquareMatrix
    };
#endif
    template <typename StateType, typename ProcessModelType>
    class FlexibleKalmanFilter {
      public:
        using State = StateType;
        using ProcessModel = ProcessModelType;
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        static const std::size_t STATE_DIMENSION = StateType::DIMENSION;
        /// copy initialization
        FlexibleKalmanFilter(State const &state,
                             ProcessModel const &processModel)
            : m_state(state), m_processModel(processModel) {}
        /// move initialization.
        FlexibleKalmanFilter(State &&state, ProcessModel &&processModel)
            : m_state(state), m_processModel(processModel) {}

        void predict(double dt) { m_processModel.predictState(m_state, dt); }

        State &state() { return m_state; }
        State const &state() const { return m_state; }
        ProcessModel &processModel() { return m_processModel; }
        ProcessModel const &processModel() const { return m_processModel; }

      private:
        State m_state;
        ProcessModel m_processModel;
    };

} // namespace kalman
} // namespace osvr

#endif // INCLUDED_FlexibleKalmanFilter_h_GUID_3A3B8A14_6DFC_4A81_97CA_189834AC4B61
