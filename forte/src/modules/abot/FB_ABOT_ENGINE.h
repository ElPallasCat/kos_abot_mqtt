/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FB_ABOT_ENGINE
 *** Description: Simple FB with one algorithm
 *** Version:
***     1.0: 2022-07-15/slava -  - 
 *************************************************************************/

#ifndef _FB_ABOT_ENGINE_H_
#define _FB_ABOT_ENGINE_H_

#include "simplefb.h"
#include "forte_int.h"

#include <gpio/gpio.h>
#include <stdbool.h>

#ifdef __arm__
#include <bsp/bsp.h>
#endif


class FORTE_FB_ABOT_ENGINE: public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_FB_ABOT_ENGINE)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  
  static const TEventID scm_nEventREQID = 0;
  
  static const TDataIOID scm_anEIWith[];
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];
  
  static const TEventID scm_nEventCNFID = 0;
  
  static const TDataIOID scm_anEOWith[];
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];
  

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

  CIEC_INT &CMD() {
    return *static_cast<CIEC_INT*>(getDI(0));
  }
  
  CIEC_INT &DURATION() {
    return *static_cast<CIEC_INT*>(getDI(1));
  }
  

  void alg_REQ(void);

  FORTE_FB_DATA_ARRAY(1, 2, 0, 0);

  

public:
  FORTE_FB_ABOT_ENGINE(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CSimpleFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, nullptr, m_anFBConnData, m_anFBVarsData) {

// 

  };

  virtual ~FORTE_FB_ABOT_ENGINE() = default;
};

#endif // _FB_ABOT_ENGINE_H_


