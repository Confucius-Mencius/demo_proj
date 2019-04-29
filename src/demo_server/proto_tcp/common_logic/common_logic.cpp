#include "common_logic.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "proto_msg_codec.h"
#include "proto_tcp_protobuf_util.h"

using namespace com::moon::demo;

namespace tcp
{
namespace proto
{
CommonLogic::CommonLogic()
{
}

CommonLogic::~CommonLogic()
{
}

const char* CommonLogic::GetVersion() const
{
    return nullptr;
}

const char* CommonLogic::GetLastErrMsg() const
{
    return nullptr;
}

void CommonLogic::Release()
{
    delete this;
}

int CommonLogic::Initialize(const void* ctx)
{
    if (LogicInterface::Initialize(ctx) != 0)
    {
        return -1;
    }

    return 0;
}

void CommonLogic::Finalize()
{
}

int CommonLogic::Activate()
{
    return 0;
}

void CommonLogic::Freeze()
{
}

void CommonLogic::OnStop()
{
    can_exit_ = true;
}

void CommonLogic::OnReload()
{
}

void CommonLogic::OnClientConnected(const ConnGUID* conn_guid)
{
}

void CommonLogic::OnClientClosed(const ConnGUID* conn_guid)
{
}
}
}
