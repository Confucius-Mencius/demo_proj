#include "global_test_env.h"

LogEngineInterface* g_log_engine;

GlobalTestEnv::GlobalTestEnv()
{
}

GlobalTestEnv::~GlobalTestEnv()
{
}

void GlobalTestEnv::SetUp()
{
    std::cout << "this funtion execute before all test suite executing" << std::endl;
    g_log_engine = &console_log_engine_;
}

void GlobalTestEnv::TearDown()
{
    std::cout << "this function execute after all test suite executed" << std::endl;
}
