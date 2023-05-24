/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: AB_KOSCMD_RECEIVER
 *** Description: Simple FB with one algorithm
 *** Version:
***     1.0: 2023-05-24/test -  - 
 *************************************************************************/

#include "AB_KOSCMD_RECEIVER.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "AB_KOSCMD_RECEIVER_gen.cpp"
#endif

#include <forte/Forte.edl.h>



typedef struct INavigationCommandImpl {
    struct forte_NavigationCommand base;     /* Base interface of object */
    TIpcVal *navCtr;
} INavigationCommandImpl;

/* Ping method implementation. */
static nk_err_t NavigationCommand_impl(struct forte_NavigationCommand *self,
                          const struct forte_NavigationCommand_SetNavigationCommand_req *req,
                          const struct nk_arena *req_arena,
                          struct forte_NavigationCommand_SetNavigationCommand_res *res,
                          struct nk_arena *res_arena) {
                            
	cmd->navCtr.cmd = req->value.command;
	cmd->navCtr.cond.notify_one();
	
    return NK_EOK;
}

static nk_err_t NavigationAutoCommand_impl(struct forte_NavigationCommand *self,
                          const struct forte_NavigationCommand_SetAutoNavigationCommand_req *req,
                          const struct nk_arena *req_arena,
                          struct forte_NavigationCommand_SetAutoNavigationCommand_res *res,
                          struct nk_arena *res_arena) {
                            

    return NK_EOK;
}

static struct forte_NavigationCommand *CreateINavigationCommandImpl(TIpcVal* navPtr) {
    /* Table of implementations of IPing interface methods. */
    static const struct forte_NavigationCommand_ops ops = {
        .SetNavigationCommand = NavigationCommand_impl,
        .SetAutoNavigationCommand = NavigationAutoCommand_impl,
    };

    /* Interface implementing object. */
    static struct INavigationCommandImpl impl = {
        .base = {&ops},
        .navCtr = {navPtr}
    };

    return &impl.base;
}



void kasperIpcIOThreadFunc(TIpcVal *valPtr) {
	NkKosTransport transport;
    ServiceId iid;

    Handle handle = ServiceLocatorRegister("navigation_connection", NULL, 0, &iid);
    assert(handle != INVALID_HANDLE);

    NkKosTransport_Init(&transport, handle, NK_NULL, 0);

   
    forte_Forte_entity_req req;
    char req_buffer[forte_Forte_entity_req_arena_size];
    struct nk_arena req_arena = NK_ARENA_INITIALIZER(req_buffer,
                                        req_buffer + sizeof(req_buffer));

    forte_Forte_entity_res res;
    char res_buffer[forte_Forte_entity_res_arena_size];
    struct nk_arena res_arena = NK_ARENA_INITIALIZER(res_buffer,
                                        res_buffer + sizeof(res_buffer));

    forte_NavigationCommand_component component;
    forte_NavigationCommand_component_init(&component, CreateINavigationCommandImpl(valPtr));

    forte_Forte_entity entity;
    forte_Forte_entity_init(&entity, &component);

    fprintf(stderr, "Navigation server started\n");

    /* Dispatch loop implementation. */
    do
    {
        /* Flush request/response buffers. */
        nk_req_reset(&req);
        nk_arena_reset(&req_arena);
        nk_arena_reset(&res_arena);

        /* Wait for request to server entity. */
        if (nk_transport_recv(&transport.base,
                              &req.base_,
                              &req_arena) != NK_EOK) {
            fprintf(stderr, "nk_transport_recv error\n");
        } else {
            forte_Forte_entity_dispatch(&entity, &req.base_, &req_arena,
                                        &res.base_, &res_arena);
        }

        /* Send response. */
        if (nk_transport_reply(&transport.base,
                               &res.base_,
                               &res_arena) != NK_EOK) {
            fprintf(stderr, "nk_transport_reply error\n");
        }
    }
    while (true);
}


DEFINE_FIRMWARE_FB(FORTE_AB_KOSCMD_RECEIVER, g_nStringIdAB_KOSCMD_RECEIVER)


const CStringDictionary::TStringId FORTE_AB_KOSCMD_RECEIVER::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdCMD};

const CStringDictionary::TStringId FORTE_AB_KOSCMD_RECEIVER::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUINT};

const TForteInt16 FORTE_AB_KOSCMD_RECEIVER::scm_anEIWithIndexes[] = {-1};
const CStringDictionary::TStringId FORTE_AB_KOSCMD_RECEIVER::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_AB_KOSCMD_RECEIVER::scm_anEOWith[] = {1, 0, 255};
const TForteInt16 FORTE_AB_KOSCMD_RECEIVER::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_AB_KOSCMD_RECEIVER::scm_anEventOutputNames[] = {g_nStringIdCNF};


const SFBInterfaceSpec FORTE_AB_KOSCMD_RECEIVER::scm_stFBInterfaceSpec = {
  1, scm_anEventInputNames, nullptr, scm_anEIWithIndexes,
  1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes,
  0, nullptr, nullptr,
  2, scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, nullptr
};

void FORTE_AB_KOSCMD_RECEIVER::setInitialValues() {
}
void FORTE_AB_KOSCMD_RECEIVER::alg_REQ(void) {

    std::unique_lock<std::mutex> lck(cmdVal.mtx);
    cmdVal.cond.wait(lck);

    st_QO()  = 1;  
    st_CMD() = cmdVal.cmd;
}


