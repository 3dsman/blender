#ifndef _COM_GlslOperation_h_
#define _COM_GlslOperation_h_

#include <string>

#include "COM_NodeOperation.h"
#include "COM_SingleThreadedOperation.h"

#define GLSL_CHANNELS 4
#define GLSL_VALUE_SOCKETS 5

struct GlslOperationParams {
    std::string fragment;
    float input0[4];
    float frameCurrent;
    float frameTime;
    float frameDelta;
};

class GlslOperation : public SingleThreadedOperation {
private:
    GlslOperationParams m_params;
    const NodeGlsl *m_data;
    bool m_channelLinked[GLSL_CHANNELS];
public:
    GlslOperation();

    void initExecution();
    void deinitExecution();
    bool determineDependingAreaOfInterest(rcti *input, ReadBufferOperation *readOperation, rcti *output);

    void setParams(const GlslOperationParams& params) { this->m_params = params; }
    void setData(const NodeGlsl *data) { this->m_data = data; }
    void setChannelLinked(int index, bool linked) { this->m_channelLinked[index] = linked; }

protected:

    MemoryBuffer *createMemoryBuffer(rcti *rect);
};

#endif
