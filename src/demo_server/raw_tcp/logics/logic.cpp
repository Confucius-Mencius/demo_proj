#include "logic.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "raw_tcp_protobuf_util.h"

using namespace com::moon::demo;

namespace tcp
{
namespace raw
{
Logic::Logic() : msg_handler_mgr_()
{
}

Logic::~Logic()
{
}

const char* Logic::GetVersion() const
{
    return nullptr;
}

const char* Logic::GetLastErrMsg() const
{
    return nullptr;
}

void Logic::Release()
{
    delete this;
}

int Logic::Initialize(const void* ctx)
{
    if (LogicInterface::Initialize(ctx) != 0)
    {
        return -1;
    }

    if (msg_handler_mgr_.Initialize(&logic_ctx_) != 0)
    {
        return -1;
    }

    return 0;
}

void Logic::Finalize()
{
    msg_handler_mgr_.Finalize();
}

int Logic::Activate()
{
    msg_handler_mgr_.SetGlobalLogic((global::TheLogicInterface*) global_logic_);
    msg_handler_mgr_.SetLogic(this);

    if (msg_handler_mgr_.Activate() != 0)
    {
        return -1;
    }

    return 0;
}

void Logic::Freeze()
{
    msg_handler_mgr_.Freeze();
}

void Logic::OnStop()
{
    can_exit_ = true;
}

void Logic::OnReload()
{
}

void Logic::OnClientConnected(const ConnGUID* conn_guid)
{
}

void Logic::OnClientClosed(const ConnGUID* conn_guid)
{
}

void Logic::OnRecvClientData(const ConnGUID* conn_guid, const void* data, size_t len)
{
    const std::string d((const char*) data, len);
    LOG_DEBUG("tcp::raw::CommonLogic::OnRecvClientData, " << *conn_guid << ", data: " << d);

    if ("req1001" == d)
    {
        const char rsp1001[] = "rsp1001";
        logic_ctx_.scheduler->SendToClient(conn_guid, rsp1001, strlen(rsp1001));

        const char nfy1001[] = "nfy1001";
        logic_ctx_.scheduler->SendToClient(conn_guid, nfy1001, strlen(nfy1001));

        ////////////////////////////////////////////////////////////////////////////////
        ::proto::MsgHead demo1002_req_msg_head = { 0, ss::MSG_ID_DEMO1002_REQ };

        ss::Demo1002Req demo1002_req;
        demo1002_req.set_a(1002);
        demo1002_req.set_raw_tcp_thread_idx(logic_ctx_.thread_idx);

        if (SendToGlobalThread(logic_ctx_.scheduler, conn_guid, demo1002_req_msg_head, &demo1002_req) != 0)
        {
            LOG_ERROR("failed to send to global thread, " << *conn_guid << ", msg id: " << demo1002_req_msg_head.msg_id);
            return;
        }

        ////////////////////////////////////////////////////////////////////////////////
        ::proto::MsgHead demo1003_req_msg_head = { 0, ss::MSG_ID_DEMO1003_REQ };

        ss::Demo1003Req demo1003_req;
        demo1003_req.set_a(1003);

        if (SendToTCPThread(logic_ctx_.scheduler, conn_guid, demo1003_req_msg_head, &demo1003_req, -1) != 0)
        {
            LOG_ERROR("failed to send to tcp thread, " << *conn_guid << ", msg id: " << demo1003_req_msg_head.msg_id);
            return;
        }

        ////////////////////////////////////////////////////////////////////////////////
        ::proto::MsgHead demo1004_req_msg_head = { 0, ss::MSG_ID_DEMO1004_REQ };

        ss::Demo1004Req demo1004_req;
        demo1004_req.set_a(1004);

        if (SendToWorkThread(logic_ctx_.scheduler, conn_guid, demo1004_req_msg_head, &demo1004_req, -1) != 0)
        {
            LOG_ERROR("failed to send to work thread, " << *conn_guid << ", msg id: " << demo1004_req_msg_head.msg_id);
            return;
        }
    }
    else if ("req1100" == d)
    {
        logic_ctx_.scheduler->CloseClient(conn_guid);
    }
    else
    {
        // echo test
        logic_ctx_.scheduler->SendToClient(conn_guid, data, len);
    }
}

void Logic::OnTask(const ConnGUID* conn_guid, ThreadInterface* source_thread, const void* data, size_t len)
{
}
}
}
