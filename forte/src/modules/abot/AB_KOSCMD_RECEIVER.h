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

#ifndef _AB_KOSCMD_RECEIVER_H_
#define _AB_KOSCMD_RECEIVER_H_

#include "simplefb.h"
#include "forte_bool.h"
#include "forte_uint.h"
#include "forte_array_at.h"


#include <thread>


void kasperIpcIOThreadFunc(TIpcVal *valPtr);

struct TIpcVal {
  std::condition_variable cond;
  std::mutex mtx;
  unsigned int cmd;

  TIpcVal():cmd(0){} 
};

class FORTE_AB_KOSCMD_RECEIVER: public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_AB_KOSCMD_RECEIVER)

  TIpcVal cmdVal;
  std::thread iothread(kasperIpcIOThreadFunc,&cmdVal);

private:
  
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  
  static const TEventID scm_nEventREQID = 0;
  
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];
  
  static const TEventID scm_nEventCNFID = 0;
  
   static const TDataIOID scm_anEOWith[]; 
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];
  

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;
virtual void setInitialValues();
  CIEC_BOOL &st_QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  }
  
  CIEC_UINT &st_CMD() {
    return *static_cast<CIEC_UINT*>(getDO(1));
  }
  

  void alg_REQ(void);

  FORTE_BASIC_FB_DATA_ARRAY(1, 0, 2, 0, 0);

public:
  FORTE_AB_KOSCMD_RECEIVER(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
       CSimpleFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, nullptr, m_anFBConnData, m_anFBVarsData) {
  };

  virtual ~FORTE_AB_KOSCMD_RECEIVER() = default;
};

#endif // _AB_KOSCMD_RECEIVER_H_


