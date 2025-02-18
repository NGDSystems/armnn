//
// Copyright © 2017 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//
#include "MemCopyLayer.hpp"

#include "LayerCloneBase.hpp"

#include <armnn/TypesUtils.hpp>
#include <backendsCommon/WorkloadData.hpp>
#include <backendsCommon/WorkloadFactory.hpp>
#include <backendsCommon/MemCopyWorkload.hpp>

namespace armnn
{

MemCopyLayer::MemCopyLayer(const char* name)
    : Layer(1, 1, LayerType::MemCopy, name)
{
}

MemCopyLayer* MemCopyLayer::Clone(Graph& graph) const
{
    return CloneBase<MemCopyLayer>(graph, GetName());
}

std::unique_ptr<IWorkload> MemCopyLayer::CreateWorkload(const IWorkloadFactory& factory) const
{
    IgnoreUnused(factory);
    MemCopyQueueDescriptor descriptor;
    SetAdditionalInfo(descriptor);

    //This is different from other workloads. Does not get created by the workload factory.
    return std::make_unique<CopyMemGenericWorkload>(descriptor, PrepInfoAndDesc(descriptor));
}

void MemCopyLayer::ValidateTensorShapesFromInputs()
{
    VerifyLayerConnections(1, CHECK_LOCATION());

    const TensorShape& outputShape = GetOutputSlot(0).GetTensorInfo().GetShape();

    VerifyShapeInferenceType(outputShape, m_ShapeInferenceMethod);

    auto inferredShapes = InferOutputShapes({ GetInputSlot(0).GetConnection()->GetTensorInfo().GetShape() });

    ARMNN_ASSERT(inferredShapes.size() == 1);

    ValidateAndCopyShape(outputShape, inferredShapes[0], m_ShapeInferenceMethod, "MemCopyLayer");
}

ARMNN_NO_DEPRECATE_WARN_BEGIN
void MemCopyLayer::Accept(ILayerVisitor& visitor) const
{
    IgnoreUnused(visitor);
    throw armnn::Exception("MemCopyLayer should not appear in an input graph");
}
ARMNN_NO_DEPRECATE_WARN_END

void MemCopyLayer::ExecuteStrategy(IStrategy& strategy) const
{
    IgnoreUnused(strategy);
    throw armnn::Exception("FakeQuantizationLayer should not appear in an input graph");
}

} // namespace armnn
