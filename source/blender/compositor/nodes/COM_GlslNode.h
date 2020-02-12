#ifndef _COM_GlslNode_h_
#define _COM_GlslNode_h_

#include "COM_Node.h"

class GlslNode : public Node {
public:
    GlslNode(bNode *editorNode);
    void convertToOperations(NodeConverter &converter, const CompositorContext &context) const;
};

#endif
