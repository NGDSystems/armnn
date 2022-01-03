//
// Copyright © 2017 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//
#pragma once

#include "LayerWithParameters.hpp"

namespace armnn
{

/// This layer represents a L2 normalization operation.
class L2NormalizationLayer : public LayerWithParameters<L2NormalizationDescriptor>
{
public:
    /// Makes a workload for the L2Normalization type.
    /// @param [in] graph The graph where this layer can be found.
    /// @param [in] factory The workload factory which will create the workload.
    /// @return A pointer to the created workload, or nullptr if not created.
    virtual std::unique_ptr<IWorkload> CreateWorkload(const IWorkloadFactory& factory) const override;

    /// Creates a dynamically-allocated copy of this layer.
    /// @param [in] graph The graph into which this layer is being cloned.
    L2NormalizationLayer* Clone(Graph& graph) const override;

    /// Check if the input tensor shape(s)
    /// will lead to a valid configuration of @ref L2NormalizationLayer.
    /// @param [in] shapeInferenceMethod Indicates if output shape shall be overwritten or just validated.
    void ValidateTensorShapesFromInputs() override;

    ARMNN_NO_DEPRECATE_WARN_BEGIN
    void Accept(ILayerVisitor& visitor) const override;
    ARMNN_NO_DEPRECATE_WARN_END

protected:
    /// Constructor to create a L2NormalizationLayer.
    /// @param [in] param L2NormalizationDescriptor to configure the L2 normalization operation.
    /// @param [in] name Optional name for the layer.
    L2NormalizationLayer(const L2NormalizationDescriptor& param, const char* name);

    /// Default destructor
    ~L2NormalizationLayer() = default;
};

} // namespace
